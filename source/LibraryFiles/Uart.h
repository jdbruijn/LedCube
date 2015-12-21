/*******************************************************************************
 * Begin of file Uart.h
 * Author: jdebruijn
 * Created on August 31, 2015, 9:03 PM
 * 
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 * 
 * This file is part of LedCube.
 * 
 * Copyright (c) 2015  Jeroen de Bruijn  <vidavidorra@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Controls the UART functionality of the device to send and receive
 * data.
 * 
 ******************************************************************************/

#ifndef UART_H
#define UART_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Switches
 ******************************************************************************/
#define UART_USE_PRINTF_FLAG 1

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#if (UART_USE_PRINTF_FLAG) || defined(DEBUG)
# include <stdio.h>           // For vsprintf() in Uartx_printf()
# include <stdarg.h>          // For Uartx_printf()
# include <string.h>          // For memset()
#endif /* UART_USE_PRINTF_FLAG or DEBUG */
#include "Delay.h"
#include "Interrupts.h"
#include "SwFifoBuffer.h"

/*******************************************************************************
 * Defines
 ******************************************************************************/
/** @brief Maximum string length for UART 1. */
#define UART1_MAX_STR_LEN       255
/** @brief Decimal ASCII number of the carriage return character. */
#define UART_CR                 13
/** @brief Decimal ASCII number of the linefeed character. */
#define UART_LF                 10
/** @brief Baudrate clock prescaler for UART 1.
 * 
 * This value should be either 4 or 16.
 * 4 = BRG generates 4 clocks per bit period (4x baud clock, High-Speed mode)
 * 16 = BRG generates 16 clocks per bit period (16x baud clock, Standard Speed
 * mode)
 */
#define UART1_BRG_CLOCKS        4
/** @brief Desired baudrate for UART 1. */
#define UART1_BAUDRATE          115200UL
/** @brief UART 1 baud rate register value. */
#define UART1_BRG               ((FCY / (UART1_BRG_CLOCKS * UART1_BAUDRATE)) -1)
/** @brief Actual calculated baudrate for UART 1. */
#define UART1_ACTUAL_BAUDRATE   ( FCY / (UART1_BRG_CLOCKS * (UART1_BRG + 1)) )
/**
 * @brief UARTx Baud Rate error.
 * 
 * This value is in tenth, so a value of 21 means that the Baud Rate error
 * equals 2.1%.
 * 
 * "Error = [(Calculated Baud Rate - Desired Baud Rate) / Desired Baud Rate]"
 * (Universal Asynchronous Receiver Transmitter (UART), Equation 3-2: Baud
 * Rate Error Calculation (BRGH = 0), Microchip)
 */
#define UART1_BAUD_ERROR        ((10000 * (UART1_ACTUAL_BAUDRATE - \
            UART1_BAUDRATE)) / UART1_BAUDRATE )

/*******************************************************************************
 * Constant macros
 ******************************************************************************/
