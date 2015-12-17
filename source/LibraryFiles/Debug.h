/*******************************************************************************
 * Begin of file Debug.h
 * Author: jdebruijn
 * Created on November 4, 2015, 12:25 PM
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
 * @brief Macros for printing debugging messages.
 * 
 ******************************************************************************/

#ifndef DEBUG_H
#define	DEBUG_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Switches
 ******************************************************************************/
#define DEBUG_FUNC_INIT_MSG_YES

#if defined(DEBUG) && defined(NDEBUG)
# warning "Both DEBUG and NDEBUG are defined"
#endif

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <xc.h>
#include <stdint.h>
#ifdef DEBUG
# include "Uart.h"
#endif

/*******************************************************************************
 * Defines
 ******************************************************************************/
#ifdef DEBUG
/** 
 * @brief Wrapper for PRINTF to an actual printf function, in this case @ref
 * Uart1_printf.
 */
# define PRINTF Uart1_printf
/**
 * Flag whether debug messages should be printed. One if these message should be
 * printed and zero if the messages should not be printed.
 */
# define _DEBUG_FLAG 1
# ifdef DEBUG_FUNC_INIT_MSG_YES
/**
 * Flag whether function initialize complete messages should be printed. One if
 * these message should be printed and zero if the messages should not be
 * printed.
 */
#  define _DEBUG_FUNC_INIT_FLAG 1
# else
#  define _DEBUG_FUNC_INIT_FLAG 0
# endif
#else
/**
 * Flag whether debug messages should be printed. One if these message should be
 * printed and zero if the messages should not be printed.
 */
# define _DEBUG_FLAG 0
/**
 * Flag whether function initialize complete messages should be printed. One if
 * these message should be printed and zero if the messages should not be
 * printed.
 */
# define _DEBUG_FUNC_INIT_FLAG 0
#endif

/*******************************************************************************
 * Function macros
 ******************************************************************************/
#ifdef DEBUG
/**
 * Print formatted debugging data with prefix filename, line and function.
 * 
 * @See     Uartx_printf() documentation for more information about the function
 * parameters.
 * @param   fmt Format C string that contains the text to be written.
 * @param   args... Additional arguments.
 */
#define DEBUG_PRINTF(fmt, args...)                                             \
    do{                                                                        \
        if(_DEBUG_FLAG) {                                                      \
            PRINTF(" DEBUG: %s:%d:%s(): " fmt "\n", __FILE__, __LINE__,        \
            __FUNCTION__, ##args);                                             \
        }                                                                      \
    } while (0)

/**
 * Print formatted debugging data from a function.
 * 
 * @See     Uartx_printf() documentation for more information about the function
 * parameters.
 * @param   fmt Format C string that contains the text to be written.
 * @param   args... Additional arguments.
 */
#   define DEBUG_PRINTF_FUNCTION(fmt, args...)                                 \
    do{                                                                        \
        if(_DEBUG_FLAG) {                                                      \
                PRINTF(" DEBUG: %s(): " fmt "\n", __FUNCTION__ , ##args);      \
        }                                                                      \
    } while (0)

/**
 * Print formatted debugging data for a function call, which can include the
 * function parameters.
 * 
 * @see     Uartx_printf() documentation for more information about the function
 * parameters.
 * @param   fmt Format C string that contains the text to be written.
 * @param   args... Additional arguments.
 */
# define DEBUG_PRINTF_FUNCTION_CALL(fmt, args...)                              \
    do{                                                                        \
        if(_DEBUG_FLAG) {                                                      \
            PRINTF(" DEBUG: %s(" fmt ")\n", __FUNCTION__ , ##args);            \
        }                                                                      \
    }while(0)

/**
 * Print a function initialize complete message.
 * 
 * @See     Uartx_printf() documentation for more information about the function
 * parameters.
 * @param   fmt Format C string that contains the text to be written.
 * @param   args... Additional arguments.
 */
# define DEBUG_PRINTF_FUNCTION_INITIALIZE_COMPLETE() if(_DEBUG_FUNC_INIT_FLAG) \
    DEBUG_PRINTF_FUNCTION("Initialize complete...");

# define DEBUG_PRINTF_INDENT_TEST(indent, fmt, args...)                        \
    do{                                                                        \
        if(_DEBUG_FLAG) {                                                      \
            PRINTF("%*c DEBUG: %s:%d:%s(): " fmt "\n", indent, ' ',            \
            __FILE__, __LINE__, __FUNCTION__, ##args);                         \
        }                                                                      \
    } while (0)
#else /* DEBUG */
# define PRINTF(fmt, args...) ((void)0)
# define DEBUG_PRINTF(fmt, args...) ((void)0)
# define DEBUG_PRINTF_FUNCTION(fmt, args...)  ((void)0)
# define DEBUG_PRINTF_FUNCTION_CALL(fmt, args...)  ((void)0)
# define DEBUG_PRINTF_FUNCTION_INITIALIZE_COMPLETE() ((void)0)
#endif /* DEBUG */

#ifdef	__cplusplus
}
#endif

#endif	/* DEBUG_H */
/* End of file Debug.h */
