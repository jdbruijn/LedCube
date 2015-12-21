/*******************************************************************************
 * Begin of file Uart.c
 * Author: jdebruijn
 * Created on August 31, 2015, 9:04 PM
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "Uart.h"

/*******************************************************************************
 * Global variables
 ******************************************************************************/
/** Global UARTx receive software FIFO buffer. */
swFifoBuffer_t rxBuffer = {0, 0, 0, {0}, 0, 0, 0};
/** Global pointer to the UARTx receive software FIFO buffer. */
pSwFifoBuffer_t const pRxBuffer = &rxBuffer;

/*******************************************************************************
 * Functions
 ******************************************************************************/
void
Uart1_init(void)
{
    /********** Configure UARTx Module ****************************************/
    U1MODE = 0; // Reset UARTx module
    /* "Baud Rate = [Fp / (16 x (UxBRG + 1))]
     *  UxBRG = [(Fp / (16 x Baud Rate)) - 1]" (Universal Asynchronous Receiver
     * Transmitter (UART), Equation 3-1: UARTx Baud Rate (BRGH = 0), Microchip)
     */
    U1BRG = UART1_BRG;

    /* 11 = UxTX, UxRX and BCLKx pins are enabled and used; UxCTS pin is
     *      controlled by port latches
     * 10 = UxTX, UxRX, UxCTS and UxRTS pins are enabled and used
     * 01 = UxTX, UxRX and UxRTS pins are enabled and used; UxCTS pin is
     *      controlled by port latches
     * 00 = UxTX and UxRX pins are enabled and used; UxCTS, UxRTS and BCLKx
     *      pins are controlled by port latches
     */
    U1MODEbits.UEN = 0b10;

    /* Note: The calculation of UxBRG depends on this setting!
     * 1 = BRG generates 4 clocks per bit period (4x baud clock, High-Speed
     *     mode)
     * 0 = BRG generates 16 clocks per bit period (16x baud clock, Standard
     *     Speed mode)
     */
    U1MODEbits.BRGH = 1;

    /* 11 = 9-bit data, no parity
     * 10 = 8-bit data, odd parity
     * 01 = 8-bit data, even parity
     * 00 = 8-bit data, no parity
     */
    U1MODEbits.PDSEL = 0b00;
    /* 1 = 2 Stop bits
     * 0 = 1 Stop bit
     */
    U1MODEbits.STSEL = 0;

    /********** Configure interrupts ******************************************/
    IPC2bits.U1RXIP = INT_U1RX_PRIO; // Set UARTx RX interrupt priority
    IFS0bits.U1RXIF = 0; // Clear the UARTx RX interrupt flag
    IEC0bits.U1RXIE = 1; // Enable UARTx RX interrupts
    /* 11 = Interrupt flag bit is set when the receive buffer is full
     *      (i.e., 4 data characters)
     * 10 = Interrupt flag bit is set when the receive buffer is 3/4 full
     *      (i.e., 3 data characters)
     * 0x = Interrupt flag bit is set when a character is received
     */
    U1STAbits.URXISEL = 0b00;

    U1MODEbits.UARTEN = 1; // Enable UARTx module
    U1STAbits.UTXEN = 1; // Enable UARTx transmitter
    DELAY_US(105);

#ifdef DEBUG
    uprintf(" DEBUG: %s(): Initialize complete...\n"
            " DEBUG: %s(): Baud Rate Error (must be below 5%%): %.2f%%\n",
            __FUNCTION__, __FUNCTION__, (UART1_BAUD_ERROR / 100.0));
#endif
    
    return;
}

void
Uart1_putc(const char _c)
{
    while (U1STAbits.UTXBF == 1); // Wait until TXREG can be written
    U1TXREG = _c;

    return;
}

void
Uart1_puts(const char* _s)
{
    while (*_s) {
        uputc(*_s++);
    }

    return;
}

