/*******************************************************************************
 * Begin of file LedCubeVisualisation.h
 * Author: jdebruijn
 * Created on December 6, 2015, 10:43 AM
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
 * @brief Data protocol and functions for connection with the LedCube
 * Visualisation software.
 * 
 ******************************************************************************/

#ifndef LEDCUBEVISUALISATION_H
#define LEDCUBEVISUALISATION_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "CubeControlData.h"
#include "Uart.h"
#include "Version.h"

/*******************************************************************************
 * Defines
 ******************************************************************************/
/** @brief Start of Header (SOH) character, decimal ASCII code 1 */
#define LCV_START_TRANSMISSION_CHAR 0x01
/** @brief End of Transmission (EOT) character, decimal ASCII code 4 */
#define LCV_END_TRANSMISSION_CHAR 0x04
/** @brief Start of Text (STX) character, decimal ASCII code 2 */
#define LCV_START_BLOCK_CHAR 0x02
/** @brief End of Transmission Block (ETB) character, decimal ASCII code 23 */
#define LCV_END_BLOCK_CHAR 0x17

/*******************************************************************************
 * Constant- and function macros
 ******************************************************************************/
/** @brief Wrapper for LCV_SEND_CHAR to a actual function, in this case @ref
 * uputc.
 */
#define LCV_SEND_CHAR(c)                                                       \
    uputc((c))

/** @brief Wrapper for LCV_SEND_STR to a actual function, in this case @ref
 * uputs.
 */
#define LCV_SEND_STR(s)                                                        \
    uputs((s))

/** @brief Wrapper for LCV_SEND_HEX_NUM to a actual function, in this case @ref
 * uputnum.
 * 
 * This does send the number in hexadecimal form without the 'h' suffix.
 */
#define LCV_SEND_HEX_NUM(s)                                                    \
    uputnum((s), 16, false)

/** @brief Macro for starting a transmission. */
#define LCV_START_TRANSMISSION                                                 \
    LCV_SEND_CHAR(LCV_START_TRANSMISSION_CHAR)

/** @brief Macro for ending a transmission. */
#define LCV_END_TRANSMISSION                                                   \
    LCV_SEND_CHAR(LCV_END_TRANSMISSION_CHAR)

/** @brief Macro for starting a block. */
#define LCV_START_BLOCK                                                        \
    LCV_SEND_CHAR(LCV_START_BLOCK_CHAR)

/** @brief Macro for ending a block. */
#define LCV_END_BLOCK                                                          \
    LCV_SEND_CHAR(LCV_END_BLOCK_CHAR)

/** @brief Macro for starting a transmission and a block. */
#define LCV_START_TRANSMISSION_AND_BLOCK                                       \
    LCV_START_TRANSMISSION;                                                    \
    LCV_START_BLOCK

/** @brief Macro for ending a transmission and a block. */
#define LCV_END_TRANSMISSION_AND_BLOCK                                         \
    LCV_END_BLOCK;                                                             \
    LCV_END_TRANSMISSION

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * @brief Send the LedCube software version data.
 */
void
LedCubeVisualisation_sendVersion(void);

/**
 * @brief Send the CubeData of a single row.
 * 
 * @param   _x Selects the row. Ranges from 0 to @ref LEDCUBE_MAX_XYZ, 0 for the
 * back row and @ref LEDCUBE_MAX_XYZ for the front row.
 * @param   _z Selects the layer. Ranges from 0 to @ref LEDCUBE_MAX_XYZ, 0 for
 * the bottom layer and @ref LEDCUBE_MAX_XYZ for the top layer.
 * @param   _pCubeControlData Pointer to a CubeControlData structure.
 */
void
LedCubeVisualisation_sendRow(uint8_t _x, uint8_t _z,
                             pCubeData_t const _pCubeData);
/**
 * @brief Send the CubeData of a single layer.
 * 
 * @param   _z Selects the layer. Ranges from 0 to @ref LEDCUBE_MAX_XYZ, 0 for
 * the bottom layer and @ref LEDCUBE_MAX_XYZ for the top layer.
 * @param   _pCubeControlData Pointer to a CubeControlData structure.
 */
void
LedCubeVisualisation_sendLayer(uint8_t _z,
                               pCubeData_t const _pCubeData);
/**
 * @brief Send the CubeData of a whole Cube.
 * 
 * @param   _pCubeControlData Pointer to a CubeControlData structure.
 */
void
LedCubeVisualisation_sendCubeData(pCubeData_t const _pCubeData);

#ifdef __cplusplus
}
#endif

#endif /* LEDCUBEVISUALISATION_H */
/* End of file LedCubeVisualisation.h */
