/*******************************************************************************
 * Begin of file Fill.h
 * Author: jdebruijn
 * Created on November 8, 2015, 12:29 PM
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
 *  Animations to fill a row, layer or the whole cube.
 * 
 ******************************************************************************/

#ifndef FILL_H
#define	FILL_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdint.h>
#include "CubeControlData.h"
#include "Delay.h"
#include "LedCube.h"

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * Fill a row with a single colour at once.
 * 
 * @param   _x, row to fill. Ranges from 0 to LEDCUBE_MAX_XYZ, 0 for the back
 * row and LEDCUBE_MAX_XYZ for front row.
 * @param   _z, layer to fill the row in. Ranges from 0 to LEDCUBE_MAX_XYZ, 0
 * for the bottom layer and LEDCUBE_MAX_XYZ for the top layer.
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
 * @Example <code>FillRowAtOnceWithSingleColour(1, 4, 0, 15, 15);\n// Fills row
 * one of layer four with a cyan colour.</code>
 */
void
FillRowAtOnceWithSingleColour( uint8_t _x, uint8_t _z,
        uint8_t _red, uint8_t _green, uint8_t _blue );

/**
 * Fill a row with a single colour by adding one LED at a time.
 * 
 * @param   _x, row to fill. Ranges from 0 to LEDCUBE_MAX_XYZ, 0 for the back
 * row and LEDCUBE_MAX_XYZ for front row.
 * @param   _z, layer to fill the row in. Ranges from 0 to LEDCUBE_MAX_XYZ, 0
 * for the bottom layer and LEDCUBE_MAX_XYZ for the top layer.
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
 * @Example <code>FillRowWithSingleColour(1, 4, 0, 15, 15);\n// Fills row one of
 * layer four with a cyan colour.</code>
 */
void
FillRowWithSingleColour( uint8_t _x, uint8_t _z,
        uint8_t _red, uint8_t _green, uint8_t _blue );

/**
 * Fill a layer with a single colour at once.
 * 
 * @param   _z, layer to fill. Ranges from 0 to LEDCUBE_MAX_XYZ, 0 for the
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
 * @Example <code>FillLayerAtOnceWithSingleColour(4, 0, 15, 15);\n// Fills layer
 * four with a cyan colour.</code>
 */
void
FillLayerAtOnceWithSingleColour( uint8_t _z,
        uint8_t _red, uint8_t _green, uint8_t _blue );

/**
 * Fill a layer with a single colour by adding one LED at a time.
 * 
 * @param   _z, layer to fill. Ranges from 0 to LEDCUBE_MAX_XYZ, 0 for the
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
 * @Example <code>FillLayerWithSingleColour(4, 0, 15, 15);\n// Fills layer four
 * with a cyan colour.</code>
 */
void
FillLayerWithSingleColour( uint8_t _z,
        uint8_t _red, uint8_t _green, uint8_t _blue );

#ifdef	__cplusplus
}
#endif

#endif	/* FILL_H */
/* End of file Fill.h */
