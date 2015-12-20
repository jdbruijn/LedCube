/*******************************************************************************
 * Begin of file Version.h
 * Author: jdebruijn
 * Created on December 6, 2015, 1:55 PM
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
 * @brief Version of the LedCube project.
 * 
 ******************************************************************************/

#ifndef VERSION_H
#define VERSION_H

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
#define VERSION_MAJOR 0     /**< Major version number. */
#define VERSION_MINOR 1     /**< Minor version number. */
#define VERSION_PATCH 0     /**< Patch version number. */

/*******************************************************************************
 * Constant macros
 ******************************************************************************/
/** @brief Version string.
 * 
 * It uses the @ref MACRO_EXPAND_CONCATENATE_STR_FIVE macro to expand and
 * and convert the version defines to a version string.
 */
#define VERSION_STRING                                                         \
    MACRO_EXPAND_CONCATENATE_STR_FIVE(VERSION_MAJOR, ., VERSION_MINOR, . ,     \
    VERSION_PATCH)

#ifdef __cplusplus
}
#endif

#endif /* VERSION_H */
/* End of file Version.h */
