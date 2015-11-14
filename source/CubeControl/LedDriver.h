/*******************************************************************************
 * Begin of file LedDriver.h
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
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 * 
 * Description:
 *  Control a single LED Sink Driver. The LED Sink Drivers has 16 outputs and
 *  sinks sixteen pillars of one colour in the LED cube.
 * 
 ******************************************************************************/

#ifndef LEDDRIVER_H
#define	LEDDRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Switches
 ******************************************************************************/
#define LD_ENABLE_SELF_TEST_NO

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <xc.h>
#include <stdint.h>
#include "System.h"             // For calculating the SPI Clock (FCY)
#include "Debug.h"
#include "Ports.h"
#include "IOPorts.h"

/*******************************************************************************
 * Defines
 ******************************************************************************/
#define SPI1_PPRE               1           /* SPI1 Primary Prescale bits */
#define SPI1_SPRE               2           /* SPI1 Secondary Prescale bits */
#define SPI1_FSCK               FCY / (SPI1_PPRE * SPI1_SPRE)

/*******************************************************************************
 * Macros
 ******************************************************************************/
#define LED_DRIVER_LeLow()      Port_ClearPin(LD_LE)
#define LED_DRIVER_LeHigh()     Port_SetPin(LD_LE)
//@fixme does this actually work or need some other method of waiting?
#define SPI1_WaitTillTxBufferEmpty() while( SPI1STATbits.SPITBF == 1 )
/**
 * Reorder the bits to be in correct order (1 left, 8 right, 9 left, 16 right)
 * 
 * Old: 4  5  3  6  2  7  1  8 12 13 11 14 10 15  9 16  
 *      |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  
 * New: 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16
 *      |      FIRST ROW     |  |    SECOND ROW      |
 * 
 * 1,2,9,10 -> 4,5,12,13    (<< 3)
 * 3,11     -> 3,11
 * 4,12     -> 6,14         (<< 2)
 * 5,13     -> 2,10         (>> 3)
 * 6,14     -> 7,15         (<< 1)
 * 7,15     -> 1,9          (>> 6)
 * 8,16     -> 8,16
 * 
 * Operations:
 *  7 AND, 6 OR, 5 SHIFT
 */
#define _LED_DRIVER_ReorderLedData(ledData) ( ((ledData) & 0x0303) << 3 | \
                ((ledData) & 0x0404)      | ((ledData) & 0x0808) << 2 | \
                ((ledData) & 0x1010) >> 3 | ((ledData) & 0x2020) << 1 | \
                ((ledData) & 0x4040) >> 6 | ((ledData) & 0x8080) )
                
/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * Initialize the LED Sink Driver using the SPIx peripheral.
 * 
 * @Note    This function should be called only once because it sets the SPIx
 * peripheral for all the LED Sink Drivers since they are in a bus.
 * @param   void
 * @return  void
 * @Example <code>LedDriver_init();</code>
 */
void
LedDriver_init( void );

/**
 * Update the output of a LED Sink Driver using the SPIx peripheral.
 * 
 * @Note    The SPIx module puts the data out MSB first.
 * @param   _ledData, 16-bit variable to send to a LED Sink Driver.
 * @return  void
 * @usage   1. Set the LE to low e.g. LED_DRIVER_LeLow;\n
 * 2. Call this update function;\n
 * 3. Wait for the SPI peripheral to be idle before setting the LE to high.
 * @Example <code>LED_DRIVER_LeLow();\n
 * LedDriver_update(0xABCD);\n
 * LED_DRIVER_SPI1WaitWhileBusy();\n
 * LED_DRIVER_LeHigh();</code>
 */
void
LedDriver_update( const uint16_t _ledData );

/**
 * Turn all the LEDs of a LED Sink Driver off.
 * 
 * @param   void
 * @return  void
 * @Example <code>LedDriver_allOff();</code>
 */
void
LedDriver_allOff( void );

/**
 * Turn all the LEDs of a LED Sink Driver off.
 * 
 * @param   void
 * @return  void
 * @Example <code>LedDriver_allOn();</code>
 */
void
LedDriver_allOn( void );    

#ifdef LD_ENABLE_SELF_TEST_YES    
/**
 * Run a self test on the LED Sink Driver. I.e. test a single LED Sink Driver.
 * Loops through all the outputs of the LED Sink Driver by putting on one output
 * at a time.
 * 
 * @param   void
 * @return  void
 * @Example <code>LedDriver_selfTest();</code>
 */
void
LedDriver_selfTest( void );
#endif /* LD_ENABLE_SELF_TEST_YES */

#ifdef	__cplusplus
}
#endif

#endif	/* LEDDRIVER_H */
/* End of file LedDriver.h */
