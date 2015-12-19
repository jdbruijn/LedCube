/*******************************************************************************
 * Begin of file Fill.c
 * Author: jdebruijn
 * Created on November 8, 2015, 12:29 PM
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
 * @brief Animations to fill a row, layer or whole LED cube.
 * 
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "Fill.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
void
FillRowAtOnceWithSingleColour(uint8_t _x, uint8_t _z,
                              uint8_t _red, uint8_t _green, uint8_t _blue) {
    DEBUG_PRINTF_FUNCTION_CALL("%u, %u, %u, %u, %u", _x, _z,
            _red, _green, _blue);

    uint8_t y;
    for (y = 0; y < CUBEDATA_MAX_Y_C; y++) {
        LedCube_setPixel(_x, y, _z, _red, _green, _blue);
    }

    return;
}

void
FillRowWithSingleColour(uint8_t _x, uint8_t _z,
                        uint8_t _red, uint8_t _green, uint8_t _blue) {
    DEBUG_PRINTF_FUNCTION_CALL("%u, %u, %u, %u, %u", _x, _z,
            _red, _green, _blue);

    uint8_t y;
    for (y = 0; y < CUBEDATA_MAX_Y_C; y++) {
        LedCube_setPixel(_x, y, _z, _red, _green, _blue);
        LedCube_updateUsingCopy();
        Delay_ms(100);
    }

    return;
}

void
FillLayerAtOnceWithSingleColour(uint8_t _z,
                                uint8_t _red, uint8_t _green, uint8_t _blue) {
    DEBUG_PRINTF_FUNCTION_CALL("%u, %u, %u, %u", _z, _red, _green, _blue);

    uint8_t x;
    for (x = 0; x < CUBEDATA_MAX_X_C; x++) {
        FillRowAtOnceWithSingleColour(x, _z, _red, _green, _blue);
    }

    return;
}

void
FillLayerWithSingleColour(uint8_t _z,
                          uint8_t _red, uint8_t _green, uint8_t _blue) {
    DEBUG_PRINTF_FUNCTION_CALL("%u, %u, %u, %u", _z, _red, _green, _blue);

    uint8_t x;
    for (x = 0; x < CUBEDATA_MAX_X_C; x++) {
        FillRowWithSingleColour(x, _z, _red, _green, _blue);
    }

    return;
}
/* End of file Fill.c */
