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
 * For full license details see file "main.c" or "LICENSE.md" or go to
 * https://opensource.org/licenses/MIT
 * 
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 * 
 * Description:
 *  Software FIFO buffer which can be used as storage for peripherals.
 *  (For example to store UART Tx and Rx data.)
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

/*******************************************************************************
 * Defines
 ******************************************************************************/
#define FIFO_BUFFER_SIZE            255     // Maximum characters in the buffer

/*******************************************************************************
 * Structures
 ******************************************************************************/
/**
 * Structure representing a software FIFO buffer.
 * 
 * @Note    The bufferFullFlag is the only flag that is not automatically
 * cleared by the software FIFO buffer.
 * @Example <code>// Declare a receive software FIFO buffer
 * swFifoBuffer_t rxBuffer = { 0,0,0, {0}, 0,0,0 };</code>
 */
typedef struct {
    /********** Flags *********************************************************/
    /* This flag is automatically set and cleared by the software buffer */
    uint8_t bufferNotEmptyFlag;
    /* This flag is automatically set and cleared by the software buffer */
    uint8_t bufferFullFlag;
    /* This flag is not automatically cleared by the software buffer */
    uint8_t bufferOverflowFlag;
    
    /********** Buffer and Buffer control *************************************/
    char data[FIFO_BUFFER_SIZE];    // The actual FIFO buffer
    uint16_t iFirst;                // Index of oldest data byte in the buffer
    uint16_t iLast;                 // Index of newest data byte in the buffer
    uint16_t numBytes;              // Number of bytes currently in the buffer
} swFifoBuffer_t, *pSwFifoBuffer_t;

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * Put a single character in the FIFO buffer.
 * 
 * @param   _pBuffer Pointer to the buffer where the data is stored in.
 * @param   _inData Character to put in the buffer.
 * @return  void
 * @Example <code>FifoBuffer_t rxBuffer = { 0,0,0, {0}, 0,0,0};
 * pSwFifoBuffer_t pRxBuffer = &rxBuffer;
 * FIFOBufferPut(pRxBuffer, U1RXREG);</code>
 */
void
swFifoBufferPut( pSwFifoBuffer_t _pBuffer, const char _inData );

/**
 * Get a single character in the FIFO buffer.
 * 
 * @param   _pBuffer Pointer to the buffer where the data is stored in.
 * @return  char The character gotten from the buffer.
 * @Example <code>FifoBuffer_t rxBuffer = { 0,0,0, {0}, 0,0,0};
 * pSwFifoBuffer_t pRxBuffer = &rxBuffer;
 * char rxData = FIFOBufferGet(pRxBuffer);</code>
 */
char
swFifoBufferGet( pSwFifoBuffer_t _pBuffer );

#ifdef	__cplusplus
}
#endif

#endif	/* SWFIFOBUFFER_H */
/* End of file SwFifoBuffer.h */
