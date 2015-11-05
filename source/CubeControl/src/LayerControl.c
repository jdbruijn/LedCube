/*******************************************************************************
 * Begin of file LayerControl.c
 * Author: Jeroen de Bruijn
 * Created on 05 August 2015, 21:10
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
#include "LayerControl.h"
#include "Uart.h"

/*******************************************************************************
 * Global variables
 ******************************************************************************/
// Used for keeping track of the current layer in the ISR.
volatile uint8_t layer = 0;
volatile uint8_t bamRound = 0;
const uint8_t layerArray[8] = { 1, 2, 4, 8, 16, 32, 64, 128 }; // @todo remove this when it is not needed anymore
/*******************************************************************************
 * Functions
 ******************************************************************************/
/**
 * Initialize everything needed for a PanelControl PCB using the
 * PanelControl_init function and configure the SPIx peripheral.
 * 
 */
void
LayerControl_init( void ) {
    /********** Setup PanelControl ********************************************/
    PanelControl_init();
    
    /********** Configure SPIx module *****************************************/
    SPI2STAT = 0;                   // Reset SPIx module
    SPI2CON1 = 0;
    SPI2CON2 = 0;
    Nop();
    
    IFS2bits.SPI2IF = 0;            // Clear the Interrupt flag
    IEC2bits.SPI2IE = 0;            // Disable the interrupt
    
    SPI2CON1bits.MSTEN = 1;         // Master mode
    /**
     * PPRE<1:0>: Primary Prescale bits (Master mode)
     * 11 = Primary prescale 1:1
     * 10 = Primary prescale 4:1
     * 01 = Primary prescale 16:1
     * 00 = Primary prescale 64:1
     * @Note Do not set the primary and secondary prescalers to the
     * value of 1:1 at the same time.
     */
    SPI2CON1bits.PPRE = 0b11;
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
    SPI2CON1bits.SPRE = 0b110;
    SPI2STATbits.SPIROV = 0;        // Clear the Receive Overflow Flag bit
    /**
     * CKE: SPIx Clock Edge Select bit
     * 1 = Serial output data changes on transition from active clock state to
     *     Idle clock state (see CKP)
     * 0 = Serial output data changes on transition from Idle clock state to
     *     active clock state (see CKP)
     */
    SPI2CON1bits.CKE = 1;
    /**
     * CKP: Clock Polarity Select bit
     * 1 = Idle state for clock is a high level; active state is a low level
     * 0 = Idle state for clock is a low level; active state is a high level
     */
    SPI2CON1bits.CKP = 0;
    
    {
        uint8_t rData;
        rData = SPI2BUF;            // Clear the SPIx transmit/receive buffer
    }
    
    SPI2STATbits.SPIEN = 1;         // Enable SPIx module
    Nop();
    
    /********** Configure Timer 3 *********************************************/
    T3CON = 0;                      // Reset Timer x
    TMR3 = 0;                       // Clear contents of Timer x register
    Nop();
    
    /** @todo remove this block of comment
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
    PR3 = 62500;                    // Interrupt at 1 Hz @todo Final: set final frequency and edit comment
    IPC2bits.T3IP = INT_T3_PRIO;    // Set Timer x interrupt priority
    IFS0bits.T3IF = 0;              // Clear the Timer x interrupt flag
    IEC0bits.T3IE = 1;              // Enable Timer x interrupts
    
    /**
     * TCKPS<1:0>: Timerx Input Clock Prescale bits
     * 11 = 1:256 prescaler value
     * 10 = 1:64 prescaler value
     * 01 = 1:8 prescaler value
     * 00 = 1:1 prescaler value
     */
    T3CONbits.TCKPS = 0b11;
    T3CONbits.TON = 1;              // Enable Timer x
    
    DEBUG_PRINTF_FUNCTION_INITIALIZE_COMPLETE();
    return;
}

/**
 * Set a single layer active using the SPIx peripheral.
 * 
 * @Note    This function is used by the _T3Interrupt ISR.
 * @param   _layer, the layer to set active ranging from 0 to 7.
 * @return  void
 * @Example <code>LayerControl_setLayer(0);</code>
 */
void
LayerControl_setLayer( const uint8_t _layer ) {
    // Wait until a possible previous transmit is finished.
    SPI2_WaitTillTxBufferEmpty();
    
    // Use the data out of the layerArray to select the data for the SPIx buffer.
    // @todo test whether the following line works, since it uses way less memory and resources.
    SPI2BUF = (0x7F >> _layer);
    
    //@todo Remove the block of code below
//    uint8_t layerData = layerArray[_layer];
//    ByteReverseBits(&layerData);
//    SPI2BUF = ~layerData;
    
    SPI2_WaitTillTxBufferEmpty();
    
    return;
}

/**
 * Update the output of the LedCube.
 * 
 * Update in reverse order (BGR instead of RGB) because the LedDriver updates
 * the data in reversed order due to shifting. So the first data need to be
 * send last.
 */
void
LayerControl_update( const pCubeControlData_t _pCubeControlData,
        const pCubeData_t _pCubeData,
        const uint8_t _layer,
        const uint8_t _bamRound ) {
    DEBUG_PRINTF_FUNCTION_CALL("%p, %p, %u, %u", _pCubeControlData, \
            _pCubeData, _layer, _bamRound);
    
    PanelControl_update( _pCubeControlData, &_pCubeData, _layer, PANEL_3,
            _bamRound );
    PanelControl_update( _pCubeControlData, &_pCubeData, _layer, PANEL_2,
            _bamRound );
    PanelControl_update( _pCubeControlData, &_pCubeData, _layer, PANEL_1,
            _bamRound );
    PanelControl_update( _pCubeControlData, &_pCubeData, _layer, PANEL_0,
            _bamRound );
    
    return;
}

/**
 * Use the PanelControl's allOff method to turn all the LedCube's LEDs off.
 * 
 */
void
LayerControl_allOff( void ) {
    uint8_t i;
    for( i=0; i<N_PANELCONTROLS; i++ ) {
        PanelControl_allOff();
    }
    
    return;
}

/**
 * Use the PanelControl's allOn method to turn all the LedCube's LEDs on.
 * 
 */
void
LayerControl_allOn( void ) {
    uint8_t i;
    for( i=0; i<N_PANELCONTROLS; i++ ) {
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
__attribute__((interrupt,auto_psv)) _T3Interrupt(void) {
    LayerControl_setLayer(0);
//    Uart1_printf("called from IR: \nLayer: %u, bamRound: %u\n", layer, bamRound);
    
    DEBUG_PRINTF_FUNCTION("     Reading: %p", pCubeControlData->pCubeDataRead);
    
    LayerControl_update( pCubeControlData, pCubeControlData->pCubeDataRead,
            /* layer */0, /* bamRound */ 0 );
    
    
    // Prepare layer data for the next round
//    layer = (layer == 0b10000000) ? 1 : layer << 1;
    layer = (layer == 7) ? 0 : layer + 1;
    bamRound = (bamRound == 3) ? 0 : bamRound + 1;
    LayerControl_pulseLatch();

    
    IFS0bits.T3IF = 0;              // Clear the Timer x interrupt flag
}
/* End of file LayerControl.c */