#if (UART_USE_PRINTF_FLAG) || defined(DEBUG)
/**
 * @brief Print formatted data.
 * 
 * Writes the C string pointed by format to the standard stream. If format
 * includes format specifiers (subsequences beginning with %), the additional
 * arguments following format are formatted and inserted in the resulting string
 * replacing their respective specifiers.
 * 
 * @param   format C string that contains the text to be written to UARTx.  
 * It can optionally contain embedded format specifiers that are replaced by
 * the values specified in subsequent additional arguments and formatted as
 * requested.                                                                 \n
 * 
 * A format specifier follows this prototype:
 *  %[flags][width][.precision][length]specifier
 * @verbatim
 * Where the specifier character at the end is the most significant component,
 * since it defines the type and the interpretation of its corresponding
 * argument:
 * | specifier  | output                                       | example       |
 * | ---------- | -------------------------------------------- | ------------- |
 * | d or i     | Signed decimal integer                       | 392           |
 * | u          | Unsigned decimal integer                     | 7235          |
 * | o          | Unsigned octal                               | 610           |
 * | x          | Unsigned hexadecimal integer                 | 7fa           |
 * | X          | Unsigned hexadecimal integer (uppercase)     | 7FA           |
 * | f          | Decimal floating point, lowercase            | 392.65        |
 * | F          | Decimal floating point, uppercase            | 392.65        |
 * | e          | Scientific notation (exponent), lowercase    | 3.9265e+2     |
 * | E          | Scientific notation (exponent), uppercase    | 3.9265E+2     |
 * | g          | Use the shortest representation: %e or %f    | 392.65        |
 * | G          | Use the shortest representation: %E or %F    | 392.65        |
 * | a          | Hexadecimal floating point, lowercase        | -0xc.90fep-2  |
 * | A          | Hexadecimal floating point, uppercase        | -0XC.90FEP-2  |
 * | c          | Character                                    | a             |
 * | s          | String of characters                         | sample        |
 * | p          | Pointer address                              | b8000000      |
 * | n          | Nothing printed. The corresponding argument
 *                must be a pointer to a signed int. The
 *                number of characters written so far is
 *                stored in the pointed location.              |               |
 * | %          | A % followed by another % character will
 *                write a single % to the stream.              | %             |
 * 
 * The format specifier can also contain sub-specifiers: flags, width,
 * .precision and modifiers (in that order), which are optional and follow these
 * specifications:
 * | flags    | description                                                    |
 * | -------- | -------------------------------------------------------------- |
 * | -        | Left-justify within the given field width; Right justification
 *              is the default (see width sub-specifier).                      |
 * | +        | Forces to preceed the result with a plus or minus sign (+ or -)
 *              even for positive numbers. By default, only negative numbers
 *              are preceded with a - sign.                                    |
 * | (space)  | If no sign is going to be written, a blank space is inserted
 *              before the value.                                              |
 * | #        | Used with o, x or X specifiers the value is preceeded
 *              with 0, 0x or 0X respectively for values different than zero.
 *              Used with a, A, e, E, f, F, g or G it forces the written output
 *              to contain a decimal point even if no more digits follow.
 *              By default, if no digits follow, no decimal point is written.  |
 * | 0        | Left-pads the number with zeroes (0) instead of spaces when
 *              padding is specified (see width sub-specifier).                |
 * 
 * | width     | description                                                   |
 * | --------- | ------------------------------------------------------------- |
 * | (number)  | Minimum number of characters to be printed.
 *               If the value to be printed is shorter than this number,
 *               the result is padded with blank spaces. The value is not
 *               truncated even if the result is larger.
 * | *         | The width is not specified in the format string, but as
 *               an additional integer value argument preceding the argument
 *               that has to be formatted.
 * 
 * | .precision | description                                                  |
 * | ---------- | ------------------------------------------------------------ |
 * | .number    | For integer specifiers (d, i, o, u, x, X): precision 
 *                specifies the minimum number of digits to be written. If the
 *                value to be written is shorter than this number, the result
 *                is padded with leading zeros. The value is not truncated
 *                even if the result is longer. A precision of 0 means that no
 *                character is written for the value 0.  
 *                For a, A, e, E, f and F specifiers: this is the number of
 *                digits to be printed after the decimal point (by default,
 *                this is 6).  
 *                For g and G specifiers: This is the maximum number of
 *                significant digits to be printed.  
 *                For s: this is the maximum number of characters to be
 *                printed. By default all characters are printed until the
 *                ending null character is encountered.  
 *                If the period is specified without an explicit value for
 *                precision, 0 is assumed.                                     |
 * | *          | The precision is not specified in the format string,
 *                but as an additional integer value argument preceding the
 *                argument that has to be formatted.                           |
 * 
 * The length sub-specifier modifies the length of the data type. This is a
 * chart showing the types used to interpret the corresponding arguments with
 * and without length specifier (if a different type is used, the proper type
 * promotion or conversion is performed, if allowed):
 * |        | specifiers                                                       |
 * | length | d i           | u o x X                | n                       |
 * | ------ | ------------- | ---------------------- | ----------------------- |
 * | (none) | int           | unsigned int           | int*                    |
 * | hh     | signed char   | unsigned char          | signed char*            |
 * | h      | short int     | unsigned short int     | short int*              |
 * | l      | long int      | unsigned long int      | long int*               |
 * | ll     | long long int | unsigned long long int | long long int*          |
 * | j      | intmax_t      | uintmax_t              | intmax_t*               |
 * | z      | size_t        | size_t                 | size_t*                 |
 * | t      | ptrdiff_t     | ptrdiff_t              | ptrdiff_t*              |
 * 
 * Extended table:
 * |        | specifiers                                                       |
 * | length | f F e E g G a A | c      | s        | p                          |
 * | ------ | --------------- | ------ | -------- | -------------------------- |
 * | (none) | double          | int    | char*    | void*                      |
 * | hh     |                 |        |          |                            |
 * | h      |                 |        |          |                            |
 * | l      |                 | wint_t | wchar_t  |                            |
 * | ll     |                 |        |          |                            |
 * | j      |                 |        |          |                            |
 * | z      |                 |        |          |                            |
 * | t      |                 |        |          |                            |
 * | L      | long double     |        |          |                            |
 * @endverbatim
 * @param   ... (additional arguments) Depending on the format string, the
 * function may expect a sequence of additional arguments, each containing a
 * value to be used to replace a format specifier in the format string (or a
 * pointer to a storage location, for n). There should be at least as many of
 * these arguments as the number of values specified in the format specifiers.
 * Additional arguments are ignored by the function.
 * @return  uint16_t Length of the printed string.
 */
