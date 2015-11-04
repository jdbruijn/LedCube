/*******************************************************************************
 * Begin of file Debug.c
 * Author: jdebruijn
 * Created on November 4, 2015, 12:25 PM
 * 
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 * 
 * Copyright (c) 2015 Jeroen de Bruijn <vidavidorra@gmail.com>
 * 
 * This file is part of LedCube which is released under The MIT License (MIT).
 * For full license details see file "main.c" or "LICENSE.md" or go to
 * https://opensource.org/licenses/MIT
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "Debug.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/

/**
 * Dummy printf function that is used if debugging is disabled.
 */
void
_dummy_printf( const char *format, ... ) {
    return;
}
/* End of file Debug.c */
