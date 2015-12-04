/*******************************************************************************
 * Begin of file PanelControl.c
 * Author: jdebruijn
 * Created on July 12, 2015, 11:50 AM
 * 
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 * 
 * Copyright (c) 2015 Jeroen de Bruijn <vidavidorra@gmail.com>
 * 
 * This file is part of LedCube which is released under The MIT License (MIT).
 * For full license details see file "main.c" or "LICENSE.md" or go to
 * https://opensource.org/licenses/MIT
 * 
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Controls a single PanelControl PCB.
 * 
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "PanelControl.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
void
PanelControl_init( void ) {
    LedDriver_init();
    
    DEBUG_PRINTF_FUNCTION_INITIALIZE_COMPLETE();
    return;
}

void
PanelControl_update( const pCubeControlData_t _pCubeControlData,
        const pCubeData_t _pCubeData,
        const uint8_t _layer,
        const Panels_t _panel,
        const uint8_t _bamRound ) {
    DEBUG_PRINTF_FUNCTION_CALL("%p, %p, %u, %d, %u", _pCubeControlData, \
            _pCubeData, _layer, _panel, _bamRound);
    
    LED_DRIVER_LeLow();
    
    /* Update in reverse order (BRG instead of RGB), because the Led Sink
     * Drivers shift the data through. So the data for the first Led Sink Driver 
     * needs to be send last.
     */
    LedDriver_update(
            ( ( ((_pCubeData + _layer * CUBEDATA_MAX_Z_C + _panel + 1)->blue &
            _pCubeControlData->BamRoundMask[_bamRound]) >>
            _pCubeControlData->BamRoundShift[_bamRound] ) << 8 ) |
            ( ((_pCubeData + _layer * CUBEDATA_MAX_Z_C + _panel)->blue &
            _pCubeControlData->BamRoundMask[_bamRound]) >>
            _pCubeControlData->BamRoundShift[_bamRound] ) );
    LedDriver_update(
            ( ( ((_pCubeData + _layer * CUBEDATA_MAX_Z_C + _panel + 1)->green &
            _pCubeControlData->BamRoundMask[_bamRound]) >>
            _pCubeControlData->BamRoundShift[_bamRound] ) << 8 ) |
            ( ((_pCubeData + _layer * CUBEDATA_MAX_Z_C + _panel)->green &
            _pCubeControlData->BamRoundMask[_bamRound]) >>
            _pCubeControlData->BamRoundShift[_bamRound] ) );
    LedDriver_update(
            ( ( ((_pCubeData + _layer * CUBEDATA_MAX_Z_C + _panel + 1)->red &
            _pCubeControlData->BamRoundMask[_bamRound]) >>
            _pCubeControlData->BamRoundShift[_bamRound] ) << 8 ) |
            ( ((_pCubeData + _layer * CUBEDATA_MAX_Z_C + _panel)->red &
            _pCubeControlData->BamRoundMask[_bamRound]) >>
            _pCubeControlData->BamRoundShift[_bamRound] ) );
    
    SPI1_WaitTillTxBufferEmpty();
    LED_DRIVER_LeHigh();
    
    return;
}

void
PanelControl_allOff( void ) {
    DEBUG_PRINTF_FUNCTION_CALL();
    
    uint8_t i;
    for( i=0; i<N_LEDDRIVERS; i++ ) {
        LedDriver_allOff();
    }
    
    return;
}

void
PanelControl_allOn( void ) {
    DEBUG_PRINTF_FUNCTION_CALL();
    
    uint8_t i;
    for( i=0; i<N_LEDDRIVERS; i++ ) {
        LedDriver_allOn();
    }
    
    return;
}

#ifdef PC_ENABLE_SELF_TEST_YES
/**
 * Self test using the update function by shifting a 64-bit value and extracting
 * the RGB values from it.
 * 
 * @param void
 * @return void
 */
void
PanelControl_selfTest( void ) {
    DEBUG_PRINTF_FUNCTION_CALL();
    
    PanelControlData_t data = {0,0,0,0,0,0};
    pPanelControlData_t pPanelData = &data;
    
    uint64_t panelData = 1;
    uint8_t led;
    
    // Loop to 49 instead of 48 so all the outputs are '0' in the end.
    for( led=0; led<49; led++ ) {
        pPanelData->red_1   = (uint8_t) (panelData & 0x00000000000000FF);
        pPanelData->red_2   = (uint8_t)((panelData & 0x000000000000FF00) >> 8);
        pPanelData->green_1 = (uint8_t)((panelData & 0x0000000000FF0000) >> 16);
        pPanelData->green_2 = (uint8_t)((panelData & 0x00000000FF000000) >> 24);
        pPanelData->blue_1  = (uint8_t)((panelData & 0x000000FF00000000) >> 32);
        pPanelData->blue_2  = (uint8_t)((panelData & 0x0000FF0000000000) >> 40);
        
        PanelControl_update(pPanelData);
        
        Delay_ms(1000);
        if( 0 == (led +1) % 8 ) {
            Delay_ms(2000);
        }
        panelData <<= 1;    // Prepare the panelData for the next iteration.
    }
    
    SPI1_WaitTillTxBufferEmpty();
    
    return;
}
#endif /* PC_ENABLE_SELF_TEST_YES */

/* End of file PanelControl.c */
