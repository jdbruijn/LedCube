/*******************************************************************************
 * Begin of file SwFifoBuffer.c
 * Author: jdebruijn
 * Created on September 12, 2015, 10:06 AM
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
 * @brief Software FIFO buffer which can be used as storage for peripherals.
 * 
 * For example UART Tx and Rx data.
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
 * 0. Checks if there is room in the software FIFO buffer;
 * 0. Automatically sets bufferOverflowFlag;
 * 0. Automatically handles bufferFullFlag;
 * 0. Automatically handles bufferNotEmptyFlag;
 * 0. Sets bufferOverflowFlag upon software FIFO buffer overflow (doesn't
 * overwrite existing data).
 * 
 */
void
swFifoBufferPut(pSwFifoBuffer_t _pBuffer, const char _inData)
{
    INTERRUPTS_DISSABLE_AND_SAVE_CPU_IPL;

    // Check if there is room in the buffer
    if (_pBuffer->numBytes == FIFO_BUFFER_SIZE) {
        _pBuffer->bufferOverflowFlag = 1;
    } else if (_pBuffer->numBytes < FIFO_BUFFER_SIZE) {
        _pBuffer->data[_pBuffer->iLast] = _inData;

        _pBuffer->iLast++;
        _pBuffer->numBytes++;
    }

    // Check if the buffer has just been filled up
    if (_pBuffer->numBytes == FIFO_BUFFER_SIZE) {
        _pBuffer->bufferFullFlag = 1;
    }

    // Check if the index needs to be rolled over
    if (_pBuffer->iLast == FIFO_BUFFER_SIZE) {
        _pBuffer->iLast = 0;
    }

    // Just put data in the buffer, so the buffer is not empty
    _pBuffer->bufferNotEmptyFlag = 1;

    INTERRUPTS_RESTORE_CPU_IPL;

    return;
}

/**
 * 0. Checks if data exists in the software FIFO buffer;
 * 0. Automatically handles bufferFullFlag;
 * 0. Automatically handles bufferNotEmptyFlag.
 * 
 */
char
swFifoBufferGet(pSwFifoBuffer_t _pBuffer)
{
    INTERRUPTS_DISSABLE_AND_SAVE_CPU_IPL;

    char outData = '\0';

    // Check if the buffer is full and handle the bufferFullFlag
    if (_pBuffer->numBytes == FIFO_BUFFER_SIZE) {
        _pBuffer->bufferFullFlag = 0;
    }

    // Check if there is data in the software FIFO buffer
    if (_pBuffer->numBytes > 0) {
        // Get the oldest element in the software FIFO buffer
        outData = _pBuffer->data[_pBuffer->iFirst];
        _pBuffer->iFirst++;
        _pBuffer->numBytes--;
    } else {
        // Handle bufferNotEmptyFlag
        _pBuffer->bufferNotEmptyFlag = 0;
    }

    // Check if the index needs to be rolled over
    if (_pBuffer->iFirst == FIFO_BUFFER_SIZE) {
        _pBuffer->iFirst = 0;
    }

    INTERRUPTS_RESTORE_CPU_IPL;

    return outData;
}
/* End of file SwFifoBuffer.c */
