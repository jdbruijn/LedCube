/*******************************************************************************
 * Begin of file LedCube.h
 * Author: jdebruijn
 * Created on June 22, 2015, 8:15 AM
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
 * @brief Controls the whole LedCube.
 * 
 * All 512 RGB LEDs are (indirectly) controlled by this file.
 * 
 ******************************************************************************/

#ifndef LEDCUBE_H
#define	LEDCUBE_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Switches
 ******************************************************************************/
#define LEDCUBE_ENABLE_SELF_TEST_YES

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <xc.h>
#include <stdint.h>
#include <stdlib.h>
#include "Uart.h"
#include "Debug.h"
#include "LayerControl.h"
#include "CubeControlData.h"
#include "MyAssert.h"

/*******************************************************************************
 * Defines
 ******************************************************************************/
/** Minimum value for the x-, y- and z-axis. */
#define LEDCUBE_MIN_XYZ 0

/** Maximum value for the x-, y- and z-axis. */
#define LEDCUBE_MAX_XYZ         (CUBEDATA_MAX_X_C - 1)

#if (CUBEDATA_N_BAM_BITS == 4)
/** Minimum value for the LEDs intensity. */
#   define LEDCUBE_MIN_INTENSITY 0

/** Maximum value for the LEDs intensity. */
#   define LEDCUBE_MAX_INTENSITY 15

#else
#   error Unknown value of CUBEDATA_N_BAM_BITS in CubeControlData.h defined!
#endif

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * Initialize everything needed for controlling the layers using the the
 * @ref LayerControl_init function and initialize the @ref CubeControlData using
 * the @ref CubeControlData_init function.
 * @note    This also initializes everything needed for controlling the layers
 * using @ref LayerControl_init.
 */
void
LedCube_init( void );

/**
 * Set a single pixel in the LedCube's data.
 * 
 * @note    See the following 'image' of how the axis of the LED cube are set.\n
 * 'O' is the origin and represents coordinate (0, 0, 0).\n
 * 'A' is the right back bottom corner of the cube and represents coordinate
 * (7, 0, 0).\n
 * 'B' is the right front bottom corner of the cube and represents coordinate
 * (7, 7, 0).\n
 * 'C' is the left front bottom corner of the cube and represents coordinate
 * (0, 7, 0).\n
 * 'D' is the right front top corner of the cube and represents coordinate
 * (7, 7, 7).\n
 * @verbatim
 *       +------------------+ - x-axis
 *      /'                 /|
 *     / '                / |
 *    /  '               /  |
 *   /   '              /   |
 *  +------------------D    |
 *  |    '             |    |
 *  |    '             |    |
 *  |    '             |    |
 *  |    O ~~~~~~~~~~~ | ~~ A
 *  |   ,              |   /
 *  |  ,               |  /
 *  | ,                | /
 *  |,                 |/
 *  C------------------B
 *  |                 /
 *  z-axis(vertical) y-axis (horizontal)
 * @endverbatim
 * 
 * @param   _x Selects the row. Ranges from 0 to @ref LEDCUBE_MAX_XYZ, 0 for the
 * back row and @ref LEDCUBE_MAX_XYZ for the front row.
 * @param   _y Selects the column. Ranges from 0 to @ref LEDCUBE_MAX_XYZ, 0 for
 * the left column and @ref LEDCUBE_MAX_XYZ for the right column.
 * @param   _z Selects the layer. Ranges from 0 to @ref LEDCUBE_MAX_XYZ, 0 for
 * the bottom layer and @ref LEDCUBE_MAX_XYZ for the top layer.
 * @param   _red Intensity of the red colour. Ranges from 0 to @ref
 * LEDCUBE_MAX_INTENSITY, 0 for the lowest intensity (off) and @ref
 * LEDCUBE_MAX_INTENSITY for the brightest intensity.
 * @param   _green Intensity of the green colour. Ranges from 0 to @ref
 * LEDCUBE_MAX_INTENSITY, 0 for the lowest intensity (off) and @ref
 * LEDCUBE_MAX_INTENSITY for the brightest intensity.
 * @param   _blue Intensity of the blue colour. Ranges from 0 to @ref
 * LEDCUBE_MAX_INTENSITY, 0 for the lowest intensity (off) and @ref
 * LEDCUBE_MAX_INTENSITY for the brightest intensity.
 */
void
LedCube_setPixel( uint8_t const _x, uint8_t const _y, uint8_t const _z,
        uint8_t const _red, uint8_t const _green, uint8_t const _blue );

/**
 * Update the outputs of the LedCube with the data that is currently set in the
 * CubeData structure array using a read-write pointer switch.
 */
void
LedCube_update( void );

/**
 * Update the outputs of the LedCube with the data that is currently set in the
 * CubeData structure array using a copy. This copies the CubeDataWrite
 * structure array to the CubeDataRead structure array so the data previously
 * written thus far in CubeDataWrite structure array becomes the LedCube's
 * output.
 */
void
LedCube_updateUsingCopy( void );

/**
 * Reset all the LedCube's LED data pointed to by @ref
 * CubeControlData_t::pCubeDataWrite using @ref CubeControlData_resetCubeData.
 */
void
LedCube_resetData( void );

/**
 * Print all the LedCube's LED data pointed to by @ref
 * CubeControlData_t::pCubeDataWrite using @ref CubeControlData_printHexCubeData.
 */
void
LedCube_printHexWriteData( void );

/**
 * Print all the LedCube's LED data pointed to by @ref
 * CubeControlData_t::pCubeDataRead using @ref CubeControlData_printHexCubeData.
 */
void
LedCube_printHexReadData( void );

/**
 * @todo edit function documentation below this point.
 * Print the data of one level via UARTx. The data is formatted to be easily
 * understandable from a serial terminal.
 * 
 * @param   _data Pointer to the layer to print, must be of type 
 * pLayerControlData_t.
 * @param   _layer Integer value of the layer to print.
 * @Example See LedCube_printLayerDataVF() documentation for a code example.
 */
//void
//LedCube_printLayerData( const pLayerControlData_t _data,
//        const uint8_t _layer );

/**
 * Print the data of one level via UARTx. The data format is compatible with the
 * Windows program "LedCube Visualisation".
 * 
 * @param   _data Pointer to the layer to print, must be of type 
 * pLayerControlData_t.
 * @param   _layer Integer value of the layer to print.
 * @Example <code>CubeControlData_t CubeData = {\n
 *  &#92* &#09 &#32     |  Panel 1  | &#32 |  panel 2  | &#32 |  panel 3  | &#32 | 
 *  panel 4  | *&#47\n
 *   { &#92* Layer 0 *&#47 {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0} },\n
 *   { &#92* Layer 1 *&#47 {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0} },\n
 *   { &#92* Layer 2 *&#47 {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0} },\n
 *   { &#92* Layer 3 *&#47 {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0} },\n
 *   { &#92* Layer 4 *&#47 {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0} },\n
 *   { &#92* Layer 5 *&#47 {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0} },\n
 *   { &#92* Layer 6 *&#47 {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0} },\n
 *   { &#92* Layer 7 *&#47 {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0} }\n
 * };\n
 * const pCubeControlData_t pCubeData = &CubeData;\n
 * LedCube_printLayerDataVF( &pCubeData->LayerData0, 0);</code>
 */
//void
//LedCube_printLayerDataVF( const pLayerControlData_t _data,
//        const uint8_t _layer );

#ifdef	__cplusplus
}
#endif

#endif	/* LEDCUBE_H */
/* End of file LedCube.h */
