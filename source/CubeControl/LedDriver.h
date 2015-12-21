/*******************************************************************************
 * Begin of file LedDriver.h
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
 * A LED Sink Driver has 16 outputs and sinks sixteen pillars (two rows) of one
 * colour in the LED cube.
 * 
 ******************************************************************************/

#ifndef LEDDRIVER_H
#define LEDDRIVER_H

#ifdef __cplusplus
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
#define SPI1_PPRE               1       /**< SPI1 Primary Prescale bits */
#define SPI1_SPRE               2       /**< SPI1 Secondary Prescale bits */
/** SPI1 clock speed. */
#define SPI1_FSCK               (FCY / (SPI1_PPRE * SPI1_SPRE))

/*******************************************************************************
 * Macros
 ******************************************************************************/
//@fixme does this actually work or need some other method of waiting?
#define SPI1_WAIT_TILL_TX_BUFFER_IS_EMPTY while( SPI1STATbits.SPITBF == 1 )
/** @todo  Change bitorder in the tables below so 0 is the LSB and 15 the MSB.*/
/**
 * Reorder the bits to be in correct order, where 0 is the rightmost (LSB) bit
 * and 15 is the leftmost (MSB) bit. This is needed for @ref LedDriver_update,
 * which needs to reorder the LED data befor sending it to the LED Sink
 * Driver.
 * 
 * | Bit number  |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
 * | ----------- |:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|
 * | **Old var** | 3  | 4  | 2  | 5  | 1  | 6  | 0  | 7  | 11 | 12 | 10 | 13 | 9  | 14 | 8  | 15 |
 * | **New var** | 0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 10 | 11 | 12 | 13 | 14 | 15 |
 * 
 * The following table shows the shift operations needed for specific bits.
 * 
 * | Old bit numbers | new bit numbers | shift action |
 * | :-------------- | :-------------- | :----------: |
 * | 0, 2, 8, 9      | 3, 4, 11, 12    | << 3         |
 * | 2, 10           | 2, 10           |              |
 * | 3, 11           | 5, 13           | << 2         |
 * | 4, 12           | 1, 9            | >> 3         |
 * | 5, 13           | 6, 14           | >> 1         |
 * | 6, 14           | 0, 8            | >> 6         |
 * | 7, 15           | 7, 15           |              |
 * 
 * #### Operations:
 * 7 `AND`, 6 `OR`, 5 `SHIFT`
 */
#define LED_DRIVER_REORDER_LEDDATA(ledData) ( ((ledData) & 0x0303) << 3 | \
                ((ledData) & 0x0404)      | ((ledData) & 0x0808) << 2 | \
                ((ledData) & 0x1010) >> 3 | ((ledData) & 0x2020) << 1 | \
                ((ledData) & 0x4040) >> 6 | ((ledData) & 0x8080) )

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * Initialize a LED Sink Driver by configuring the SPIx peripheral.
 * 
 * @note    This function should be called only once because it sets the SPIx
 * peripheral for all the LED Sink Drivers since they are in a bus.
 */
void
LedDriver_init(void);

/**
 * Update the output of a LED Sink Driver using the SPIx peripheral.
 * 
 * @param   _ledData 16-bit variable to send to a LED Sink Driver.
 */
void
LedDriver_update(const uint16_t _ledData);

/**
 * Turn all the LEDs of a LED Sink Driver off using @ref LedDriver_update.
 */
void
LedDriver_allOff(void);

/**
 * Turn all the LEDs of a LED Sink Driver off using @ref LedDriver_update.
 */
void
LedDriver_allOn(void);

#ifdef LD_ENABLE_SELF_TEST_YES
/** @todo UnitTest: Remove selftest and create a selftest for the leddriver.
 * 
 * Run a self test on a LED Sink Driver. I.e. test a single LED Sink Driver.
 * Loops through all the outputs of the LED Sink Driver by putting on one output
 * at a time using the @ref LedDriver_update function.
 */
void
LedDriver_selfTest(void);
#endif /* LD_ENABLE_SELF_TEST_YES */

#ifdef __cplusplus
}
#endif

#endif /* LEDDRIVER_H */
/* End of file LedDriver.h */
