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
#include <assert.h>
#include "Uart.h"
#include "Debug.h"
#include "LayerControl.h"
#include "CubeData.h"

/*******************************************************************************
 * Defines
 ******************************************************************************/
#define LEDCUBE_MIN_XYZ         0
#define LEDCUBE_MAX_XYZ         7
#define LEDCUBE_MIN_INTENSITY   0
#define LEDCUBE_MAX_INTENSITY   15

/*******************************************************************************
 * Structures
 ******************************************************************************/
//typedef struct {
//    LayerControlData_t LayerData0;
//    LayerControlData_t LayerData1;
//    LayerControlData_t LayerData2;
//    LayerControlData_t LayerData3;
//    LayerControlData_t LayerData4;
//    LayerControlData_t LayerData5;
//    LayerControlData_t LayerData6;
//    LayerControlData_t LayerData7;
//    uint32_t CubeData[8][8][3];
//}CubeControlData_t, *pCubeControlData_t;

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
 * @todo Add an image or diagram of how the LedCube's axis are set.
 * 
 * @param   _pCubeData[], pointer to the first element of a CubeData structure
 * array.
 * @param   _x Ranges from 0 to 7 and selects the row, 0 for the back row and
 * 8 for the front row.
 * @param   _y Ranges from 0 to 7 and selects the column, 0 for the left column
 * and 7 for the right column.
 * @param   _z Ranges from 0 to 7 and selects the layer, 0 for the bottom layer
 * and 7 for the top layer.
 * @param   _red Ranges from 0 (off) to 255 (full on) and selects the intensity
 * of the selected LED's red colour.
 * @param   _green Ranges from 0 (off) to 255 (full on) and selects the intensity
 * of the selected LED's green colour.
 * @param   _blue Ranges from 0 (off) to 255 (full on) and selects the intensity
 * of the selected LED's blue colour.
 * @return  void
 * @Example <code>LedCube_setPixel(0, 0, 0, 255, 0, 0); // Set the origin (most
 * back, left and lowest LED to 100% red.</code>
 */
void
LedCube_setPixel( const pCubeData_t _pCubeData[],
        const uint8_t _x, const uint8_t _y, const uint8_t _z,
        const uint8_t _red, const uint8_t _green, const uint8_t _blue );

/**
 * Update the outputs of the LedCube with the data that is currently set in the
 * LedCube's LED data.
 * 
 * @param   void
 * @return  void
 * @Example <code>LedCube_update();</code>
 */
void
LedCube_update( void );

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
