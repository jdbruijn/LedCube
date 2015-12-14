/*******************************************************************************
 * Begin of file Delay.h
 * Author: jdebruijn
 * Created on November 6, 2015, 9:40 AM
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
 * @brief Delay macros and wrappers to the delay macros in libpic32.h.
 * 
 ******************************************************************************/

#ifndef DELAY_H
#define	DELAY_H

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
#ifndef FCY
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
#define Delay_s(t)                                                             \
    { __delay32((unsigned long)( ((unsigned long long)(t))*(FCY)/1ULL )); }

/**
 * @brief Delay a certain number of milliseconds.
 * 
 * @param   d Milliseconds to delay. Ranging from 1 to @ref DELAY_MAX_MS.
 */
#define Delay_ms(t) __delay_ms((t))

/**
 * @brief Delay a certain number of microseconds.
 * 
 * @param   d, number of microseconds to delay. Ranging from 1 to @ref
 * DELAY_MAX_US.
 */
#define Delay_us(t) __delay_us((t))

#ifdef	__cplusplus
}
#endif

#endif	/* DELAY_H */
/* End of file Delay.h */
