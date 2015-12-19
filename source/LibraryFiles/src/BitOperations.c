/*******************************************************************************
 * Begin of file BitOperations.c
 * Author: jdebruijn
 * Created on October 5, 2015, 9:00 AM
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
 * 
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "BitOperations.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
bool
isPositive(int32_t const _v) {
    return (1 ^ ((unsigned int)_v >> (sizeof (int) * CHAR_BIT - 1)));
}

bool
haveOppositeSigns(int32_t const _x, int32_t const _y) {
    return ((_x ^ _y) < 0);
}

int32_t
min(int32_t const _x, int32_t const _y) {
    return (_y ^ ((_x ^ _y) & -(_x < _y)));
}

int32_t
max(int32_t const _x, int32_t const _y) {
    return (_x ^ ((_x ^ _y) & -(_x < _y)));
}

bool
isPowerOf2(int32_t const _v) {
    return (_v && !(_v & (_v - 1)));
}

void
modifyBits(uint32_t *_v, uint32_t const _mask, bool const _f) {
    *_v ^= (-_f ^*_v) & _mask;

    return;
}

uint32_t
mergeBits(uint32_t const _x, uint32_t const _y, uint32_t const _mask) {
    return (_x ^((_x ^_y) & _mask));
}

uint8_t
nBitsSet(int32_t const _v) {
    uint8_t result;
    result = ((_v & 0xfff) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1F;
    result += (((_v & 0xfff000) >> 12) * 0x1001001001001ULL & \
            0x84210842108421ULL) % 0x1f;
    result += ((_v >> 24) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1F;

    return (result);
}

bool
isEven(uint32_t const _v) {
    uint32_t v = _v;
    v ^= v >> 1;
    v ^= v >> 2;
    v = (v & 0x11111111U) * 0x11111111U;

    return ((v >> 28) & 1);
}

void
reverseBitOrder(uint32_t *_v) {
    // swap odd and even bits
    *_v = ((*_v >> 1) & 0x55555555) | ((*_v & 0x55555555) << 1);
    // swap consecutive pairs
    *_v = ((*_v >> 2) & 0x33333333) | ((*_v & 0x33333333) << 2);
    // swap nibbles ...
    *_v = ((*_v >> 4) & 0x0F0F0F0F) | ((*_v & 0x0F0F0F0F) << 4);
    // swap bytes
    *_v = ((*_v >> 8) & 0x00FF00FF) | ((*_v & 0x00FF00FF) << 8);
    // swap 2-byte long pairs
    *_v = (*_v >> 16) | (*_v << 16);

    return;
}

uint32_t
roundUpToPowerOf2(uint32_t const _v) {
    if (_v > 1) {
        float f = (float)_v;
        uint32_t const t = 1U << ((*(uint32_t *) & f >> 23) - 0x7F);
        return (t << (t < _v));
    } else {
        return (1);
    }
}
/* End of file BitOperations.c */
