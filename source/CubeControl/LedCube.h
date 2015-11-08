/*******************************************************************************
 * Begin of file LedCube.h
 * Author: jdebruijn
 * Created on June 22, 2015, 8:15 AM
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
 *  Control the whole LedCube, so all 512 RGB LEDs are (indirectly) controlled.
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
#define LEDCUBE_MIN_XYZ         0
#define LEDCUBE_MAX_XYZ         (CUBEDATA_MAX_X_C - 1)
#if (CUBEDATA_N_BAM_BITS == 4)
#   define LEDCUBE_MIN_INTENSITY   0
#   define LEDCUBE_MAX_INTENSITY   15
#else
#   error Unknown value of CUBEDATA_N_BAM_BITS in CubeControlData.h defined!
#endif

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * Initialize everything needed for controlling the LED cube.
 * 
 * @Note    This also initializes everything needed for controlling the layers
 * and a PanelControl PCB.
 * @param   void
 * @return  void
 * @Example <code>LedCube_init();</code>
 */
void
LedCube_init( void );

/**
 * Set a single pixel in the LedCube's data.
 * 
 * @Note    See the following 'image' of how the axis of the LED cube are set.
 * The 'O' is the origin and represents coordinate (0, 0, 0).
 * 'A' is the right back bottom corner of the cube and represents coordinate
 * (7, 0, 0).
 * 'B' is the right front bottom corner of the cube and represents coordinate
 * (7, 7, 0).
 * 'C' is the left front bottom corner of the cube and represents coordinate
 * (0, 7, 0).
 * 'D' is the right front top corner of the cube and represents coordinate
 * (7, 7, 7).
 * 
 * Image great here but rubbish in the function documentation view:\n
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
 * 
 * Image rubbish here but great in the function documentation view.           \n
 *  &#32 &#32 &#32+------------------+ - x-axis                               \n
 *  &#32 &#32 /' &#32 &#32 &#32 &#32 &#32 &#32 &#32 &#32 /|                   \n
 *  &#32&#32 / ' &#32&#32&#32&#32&#32&#32&#32&#32&#32&#32&#32&#32&#32&#32 / | \n
 *  &#32 / &#32' &#32 &#32 &#32 &#32 &#32 &#32 &#32 / &#32|                   \n
 *  &#32/ &#32 ' &#32 &#32 &#32 &#32 &#32 &#32 &#32/ &#32 |                   \n
 *  +------------------D &#32 &#32|                                           \n
 *  | &#32 &#32' &#32 &#32 &#32 &#32 &#32 &#32 | &#32 &#32|                   \n
 *  | &#32 &#32' &#32 &#32 &#32 &#32 &#32 &#32 | &#32 &#32|                   \n
 *  | &#32 &#32' &#32 &#32 &#32 &#32 &#32 &#32 | &#32 &#32|                   \n
 *  | &#32 &#32O ~~~~~~~~~~~ | ~~ A                                           \n
 *  | &#32 , &#32 &#32 &#32 &#32 &#32 &#32 &#32| &#32 /                       \n
 *  | &#32, &#32 &#32 &#32 &#32 &#32 &#32 &#32 | &#32/                        \n
 *  | , &#32 &#32 &#32 &#32 &#32 &#32 &#32 &#32| /                            \n
 *  |, &#32 &#32 &#32 &#32 &#32 &#32 &#32 &#32 |/                             \n
 *  C------------------B                                                      \n
 *  | &#32 &#32 &#32 &#32 &#32 &#32 &#32 &#32 /                               \n
 *  z-axis(vertical) y-axis (horizontal)
 * 
 * @param   _x, selects the row. Ranges from 0 to LEDCUBE_MAX_XYZ, 0 for the
 * back row and LEDCUBE_MAX_XYZ for the front row.
 * @param   _y, selects the column. Ranges from 0 to LEDCUBE_MAX_XYZ, 0 for the
 * left column and LEDCUBE_MAX_XYZ for the right column.
 * @param   _z, selects the layer. Ranges from 0 to LEDCUBE_MAX_XYZ, 0 for the
 * bottom layer and LEDCUBE_MAX_XYZ for the top layer.
 * @param   _red, intensity of the red colour. Ranges from 0 to 
 * LEDCUBE_MAX_INTENSITY, 0 for the lowest intensity (off) and
 * LEDCUBE_MAX_INTENSITY for the brightest intensity.
 * @param   _green, intensity of the green colour. Ranges from 0 to 
 * LEDCUBE_MAX_INTENSITY, 0 for the lowest intensity (off) and
 * LEDCUBE_MAX_INTENSITY for the brightest intensity.
 * @param   _blue, intensity of the blue colour. Ranges from 0 to 
 * LEDCUBE_MAX_INTENSITY, 0 for the lowest intensity (off) and
 * LEDCUBE_MAX_INTENSITY for the brightest intensity.
 * @return  void
 * @Example <code>LedCube_setPixel(0, 0, 0, 255, 0, 0); // Set the origin (most
 * back, left and lowest LED to 100% red.</code>
 */
void
LedCube_setPixel( uint8_t const _x, uint8_t const _y, uint8_t const _z,
        uint8_t const _red, uint8_t const _green, uint8_t const _blue );

/**
 * Update the outputs of the LedCube with the data that is currently set in the
 * CubeData structure array using a read-write pointer switch.
 * 
 * @param   void
 * @return  void
 * @Example <code>LedCube_update();</code>
 */
void
LedCube_update( void );

/**
 * Update the outputs of the LedCube with the data that is currently set in the
 * CubeData structure array using a copy.
 * 
 * @param   void
 * @return  void
 * @Example <code>LedCube_updateUsingCopy();</code>
 */
void
LedCube_updateUsingCopy( void );

/**
 * Reset all the LedCube's LED data.
 * 
 * @param   void
 * @return  void
 * @Example <code>LedCube_resetData();</code>
 */
void
LedCube_resetData( void );

/**
 * Print all the LedCube's write LED data.
 * 
 * @param   void
 * @return  void
 * @Example <code>LedCube_printHexWriteData();</code>
 */
void
LedCube_printHexWriteData( void );

/**
 * Print all the LedCube's read LED data.
 * 
 * @param   void
 * @return  void
 * @Example <code>LedCube_printHexReadData();</code>
 */
void
LedCube_printHexReadData( void );

/**
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
