/*******************************************************************************
 * Begin of file LedCube.c
 * Author: jdebruijn
 * Created on June 22, 2015, 8:15 AM
 * 
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 * 
 * Copyright (c) 2015 Jeroen de Bruijn <vidavidorra@gmail.com>
 * 
 * This file is part of LedCube which is released under The MIT License (MIT).
 * For full license details see file "main.c" or "LICENSE.md" or go to
 * https://opensource.org/licenses/MIT
 * 
*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Controls the whole LedCube.
 * 
 * All 512 RGB LEDs are (indirectly) controlled by this file.
 * 
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "LedCube.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
void
LedCube_init( void ) {
    LayerControl_init();
    CubeControlData_init(pCubeControlData);
    
    DEBUG_PRINTF_FUNCTION_INITIALIZE_COMPLETE();
    return;
}

void
LedCube_setPixel( uint8_t const _x, uint8_t const _y, uint8_t const _z,
        uint8_t const _red, uint8_t const _green, uint8_t const _blue ) {
    DEBUG_PRINTF_FUNCTION_CALL("%u, %u, %u, %u, %u, %u", \
            _x, _y, _z, _red, _green, _blue);
    
    /********** Check conditions **********************************************/
    /* X, y, z positions within range */
    ASSERT( LEDCUBE_MIN_XYZ <= _x && \
            LEDCUBE_MAX_XYZ >= _x );
    ASSERT( LEDCUBE_MIN_XYZ <= _y && \
            LEDCUBE_MAX_XYZ >= _y );
    ASSERT( LEDCUBE_MIN_XYZ <= _z && \
            LEDCUBE_MAX_XYZ >= _z );
    /* Intensities within range */
    ASSERT( LEDCUBE_MIN_INTENSITY <= _red && \
            LEDCUBE_MAX_INTENSITY >= _red );
    ASSERT( LEDCUBE_MIN_INTENSITY <= _green && \
            LEDCUBE_MAX_INTENSITY >= _green );
    ASSERT( LEDCUBE_MIN_INTENSITY <= _blue && \
            LEDCUBE_MAX_INTENSITY >= _blue );
    
    /********** Calculate position ********************************************/
    /* _x Ranges from 0 to 7 and selects the row, 0 for the back row and
     * 7 for the front row.
     * _y Ranges from 0 to 7 and selects the column, 0 for the left column
     * and 7 for the right column.
     * _z Ranges from 0 to 7 and selects the layer, 0 for the bottom layer
     * and 7 for the top layer.
     * 
     * @Note    It's necessary that the variables where the colour values are
     * AND-ed with have the prefix UL, since an 32-bits number is needed for
     * further calculations.
     * 
     * Assume the LED intensity of 15 is written to a the LED in the first
     * column. Than the binary value of that LED's intensity will be 00001111.
     * Since a BAM of four bits is used the zero padding is not relevant.
     * This means that every BAM-round a value of 1 needs to be written to the
     * LED. As said earlier, if this is written to the fist column it should
     * look as the sample below the next paragraph.
     * So the first (rightmost) bit of the LED intensity does not need to be
     * shifted left since it is already in the right position. The second bit
     * (from the right) needs to be shifted 7 positions to the left since it is
     * in the second position and needs to be in the 9th. The third bit is needs
     * to be shifted 14 positions to the left since it is in the third position
     * and needs to be in the 17th. And so on...
     * Example:
     *  BAM-round: |  3   ||  2   ||  1   ||  0   |
     *             00000001000000010000000100000001
     *  LED intensity                             1 (same position)
     *                                    |      1  (7 positions to the left)
     *                            |             1   (14 positions to the left)
     *                    |                    1    (21 positions to the left)
     */
    pCubeData_t const pCubeDataWrite = pCubeControlData->pCubeDataWrite;
    (pCubeDataWrite + _z * CUBEDATA_MAX_Z_C + _x)->red |= \
            ((_red   & 0x01UL) << _y)        |
            ((_red   & 0x02UL) << (_y + 7))  |
            ((_red   & 0x04UL) << (_y + 14)) |
            ((_red   & 0x08UL) << (_y + 21));
    (pCubeDataWrite + _z * CUBEDATA_MAX_Z_C + _x)->green |= \
            ((_green & 0x01UL) << _y)        |
            ((_green & 0x02UL) << (_y + 7))  |
            ((_green & 0x04UL) << (_y + 14)) |
            ((_green & 0x08UL) << (_y + 21));
    (pCubeDataWrite + _z * CUBEDATA_MAX_Z_C + _x)->blue |= \
            ((_blue  & 0x01UL) << _y)        |
            ((_blue  & 0x02UL) << (_y + 7))  |
            ((_blue  & 0x04UL) << (_y + 14)) |
            ((_blue  & 0x08UL) << (_y + 21));
    
    return;
}

