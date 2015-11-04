/*******************************************************************************
 * Begin of file Uart.h
 * Author: jdebruijn
 * Created on August 31, 2015, 9:03 PM
 * 
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 * 
 * Copyright (c) 2015 Jeroen de Bruijn <vidavidorra@gmail.com>
 * 
 * This file is part of LedCube which is released under The MIT License (MIT).
 * For full license details see file "main.c" or "LICENSE.md" or go to
 * https://opensource.org/licenses/MIT
 * 
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 * 
 * Description:
 *  Controls the UART functionality of the device to send and receive data.
 * 
 ******************************************************************************/

#ifndef UART_H
#define	UART_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Switches
 ******************************************************************************/
#define UART_USE_PRINTF_YES
#define UART_INIT_COMPLETE_MSG_NO
    
#ifdef DEBUG
  #define DEBUG_FLAG 1
  #ifndef UART_USE_PRINTF_YES
    #define UART_USE_PRINTF_YES
  #endif
#else
  #define DEBUG_FLAG 0
#endif

#define DEBUG_PR(intend, fmt, args...) do{ if(DEBUG_FLAG) \
                Uart1_printf("%*c DEBUG: %s:%d:%s(): " fmt "\n", intend, ' ', __FILE__, __LINE__, \
                __func__, ##args); }while(0)

#define DEBUG_PRINTF(fmt, args...) do{ if(DEBUG_FLAG) \
                Uart1_printf(" DEBUG: %s:%d:%s(): " fmt "\n", __FILE__, __LINE__, \
                __func__, ##args); }while(0)
#define DEBUG_PRINTF_FUNCTION_CALL(fmt, args...) do{ if(DEBUG_FLAG) \
                Uart1_printf(" DEBUG: %s(" fmt ")\n", __FUNCTION__ , ##args); }while(0)  
    // @todo Move debug printf to debug.h or debug.c file...
    
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#ifdef UART_USE_PRINTF_YES
#include <stdio.h>              // For vsprintf() in Uart_printf()
#include <stdarg.h>             // For Uart_printf()
#include <string.h>             // For memset()
#endif /* UART_USE_PRINTF_YES */
#include "System.h"             // For definition of FCY (must be before libpic30.h)
#include <libpic30.h>           // for __delay_ms()
#include "Interrupts.h"
#include "SwFifoBuffer.h"

/*******************************************************************************
 * Defines
 ******************************************************************************/
/**
 * Note: UART_BRG_CLOCKS must be either 4 or 16 for further calculations!
 * 4 = BRG generates 4 clocks per bit period (4x baud clock, High-Speed mode)
 * 16 = BRG generates 16 clocks per bit period (16x baud clock, Standard Speed mode)
 */
#define UART1_MAX_STR_LEN       255
#define UART_CR                 13              // Carriage return character
#define UART_LF                 10              // Linefeed character
#define UART1_BRG_CLOCKS        4
#define UART1_BAUDRATE          115200UL
#define UART1_BRG               ((FCY / (UART1_BRG_CLOCKS * UART1_BAUDRATE)) -1)
#define UART1_ACTUAL_BAUDRATE   ( FCY / (UART1_BRG_CLOCKS * (UART1_BRG + 1)) )
/**
 * UARTx Baud Rate error. This value is in tenth, so a value of 21 means that
 * the Baud Rate error equals 2.1%.
 * 
 * "Error = [(Calculated Baud Rate - Desired Baud Rate) / Desired Baud Rate]"
 * (Universal Asynchronous Receiver Transmitter (UART), Equation 3-2: Baud
 * Rate Error Calculation (BRGH = 0), Microchip)
 */
#define UART1_BAUD_ERROR        ((10000 * (UART1_ACTUAL_BAUDRATE - \
            UART1_BAUDRATE)) / UART1_BAUDRATE )

/*******************************************************************************
 * Condition checks
 ******************************************************************************/
#if (UART1_BRG_CLOCKS != 4) && (UART1_BRG_CLOCKS != 16)
#error "Wrong value for UART_BRG_CLOCKS"
#endif
#if (UART1_BAUD_ERROR > 250) && (UART1_BAUD_ERROR <= 500)
#warning UART1 Baud Rate error is greater than 2.5%
#elif (UART1_BAUD_ERROR > 500)
#error UART1 Baud Rate error is greater than 5.0%
#endif

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * Initialize the UARTx module with the given baud rate.
 * 
 * @Note    Make sure the analog functionality of the RX pin, if it has an
 * analog functionality, is disabled.
 * @param   void
 * @return  void
 * @Example <code>Uartx_init();</code>
 */
void
Uart1_init( void );