#define uprintf Uart1_printf
#else
# define uprintf(...) (void)0
# warning "uprintf is disabled. No uprintf messages will be printed!"
#endif /* UART_USE_PRINTF_FLAG or DEBUG */

/**
 * @brief Print a character.
 * 
 * Writes the a character (byte) to the standard stream.
 * 
 * @param   _c Character to send.
 */
#define uputc Uart1_putc

/**
 * @brief Print a string.
 * 
 * Writes the a string to the standard stream.
 * 
 * @param   _s String to send.
 */
#define uputs Uart1_puts

/**
 * @brief Print a number.
 * 
 * Writes an integer number to the standard stream.
 * 
 * @note    The number must be within range of a 32-bit integer. Thus the
 * lowest number is -2147483647 and the highest number is 2147483647.
 * @param   _num Number to send.
 * @param   _base Numeral system to use.
 * @verbatim
 * | _base  | Description                                                      |
 * | ------ | ---------------------------------------------------------------- |
 * | 2      | Binary (adds suffix 'b' to the output)                           |
 * | 10     | Decimal                                                          |
 * | 16     | hexadecimal (adds suffix 'h' to the output)                      |
 * @endverbatim
 * @param   _printBase Boolean value whether the base ('b' or 'h' suffix) needs
 * to be send.
 */
#define uputnum Uart1_putNum

/**
 * @brief Print an unsigned number with zero padding.
 * 
 * Writes an unsigned number with zero padding to the standard stream.
 * 
 * @param   _num Number to send
 * @param   _nBits Number of bits to send.
 */
#define uputbits Uart1_putBits

/*******************************************************************************
 * Condition checks
 ******************************************************************************/
#if (UART1_BRG_CLOCKS != 4) && (UART1_BRG_CLOCKS != 16)
# error "Wrong value for UART_BRG_CLOCKS"
#endif
#if (UART1_BAUD_ERROR > 250) && (UART1_BAUD_ERROR <= 500)
# warning "UART1 Baud Rate error is greater than 2.5%"
#elif (UART1_BAUD_ERROR > 500)
# error "UART1 Baud Rate error is greater than 5.0%"
#endif

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * @brief Initialize the UARTx module with the given baud rate.
 * 
 * @note    If debug is enabled this function should be called before
 * initializing all other initialize functions. But obviously I/O ports should
 * be configured fist.
 * @note    Make sure the analog functionality of the RX pin, if it has an
 * analog functionality, is disabled.
 */
void
Uart1_init(void);

/**
 * @brief Send a single character (byte) using the UARTx module.
 * 
 * @param   _c Character to send using UARTx.
 */
void
Uart1_putc(const char _c);

/**
 * @brief Send a string using the UARTx module.
 * 
 * @param   _s String to send using UARTx.
 */
void
Uart1_puts(const char* _s);