void
LedCube_update( void ) {
    DEBUG_PRINTF_FUNCTION_CALL();
    
    CubeControlData_switchCubeData(pCubeControlData);
    
    return;
}

void
LedCube_updateUsingCopy( void ) {
    DEBUG_PRINTF_FUNCTION_CALL();
    
    CubeControlData_copyCubeData(pCubeControlData->pCubeDataWrite,
            pCubeControlData->pCubeDataRead);
    
    return;
}

void
LedCube_resetData( void ) {
    DEBUG_PRINTF_FUNCTION_CALL();
    
    CubeControlData_resetCubeData(pCubeControlData->pCubeDataWrite);
    
    return;
}

void
LedCube_printHexWriteData( void ) {
    DEBUG_PRINTF_FUNCTION_CALL();
    
    CubeControlData_printHexCubeData(pCubeControlData->pCubeDataWrite);
    
    return;
}

void
LedCube_printHexReadData( void ) {
    DEBUG_PRINTF_FUNCTION_CALL();
    
    CubeControlData_printHexCubeData(pCubeControlData->pCubeDataRead);
    
    return;
}

/**
 * Helper function to print the bits in a byte, separated by spaces, with zero
 * padding.
 * @todo edit function documentation below this point.
 */
void
_helperPrintByte(const uint8_t _b) {
    DEBUG_PRINTF_FUNCTION_CALL();
    
    uint8_t i;
    for( i=8; i>0; i-- ) {
        Uart1_putc( ((_b >>(i-1)) & 0x01) + 48 ); Uart1_puts("  ");
    }
    
    return;
}

