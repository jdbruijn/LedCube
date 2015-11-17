/*******************************************************************************
 * Begin of file Colours.h
 * Author: jdebruijn
 * Created on November 6, 2015, 7:35 PM
 * 
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 * 
 * Copyright (c) 2015 Jeroen de Bruijn <vidavidorra@gmail.com>
 * 
 * This file is part of LedCube which is released under The MIT License (MIT).
 * For full license details see file "main.c" or "LICENSE.md" or go to
 * https://opensource.org/licenses/MIT
 * 
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Definition of a number of colours.
 * 
 * These colours can be used in combination with the @ref LedCube_setPixel
 * function and are formatted in RGB order.
 * 
 ******************************************************************************/

#ifndef COLOURS_H
#define	COLOURS_H

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
#define _MAX    LEDCUBE_MAX_INTENSITY

/* Colour values:       
 *             | red   || green || blue  | */
/** Colour black, i.e. the red, green and blue LED are turned off. @ref OFF can
 *  also be used for this. */
#define BLACK   0      , 0      , 0

/** Colour red. Red is at full intensity and green and blue are turned off. */
#define RED     _MAX   , 0      , 0

/** Colour green. Green is at full intensity and red and blue are turned off. */
#define GREEN   0      , _MAX   , 0

/** Colour yellow. Red and green are at full intensity and blue is turned off. */
#define YELLOW  _MAX   , _MAX   , 0

/** Colour blue. Blue is at full intensity and red and blue are turned off. */
#define BLUE    0      , 0      , _MAX

/** Colour magenta. Red and blue are at full intensity and green is turned off. */
#define MAGENTA _MAX   , 0      , _MAX

/** Colour cyan. Green and blue are at full intensity and red is turned off. */
#define CYAN    0      , _MAX   , _MAX

/** Colour white. Red, green and blue are all at full intensity. */
#define WHITE   _MAX   , _MAX   , _MAX

/** Alias for @ref BLACK. */
#define OFF     BLACK

#ifdef	__cplusplus
}
#endif

#endif	/* COLOURS_H */
/* End of file Colours.h */
