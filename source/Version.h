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
 * Defines
 ******************************************************************************/
#define VERSION_MAJOR 0
#define VERSION_MINOR 1
#define VERSION_PATCH 0

/*******************************************************************************
 * Macros
 ******************************************************************************/
/** @brief Helper macro to correctly expand the argument. */
#define _HELPER_VERSION_TO_STRING(s) #s

/** @brief Macro to expand the argument. */
#define _VERSION_TO_STRING(s) _HELPER_VERSION_TO_STRING(s)

/** @brief Macro for defining a version string.
 *  It uses the @ref _VERSION_TO_STRING macro to expand the version defines to a
 *  single version string.
 */
#define VERSION_STRING _VERSION_TO_STRING(VERSION_MAJOR) "." \
            _VERSION_TO_STRING(VERSION_MINOR) "." \
            _VERSION_TO_STRING(VERSION_PATCH)

#ifdef	__cplusplus
}
#endif

#endif	/* VERSION_H */
/* End of file Version.h */
