/*******************************************************************************
 * Begin of file SwFifoBuffer.c
 * Author: jdebruijn
 * Created on September 12, 2015, 10:06 AM
 * 
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 * 
 * Copyright (c) 2015 Jeroen de Bruijn <vidavidorra@gmail.com>
 * 
 * This file is part of LedCube which is released under The MIT License (MIT).
 * For full license details see file "main.c" or "LICENSE.md" or go to
 * https://opensource.org/licenses/MIT
 * 
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "SwFifoBuffer.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
/**
 * Checks if there is room in the software FIFO buffer;
 * Automatically sets bufferOverflowFlag;
 * Automatically handles bufferFullFlag;
 * Automatically handles bufferNotEmptyFlag;
 * Sets bufferOverflowFlag upon software FIFO buffer overflow (doesn't overwrite
 * existing data).
 * 
 */
void
swFifoBufferPut( pSwFifoBuffer_t _pBuffer, const char _inData ) {
    uint16_t cpuIntPrio = 0;
    SET_AND_SAVE_CPU_IPL(cpuIntPrio, 7);
    // @todo Improve disabling interrupts
    
    // Check if there is room in the buffer
    if( _pBuffer->numBytes == FIFO_BUFFER_SIZE ) {
        _pBuffer->bufferOverflowFlag = 1;
        // @todo Handle overflow error. Remove all received data, or ...?
//        Uart1_puts("\nSoftware FIFO buffer: an overflow has occurred!\n");
    }
    else if( _pBuffer->numBytes < FIFO_BUFFER_SIZE ) {
        _pBuffer->data[_pBuffer->iLast] = _inData;
        
        _pBuffer->iLast++;
        _pBuffer->numBytes++;
    }
    
    // Check if the buffer has just been filled up
    if( _pBuffer->numBytes == FIFO_BUFFER_SIZE ) {
        _pBuffer->bufferFullFlag = 1;
    }
    
    // Check if the index needs to be rolled over
    if( _pBuffer->iLast == FIFO_BUFFER_SIZE ) {
        _pBuffer->iLast = 0;
    }
    
    // Just put data in the buffer, so the buffer is not empty
    _pBuffer->bufferNotEmptyFlag = 1;
    
    RESTORE_CPU_IPL(cpuIntPrio);
    
    return;
}

/**
 * Checks if data exists in the software FIFO buffer;
 * Automatically handles bufferFullFlag;
 * Automatically handles bufferNotEmptyFlag;
 * 
 */
char
swFifoBufferGet( pSwFifoBuffer_t _pBuffer ) {
    char outData = '\0';
    
    uint16_t cpuIntPrio = 0;
    SET_AND_SAVE_CPU_IPL(cpuIntPrio, 7);
    // @todo Improve disabling interrupts.
    
    // Check if the buffer is full and handle the bufferFullFlag
    if( _pBuffer->numBytes == FIFO_BUFFER_SIZE ) {
        _pBuffer->bufferFullFlag = 0;
    }
    
    // Check if there is data in the software FIFO buffer
    if( _pBuffer->numBytes > 0 ) {
        // Get the oldest element in the software FIFO buffer
        outData = _pBuffer->data[_pBuffer->iFirst];
        _pBuffer->iFirst++;
        _pBuffer->numBytes--;
    }
    else {
        // Handle bufferNotEmptyFlag
        _pBuffer->bufferNotEmptyFlag = 0;
    }
    
    // Check if the index needs to be rolled over
    if( _pBuffer->iFirst == FIFO_BUFFER_SIZE ) {
        _pBuffer->iFirst = 0;
    }
    
    RESTORE_CPU_IPL(cpuIntPrio);
    
    return outData;
}

/* End of file SwFifoBuffer.c */
