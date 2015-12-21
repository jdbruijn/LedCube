/*******************************************************************************
 * Begin of file LedDriver.c
 * Author: jdebruijn
 * Created on July 12, 2015, 11:27 AM
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
 * @brief Controls a single LED Sink Driver.
 * 
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "LedDriver.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
void
LedDriver_init(void)
{
    SPI1STAT = 0; // Reset SPIx module
    SPI1CON1 = 0;
    SPI1CON2 = 0;
    Nop();

    IFS0bits.SPI1IF = 0;        // Clear the Interrupt flag
    IEC0bits.SPI1IE = 0;        // Disable the interrupt

    SPI1CON1bits.MSTEN = 1;     // Master Mode
    SPI1CON1bits.MODE16 = 1;    // Communication is word-wide (16 bits)
    SPI1CON1bits.SSEN = 0;      // SSx pin is not used by the module
    /* PPRE<1:0>: Primary Prescale bits (Master mode)
     * 11 = Primary prescale 1:1
     * 10 = Primary prescale 4:1
     * 01 = Primary prescale 16:1
     * 00 = Primary prescale 64:1
     * @note Do not set the primary and secondary prescalers to the
     * value of 1:1 at the same time.
     */
    SPI1CON1bits.PPRE = 0b11;
    /* SPRE<2:0>: Secondary Prescale bits (Master mode)
     * 111 = Secondary prescale 1:1
     * 110 = Secondary prescale 2:1
     * 101 = Secondary prescale 3:1
     * 100 = Secondary prescale 4:1
     * 011 = Secondary prescale 5:1
     * 010 = Secondary prescale 6:1
     * 001 = Secondary prescale 7:1
     * 000 = Secondary prescale 8:1
     * @note Do not set the primary and secondary prescalers to the
     * value of 1:1 at the same time.
     */
    SPI1CON1bits.SPRE = 0b110;
    /* CKE: SPIx Clock Edge Select bit
     * 1 = Serial output data changes on transition from active clock state to
     *     Idle clock state (see CKP)
     * 0 = Serial output data changes on transition from Idle clock state to
     *     active clock state (see CKP)
     */
    SPI2CON1bits.CKE = 1;
    /* CKP: Clock Polarity Select bit
     * 1 = Idle state for clock is a high level; active state is a low level
     * 0 = Idle state for clock is a low level; active state is a high level
     */
    SPI2CON1bits.CKP = 0;

    {
        uint16_t rData;
        rData = SPI1BUF;        // Clear the SPIx transmit/receive buffer
    }

    SPI1STATbits.SPIEN = 1;     // Enable SPIx module
    Nop();

    DEBUG_PRINTF_FUNCTION_INITIALIZE_COMPLETE;
    return;
}

void
LedDriver_update(const uint16_t _ledData)
{
    DEBUG_PRINTF_FUNCTION_CALL("0x%.4X", _ledData);

    SPI1_WAIT_TILL_TX_BUFFER_IS_EMPTY;

    SPI1BUF = LED_DRIVER_REORDER_LEDDATA(_ledData);

    SPI1_WAIT_TILL_TX_BUFFER_IS_EMPTY;

    return;
}

void
LedDriver_allOff(void)
{
    DEBUG_PRINTF_FUNCTION_CALL();

    LedDriver_update(0x0000);

    return;
}

void
LedDriver_allOn(void)
{
    DEBUG_PRINTF_FUNCTION_CALL();

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
LedDriver_selfTest(void)
{
    DEBUG_PRINTF_FUNCTION_CALL();

    uint8_t led;
    uint16_t ledData = 0x0001;
    uint32_t delay;

    // Loop to 17 instead of 16 so all the outputs are off in the end.
    for (led = 0; led < 17; led++) {
        LED_DRIVER_LeLow();

        LedDriver_update(ledData);

        SPI1_WaitTillTxBufferEmpty();
        LED_DRIVER_LeHigh();

        for (delay = 0; delay < 400000; delay++) Nop();
        shiftLeft(ledData, 1); // Prepare the ledData for the next iteration.
    }

    SPI1_WaitTillTxBufferEmpty();

    return;
}
#endif /* LD_ENABLE_SELF_TEST_YES */
/* End of file LedDriver.c */