/**
 * Send a single character (byte) using the UARTx module.
 * 
 * @param   _c, character to send using UARTx.
 * @return  void
 * @Example <code>Uartx_putc('n'); &#09 // Outputs n</code>
 */
void
Uart1_putc( const char _c );

/**
 * Send a string using the UARTx module.
 * 
 * @param   _s, string to send using UARTx
 * @return  void
 * @example <code>Uartx_puts("Hello this is a string");</code>
 */
void
Uart1_puts( const char* _s );

/**
 * Send a integer number using the UARTx module.
 * 
 * @Note    Output is without zero padding.
 * @Note    The number must be within range of a 32-bit integer. Thus the
 * lowest number is -2147483647 and the highest number is 2147483647.
 * @param   _num Number to send using UARTx.
 * @param   _base The numeral system to use.\n
 * _base    &#09 Description\n
 * 2        &#09 Binary (adds prefix b to the output)\n
 * 10       &#09 Decimal\n
 * 16       &#09 Hexadecimal (adds prefix h to the output)
 * @return  void
 * @example <code>Uartx_putNum(123, 10);    &#09 // Outputs 123\n
 *          Uartx_putNum(123, 2);           &#09 // Outputs 1111011b\n
 *          Uartx_putNum(123, 16);          &#09 // Outputs 7Bh
 */
void
Uart1_putNum( int32_t _num, uint8_t _base );

/**
 * Send a byte in binary form (with zero padding) using the UARTx module.
 * 
 * @param   _v, variable to send using UARTx
 * @param   _nBits, number of bits to send
 * @return  void
 * @Example <code>Uartx_putByte(32, 8); &#09 // Outputs 00100000\n
 * Uartx_putBits(1024, 16); &#09 // Outputs 0000010000000000</code>
 */
void
Uart1_putBits( const uint64_t _v, uint8_t _nBits );

