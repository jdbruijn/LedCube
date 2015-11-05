/*******************************************************************************
 * Begin of file MyAssert.h
 * Author: jdebruijn
 * Created on November 4, 2015, 8:32 PM
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
 *  Macros to evaluate an assertion and wrapper to print the output to the
 *  standard device.
 * 
 ******************************************************************************/

#ifndef MYASSERT_H
#define	MYASSERT_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef NDEBUG

/*******************************************************************************
 * Includes
 ******************************************************************************/
#ifdef DEBUG
#include <xc.h>
#   ifndef UART_H
#     include "Uart.h"
#   endif
#else
#   include <assert.h>
#endif

/*******************************************************************************
 * Defines
 ******************************************************************************/
#ifdef DEBUG
#   ifndef PRINTF
/* Wrapper for PRINTF to an actual printf function, in this case Uart1_printf */
#     define PRINTF Uart1_printf
#   endif
#   define _ASSERTION_FAILED_MSG " -- assertion failed, program halted..."

/*******************************************************************************
 * Macros
 ******************************************************************************/
/**
 * Helper macro to print a debugging message to the standard device.
 * 
 * @Note    The macros need a second helper macro in order to expand multiple
 * defines.
 */
#   define _HELPER_ASSERT(expr) \
                PRINTF("DEBUG: %s:%d:%s(): " expr _ASSERTION_FAILED_MSG "\n", \
                __FILE__, __LINE__, __FUNCTION__)

/**
 * Evaluate an assertion.\n
 * If the argument expression of this macro with functional form compares equal
 * to zero (i.e., the expression is false), a message is written to the standard
 * device and the program execution is halted. Halting the program execution is
 * done by setting the CPU interrupt priority level to seven and entering an
 * infinite loop.
 * 
 * @Note    This macro is disabled if, at the moment of including "MyAssert.h",
 * a macro with the name NDEBUG has already been defined. This allows for a
 * coder to include as many assert calls as needed in a source code while
 * debugging the program and then disable all of them for the production version
 * by simply including a line like <code>#define NDEBUG</code> at the beginning
 * of the code, before the inclusion of "MyAssert.h".\n
 * Therefore, this macro is designed to capture programming errors, not user or
 * run-time errors, since it is generally disabled after a program exits its
 * debugging phase.
 * @param   expression, expression to be evaluated. If this expression evaluates
 * to 0, this causes an assertion failure that halts the program.
 * 
 */
#   define ASSERT(expression) {                     \
                if(!(expression)) {                    \
                    _HELPER_ASSERT(#expression);    \
                    SET_CPU_IPL(7);                 \
                    while(1);                       \
                } }(void) 0

#else /* DEBUG */
/* Wrapper for ASSERT to the standard assert (from assert.h). */
#   define ASSERT(expr) assert(expr)
#endif /* DEBUG */

#else /* NDEBUG is defined */
#   ifdef DEBUG
#     warning Both DEBUG and NDEBUG are defined!
#   endif
/**
 * The ASSERT macro does not do anything, the device proceeds program execution
 * as normal.
 */
#   define ASSERT(expr) ((void)0)
#endif /* NDEBUG */

#ifdef	__cplusplus
}
#endif

#endif	/* MYASSERT_H */
/* End of file MyAssert.h */
