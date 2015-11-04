/*******************************************************************************
 * Begin of file LedDriver.c
 * Author: jdebruijn
 * Created on July 12, 2015, 11:27 AM
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
#include "LedDriver.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
/**
 * Configure the SPIx peripheral.
 * 
 */
void
LedDriver_init( void ) {
    SPI1STAT = 0;               // Reset SPIx module
    SPI1CON1 = 0;
    SPI1CON2 = 0;
    Nop();
    
    IFS0bits.SPI1IF = 0;        // Clear the Interrupt flag
    IEC0bits.SPI1IE = 0;        // Disable the interrupt
    
    SPI1CON1bits.MSTEN = 1;     // Master Mode
    SPI1CON1bits.MODE16 = 1;    // Communication is word-wide (16 bits)
    SPI1CON1bits.SSEN = 0;      // SSx pin is not used by the module
    /**
     * PPRE<1:0>: Primary Prescale bits (Master mode)
     * 11 = Primary prescale 1:1
     * 10 = Primary prescale 4:1
     * 01 = Primary prescale 16:1
     * 00 = Primary prescale 64:1
     * @Note Do not set the primary and secondary prescalers to the
     * value of 1:1 at the same time.
     */
    SPI1CON1bits.PPRE = 0b11;
    /**
     * SPRE<2:0>: Secondary Prescale bits (Master mode)
     * 111 = Secondary prescale 1:1
     * 110 = Secondary prescale 2:1
     * 101 = Secondary prescale 3:1
     * 100 = Secondary prescale 4:1
     * 011 = Secondary prescale 5:1
     * 010 = Secondary prescale 6:1
     * 001 = Secondary prescale 7:1
     * 000 = Secondary prescale 8:1
     * @Note Do not set the primary and secondary prescalers to the
     * value of 1:1 at the same time.
     */
    SPI1CON1bits.SPRE = 0b110;
    // @todo Check if clock edge select is needed (I think it is)
    {
        uint16_t rData;
        rData = SPI1BUF;        // Clear the SPIx transmit/receive buffer
    }
    
    SPI1STATbits.SPIEN = 1;     // Enable SPIx module
    Nop();
    
    DEBUG_PRINTF_FUNCTION_INITIALIZE_COMPLETE();
    return;
}

/**
 * Update the output of the LED Sink Driver using SPIx module. The SPIx module
 * will automatically start transmitting after the data is in it's buffer.
 * @Note    The LED data needs to be reordered before it is send to the SPIx
 * module since the hardware layout of the data is different than a standard
 * ascending order of 01234567.
 * 
 */
void
LedDriver_update( const uint16_t _ledData ) {
    DEBUG_PRINTF_FUNCTION_CALL("0x%.4X", _ledData);
    
    SPI1_WaitTillTxBufferEmpty();
    
    SPI1BUF = _LED_DRIVER_ReorderLedData(_ledData);
    
    SPI1_WaitTillTxBufferEmpty();
    
    return;
}

/**
 * Use the update function to turn all the LEDs of a LED Sink Driver off.
 * 
 */
void
LedDriver_allOff( void ) {
    LedDriver_update(0x0000);
    
    return;
}

/**
 * Use the update function to turn all the LEDs of a LED Sink Driver on.
 * 
 */
void
LedDriver_allOn( void ) {
    LedDriver_update(0xFFFF);
    
    return;
}


#ifdef LD_ENABLE_SELF_TEST_YES
/**
 * Self test using the update function and shifting a 16 bit value to the
 * outputs.
 * 
 */
void
LedDriver_selfTest( void ) {
    uint8_t led;
    uint16_t ledData = 0x0001;
    uint32_t delay;
    
    // Loop to 17 instead of 16 so all the outputs are off in the end.
    for( led=0; led<17; led++ ) {
        LED_DRIVER_LeLow();
        
        LedDriver_update(ledData);
        
        SPI1_WaitTillTxBufferEmpty();
        LED_DRIVER_LeHigh();
        
        for( delay=0;delay<400000;delay++ ) Nop();
        shiftLeft(ledData, 1);  // Prepare the ledData for the next iteration.
    }
    
    SPI1_WaitTillTxBufferEmpty();
    
    return;
}
#endif /* LD_ENABLE_SELF_TEST_YES */

/* End of file LedDriver.c */
