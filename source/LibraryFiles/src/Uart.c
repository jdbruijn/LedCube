/*******************************************************************************
 * Begin of file Uart.c
 * Author: jdebruijn
 * Created on August 31, 2015, 9:04 PM
 * 
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 * 
 * Copyright (c) 2015 Jeroen de Bruijn <vidavidorra@gmail.com>
 * 
 * This file is part of LedCube which is released under The MIT License (MIT).
 * For full license details see file "main.c" or "LICENSE.md" or go to
 * https://opensource.org/licenses/MIT
 * 
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "Uart.h"

/*******************************************************************************
 * Global variables
 ******************************************************************************/
// Declare a UARTx receive software FIFO buffer
swFifoBuffer_t rxBuffer = { 0,0,0, {0}, 0, 0, 0 };
pSwFifoBuffer_t pRxBuffer = &rxBuffer;

/*******************************************************************************
 * Functions
 ******************************************************************************/
/**
 * Use FCY to calculate the BRG value and put the desired settings in the UART1
 * registers.
 * 
 */
void
Uart1_init( void ) {
    /********** Configure UARTx Module ****************************************/
    U1MODE = 0;                         // Reset UARTx module
    /**
     * "Baud Rate = [Fp / (16 x (UxBRG + 1))]
     *  UxBRG = [(Fp / (16 x Baud Rate)) - 1]" (Universal Asynchronous Receiver
     * Transmitter (UART), Equation 3-1: UARTx Baud Rate (BRGH = 0), Microchip)
     */
    U1BRG = UART1_BRG;
    
    /**
     * 11 = UxTX, UxRX and BCLKx pins are enabled and used; UxCTS pin is
     *      controlled by port latches
     * 10 = UxTX, UxRX, UxCTS and UxRTS pins are enabled and used
     * 01 = UxTX, UxRX and UxRTS pins are enabled and used; UxCTS pin is
     *      controlled by port latches
     * 00 = UxTX and UxRX pins are enabled and used; UxCTS, UxRTS and BCLKx
     *      pins are controlled by port latches
     */
    U1MODEbits.UEN = 0b10;
    
    /**
     * Note: The calculation of UxBRG depends on this setting!
     * 1 = BRG generates 4 clocks per bit period (4x baud clock, High-Speed
     *     mode)
     * 0 = BRG generates 16 clocks per bit period (16x baud clock, Standard
     *     Speed mode)
     */
    U1MODEbits.BRGH = 1;
    
    /**
     * 11 = 9-bit data, no parity
     * 10 = 8-bit data, odd parity
     * 01 = 8-bit data, even parity
     * 00 = 8-bit data, no parity
     */
    U1MODEbits.PDSEL = 0b00;
    /**
     * 1 = 2 Stop bits
     * 0 = 1 Stop bit
     */
    U1MODEbits.STSEL = 0;
    
    /********** Configure interrupts ******************************************/
    IPC2bits.U1RXIP = INT_U1RX_PRIO;    // Set UARTx RX interrupt priority
    IFS0bits.U1RXIF = 0;                // Clear the UARTx RX interrupt flag
    IEC0bits.U1RXIE = 1;                // Enable UARTx RX interrupts
    /**
     * 11 = Interrupt flag bit is set when the receive buffer is full
     *      (i.e., 4 data characters)
     * 10 = Interrupt flag bit is set when the receive buffer is 3/4 full
     *      (i.e., 3 data characters)
     * 0x = Interrupt flag bit is set when a character is received
     */
    U1STAbits.URXISEL = 0b00;
    
    U1MODEbits.UARTEN = 1;              // Enable UARTx module
    U1STAbits.UTXEN = 1;                // Enable UARTx transmitter
    Delay_us(105);
    
#ifdef DEBUG
    Uart1_printf(" DEBUG: %s(): Initialize complete...\n" 
            " DEBUG: %s(): Baud Rate Error (must be below 5%%): %.2f%%\n",
            __FUNCTION__, __FUNCTION__, (UART1_BAUD_ERROR / 100.0) );
#endif
    
    return;
}

/**
 * Check if the buffer can be written and than write a single character to the
 * UARTx TX buffer.
 * 
 */
