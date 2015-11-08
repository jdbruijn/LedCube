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
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 * 
 * Description:
 *  Definitions of a number of colours that can be used in combination with the
 *  LedCube_setPixel function.
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
#define _MAX    LEDCUBE_MAX_INTENSITY
/* 
 * Colour values:       
 *             | red   || green || blue  | */
#define BLACK   0      , 0      , 0
#define RED     _MAX   , 0      , 0
#define GREEN   0      , _MAX   , 0
#define YELLOW  _MAX   , _MAX   , 0
#define BLUE    0      , 0      , _MAX
#define MAGENTA _MAX   , 0      , _MAX
#define CYAN    0      , _MAX   , _MAX
#define WHITE   _MAX   , _MAX   , _MAX
#define OFF     BLACK

#ifdef	__cplusplus
}
#endif

#endif	/* COLOURS_H */
/* End of file Colours.h */
