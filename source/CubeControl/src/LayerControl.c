/*******************************************************************************
 * Begin of file LayerControl.c
 * Author: Jeroen de Bruijn
 * Created on 05 August 2015, 21:10
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
 * @brief Controls a single layer of the 8x8x8 LED cube.
 * 
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "LayerControl.h"
#include "Buzzer.h"

/*******************************************************************************
 * Global variables
 ******************************************************************************/
/** Global variable for keeping track of the current active layer in the ISR. */
volatile uint8_t layer = 0;
/** Global variable for keeping track of the current BAM round in the ISR. */
volatile uint8_t bamRound = 0;
/** Pattern to select the current layer. */
uint8_t const layerReg[8] = {
    0b11111101,
    0b11111110,
    0b11110111,
    0b11111011,
    0b11011111,
    0b11101111,
    0b10111111,
    0b01111111
};

/*******************************************************************************
 * Functions
 ******************************************************************************/
void
LayerControl_init(void)
{
    /********** Setup PanelControl ********************************************/
    PanelControl_init();

    /********** Configure SPIx module *****************************************/
    SPI2STAT = 0; // Reset SPIx module
    SPI2CON1 = 0;
    SPI2CON2 = 0;
    Nop();

    IFS2bits.SPI2IF = 0; // Clear the Interrupt flag
    IEC2bits.SPI2IE = 0; // Disable the interrupt

    SPI2CON1bits.MSTEN = 1; // Master mode
    /* PPRE<1:0>: Primary Prescale bits (Master mode)
     * 11 = Primary prescale 1:1
     * 10 = Primary prescale 4:1
     * 01 = Primary prescale 16:1
     * 00 = Primary prescale 64:1
     * @Note Do not set the primary and secondary prescalers to the
     * value of 1:1 at the same time.
     */
    SPI2CON1bits.PPRE = 0b11;
    /* SPRE<2:0>: Secondary Prescale bits (Master mode)
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
    SPI2CON1bits.SPRE = 0b110;
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
        uint8_t rData;
        rData = SPI2BUF; // Clear the SPIx transmit/receive buffer
    }

    SPI2STATbits.SPIEN = 1; // Enable SPIx module
    Nop();

    /********** Configure Timer 3 *********************************************/
    T3CON = 0; // Reset Timer x
    TMR3 = 0; // Clear contents of Timer x register
    Nop();

    /* @todo remove this block of comment
     * Fpb of 16 MHz, TCKPS 8
     * need period of 8000 to get 250 Hz
     *                2000 to get 1 kHz
     *                1600 to get 1.25 kHz
     *                1000 to get 2 kHz
     *                800 to get 2.5 kHz
     * 
     * ////
     * TCKPS 256
     * need period of 62500 to get 1 Hz
     *                31250 to get 2 Hz
     *                6250 to get 10 Hz
     *                3125 to get 20 Hz
     *                2976 to get 21 Hz
     *                2840 to get 22 Hz
     *                2717 to get 23 Hz
     *                2604 to get 24 Hz
     */
    PR3 = 1600; // Interrupt at 1 Hz @todo Final: set final frequency and edit comment
    IPC2bits.T3IP = INT_T3_PRIO; // Set Timer x interrupt priority
    IFS0bits.T3IF = 0; // Clear the Timer x interrupt flag
    IEC0bits.T3IE = 1; // Enable Timer x interrupts

    /* TCKPS<1:0>: Timerx Input Clock Prescale bits
     * 11 = 1:256 prescaler value
     * 10 = 1:64 prescaler value
     * 01 = 1:8 prescaler value
     * 00 = 1:1 prescaler value
     */
    T3CONbits.TCKPS = 0b01;
    T3CONbits.TON = 1; // Enable Timer x

    DEBUG_PRINTF_FUNCTION_INITIALIZE_COMPLETE;
    return;
}

/**
 * Set a single layer active using the SPIx peripheral.
 * 
 * @note    This function is used by the _T3Interrupt ISR.
 * @param   _layer The layer to set active ranging from 0 to @ref LC_MAX_Z_C.
 */
void
LayerControl_setLayer(const uint8_t _layer)
{
    DEBUG_PRINTF_FUNCTION_CALL("%u", _layer);

    SPI2_WAIT_TILL_TX_BUFFER_IS_EMPTY;

    /* Shift 0xFF7F, which is 1111 1111 0111 1111 binary, _layer places to the
     * right so at all times one bit (layer) is 0 (turned on). Only a 8-bit
     * value is needed but since it is shifted to the right an additional 8-bit
     * value of 0xFF is needed for padding the value with ones. Since a logical
     * 1 as output of the shift register results in 0 Volt on the MOSFET output.
     * Finally AND it with 0xFF so it becomes an 8-bit value that can be put in
     * the SPIx buffer.
     */
    //SPI2BUF = (0xFF7F >> _layer) & 0xFF;
    SPI2BUF = layerReg[_layer];

    SPI2_WAIT_TILL_TX_BUFFER_IS_EMPTY;

    return;
}

void
LayerControl_update(const pCubeControlData_t _pCubeControlData,
                    const pCubeData_t _pCubeData,
                    const uint8_t _layer,
                    const uint8_t _bamRound)
{
    DEBUG_PRINTF_FUNCTION_CALL("%p, %p, %u, %u", _pCubeControlData, \
            _pCubeData, _layer, _bamRound);

    /* Update in reverse order (panel 3 first), because the PanelControl PCBs
     * shift the data trough. So the data for the first PanelControl PCB needs
     * to be send last.
     */
    PanelControl_update(_pCubeControlData, _pCubeData, _layer, PANEL_3,
                        _bamRound);
    PanelControl_update(_pCubeControlData, _pCubeData, _layer, PANEL_2,
                        _bamRound);
    PanelControl_update(_pCubeControlData, _pCubeData, _layer, PANEL_1,
                        _bamRound);
    PanelControl_update(_pCubeControlData, _pCubeData, _layer, PANEL_0,
                        _bamRound);

    return;
}

void
LayerControl_allOff(void)
{
    DEBUG_PRINTF_FUNCTION_CALL();

    uint8_t i;
    for (i = 0; i < N_PANELCONTROLS; i++) {
        PanelControl_allOff();
    }

    return;
}

void
LayerControl_allOn(void)
{
    DEBUG_PRINTF_FUNCTION_CALL();

    uint8_t i;
    for (i = 0; i < N_PANELCONTROLS; i++) {
        PanelControl_allOn();
    }

    return;
}

/**
 * Interrupt for timer 3. This interrupt multiplexes the eight layers and puts
 * the correct LED data in the current layer.
 * 
 */
void
__attribute__((interrupt, auto_psv))
_T3Interrupt(void)
{
    LayerControl_setLayer(layer);

    LayerControl_update(pCubeControlData, pCubeControlData->pCubeDataRead,
                        layer, bamRound);

    //    layer = (layer == LC_MAX_Z_C) ? 0 : layer + 1;
    //    bamRound = (bamRound == LC_MAX_BAM_VAL) ? 0 : bamRound + 1;
    if (layer == LC_MAX_Z_C) {
        layer = 0;
        bamRound = (bamRound == LC_MAX_BAM_VAL) ? 0 : bamRound + 1;
    } else {
        layer++;
    }

    PORT_SET_PIN(OE); // Disable the output during the update
    PORT_PULSE_PIN(LD_LE);
    LAYERCONTROL_PULSE_LATCH;
    PORT_CLEAR_PIN(OE); // Enable the output again

    IFS0bits.T3IF = 0; // Clear the Timer x interrupt flag
}
/* End of file LayerControl.c */
