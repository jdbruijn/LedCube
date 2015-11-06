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
 * For full license details see file "main.c" or "LICENSE.md" or go to
 * https://opensource.org/licenses/MIT
 * 
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 * 
 * Description:
 *  Delay macros and wrappers to the delay macros in libpic32.h.
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
/**
 * System.h must be included before libpic32.h because the libpic32.h needs the
 * definition of FCY, which is in System.h
 */
#include "System.h"
#include <libpic30.h>

/*******************************************************************************
 * Condition checks
 ******************************************************************************/
#ifndef FCY
#   warning FCY is not defined!
#elif (FCY < 31250UL)
#   warning FCY has a very low value!
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/
/**
 * Delay a certain number of seconds.
 * 
 * @param   d, the number of seconds to delay. Ranging from 1 to 134 seconds.
 * @Example <code>// Prints "Testing Delay_s()..." every second.\n
 * while(1) {\n
 *  &#32 printf("Testing Delay_s()...");\n
 *  &#32 Delay_s(1);\n
 * }</code>
 */
#define Delay_s(d)  \
        { __delay32( (unsigned long)( ((unsigned long long)d)*(FCY)/1ULL ) ); }

/**
 * Delay a certain number of milliseconds.
 * 
 * @param   d, number of milliseconds to delay. Ranging from 1 to 134217
 * milliseconds.
 * @Example <code>// Prints "Testing Delay_ms()..." every 100 milliseconds.\n
 * while(1) {\n
 *  &#32 printf("Testing Delay_ms()...");\n
 *  &#32 Delay_ms(100);\n
 * }</code>
 */
#define Delay_ms(d) __delay_ms(d)

/**
 * Delay a certain number of microseconds.
 * 
 * @param   d, number of microseconds to delay. Ranging from 1 to 134217727
 * microseconds.
 * @Example <code>// Prints "Testing Delay_us()..." every 1000 microseconds.\n
 * while(1) {\n
 *  &#32 printf("Testing Delay_us()...");\n
 *  &#32 Delay_us(1000);\n
 * }</code>
 */
#define Delay_us(d) __delay_us(d)

#ifdef	__cplusplus
}
#endif

#endif	/* DELAY_H */
/* End of file Delay.h */