/**
 * Print the data of a single LedCube layer using Uartx_puts, Uartx_putc,
 * Uartx_putNum and _helperPrintByte functions.
 * 
// */
//void
//LedCube_printLayerData( const pLayerControlData_t _data,
//        const uint8_t _layer ) {
//    Uart1_puts("\nLayerControlData (layer "); Uart1_putNum(_layer, 10);
//    Uart1_puts(") :\n");
//    
//    Uart1_puts(" color:\t|_____red______|\t|_____green____|\t|_____blue_____|\n");
//    Uart1_puts(" colum:\t1  2  3  4  5  6  7  8\t1  2  3  4  5  6  7  8\t1  2  3  4  5  6  7  8\n");
//    
//    Uart1_puts("row 1: \t"); _helperPrintByte(_data->PanelData1.red_1);
//    Uart1_putc('\t'); _helperPrintByte(_data->PanelData1.green_1); Uart1_putc('\t');
//    _helperPrintByte(_data->PanelData1.blue_1); Uart1_putc('\n');
//    
//    Uart1_puts("row 2: \t"); _helperPrintByte(_data->PanelData1.red_2);
//    Uart1_putc('\t'); _helperPrintByte(_data->PanelData1.green_2); Uart1_putc('\t');
//    _helperPrintByte(_data->PanelData1.blue_2); Uart1_putc('\n');
//    
//    Uart1_puts("row 3: \t"); _helperPrintByte(_data->PanelData2.red_1);
//    Uart1_putc('\t'); _helperPrintByte(_data->PanelData2.green_1); Uart1_putc('\t');
//    _helperPrintByte(_data->PanelData2.blue_1); Uart1_putc('\n');
//   
//    Uart1_puts("row 4: \t"); _helperPrintByte(_data->PanelData2.red_2);
//    Uart1_putc('\t'); _helperPrintByte(_data->PanelData2.green_2); Uart1_putc('\t');
//    _helperPrintByte(_data->PanelData2.blue_2); Uart1_putc('\n');
//    
//    Uart1_puts("row 5: \t"); _helperPrintByte(_data->PanelData3.red_1);
//    Uart1_putc('\t'); _helperPrintByte(_data->PanelData3.green_1); Uart1_putc('\t');
//    _helperPrintByte(_data->PanelData3.blue_1); Uart1_putc('\n');
//    
//    Uart1_puts("row 6: \t"); _helperPrintByte(_data->PanelData3.red_2);
//    Uart1_putc('\t'); _helperPrintByte(_data->PanelData3.green_2); Uart1_putc('\t');
//    _helperPrintByte(_data->PanelData3.blue_2); Uart1_putc('\n');
//    
////    Uart1_puts("row 7: \t"); _helperPrintByte(_data->PanelData4.red_1);
////    Uart1_putc('\t'); _helperPrintByte(_data->PanelData4.green_1); Uart1_putc('\t');
////    _helperPrintByte(_data->PanelData4.blue_1); Uart1_putc('\n');
////    
////    Uart1_puts("row 8: \t"); _helperPrintByte(_data->PanelData4.red_2);
////    Uart1_putc('\t'); _helperPrintByte(_data->PanelData4.green_2); Uart1_putc('\t');
////    _helperPrintByte(_data->PanelData4.blue_2); Uart1_putc('\n');
//    
//    return;
//}
//
///**
// * Print the data of a single LedCube layer using the Uartx_putBits function.
// * 
// */
//void
//LedCube_printLayerDataVF( const pLayerControlData_t _data,
//        const uint8_t _layer ) {
//    const char begin = 'A';
//    const char end = 'Z';
//    const char splitColour = ',';
//    const char splitRow = '.';
//    
//    Uart1_putc(begin);
//    /* Row 0 */
//    Uart1_putBits(_data->PanelData1.red_1, 8); Uart1_putc(splitColour);
//    Uart1_putBits(_data->PanelData1.green_1, 8); Uart1_putc(splitColour);
//    Uart1_putBits(_data->PanelData1.blue_1, 8); Uart1_putc(splitRow);
//    /* Row 1 */
//    Uart1_putBits(_data->PanelData1.red_2, 8); Uart1_putc(splitColour);
//    Uart1_putBits(_data->PanelData1.green_2, 8); Uart1_putc(splitColour);
//    Uart1_putBits(_data->PanelData1.blue_2, 8); Uart1_putc(splitRow);
//    /* Row 2 */
//    Uart1_putBits(_data->PanelData2.red_1, 8); Uart1_putc(splitColour);
//    Uart1_putBits(_data->PanelData2.green_1, 8); Uart1_putc(splitColour);
//    Uart1_putBits(_data->PanelData2.blue_1, 8); Uart1_putc(splitRow);
//    /* Row 3 */
//    Uart1_putBits(_data->PanelData2.red_2, 8); Uart1_putc(splitColour);
//    Uart1_putBits(_data->PanelData2.green_2, 8); Uart1_putc(splitColour);
//    Uart1_putBits(_data->PanelData2.blue_2, 8); Uart1_putc(splitRow);
//    /* Row 4 */
//    Uart1_putBits(_data->PanelData3.red_1, 8); Uart1_putc(splitColour);
//    Uart1_putBits(_data->PanelData3.green_1, 8); Uart1_putc(splitColour);
//    Uart1_putBits(_data->PanelData3.blue_1, 8); Uart1_putc(splitRow);
//    /* Row 5 */
//    Uart1_putBits(_data->PanelData3.red_2, 8); Uart1_putc(splitColour);
//    Uart1_putBits(_data->PanelData3.green_2, 8); Uart1_putc(splitColour);
//    Uart1_putBits(_data->PanelData3.blue_2, 8); Uart1_putc(splitRow);
//    /* Row 6 */
////    Uart1_putBits(_data->PanelData4.red_1, 8); Uart1_putc(splitColour);
////    Uart1_putBits(_data->PanelData4.green_1, 8); Uart1_putc(splitColour);
////    Uart1_putBits(_data->PanelData4.blue_1, 8); Uart1_putc(splitRow);
////    /* Row 7 */
////    Uart1_putBits(_data->PanelData4.red_2, 8); Uart1_putc(splitColour);
////    Uart1_putBits(_data->PanelData4.green_2, 8); Uart1_putc(splitColour);
////    Uart1_putBits(_data->PanelData4.blue_2, 8);
//    Uart1_putc(end);
//    
//    return;
//}

/* End of file LedCube.c */
