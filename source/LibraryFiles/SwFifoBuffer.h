/*******************************************************************************
 * Begin of file SwFifoBuffer.h
 * Author: jdebruijn
 * Created on September 12, 2015, 10:05 AM
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
 * @brief Software FIFO buffer which can be used as storage for peripherals.
 * 
 * For example UART Tx and Rx data.
 * 
 ******************************************************************************/

#ifndef SWFIFOBUFFER_H
#define	SWFIFOBUFFER_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <xc.h>
#include <stdint.h>
#include "Interrupts.h"

/*******************************************************************************
 * Defines
 ******************************************************************************/
#define FIFO_BUFFER_SIZE    255     /**< Maximum characters in the buffer. */

/*******************************************************************************
 * Structures
 ******************************************************************************/
/**
 * @brief Structure representing a software FIFO buffer.
 * 
 * @note    The bufferFullFlag is the only flag that is not automatically
 * cleared by the software FIFO buffer.
 * @example <code>// Declare a receive software FIFO buffer
 * swFifoBuffer_t rxBuffer = { 0,0,0, {0}, 0,0,0 };</code>
 */
typedef struct {
    /********** Flags *********************************************************/
    /** This flag is automatically set and cleared by the software buffer */
    uint8_t bufferNotEmptyFlag;
    /** This flag is automatically set and cleared by the software buffer */
    uint8_t bufferFullFlag;
    /** This flag is not automatically cleared by the software buffer */
    uint8_t bufferOverflowFlag;
    
    /********** Buffer and Buffer control *************************************/
    /** The actual FIFO buffer. */
    char data[FIFO_BUFFER_SIZE];
    /** Index of oldest data byte in the buffer. */
    uint16_t iFirst;
    /** Index of newest data byte in the buffer. */
    uint16_t iLast;
    /** Number of bytes currently stored in the buffer. */
    uint16_t numBytes;
} swFifoBuffer_t, *pSwFifoBuffer_t;

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * @brief Put a single character in the FIFO buffer.
 * 
 * @param   _pBuffer Pointer to the buffer where the data is stored in.
 * @param   _inData Character to put in the buffer.
 */
void
swFifoBufferPut( pSwFifoBuffer_t _pBuffer, const char _inData );

/**
 * @brief Get a single character in the FIFO buffer.
 * 
 * @param   _pBuffer Pointer to the buffer where the data is stored in.
 * @return  char The character gotten from the buffer.
 */
char
swFifoBufferGet( pSwFifoBuffer_t _pBuffer );

#ifdef	__cplusplus
}
#endif

#endif	/* SWFIFOBUFFER_H */
/* End of file SwFifoBuffer.h */
