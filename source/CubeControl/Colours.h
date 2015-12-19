/*******************************************************************************
 * Begin of file Colours.h
 * Author: jdebruijn
 * Created on November 6, 2015, 7:35 PM
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
 * @brief Definition of a number of basic RGB colours.
 * 
 * These colours can be used in combination with the @ref LedCube_setPixel
 * function and are formatted in RGB order.
 * 
 ******************************************************************************/

#ifndef COLOURS_H
#define COLOURS_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "LedCube.h"

/*******************************************************************************
 * Defines
 ******************************************************************************/
/** Internal maximum intensity for a single colour. */
#define _COLOUR_MAX LEDCUBE_MAX_INTENSITY

/* Colour values:
 *                     | red      |  | green      |  | blue     | */
/** Colour black, i.e. the red, green and blue LED are turned off. @ref
 * COLOUR_OFF can also be used for this.
 */
#define COLOUR_BLACK   0           , 0             , 0

/** Colour red. Red is at full intensity and green and blue are turned off. */
#define COLOUR_RED     _COLOUR_MAX , 0             , 0

/** Colour green. Green is at full intensity and red and blue are turned off. */
#define COLOUR_GREEN   0           , _COLOUR_MAX   , 0

/** Colour yellow. Red and green are at full intensity and blue is turned off.
 */
#define COLOUR_YELLOW  _COLOUR_MAX , _COLOUR_MAX   , 0

/** Colour blue. Blue is at full intensity and red and blue are turned off. */
#define COLOUR_BLUE    0           , 0             , _COLOUR_MAX

/** Colour magenta. Red and blue are at full intensity and green is turned off.
 */
#define COLOUR_MAGENTA _COLOUR_MAX , 0             , _COLOUR_MAX

/** Colour cyan. Green and blue are at full intensity and red is turned off. */
#define COLOUR_CYAN    0           , _COLOUR_MAX   , _COLOUR_MAX

/** Colour white. Red, green and blue are all at full intensity. */
#define COLOUR_WHITE   _COLOUR_MAX , _COLOUR_MAX   , _COLOUR_MAX

/** Alias for @ref COLOUR_BLACK. */
#define COLOUR_OFF COLOUR_BLACK

#ifdef __cplusplus
}
#endif

#endif /* COLOURS_H */
/* End of file Colours.h */
