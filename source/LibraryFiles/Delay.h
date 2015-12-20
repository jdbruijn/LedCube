/*******************************************************************************
 * Begin of file Delay.h
 * Author: jdebruijn
 * Created on November 6, 2015, 9:40 AM
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
 * @brief Delay macros and wrappers to the delay macros in libpic32.h.
 * 
 ******************************************************************************/

#ifndef DELAY_H
#define DELAY_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Includes
 ******************************************************************************/
/* System.h must be included before libpic32.h because the libpic32.h needs the
 * definition of FCY, which is in System.h
 */
#include "System.h"
#include <libpic30.h>

/*******************************************************************************
 * Defines
 ******************************************************************************/
/** @brief Maximum amount of seconds to delay. */
#define DELAY_MAX_S     134U
/** @brief Maximum amount of milliseconds to delay. */
#define DELAY_MAX_MS    134217UL
/** @brief Maximum amount of microseconds to delay. */
#define DELAY_MAX_US    134217727UL

/*******************************************************************************
 * Condition checks
 ******************************************************************************/
#if !defined(FCY)
# warning "FCY is not defined!"
#elif (FCY < 31250UL)
# warning "FCY has a very low value!"
#endif

/*******************************************************************************
 * Function macros
 ******************************************************************************/
/**
 * @brief Delay a certain number of seconds.
 * 
 * @param   d Number of seconds to delay. Ranging from 1 to @ref DELAY_MAX_S.
 */
#define DELAY_S(t)                                                             \
    { __delay32((unsigned long)( ((unsigned long long)(t))*(FCY))); }

/**
 * @brief Delay a certain number of milliseconds.
 * 
 * @param   d Milliseconds to delay. Ranging from 1 to @ref DELAY_MAX_MS.
 */
#define DELAY_MS(t) __delay_ms((t))

/**
 * @brief Delay a certain number of microseconds.
 * 
 * @param   d, number of microseconds to delay. Ranging from 1 to @ref
 * DELAY_MAX_US.
 */
#define DELAY_US(t) __delay_us((t))

#ifdef __cplusplus
}
#endif

#endif /* DELAY_H */
/* End of file Delay.h */
