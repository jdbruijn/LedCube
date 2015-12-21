/*******************************************************************************
 * Begin of file LayerControl.h
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

#ifndef LAYERCONTROL_H
#define LAYERCONTROL_H

#ifdef __cplusplus
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
/** @brief Number of PanelControl PCBs in the LedCube. */
#define N_PANELCONTROLS     4
/** @brief SPI2 Primary Prescale bits. */
#define SPI2_PPRE           1
/** SPI2 Secondary Prescale bits. */
#define SPI2_SPRE           2
/** SPI2 clock speed. */
#define SPI2_FSCK           (FCY / (SPI2_PPRE * SPI2_SPRE))
/** Maximum z-coordinate for the LedCube. */
#define LC_MAX_Z_C          (CUBEDATA_MAX_X_C - 1)
/** Maximum BAM value for the LedCube. */
#define LC_MAX_BAM_VAL      (CUBEDATA_N_BAM_BITS - 1)

/*******************************************************************************
 * Macros
 ******************************************************************************/
#define LAYERCONTROL_PULSE_LATCH                                               \
    PORT_PULSE_PIN(ANODE_LATCH)
#define SPI2_WAIT_TILL_TX_BUFFER_IS_EMPTY                                      \
    while( SPI2STATbits.SPITBF == 1 )

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
LayerControl_init(void);

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
LayerControl_update(const pCubeControlData_t _pCubeControlData,
                    const pCubeData_t _pCubeData,
                    const uint8_t _layer,
                    const uint8_t _bamRound);

/**
 * Turn all the LEDs of a layer off using @ref PanelControl_allOff.
 */
void
LayerControl_allOff(void);

/**
 * Turn all the LEDs of a layer on using @ref PanelControl_allOn.
 */
void
LayerControl_allOn(void);

#ifdef __cplusplus
}
#endif

#endif /* LAYERCONTROL_H */
/* End of file LayerControl.h */
