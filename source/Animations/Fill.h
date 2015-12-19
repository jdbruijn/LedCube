/*******************************************************************************
 * Begin of file Fill.h
 * Author: jdebruijn
 * Created on November 8, 2015, 12:29 PM
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
 * @brief Animations to fill a row, layer or whole LED cube.
 *
 ******************************************************************************/

#ifndef FILL_H
#define FILL_H

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
 * Fill a row with a single colour at once, using @ref LedCube_setPixel.
 *
 * @param   _x Row to fill. Ranges from 0 to @ref LEDCUBE_MAX_XYZ, 0 for the
 * back row and @ref LEDCUBE_MAX_XYZ for front row.
 * @param   _z Layer to fill the row in. Ranges from 0 to @ref LEDCUBE_MAX_XYZ,
 * 0 for the bottom layer and @ref LEDCUBE_MAX_XYZ for the top layer.
 * @param   _red Intensity of the red colour. Ranges from 0 to
 * @ref LEDCUBE_MAX_INTENSITY, 0 for the lowest intensity (off) and
 * @ref LEDCUBE_MAX_INTENSITY for the brightest intensity.
 * @param   _green Intensity of the green colour. Ranges from 0 to
 * @ref LEDCUBE_MAX_INTENSITY, 0 for the lowest intensity (off) and
 * @ref LEDCUBE_MAX_INTENSITY for the brightest intensity.
 * @param   _blue Intensity of the blue colour. Ranges from 0 to
 * @ref LEDCUBE_MAX_INTENSITY, 0 for the lowest intensity (off) and
 * @ref LEDCUBE_MAX_INTENSITY for the brightest intensity.
 */
void
FillRowAtOnceWithSingleColour(uint8_t _x, uint8_t _z,
                              uint8_t _red, uint8_t _green, uint8_t _blue);

/**
 * Fill a row with a single colour by adding one LED at a time using @ref
 * LedCube_setPixel.
 *
 * @param   _x Row to fill. Ranges from 0 to @ref LEDCUBE_MAX_XYZ, 0 for the
 * back row and @ref LEDCUBE_MAX_XYZ for front row.
 * @param   _z Layer to fill the row in. Ranges from 0 to @ref LEDCUBE_MAX_XYZ,
 * 0 for the bottom layer and @ref LEDCUBE_MAX_XYZ for the top layer.
 * @param   _red Intensity of the red colour. Ranges from 0 to
 * @ref LEDCUBE_MAX_INTENSITY, 0 for the lowest intensity (off) and
 * @ref LEDCUBE_MAX_INTENSITY for the brightest intensity.
 * @param   _green Intensity of the green colour. Ranges from 0 to
 * @ref LEDCUBE_MAX_INTENSITY, 0 for the lowest intensity (off) and
 * @ref LEDCUBE_MAX_INTENSITY for the brightest intensity.
 * @param   _blue Intensity of the blue colour. Ranges from 0 to
 * @ref LEDCUBE_MAX_INTENSITY, 0 for the lowest intensity (off) and
 * @ref LEDCUBE_MAX_INTENSITY for the brightest intensity.
 */
void
FillRowWithSingleColour(uint8_t _x, uint8_t _z,
                        uint8_t _red, uint8_t _green, uint8_t _blue);

/**
 * Fill a layer with a single colour at once using @ref
 * FillRowAtOnceWithSingleColour.
 *
 * @param   _z Layer to fill the row in. Ranges from 0 to @ref LEDCUBE_MAX_XYZ,
 * 0 for the bottom layer and @ref LEDCUBE_MAX_XYZ for the top layer.
 * @param   _red Intensity of the red colour. Ranges from 0 to
 * @ref LEDCUBE_MAX_INTENSITY, 0 for the lowest intensity (off) and
 * @ref LEDCUBE_MAX_INTENSITY for the brightest intensity.
 * @param   _green Intensity of the green colour. Ranges from 0 to
 * @ref LEDCUBE_MAX_INTENSITY, 0 for the lowest intensity (off) and
 * @ref LEDCUBE_MAX_INTENSITY for the brightest intensity.
 * @param   _blue Intensity of the blue colour. Ranges from 0 to
 * @ref LEDCUBE_MAX_INTENSITY, 0 for the lowest intensity (off) and
 * @ref LEDCUBE_MAX_INTENSITY for the brightest intensity.
 */
void
FillLayerAtOnceWithSingleColour(uint8_t _z,
                                uint8_t _red, uint8_t _green, uint8_t _blue);

/**
 * Fill a layer with a single colour by adding one LED at a time using @ref
 * FillRowAtOnceWithSingleColour.
 *
 * @param   _z Layer to fill the row in. Ranges from 0 to @ref LEDCUBE_MAX_XYZ,
 * 0 for the bottom layer and @ref LEDCUBE_MAX_XYZ for the top layer.
 * @param   _red Intensity of the red colour. Ranges from 0 to
 * @ref LEDCUBE_MAX_INTENSITY, 0 for the lowest intensity (off) and
 * @ref LEDCUBE_MAX_INTENSITY for the brightest intensity.
 * @param   _green Intensity of the green colour. Ranges from 0 to
 * @ref LEDCUBE_MAX_INTENSITY, 0 for the lowest intensity (off) and
 * @ref LEDCUBE_MAX_INTENSITY for the brightest intensity.
 * @param   _blue Intensity of the blue colour. Ranges from 0 to
 * @ref LEDCUBE_MAX_INTENSITY, 0 for the lowest intensity (off) and
 * @ref LEDCUBE_MAX_INTENSITY for the brightest intensity.
 */
void
FillLayerWithSingleColour(uint8_t _z,
                          uint8_t _red, uint8_t _green, uint8_t _blue);

#ifdef __cplusplus
}
#endif

#endif /* FILL_H */
/* End of file Fill.h */
