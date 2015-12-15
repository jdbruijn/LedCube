/*******************************************************************************
 * Begin of file Version.h
 * Author: jdebruijn
 * Created on December 6, 2015, 1:55 PM
 * 
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 * 
 * Copyright (c) 2015 Jeroen de Bruijn <vidavidorra@gmail.com>
 * 
 * This file is part of LedCube which is released under The MIT License (MIT).
 * For full license details see file "main.c" or "LICENSE" or go to
 * https://opensource.org/licenses/MIT
 * 
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Version of the LedCube project.
 * 
 ******************************************************************************/

#ifndef VERSION_H
#define	VERSION_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "Macro.h"

/*******************************************************************************
 * Defines
 ******************************************************************************/
#define VERSION_MAJOR           0   /**< Major version number. */
#define VERSION_MINOR           1   /**< Minor version number. */
#define VERSION_PATCH           0   /**< Patch version number. */

/*******************************************************************************
 * Macros
 ******************************************************************************/
/** @brief Version string.
 * 
 * It uses the @ref MACRO_EXPAND_CONCATENATE_STR_FIVE macro to expand and
 * and convert the version defines to a version string.
 */
#define VERSION_STRING                                                         \
    MACRO_EXPAND_CONCATENATE_STR_FIVE(VERSION_MAJOR, ., VERSION_MINOR, . ,     \
    VERSION_PATCH)

#ifdef	__cplusplus
}
#endif

#endif	/* VERSION_H */
/* End of file Version.h */
