/*******************************************************************************
 * Begin of file BitOperations.h
 * Author: jdebruijn
 * Created on October 5, 2015, 8:59 AM
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
 *  Several bit operations and manipulations.
 * 
 ******************************************************************************/

#ifndef BITOPERATIONS_H
#define	BITOPERATIONS_H

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
#define CHAR_BIT        8           /* Number of bits in a byte */

/*******************************************************************************
 * Macros
 ******************************************************************************/
/**
 * Create a bitmask. E.g. 0b00010000
 * 
 * @Note    b must be a power of 2
 * @param   b The number of the bit to create the mask for (0-128)
 * @Example <code>uint8_t mask1 = bitMask(3); // Create bit mask 0b00001000</code>
 */
#define bitMask(b) (0x01 << (b))

/**
 * Get the value of a bit or bits.
 * 
 * @param   b The variable to get the bit(s) from
 * @param   mask The mask for getting the bit(s)
 * @Example <code>bitGet(x, 8); // Get the value of bit 3 (0b00001000) of
 * variable x\n
 * bitGet(x, 7); // Get the value of bits 0-2 (0b00000111) of variable x\n
 * bitGet(x, bitMask(5)); // Get the value of bit 5 (0b00100000) of variable x
 * </code>
 */
#define bitGet(b, mask)   ((b) & (mask))

/**
 * Set a bit or bits.
 * 
 * @Note    This changes the variable!
 * @param   b The variable to set the bit(s) in
 * @param   mask The mask for setting the bit(s)
 * @Example <code>bitSet(x, 8); // Set bit 3 (0b00001000) in variable x\n
 * bitSet(x, 7); // Set bits 0-2 (0b00000111) in variable x\n
 * bitSet(x, bitMask(5)); // Set the value of bit 5 (0b00100000) in variable x
 * </code>
 */
#define bitSet(b, mask)   ((p) |= (mask))

/**
 * Clear a bit or bits.
 * 
 * @Note    This changes the variable!
 * @param   b The variable to clear the bit(s) in
 * @param   mask The mask for clearing the bit(s)
 * @Example <code>bitClear(x, 8); // Clear bit 3 (0b00001000) of variable x\n
 * bitClear(x, 7); // Clear bits 0-2 (0b00000111) of variable x\n
 * bitClear(x, bitMask(5)); // Clear the value of bit 5(0b00100000) of variable
 * x</code>
 */
#define bitClear(b, mask) ((b) &= (~(mask)))

/**
 * Flip/toggle a bit or bits.
 * 
 * @Note    This changes the variable!
 * @param   b The variable to flip the bit(s) in
 * @param   mask The mask for flipping the bit(s)
 * @Example <code>bitFlip(x, 8); // Flip bit 3 (0b00001000) of variable x\n
 * bitFlip(x, 7); // Flip bits 0-2 (0b00000111) of variable x\n
 * bitFlip(x, bitMask(5)); // Get the value of bit 5 (0b00100000) of variable x
 * </code>
 */
#define bitFlip(b, mask) ((b) ^= (mask))

/**
 * Shift a variable left.
 * 
 * @Note    This changes the variable!
 * @param   v The variable to shift left
 * @param   p Number of positions to shift the variable left
 * @Example <code>shiftLeft(x, 2); // Shift variable x 2 places left</code>
 */
#define shiftLeft(v, p) ((v) <<= (p))

/**
 * Shift a variable right.
 * 
 * @Note    This changes the variable!
 * @param   v The variable to shift right
 * @param   p Number of positions to shift the variable right
 * @Example <code>shiftRight(x, 2); // Shift variable x 2 places right</code>
 */
#define shiftRight(v, p) ((v) >>= (p))

/**
 * Shift a variable left without changing the variable.
 * 
 * @Note    This does not change the variable.
 * @param   v The variable to shift left
 * @param   p Number of positions to shift left
 * @Example <code>x = shiftLeftM(x, 2); // Shift 2 places left</code>
 */
