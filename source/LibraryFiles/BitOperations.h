/*******************************************************************************
 * Begin of file BitOperations.h
 * Author: jdebruijn
 * Created on October 5, 2015, 8:59 AM
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
 * @brief Several bit operations and manipulations.
 * @note The macros and functions below are based on Sean Eron Anderson's Bit
 * Twiddling Hacks.
 * @see https://graphics.stanford.edu/~seander/bithacks.html#CopyIntegerSign
 * @see https://github.com/gibsjose/BitHacks/blob/master/BitHacks.md#compute-the-sign-of-an-integer
 *
 ******************************************************************************/

#ifndef BITOPERATIONS_H
#define BITOPERATIONS_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

/*******************************************************************************
 * Defines
 ******************************************************************************/
#define CHAR_BIT        8           /**< @brief Number of bits in a byte. */

/*******************************************************************************
 * Function macros
 ******************************************************************************/
/**
 * @brief Create a bitmask. E.g. 0b00010000
 *
 * @param   b The number of the bit to create the mask for (0-64).
 */
#define bitMask(b) (0x01 << (b))

/**
 * @brief Get the value of a bit or bits.
 *
 * @param   b The variable to get the bit(s) from.
 * @param   mask The mask for getting the bit(s).
 */
#define bitGet(b, mask)   ((b) & (mask))

/**
 * @brief Set a bit or bits.
 *
 * @note    This changes the variable!
 * @param   b The variable to set the bit(s) in.
 * @param   mask The mask for setting the bit(s).
 */
#define bitSet(b, mask)   ((p) |= (mask))

/**
 * @brief Clear a bit or bits.
 *
 * @note    This changes the variable!
 * @param   b The variable to clear the bit(s) in.
 * @param   mask The mask for clearing the bit(s).
 */
#define bitClear(b, mask) ((b) &= (~(mask)))

/**
 * @brief Flip/toggle a bit or bits.
 *
 * @note    This changes the variable!
 * @param   b The variable to flip the bit(s) in.
 * @param   mask The mask for flipping the bit(s).
 */
#define bitFlip(b, mask) ((b) ^= (mask))

/**
 * @brief Shift a variable left.
 *
 * @note    This changes the variable!
 * @param   v The variable to shift left.
 * @param   p Number of positions to shift the variable left.
 */
#define shiftLeft(v, p) ((v) <<= (p))

/**
 * @brief Shift a variable right.
 *
 * @note    This changes the variable!
 * @param   v The variable to shift right.
 * @param   p Number of positions to shift the variable right.
 */
#define shiftRight(v, p) ((v) >>= (p))

/**
 * @brief Shift a variable left without changing the variable.
 *
 * @note    This does not change the variable.
 * @param   v The variable to shift left.
 * @param   p Number of positions to shift left.
 */
#define shiftLeftM(v, p) ((v) << (p))

/**
 * @brief Shift a variable right without changing the variable.
 *
 * @note    This does not change the variable.
 * @param   v The variable to shift right.
 * @param   p Number of positions to shift right.
 */
#define shiftRightM(v, p) ((v) << (p))

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * @brief Compute the sign of an integer.
 *
 * @param   _v Variable of which to compute the sign.
 * @return  bool True if the variable is positive, false else.
 */
bool
isPositive(int32_t const _v);

/**
 * @brief Detect if two integers have opposite signs.
 *
 * @param   _x First variable of which the signs need to be compared.
 * @param   _y Second variable of which the signs need to be compared.
 * @return  bool True if the variables have opposite signs, false else.
 */
bool
haveOppositeSigns(int32_t const _x, int32_t const _y);

/* Make sure the implementation below is used instead of a standard
 * implementation like in @ref stdlib.h
 */
#ifdef min
#undef min
#endif
/**
 * @brief Compute the minimum of two integers without branching.
 *
 * @param   _x First variable of which the minimum needs to be found.
 * @param   _y Second variable of which the minimum needs to be found.
 * @return  int32_t The minimum value, _x or _y.
 */
int32_t
min(int32_t const _x, int32_t const _y);

/* Make sure the implementation below is used instead of a standard
 * implementation like in @ref stdlib.h
 */
#ifdef max
#undef max
#endif
/**
 * @brief Compute the maximum of two integers without branching.
 *
 * @param   _x First variable of which the maximum needs to be found.
 * @param   _y Second variable of which the maximum needs to be found.
 * @return  int32_t The maximum value, _x or _y.
 */
int32_t
max(int32_t const _x, int32_t const _y);

/**
 * @brief Determining if an integer is a power of two.
 *
 * @param   _v, variable of which to check if it is a power of two.
 * @return  bool True if _v is a power of to, false else.
 */
bool
isPowerOf2(int32_t const _v);

/**
 * @brief Conditionally set or clear bits without branching.
 *
 * @param   _v Pointer to the variable of which to set or clear bits.
 * @param   _mask Bit mask for setting or clearing bits.
 * @param   _f Flag whether the bits needs to be set or cleared (1 or 0).
 */
void
modifyBits(uint32_t *_v, uint32_t const _mask, bool const _f);

/**
 * @brief Merge bits from two values according to a mask.
 *
 * @param   _x Variable to merge in non-masked bits.
 * @param   _y Variable to merge in masked bits.
 * @param   _mask Bit mask for setting or clearing bits.
 * @return  uint32_t Result of the merged variables _x and _y.
 */
uint32_t
mergeBits(uint32_t const _x, uint32_t const _y, uint32_t const _mask);

/**
 * @brief Counting bits set.
 *
 * @param   _v Variable of which to check how much bits are set.
 * @return  uint8_t Number of bits set in _v.
 */
uint8_t
nBitsSet(int32_t const _v);

/**
 * @brief Compute parity of word with a multiply.
 *
 * @param   _v Variable of which to compute the parity.
 * @return  bool True if _v is odd, false else.
 */
bool
isEven(uint32_t const _v);

/**
 * @brief Reverse an N-bit quantity in parallel in 5 * lg(N) operations. Now set
 * to reverse the bit order of an 32 bit unsigned integer.
 *
 * @param   _v Pointer to the variable of which the bit order needs to be
 * reversed.
 */
void
reverseBitOrder(uint32_t *_v);

/**
 * @brief Round up to the next highest power of two by float casting.
 *
 * @param   _v Pointer to the variable of which needs to be round up to the
 * next power of two.
 * @return  uint16_t The next power of two.
 */
uint32_t
roundUpToPowerOf2(uint32_t const _v);

#ifdef __cplusplus
}
#endif

#endif /* BITOPERATIONS_H */
/* End of file BitOperations.h */
