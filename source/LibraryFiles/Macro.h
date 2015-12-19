/*******************************************************************************
 * Begin of file Macro.h
 * Author: Jeroen de Bruijn
 * Created on December 15, 2015, 7:35 PM
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
 * @brief Standard macros to perform general macro operations like expansion and
 * concatenation.
 * 
 ******************************************************************************/

#ifndef MACRO_H
#define MACRO_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Function macros
 ******************************************************************************/
/** @brief Internal helper macro to expand and concatenate two arguments.
 *
 * @note    The helper macro is needed to expand the arguments. Due to the macro
 * replacement of the C99 standard. For more information see section 6.10.3 of
 * the C99 standard.
 * @param   a First argument that is expanded.
 * @param   b Second argument that is expanded.
 */
#define _MACRO_EXPAND_CONCATENATE_TWO(a, b) a ## b

/** @brief Expand and concatenate two arguments.
 *
 * @param   a First argument that is expanded.
 * @param   b Second argument that is expanded.
 */
#define MACRO_EXPAND_CONCATENATE_TWO(a, b)                                     \
    _MACRO_EXPAND_CONCATENATE_TWO(a, b)

/** @brief Internal helper macro to expand and concatenate three arguments.
 *
 * @note    The helper macro is needed to expand the arguments. Due to the macro
 * replacement of the C99 standard. For more information see section 6.10.3 of
 * the C99 standard.
 * @param   a First argument that is expanded.
 * @param   b Second argument that is expanded.
 * @param   c Third argument that is expanded.
 */
#define _MACRO_EXPAND_CONCATENATE_THREE(a, b, c) a ## b ## c

/** @brief Expand and concatenate three arguments.
 *
 * @param   a First argument that is expanded.
 * @param   b Second argument that is expanded.
 * @param   c Third argument that is expanded.
 */
#define MACRO_EXPAND_CONCATENATE_THREE(a, b, c)                                \
    _MACRO_EXPAND_CONCATENATE_THREE(a, b, c)

/** @brief Internal helper macro to expand and concatenate four arguments.
 *
 * @note    The helper macro is needed to expand the arguments. Due to the macro
 * replacement of the C99 standard. For more information see section 6.10.3 of
 * the C99 standard.
 * @param   a First argument that is expanded.
 * @param   b Second argument that is expanded.
 * @param   c Third argument that is expanded.
 * @param   d Fourth argument that is expanded.
 */
#define _MACRO_EXPAND_CONCATENATE_FOUR(a, b, c, d) a ## b ## c ## d

/** @brief Expand and concatenate four arguments.
 *
 * @param   a First argument that is expanded.
 * @param   b Second argument that is expanded.
 * @param   c Third argument that is expanded.
 * @param   d Fourth argument that is expanded.
 */
#define MACRO_EXPAND_CONCATENATE_FOUR(a, b, c, d)                              \
    _MACRO_EXPAND_CONCATENATE_FOUR(a, b, c, d)

/** @brief Internal helper macro to expand and concatenate five arguments.
 *
 * @note    The helper macro is needed to expand the arguments. Due to the macro
 * replacement of the C99 standard. For more information see section 6.10.3 of
 * the C99 standard.
 * @param   a First argument that is expanded.
 * @param   b Second argument that is expanded.
 * @param   c Third argument that is expanded.
 * @param   d Fourth argument that is expanded.
 * @param   e Fifth argument that is expanded.
 */
#define _MACRO_EXPAND_CONCATENATE_FIVE(a, b, c, d, e) a ## b ## c ## d ## e

/** @brief Expand and concatenate five arguments.
 *
 * @param   a First argument that is expanded.
 * @param   b Second argument that is expanded.
 * @param   c Third argument that is expanded.
 * @param   d Fourth argument that is expanded.
 * @param   e Fifth argument that is expanded.
 */
#define MACRO_EXPAND_CONCATENATE_FIVE(a, b, c, d, e)                           \
    _MACRO_EXPAND_CONCATENATE_FIVE(a, b, c, d, e)

/** @brief Internal helper macro to expand and convert to a string one argument.
 *
 * @note    The helper macro is needed to expand the arguments. Due to the macro
 * replacement of the C99 standard. For more information see section 6.10.3 of
 * the C99 standard.
 * @param   a The argument that is expanded and converted to a string.
 */
#define _MACRO_EXPAND_STR_ONE(a) #a

/** @brief Expand and convert to a string one argument.
 *
 * @note    The argument could be anything. For example a number.
 * @param   a The argument that is expanded and converted to a string.
 */