/**
 * @brief Send an integer number using the UARTx module.
 * 
 * @note    The number must be within range of a 32-bit integer. Thus the
 * lowest number is -2147483647 and the highest number is 2147483647.
 * @param   _num Number to send using UARTx.
 * @param   _base The numeral system to use.
 * @verbatim
 * | _base  | Description                                                      |
 * | ------ | ---------------------------------------------------------------- |
 * | 2      | Binary (adds suffix 'b' to the output)                           |
 * | 10     | Decimal                                                          |
 * | 16     | hexadecimal (adds suffix 'h' to the output)                      |
 * @endverbatim
 * @param   _printBase Boolean value whether the base ('b' or 'h' suffix) needs
 * to be send.
 */
void
Uart1_putNum(int32_t _num, uint8_t _base, bool _printBase);

/**
 * @brief Send a byte in binary form (with zero padding) using the UARTx module.
 * 
 * @param   _num Variable to send using UARTx
 * @param   _nBits Number of bits to send
 */
void
Uart1_putBits(const uint64_t _num, uint8_t _nBits);

#if (UART_USE_PRINTF_FLAG) || defined(DEBUG)
/**
 * @brief Print formatted data.
 * 
 * Writes the C string pointed by format to the standard stream. If format
 * includes format specifiers (subsequences beginning with %), the additional
 * arguments following format are formatted and inserted in the resulting string
 * replacing their respective specifiers.
 * 
 * @param   format C string that contains the text to be written to UARTx.  
 * It can optionally contain embedded format specifiers that are replaced by
 * the values specified in subsequent additional arguments and formatted as
 * requested.                                                                 \n
 * 
 * A format specifier follows this prototype:
 *  %[flags][width][.precision][length]specifier
 * @verbatim
 * Where the specifier character at the end is the most significant component,
 * since it defines the type and the interpretation of its corresponding
 * argument:
 * | specifier  | output                                       | example       |
 * | ---------- | -------------------------------------------- | ------------- |
 * | d or i     | Signed decimal integer                       | 392           |
 * | u          | Unsigned decimal integer                     | 7235          |
 * | o          | Unsigned octal                               | 610           |
 * | x          | Unsigned hexadecimal integer                 | 7fa           |
 * | X          | Unsigned hexadecimal integer (uppercase)     | 7FA           |
 * | f          | Decimal floating point, lowercase            | 392.65        |
 * | F          | Decimal floating point, uppercase            | 392.65        |
 * | e          | Scientific notation (exponent), lowercase    | 3.9265e+2     |
 * | E          | Scientific notation (exponent), uppercase    | 3.9265E+2     |
 * | g          | Use the shortest representation: %e or %f    | 392.65        |
 * | G          | Use the shortest representation: %E or %F    | 392.65        |
 * | a          | Hexadecimal floating point, lowercase        | -0xc.90fep-2  |
 * | A          | Hexadecimal floating point, uppercase        | -0XC.90FEP-2  |
 * | c          | Character                                    | a             |
 * | s          | String of characters                         | sample        |
 * | p          | Pointer address                              | b8000000      |
 * | n          | Nothing printed. The corresponding argument
 *                must be a pointer to a signed int. The
 *                number of characters written so far is
 *                stored in the pointed location.              |               |
 * | %          | A % followed by another % character will
 *                write a single % to the stream.              | %             |
 * 
 * The format specifier can also contain sub-specifiers: flags, width,
 * .precision and modifiers (in that order), which are optional and follow these
 * specifications:
 * | flags    | description                                                    |
 * | -------- | -------------------------------------------------------------- |
 * | -        | Left-justify within the given field width; Right justification
 *              is the default (see width sub-specifier).                      |
 * | +        | Forces to preceed the result with a plus or minus sign (+ or -)
 *              even for positive numbers. By default, only negative numbers
 *              are preceded with a - sign.                                    |
 * | (space)  | If no sign is going to be written, a blank space is inserted
 *              before the value.                                              |
 * | #        | Used with o, x or X specifiers the value is preceeded
 *              with 0, 0x or 0X respectively for values different than zero.
 *              Used with a, A, e, E, f, F, g or G it forces the written output
 *              to contain a decimal point even if no more digits follow.
 *              By default, if no digits follow, no decimal point is written.  |
 * | 0        | Left-pads the number with zeroes (0) instead of spaces when
 *              padding is specified (see width sub-specifier).                |
 * 
 * | width     | description                                                   |
 * | --------- | ------------------------------------------------------------- |
 * | (number)  | Minimum number of characters to be printed.
 *               If the value to be printed is shorter than this number,
 *               the result is padded with blank spaces. The value is not
 *               truncated even if the result is larger.
 * | *         | The width is not specified in the format string, but as
 *               an additional integer value argument preceding the argument
 *               that has to be formatted.
 * 
 * | .precision | description                                                  |
 * | ---------- | ------------------------------------------------------------ |
 * | .number    | For integer specifiers (d, i, o, u, x, X): precision 
 *                specifies the minimum number of digits to be written. If the
 *                value to be written is shorter than this number, the result
 *                is padded with leading zeros. The value is not truncated
 *                even if the result is longer. A precision of 0 means that no
 *                character is written for the value 0.  
 *                For a, A, e, E, f and F specifiers: this is the number of
 *                digits to be printed after the decimal point (by default,
 *                this is 6).  
 *                For g and G specifiers: This is the maximum number of
 *                significant digits to be printed.  
 *                For s: this is the maximum number of characters to be
 *                printed. By default all characters are printed until the
 *                ending null character is encountered.  
 *                If the period is specified without an explicit value for
 *                precision, 0 is assumed.                                     |
 * | *          | The precision is not specified in the format string,
 *                but as an additional integer value argument preceding the
 *                argument that has to be formatted.                           |
 * 
 * The length sub-specifier modifies the length of the data type. This is a
 * chart showing the types used to interpret the corresponding arguments with
 * and without length specifier (if a different type is used, the proper type
 * promotion or conversion is performed, if allowed):
 * |        | specifiers                                                       |
 * | length | d i           | u o x X                | n                       |
 * | ------ | ------------- | ---------------------- | ----------------------- |
 * | (none) | int           | unsigned int           | int*                    |
 * | hh     | signed char   | unsigned char          | signed char*            |
 * | h      | short int     | unsigned short int     | short int*              |
 * | l      | long int      | unsigned long int      | long int*               |
 * | ll     | long long int | unsigned long long int | long long int*          |
 * | j      | intmax_t      | uintmax_t              | intmax_t*               |
 * | z      | size_t        | size_t                 | size_t*                 |
 * | t      | ptrdiff_t     | ptrdiff_t              | ptrdiff_t*              |
 * 
 * Extended table:
 * |        | specifiers                                                       |
 * | length | f F e E g G a A | c      | s        | p                          |
 * | ------ | --------------- | ------ | -------- | -------------------------- |
 * | (none) | double          | int    | char*    | void*                      |
 * | hh     |                 |        |          |                            |
 * | h      |                 |        |          |                            |
 * | l      |                 | wint_t | wchar_t  |                            |
 * | ll     |                 |        |          |                            |
 * | j      |                 |        |          |                            |
 * | z      |                 |        |          |                            |
 * | t      |                 |        |          |                            |
 * | L      | long double     |        |          |                            |
 * @endverbatim
 * @param   ... (additional arguments) Depending on the format string, the
 * function may expect a sequence of additional arguments, each containing a
 * value to be used to replace a format specifier in the format string (or a
 * pointer to a storage location, for n). There should be at least as many of
 * these arguments as the number of values specified in the format specifiers.
 * Additional arguments are ignored by the function.
 * @return  uint16_t Length of the printed string.
 */
uint16_t
Uart1_printf(const char *format, ...);
#endif /* UART_USE_PRINTF_FLAG or DEBUG */

/**
 * Receive a string using the UARTx module.
 * 
 * @param   _str, pointer to an array of chars where the received string is
 * copied.
 * @param   _num, maximum number of characters to be copied into _str (including
 * the terminating null-character).
 * @return  void
 * @example <code>char rxStr[100] = {0};\n
 * Uartx_gets(rxStr, 100);</code>
 */
void
Uart1_gets(char *_str, uint8_t _num);

#ifdef __cplusplus
}
#endif

#endif /* UART_H */
/* End of file Uart.h */