#ifdef UART_USE_PRINTF_YES
/**
 * Print formatted data to UARTx.
 * Writes the C string pointed by format to the UARTx. If format includes format
 * specifiers (subsequences beginning with %), the additional arguments
 * following format are formatted and inserted in the resulting string
 * replacing their respective specifiers.
 * 
 * @param   format C string that contains the text to be written to UARTx.
 * It can optionally contain embedded format specifiers that are replaced by
 * the values specified in subsequent additional arguments and formatted as
 * requested.\n
 * 
 * A format specifier follows this prototype:\n
 *  %[flags][width][.precision][length]specifier\n
 * 
 * specifier    &#09 output                          &#09 &#09 &#09 &#09    example     \n
 * d or i       &#09 Signed decimal integer                    &#09 &#09    392         \n
 * u            &#09 Unsigned decimal integer                  &#09 &#09    7235        \n
 * o            &#09 Unsigned octal                       &#09 &#09 &#09    610         \n
 * x            &#09 Unsigned hexadecimal integer              &#09 &#09    7fa         \n
 * X            &#09 Unsigned hexadecimal integer (uppercase)       &#09    7FA         \n
 * f            &#09 Decimal floating point, lowercase         &#09 &#09    392.65      \n
 * F            &#09 Decimal floating point, uppercase         &#09 &#09    392.65      \n
 * e            &#09 Scientific notation (exponent), lowercase      &#09    3.9265e+2   \n
 * E            &#09 Scientific notation (exponent), uppercase      &#09    3.9265E+2   \n
 * g            &#09 Use the shortest representation: %e or %f      &#09    392.65      \n
 * G            &#09 Use the shortest representation: %E or %F      &#09    392.65      \n
 * a            &#09 Hexadecimal floating point, lowercase          &#09    -0xc.90fep-2\n
 * A            &#09 Hexadecimal floating point, uppercase          &#09    -0XC.90FEP-2\n
 * c            &#09 Character                      &#09 &#09  &#09 &#09    a           \n
 * s            &#09 String of characters                 &#09 &#09 &#09    sample      \n
 * p            &#09 Pointer address                      &#09 &#09 &#09    b8000000    \n
 * n            &#09 Nothing printed. The corresponding argument                        \n
 *              &#09 must be a pointer to a signed int.                                 \n
 *              &#09 The number of characters written so far is                         \n
 *              &#09 stored in the pointed location.                                    \n
 * %            &#09 A % followed by another % character will       &#09    %           \n
 *              &#09 write a single % to the stream.
 * 
 * flags        &#09 description                                                        \n
 * -            &#09 Left-justify within the given field width; Right justification     \n
 *              &#09 is the default (see width sub-specifier).                          \n
 * +            &#09 Forces to preceed the result with a plus or minus sign (+ or -)    \n
 *              &#09 even for positive numbers. By default, only negative numbers       \n
 *              &#09 are preceded with a - sign.                                        \n
 * (space)      &#09 If no sign is going to be written, a blank space is inserted       \n
 *              &#09 before the value.                                                  \n
 * #            &#09 Used with o, x or X specifiers the value is preceeded              \n
 *              &#09 with 0, 0x or 0X respectively for values different than zero.      \n
 *              &#09 Used with a, A, e, E, f, F, g or G it forces the written output    \n
 *              &#09  to contain a decimal point even if no more digits follow.         \n
 *              &#09 By default, if no digits follow, no decimal point is written.      \n
 * 0            &#09 Left-pads the number with zeroes (0) instead of spaces when        \n
 *              &#09 padding is specified (see width sub-specifier).
 * 
 * width        &#09 description                                                        \n
 * (number)     &#09 Minimum number of characters to be printed.                        \n
 *              &#09 If the value to be printed is shorter than this number,            \n
 *              &#09 the result is padded with blank spaces. The value is not           \n
 *              &#09 truncated even if the result is larger.                            \n
 * *            &#09 The width is not specified in the format string, but as            \n
 *              &#09 an additional integer value argument preceding the argument        \n
 *              &#09 that has to be formatted.
 * 
 * .precision	&#09 description                                                        \n
 * .number      &#09 For integer specifiers (d, i, o, u, x, X): precision specifies     \n
 *              &#09 the minimum number of digits to be written. If the value to be     \n
 *              &#09 written is shorter than this number, the result is padded with     \n
 *              &#09 leading zeros. The value is not truncated even if the result       \n
 *              &#09  is longer. A precision of 0 means that no character is written    \n
 *              &#09 for the value 0.                                                   \n
 *              &#09 For a, A, e, E, f and F specifiers: this is the number of digits   \n
 *              &#09 to be printed after the decimal point (by default, this is 6).     \n
 *              &#09 For g and G specifiers: This is the maximum number of significant  \n
 *              &#09 digits to be printed.                                              \n
 *              &#09 For s: this is the maximum number of characters to be printed.     \n
 *              &#09 By default all characters are printed until the ending null        \n
 *              &#09 character is encountered. If the period is specified without an    \n
 *              &#09 explicit value for precision, 0 is assumed.                        \n
 * .*           &#09 The precision is not specified in the format string, but as an     \n
 *              &#09 additional integer value argument preceding the argument that      \n
 *              &#09 has to be formatted.
 * 
 * length       &#09 specifiers [d i]               \n
 *  &#32 (none) &#09 int                            \n
 *  &#32 hh     &#09 signed char                    \n
 *  &#32 h      &#09 short int                      \n
 *  &#32 l      &#09 long int                       \n
 *  &#32 ll     &#09 long long int                  \n
 *  &#32 j      &#09 intmax_t                       \n
 *  &#32 z      &#09 size_t                         \n
 *  &#32 t      &#09 ptrdiff_t                      \n
 * length       &#09 specifiers [u o x X]           \n
 *  &#32(none)  &#09 unsigned int                   \n
 *  &#32 hh     &#09 unsigned char                  \n
 *  &#32 h      &#09 unsigned short int             \n
 *  &#32 l      &#09 unsigned long int              \n
 *  &#32 ll     &#09 unsigned long long int         \n
 *  &#32 j      &#09 uintmax_t                      \n
 *  &#32 z      &#09 size_t                         \n
 *  &#32 t      &#09 ptrdiff_t                      \n
 * length       &#09 specifiers [f F e E g G a A]   \n
 *  &#32 (none) &#09 double                         \n
 *  &#32 L      &#09 long double                    \n
 * 
 * @param   ... (additional arguments) Depending on the format string, the function \n
 * may expect a sequence of additional arguments, each containing a value to be     \n
 * used to replace a format specifier in the format string (or a pointer to a       \n
 * storage location, for n). There should be at least as many of these arguments as \n
 * the number of values specified in the format specifiers. Additional arguments    \n
 * are ignored by the function.
 * @return  uint16_t len Length of the printed string.
 * @Example <code>length = Uartx_printf("Pi is: %f", 3.141592);</code>
 */
uint16_t
Uart1_printf( const char *format, ... );
#endif /* UART_USE_PRINTF_YES */

/**
 * Receive a string using the UARTx module.
 * 
 * @param   str, pointer to the char array to put the received string in.
 * @param   echo, true or false, specifies if the received string is send back.
 * for debugging purposes
 * @return  void
 * @example <code>char* rxStr;\n
 * Uartx_gets(rxStr, 0);</code>
 */
void
Uart1_gets( char* str, bool echo );

#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */
/* End of file Uart.h */