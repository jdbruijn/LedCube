/*******************************************************************************
 * Begin of file LayerControl.h
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
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Controls a single layer of the 8x8x8 LED cube. 
 * 
 ******************************************************************************/

// <editor-fold defaultstate="collapsed" desc="Cube Layout">
/** @todo this layout looks weird in Doxygen
 * Cube Layout:
 * 
 *                   Rear
 * Panel 1  01 02 03 04 05 06 07 08
 * Panel 2  09 10 11 12 13 14 15 16
 * Panel 3  17 18 19 20 21 22 23 24
 * Panel 4  25 26 27 28 29 30 31 32
 * Panel 5  33 34 35 36 37 38 39 40
 * Panel 6  41 42 43 44 45 46 47 48
 * Panel 7  49 50 51 52 53 54 55 56
 * Panel 8  57 58 59 60 61 62 63 64
 *                   Front
 * 
 * The 8x8x8 LedCube takes eight of these layers, where the bottom layer is
 * labeled layer 1 and the top layer layer 8.
 */
// </editor-fold>

#ifndef LAYERCONTROL_H
#define	LAYERCONTROL_H

#ifdef	__cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Switches
 ******************************************************************************/
#define LC_ENABLE_SELF_TEST_NO

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <xc.h>
#include <stdint.h>
#include "System.h"             // For calculating the SPI Clock (FCY)
#include "Debug.h"
#include "PanelControl.h"
#include "Interrupts.h"
#include "CubeControlData.h"
    
/*******************************************************************************
 * Defines
 ******************************************************************************/
    /** @todo document defines and macros */
#define N_PANELCONTROLS     4       /* Number of PanelControls in the cube */
#define SPI2_PPRE           1       /* SPI2 Primary Prescale bits */
#define SPI2_SPRE           2       /* SPI2 Secondary Prescale bits */
#define SPI2_FSCK           FCY / (SPI2_PPRE * SPI2_SPRE)
#define LC_MAX_Z_C          (CUBEDATA_MAX_X_C - 1)
#define LC_MAX_BAM_VAL      (CUBEDATA_N_BAM_BITS - 1)

/*******************************************************************************
 * Macros
 ******************************************************************************/
#define LayerControl_pulseLatch() Port_PulsePin(ANODE_LATCH)
#define SPI2_WaitTillTxBufferEmpty() while( SPI2STATbits.SPITBF == 1 )

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * Initialize everything needed for controlling the layers by configuring the
 * SPIx peripheral.
 * 
 * @note    This also initializes everything needed for a PanelControl PCB using
 * the @ref PanelControl_init function.
 */
void
LayerControl_init( void );

/**
 * Update the output of a single layer in the LED cube by calling the @ref
 * PanelControl_update function four times.
 * 
 * @param   _pCubeControlData Pointer to CubeControlData structure.
 * @param   _pCubeData Pointer to the first element of a CubeData structure
 * array.
 * @param   _layer The layer to update.
 * @param   _bamRound The BAM-round to update.
 */
void
LayerControl_update( const pCubeControlData_t _pCubeControlData,
        const pCubeData_t _pCubeData,
        const uint8_t _layer,
        const uint8_t _bamRound );

/**
 * Turn all the LEDs of a layer off using @ref PanelControl_allOff.
 */
void
LayerControl_allOff( void );

/**
 * Turn all the LEDs of a layer on using @ref PanelControl_allOn.
 */
void
LayerControl_allOn( void );

#ifdef	__cplusplus
}
#endif

#endif	/* LAYERCONTROL_H */
/* End of file LayerControl.h */