#define MACRO_EXPAND_STR_ONE(a)                                                \
    _MACRO_EXPAND_STR_ONE(a)

/** @brief Internal helper macro to expand, convert to a string and concatenate
 * two arguments.
 *
 * @note    The helper macro is needed to expand the arguments. Due to the macro
 * replacement of the C99 standard. For more information see section 6.10.3 of
 * the C99 standard.
 * @param   a First argument that is expanded and converted to a string.
 * @param   b Second argument that is expanded and converted to a string.
 */
#define _MACRO_EXPAND_CONCATENATE_STR_TWO(a, b) #a #b

/** @brief Expand, convert to a string and concatenate two arguments.
 *
 * @note    The arguments could be anything. For example a number.
 * @param   a First argument that is expanded and converted to a string.
 * @param   b Second argument that is expanded and converted to a string.
 */
#define MACRO_EXPAND_CONCATENATE_STR_TWO(a, b)                                 \
    _MACRO_EXPAND_CONCATENATE_STR_TWO(a, b)

/** @brief Internal helper macro to expand, convert to a string and concatenate
 * three arguments.
 *
 * @note    The helper macro is needed to expand the arguments. Due to the macro
 * replacement of the C99 standard. For more information see section 6.10.3 of
 * the C99 standard.
 * @param   a First argument that is expanded and converted to a string.
 * @param   b Second argument that is expanded and converted to a string.
 * @param   c Third argument that is expanded and converted to a string.
 */
#define _MACRO_EXPAND_CONCATENATE_STR_THREE(a, b, c) #a #b #c

/** @brief Expand, convert to a string and concatenate three arguments.
 *
 * @note    The arguments could be anything. For example a number.
 * @param   a First argument that is expanded and converted to a string.
 * @param   b Second argument that is expanded and converted to a string.
 * @param   c Third argument that is expanded and converted to a string.
 */
#define MACRO_EXPAND_CONCATENATE_STR_THREE(a, b, c)                            \
    _MACRO_EXPAND_CONCATENATE_STR_THREE(a, b, c)

/** @brief Internal helper macro to expand, convert to a string and concatenate
 * four arguments.
 *
 * @note    The helper macro is needed to expand the arguments. Due to the macro
 * replacement of the C99 standard. For more information see section 6.10.3 of
 * the C99 standard.
 * @param   a First argument that is expanded and converted to a string.
 * @param   b Second argument that is expanded and converted to a string.
 * @param   c Third argument that is expanded and converted to a string.
 * @param   d Fourth argument that is expanded and converted to a string.
 */
#define _MACRO_EXPAND_CONCATENATE_STR_FOUR(a, b, c, d) #a #b #c #d

/** @brief Expand, convert to a string and concatenate four arguments.
 *
 * @note    The arguments could be anything. For example a number.
 * @param   a First argument that is expanded and converted to a string.
 * @param   b Second argument that is expanded and converted to a string.
 * @param   c Third argument that is expanded and converted to a string.
 * @param   d Fourth argument that is expanded and converted to a string.
 */
#define MACRO_EXPAND_CONCATENATE_STR_FOUR(a, b, c, d)                          \
    _MACRO_EXPAND_CONCATENATE_STR_FOUR(a, b, c, d)

/** @brief Internal helper macro to expand, convert to a string and concatenate
 * five arguments.
 *
 * @note    The helper macro is needed to expand the arguments. Due to the macro
 * replacement of the C99 standard. For more information see section 6.10.3 of
 * the C99 standard.
 * @param   a First argument that is expanded and converted to a string.
 * @param   b Second argument that is expanded and converted to a string.
 * @param   c Third argument that is expanded and converted to a string.
 * @param   d Fourth argument that is expanded and converted to a string.
 * @param   e Fifth argument that is expanded and converted to a string.
 */
#define _MACRO_EXPAND_CONCATENATE_STR_FIVE(a, b, c, d, e) #a #b #c #d #e

/** @brief Expand, convert to a string and concatenate five arguments.
 *
 * @note    The arguments could be anything. For example a number.
 * @param   a First argument that is expanded and converted to a string.
 * @param   b Second argument that is expanded and converted to a string.
 * @param   c Third argument that is expanded and converted to a string.
 * @param   d Fourth argument that is expanded and converted to a string.
 * @param   e Fifth argument that is expanded and converted to a string.
 */
#define MACRO_EXPAND_CONCATENATE_STR_FIVE(a, b, c, d, e)                       \
    _MACRO_EXPAND_CONCATENATE_STR_FIVE(a, b, c, d, e)

#ifdef __cplusplus
}
#endif

#endif /* MACRO_H */
/* End of file Macro.h */
