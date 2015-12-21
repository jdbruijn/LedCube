/*******************************************************************************
 * Begin of file MyAssert.h
 * Author: jdebruijn
 * Created on November 4, 2015, 8:32 PM
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
 * @brief Macros to evaluate an assertion and wrapper to print the output to the
 * standard device.
 * 
 * If @ref NDEBUG is defined, assertions will be disabled.
 * 
 ******************************************************************************/

#ifndef MYASSERT_H
#define MYASSERT_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Condition checks
 ******************************************************************************/
#if !defined(NDEBUG)

/*******************************************************************************
 * Includes
 ******************************************************************************/
# include <xc.h>
# ifndef UART_H
#  include "Uart.h"
# endif

/*******************************************************************************
 * Defines
 ******************************************************************************/
# ifndef PRINTF
/**
 * @brief Wrapper for PRINTF to an actual printf function, in this case @ref
 * Uart1_printf.
 */
#  define PRINTF Uart1_printf
# endif
# define _ASSERTION_FAILED_MSG " -- assertion failed, program halted..."

/*******************************************************************************
 * Function macros
 ******************************************************************************/
/**
 * Helper macro to print a debugging message to the standard device.
 * 
 * @Note    The macros need a second helper macro in order to expand multiple
 * defines.
 */
# define _MYASSERT_ASSERT(expr)                                                \
    PRINTF("DEBUG: %s:%d:%s(): " expr _ASSERTION_FAILED_MSG "\n",              \
    __FILE__, __LINE__, __FUNCTION__)

/**
 * @brief Evaluate an assertion.
 * 
 * If the argument expression of this macro with functional form compares equal
 * to zero (i.e., the expression is false), a message is written to the standard
 * device and the program execution is halted. Halting the program execution is
 * done by setting the CPU interrupt priority level to seven and entering an
 * infinite loop.
 * 
 * @note    This macro is disabled if, at the moment of including "MyAssert.h",
 * a macro with the name @ref NDEBUG has already been defined. This allows for a
 * coder to include as many assert calls as needed in a source code while
 * debugging the program and then disable all of them for the production version
 * by simply including a line like <code>#define NDEBUG</code> at the beginning
 * of the code, before the inclusion of "MyAssert.h".
 * Therefore, this macro is designed to capture programming errors, not user or
 * run-time errors, since it is generally disabled after a program exits its
 * debugging phase.
 * @param   expression Expression to be evaluated. If this expression evaluates
 * to zero, this causes an assertion failure that halts the program.
 * 
 */
# define ASSERT(expr) {                                                        \
    if(!(expr)) {                                                              \
        _MYASSERT_ASSERT(#expr);                                               \
        SET_CPU_IPL(7);                                                        \
        while(1);                                                              \
                } }(void) 0


#else /* NDEBUG is defined */
/* Disable the assert macro by a void 0 cast. */
# define ASSERT(expr) ((void)0)
#endif /* NDEBUG */

#ifdef __cplusplus
}
#endif

#endif /* MYASSERT_H */
/* End of file MyAssert.h */