#define shiftLeftM(v, p) ((v) << (p))

/**
 * Shift a variable right without changing the variable.
 * 
 * @Note    This does not change the variable.
 * @param   v The variable to shift right
 * @param   p Number of positions to shift right
 * @Example <code>x = shiftRightM(x, 2); // Shift 2 places right</code>
 */
#define shiftRightM(v, p) ((v) << (p))

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * Compute the sign of an integer.
 * 
 * @param   _v, variable of which to compute the sign
 * @return  boolean value of 1 (true) if the variable is positive, 0 else.
 */
bool
isPositive( int32_t const _v ) ;

/**
 * Detect if two integers have opposite signs.
 * 
 * @param   _x, first variable of which the signs need to be compared
 * @param   _y, second variable of which the signs need to be compared
 * @return  bool, true if the variables have opposite signs, false else
 */
bool
haveOppositeSigns( int32_t const _x, int32_t const _y );

/* Make sure the implementation below is used instead of a standard
 * implementation like in @ref stdlib.h
 */
#ifdef min
#undef min
#endif
/**
 * Compute the minimum of two integers without branching.
 * 
 * @param   _x First variable of which the minimum needs to be found.
 * @param   _y Second variable of which the minimum needs to be found.
 * @return  int32_t The minimum value, _x or _y.
 */
int32_t
min( int32_t const _x, int32_t const _y );

/* Make sure the implementation below is used instead of a standard
 * implementation like in @ref stdlib.h
 */
#ifdef max
#undef max
#endif
/**
 * Compute the maximum of two integers without branching.
 * 
 * @param   _x First variable of which the maximum needs to be found.
 * @param   _y Second variable of which the maximum needs to be found.
 * @return  int32_t The maximum value, _x or _y.
 */
int32_t
max( int32_t const _x, int32_t const _y );

/**
 * Determining if an integer is a power of 2
 * 
 * @param   _v, variable of which to check if it is a power of two
 * @return  bool, true if _v is a power of to, false else
 */
bool
isPowerOf2( int32_t const _v );

/**
 * Conditionally set or clear bits without branching.
 * 
 * @param   _v, pointer to the variable of which to set or clear bits
 * @param   _mask, bit mask for setting or clearing bits
 * @param   _f, flag whether the flag needs to be set or cleared (1 or 0)
 * @return  void
 */
void
modifyBits( uint32_t *_v, uint32_t const _mask, bool const _f );

/**
 * Merge bits from two values according to a mask.
 * 
 * @param   _x, variable to merge in non-masked bits
 * @param   _y, variable to merge in masked bits
 * @param   _mask, bit mask for setting or clearing bits
 * @return  uint32_t, result of the merged variables _x and _y
 */
uint32_t
mergeBits( uint32_t const _x, uint32_t const _y, uint32_t const _mask );

/**
 * Counting bits set.
 * 
 * @param   _v, variable of which to check how much bits are set
 * @return  uint8_t, number of bits set in _v
 */
uint8_t
nBitsSet( int32_t const _v );

/**
 * Compute parity of word with a multiply.
 * 
 * @param   _v, variable of which to compute the parity
 * @return  bool, true if _v is odd, false else
 */
bool
isEven( uint32_t const _v );

/**
 * Reverse an N-bit quantity in parallel in 5 * lg(N) operations. Now set to
 * reverse the bit order of an 32 bit unsigned integer.
 * 
 * @param   _v, pointer to the variable of which the bit order needs to be
 * reversed
 * @return  void
 */
void
reverseBitOrder( uint32_t *_v );

/**
 * Round up to the next highest power of 2 by float casting.
 * 
 * @param   _v, pointer to the variable of which needs to be round up to the
 * next power of 2
 * @return  uint16_t, the next power of 2
 */
uint32_t
roundUpToPowerOf2( uint32_t const _v );

#ifdef	__cplusplus
}
#endif

#endif	/* BITOPERATIONS_H */
/* End of file BitOperations.h */