void
Uart1_putNum(int32_t _num, uint8_t _base, bool _printBase)
{
    char const digit[] = "0123456789ABCDEF";
    char str[20] = {0};

    char* p_str = str;
    if (_num < 0) {
        *p_str++ = '-'; // Add minus prefix
        _num *= -1; // Make number positive for further calculations
    }

    /* Calculate how much char positions are needed for the number string. This
     * moves from left to right and puts the NUL terminator at the end of the
     * number string. It also adds a prefix to binary and hexadecimal numbers.
     * At the end the pointer is at the end of the number string (rightmost
     * character) or, in case of binary and hexadecimal numbers, one to the
     * rightmost character.
     */
    uint32_t shifter = _num;
    do {
        ++p_str;
        shifter /= _base;
    } while (shifter);

    if (_printBase && _base == 2) {
        *p_str = 'b';
        *++p_str = '\0';
        p_str--;
    } else if (_printBase && _base == 16) {
        *p_str = 'h';
        *++p_str = '\0';
        p_str--;
    } else {
        *p_str = '\0';
    }

    /* Move back along the number string (from right to left) and insert the
     * digits on the way. In case of the number 123 the 3 will be inserted
     * first, since this is the rightmost digit.
     */
    do {
        *--p_str = digit[_num % _base];
        _num /= _base;
    } while (_num);

    uputs(str);

    return;
}

void
Uart1_putBits(const uint64_t _num, uint8_t _nBits)
{
    uint8_t i;

    // Comparing with 8 instead of 7, due to overflow of unsigned.
    for (i = _nBits; i > 0; i--) {
        /* Output plus 48, since character '0' is in the 48th place of the
         * ASCII table.
         */
        uputc(((_num >> (i - 1)) & 1) + 48);
    }

    return;
}

#if (UART_USE_PRINTF_FLAG) || defined(DEBUG)
uint16_t
Uart1_printf(const char *format, ...)
{
    va_list argptr;
    uint16_t len = 1;
    char _dstr[UART1_MAX_STR_LEN];

    memset(&_dstr, 0x00, sizeof (_dstr));
    va_start(argptr, format);
    len = vsprintf(_dstr, format, argptr);
    va_end(argptr);

    if ((len > 0) && (len < UART1_MAX_STR_LEN)) {
        uputs(_dstr);
        Nop();
        while (U1STAbits.TRMT == 0); /* wait till finish */
    }

    return len;
}
#endif /* UART_USE_PRINTF_FLAG or DEBUG */

void
Uart1_gets(char *_str, uint8_t _num)
{
    uint8_t i = 0;
    while (i < _num) {
        if (pRxBuffer->bufferOverflowFlag == 1) {
            /* Handle overflow error by (at this time) informing about the
             * overflow.
             */
#ifdef DEBUG
            uprintf("\n\n ERROR: %s:%d:%s(): "                                 \
                    "UART1 FIFO software buffer overflow\n\n",
                     __FILE__, __LINE__, __FUNCTION__);
#else /* DEBUG */
            uputs("\n\n ERROR: ");
            uputs(__FILE__);
            uputnum(__LINE__, 10, false);
            uputs(__FUNCTION__);
            uputs("UART1 FIFO software buffer overflow\n\n");
#endif /* DEBUG */

            return;
        } else if (pRxBuffer->bufferNotEmptyFlag) {
            *_str = swFifoBufferGet(pRxBuffer);

            if (*_str == UART_CR || *_str == UART_LF) {
                *_str = '\0'; // Ignore character and end the string
                return; // String is complete, exit loop and return
            }

            _str++; // Move to next position in the string
        }
        i++;
    }

    return;
}

/**
 * @brief Interrupt for received UARTx data. Puts the data in a software FIFO
 * buffer (@ref pRxBuffer).
 * 
 */
void
__attribute__((interrupt, auto_psv))
_U1RXInterrupt(void)
{
    if (!U1STAbits.PERR && !U1STAbits.FERR && !U1STAbits.OERR) {
        swFifoBufferPut(pRxBuffer, U1RXREG);
    } else if (U1STAbits.OERR == 1) {
        U1STAbits.OERR = 0; // Clear the Overrun Error Status bit
#ifdef DEBUG
        uprintf("\n\n ERROR: %s:%d:%s(): UART1 hardware overrun\n\n",
                __FILE__, __LINE__, __FUNCTION__);
#else /* DEBUG */
        uputs("\n\n ERROR: ");
        uputs(__FILE__);
        uputnum(__LINE__, 10, false);
        uputs(__FUNCTION__);
        uputs("UART1 hardware overrun\n\n");
#endif /* DEBUG */
    }

    IFS0bits.U1RXIF = 0; // Clear the UARTx RX interrupt flag
}
/* End of file Uart.c */
