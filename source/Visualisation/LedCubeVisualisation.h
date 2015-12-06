/*******************************************************************************
 * Begin of file LedCubeVisualisation.h
 * Author: jdebruijn
 * Created on December 6, 2015, 10:43 AM
 * 
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 * 
 * Copyright (c) 2015 Jeroen de Bruijn <vidavidorra@gmail.com>
 * 
 * This file is part of LedCube which is released under The MIT License (MIT).
 * For full license details see file "main.c" or "LICENSE" or go to
 * https://opensource.org/licenses/MIT
 * 
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Data protocol and functions for connection with the LedCube
 * Visualisation software.
 * 
 ******************************************************************************/

#ifndef LEDCUBEVISUALISATION_H
#define	LEDCUBEVISUALISATION_H

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
 * Macros
 ******************************************************************************/
/** @brief Wrapper for LCV_SEND_CHAR to a actual function, in this case @ref
 *  Uart1_putc.
 */
#define LCV_SEND_CHAR(c) Uart1_putc(c)

/** @brief Wrapper for LCV_SEND_STR to a actual function, in this case @ref
 *  Uart1_puts.
 */
#define LCV_SEND_STR(s) Uart1_puts(s)

/** @brief Wrapper for LCV_SEND_HEX_NUM to a actual function, in this case @ref
 *  Uart1_putNum.
 *  This does send the number in hexadecimal form without the 'h'
 *  suffix.
 */
#define LCV_SEND_HEX_NUM(s) Uart1_putNum(s, 16, false)

/** @brief Macro for starting a transmission. */
#define LCV_START_TRANSMISSION() LCV_SEND_CHAR(LCV_START_TRANSMISSION_CHAR)

/** @brief Macro for ending a transmission. */
#define LCV_END_TRANSMISSION() LCV_SEND_CHAR(LCV_END_TRANSMISSION_CHAR)

/** @brief Macro for starting a block. */
#define LCV_START_BLOCK() LCV_SEND_CHAR(LCV_START_BLOCK_CHAR)

/** @brief Macro for ending a block. */
#define LCV_END_BLOCK() LCV_SEND_CHAR(LCV_END_BLOCK_CHAR)

/** @brief Macro for starting a transmission and a block. */
#define LCV_START_TRANSMISSION_AND_BLOCK()  \
            LCV_START_TRANSMISSION();       \
            LCV_START_BLOCK()

/** @brief Macro for ending a transmission and a block. */
#define LCV_END_TRANSMISSION_AND_BLOCK()    \
            LCV_END_BLOCK();                \
            LCV_END_TRANSMISSION()

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * @brief Send the LedCube software version data.
 */
void
LedCubeVisualisation_sendVersion( void );

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
LedCubeVisualisation_sendRow( uint8_t _x, uint8_t _z,
                              pCubeData_t const _pCubeData );
/**
 * @brief Send the CubeData of a single layer.
 * 
 * @param   _z Selects the layer. Ranges from 0 to @ref LEDCUBE_MAX_XYZ, 0 for
 * the bottom layer and @ref LEDCUBE_MAX_XYZ for the top layer.
 * @param   _pCubeControlData Pointer to a CubeControlData structure.
 */
void
LedCubeVisualisation_sendLayer( uint8_t _z,
                                pCubeData_t const _pCubeData );
/**
 * @brief Send the CubeData of a whole Cube.
 * 
 * @param   _pCubeControlData Pointer to a CubeControlData structure.
 */
void
LedCubeVisualisation_sendCubeData( pCubeData_t const _pCubeData );

#ifdef	__cplusplus
}
#endif

#endif	/* LEDCUBEVISUALISATION_H */
/* End of file LedCubeVisualisation.h */
