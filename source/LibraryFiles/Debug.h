/*******************************************************************************
 * Begin of file Debug.h
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
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 * Description:
 *  Macros for printing debugging messages.
 * 
 ******************************************************************************/

#ifndef DEBUG_H
#define	DEBUG_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdint.h>
#ifdef DEBUG
# include "Uart.h"
#endif

/*******************************************************************************
 * Defines
 ******************************************************************************/
#ifdef DEBUG
#   define DEBUG_FLAG 1
/* Wrapper for PRINTF to an actual printf function, in this case Uart1_printf */
#   define PRINTF Uart1_printf
#else
#   define DEBUG_FLAG 0
/* Wrapper for PRINTF to a dummy printf function which doesn't do anything */
#   define PRINTF _dummy_printf
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/
/**
 * Print formatted debugging data with prefix filename, line and function.
 * 
 * @See     Uartx_printf() documentation for more information about the
 * parameters.
 * @param   fmt, format C string that contains the text to be written.
 * @param   args..., additional arguments.
 * @Example <code>// If the following line was placed in a file called test.c,
 * on line 51 and in a function called debugTest().\n
 * DEBUG_PRINTF("Testing %s printing %d...", "debug", 123);\n
 * // Prints (without the quotemarks): "&#32;DEBUG: src/test.c:51:debugTest():
 * Testing debug printing 123..."\n</code>
 */
#define DEBUG_PRINTF(fmt, args...) do{ if(DEBUG_FLAG) { \
                PRINTF(" DEBUG: %s:%d:%s(): " fmt "\n", __FILE__, __LINE__, \
                __func__, ##args); \
                } }while(0)

/**
 * Print formatted debugging data for a function call.
 * 
 * @See     Uartx_printf() documentation for more information about the
 * parameters.
 * @param   fmt, format C string that contains the text to be written.
 * @param   args..., additional arguments.
 * @Example <code>// function declaration: \n
 * void test( uint8_t *_ptr, uint8_t _v ) {\n
 * &#32 DEBUG_PRINTF_FUNCTION_CALL("%p, %u", _ptr, _v);\n
 * &#32 // user code\n
 * &#32 return;\n
 * }\n\n
 * uint8_t value = 44;\n
 * test( &value, value ); // function call\n
 * // Prints (without the quotemarks): " DEBUG: test(b06, 44)"
 * </code>
 */
#define DEBUG_PRINTF_FUNCTION_CALL(fmt, args...) do{ if(DEBUG_FLAG) { \
                PRINTF(" DEBUG: %s(" fmt ")\n", __FUNCTION__ , ##args); \
                } }while(0)

#define DEBUG_PRINTF_INDENT(indent, fmt, args...) do{ if(DEBUG_FLAG) { \
                PRINTF("%*c DEBUG: %s:%d:%s(): " fmt "\n", indent, ' ', \
                __FILE__, __LINE__, __FUNCTION__, ##args); \
                } }while(0)

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * Dummy printf function that is used if debugging is disabled.
 * 
 * @See     Uartx_printf() documentation for information about the parameters.
 */
void
_dummy_printf( const char *format, ... );

#ifdef	__cplusplus
}
#endif

#endif	/* DEBUG_H */
/* End of file Debug.h */
