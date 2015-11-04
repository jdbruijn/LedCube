/*******************************************************************************
 * Begin of file PanelControl.h
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
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 * 
 * Description:
 *  Control a single PanelControl PCB. A PanelControl PCB holds three LED Sink
 *  Drivers.
 * 
 ******************************************************************************/

#ifndef PANELCONTROL_H
#define	PANELCONTROL_H

#ifdef	__cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Switches
 ******************************************************************************/
#define PC_ENABLE_SELF_TEST_NO

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <xc.h>
#include "Debug.h"
#include "LedDriver.h"
#include "CubeData.h"
#ifdef PC_ENABLE_SELF_TEST_YES
// System.h must be included before libpic32.h because of usage of FCY
#include "System.h"
#include <libpic30.h>           // for __delay_ms()
#endif /* PC_ENABLE_SELF_TEST_YES */

/*******************************************************************************
 * Defines
 ******************************************************************************/
#define N_LEDDRIVERS    3       // Number of LedDrivers on a PanelControl

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * Initialize everything needed for a PanelControl PCB.
 * 
 * @Note    This initializes the LED Sink Drivers.
 * @param   void
 * @return  void
 * @Example <code>PanelControl_init();</code>
 */
void
PanelControl_init( void );

/**
 * Update the outputs of a PanelControl PCB.
 * 
 * @param   _pCubeControlData, pointer to CubeControlData structure.
 * @param   _pCubeData[], pointer to the first element of a CubeData structure
 * array.
 * @param   _layer, the layer to update.
 * @param   _panel, the panel to update.
 * @param   _bamRound, the BAM-round to update.
 * @return  void
 * @Example <code>// See CubeControlData.h or CubeControlData.c for more
 * information on how to setup the CubeControlData structure.\n
 * PanelControl_update( pCubeControlData, &pCubeData, layer, PANEL_0,
 * bamRound );</code>
 */
void
PanelControl_update( const pCubeControlData_t _pCubeControlData,
        const pCubeData_t _pCubeData[],
        const uint8_t _layer,
        const Panels_t _panel,
        const uint8_t _bamRound );

/**
 * Turn all the LEDs of a PanelControl PCB off.
 * 
 * @param   void
 * @return  void
 * @Example <code>PanelControl_allOff();</code>
 */
void
PanelControl_allOff( void );

/**
 * Turn all the LEDs of a PanelControl PCB on.
 * 
 * @param   void
 * @return  void
 * @Example <code>PanelControl_allOn();</code>
 */
void
PanelControl_allOn( void );

#ifdef PC_ENABLE_SELF_TEST_YES
/**
 * Run a self test on a PanelControl PCB. I.e. test a PanelControl PCB.
 * Loops through all the outputs of a PanelControl PCB by putting on one output
 * at a time.
 * 
 * @param   void
 * @return  void
 * @Example <code>PanelControl_selfTest();</code>
 */
void
PanelControl_selfTest( void );
#endif /* PC_ENABLE_SELF_TEST_YES */

#ifdef	__cplusplus
}
#endif

#endif	/* PANELCONTROL_H */
/* End of file PanelControl.h */