void
Uart1_putc( const char _c ) {
    while( U1STAbits.UTXBF == 1 );      // Wait until TXREG can be written
    U1TXREG = _c;
    
    return;
}

/**
 * Use the Uartx_putc function to send a string.
 * 
 */
void
Uart1_puts( const char* _s ) {
    while( *_s ) {
        Uart1_putc(*_s++);
    }
    
    return;
}

/**
 * Use Uartx_puts function to send a number.
 * 
 */
void
Uart1_putNum( int32_t _num, uint8_t _base ) {
    char const digit[] = "0123456789ABCDEF";
    char str[20] = {0};
    
    char* p_str = str;
    if( _num < 0 ) {
        *p_str++ = '-';         // Add minus prefix
        _num *= -1;             // Make number positive for further calculations
    }
    
    /**
     * Calculate how much char positions are needed for the number string. This
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
    } while( shifter );
    
    if( _base == 2 ) {
        *p_str = 'b';
        *++p_str = '\0';
        p_str--;
    }
    else if( _base == 16 ) {
        *p_str = 'h';
        *++p_str = '\0';
        p_str--; 
    }
    else {
        *p_str = '\0';
    }
    
    /**
     * Move back along the number string (from right to left) and insert the
     * digits on the way. In case of the number 123 the 3 will be inserted
     * first, since this is the rightmost digit.
     */
    do {
        *--p_str = digit[_num % _base];
        _num /= _base;
    } while( _num );
    
    Uart1_puts(str);
    
    return;
}

/**
 * Use Uartx_putc function to send a number.
 * 
 */
void
Uart1_putBits( const uint64_t _v, uint8_t _nBits ) {
    uint8_t i;
    
    // Comparing with 8 instead of 7, due to overflow of unsigned.
    for( i = _nBits; i > 0; i-- ) {
        /**
         * Output plus 48, since character '0' is in the 48th place of the
         * ASCII table.
         */
        Uart1_putc( ( (_v >>(i-1)) & 1) + 48 );
    }
    
    return;
}

#if defined(UART_USE_PRINTF_YES) || defined(DEBUG)
/**
 * Use the same method as printf to create a formatted string. The formatted
 * string is then printed using Uartx_puts().
 * 
 */
uint16_t
Uart1_printf( const char *format, ... ) {
    va_list argptr;
    uint16_t len = 1;
    char _dstr[UART1_MAX_STR_LEN];

    memset(&_dstr, 0x00, sizeof(_dstr));
    va_start(argptr, format);
    len = vsprintf(_dstr, format, argptr);
    va_end(argptr);

    if( (len > 0) && (len < UART1_MAX_STR_LEN ) )
    {
        Uart1_puts( _dstr );
        Nop();
        while( U1STAbits.TRMT == 0 );    /* wait till finish */
    }
    
    return len;
}
#endif /* UART_USE_PRINTF_YES or DEBUG */

/**
 * Use the software FIFO buffer to receive data.
 * 
 */
void
Uart1_gets( char* str, bool echo ) {
    while(1) {
        // @todo While fifo not empty?
        *str = swFifoBufferGet( pRxBuffer );
        // @todo Check sw fifo overflow flag
        
        // If string is empty or linefeed character is received
        if( !*str || *str == UART_LF ) {
            continue;
        }
        else if( *str == UART_CR ) {
            *str = '\0';                // Ignore character and end the string
            return;                     // String is complete, exit loop and return
        }

        if( echo == 1 ) {
            Uart1_putc(*str);
        }
        
        str++;                          // Move to next position in the string
    }
    return;
}

/**
 * Interrupt for received UARTx data. Puts the data in a software FIFO buffer.
 * 
 */
void
__attribute__((interrupt,auto_psv)) _U1RXInterrupt(void) {
        if( !U1STAbits.PERR && !U1STAbits.FERR && !U1STAbits.OERR ) {
            swFifoBufferPut(pRxBuffer, U1RXREG);
        }
        else if( U1STAbits.OERR == 1 ) {
            U1STAbits.OERR = 0;         // Clear the Overrun Error Status bit
            // @todo @check Is this needed and wanted?
            Uart1_puts("An Overrun Error has been detected.");
        }

    IFS0bits.U1RXIF = 0;                // Clear the UARTx RX interrupt flag
}
/* End of file Uart.c */
