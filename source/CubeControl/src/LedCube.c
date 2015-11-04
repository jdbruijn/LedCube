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
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "LedCube.h"

/*******************************************************************************
 * Global variables
 ******************************************************************************/
uint8_t _pArray[8][3] = {
#if 0
/*  |red |green |blue | */
/*   \  / \    / \   /  */
    {0x01, 0x02, 0x03}, /* row 1 */
    {0x04, 0x05, 0x06}, /* row 2 */
    {0x07, 0x08, 0x09}, /* row 3 */
    {0x0A, 0x0B, 0x0C}, /* row 4 */
    {0x0D, 0x0E, 0x0F}, /* row 5 */
    {0x10, 0x11, 0x12}, /* row 6 */
    {0x13, 0x14, 0x15}, /* row 7 */
    {0x16, 0x17, 0x18}  /* row 8 */
#else
    {0x00, 0x00, 0x00}, /* row 1 */
    {0x00, 0x00, 0x00}, /* row 2 */
    {0x00, 0x00, 0x00}, /* row 3 */
    {0x00, 0x00, 0x00}, /* row 4 */
    {0x00, 0x00, 0x00}, /* row 5 */
    {0x00, 0x00, 0x00}, /* row 6 */
    {0x00, 0x00, 0x00}, /* row 7 */
    {0x00, 0x00, 0x00}  /* row 8 */
#endif
};

//CubeControlData_t CubeData = {
//     /*               |  Panel 1  | |  panel 2  | |  panel 3  | |  panel 4  | */
//    {/* LayerData0 */ {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0} },
//    {/* LayerData1 */ {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0} },
//    {/* LayerData2 */ {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0} },
//    {/* LayerData3 */ {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0} },
//    {/* LayerData4 */ {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0} },
//    {/* LayerData5 */ {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0} },
//    {/* LayerData6 */ {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0} },
//    {/* LayerData7 */ {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0} },
//    {/* CubeData */
//        /*            | row 0 | | row 1 | | row 2 | | row 3 | (x-value) */
//      { /* Layer 0 */ { 0,0,0 },{ 0,0,0 },{ 0,0,0 },{ 0,0,0 },
//        /*            | row 4 | | row 5 | | row 6 | | row 7 | (x-value) */
//                      { 0,0,0 },{ 0,0,0 },{ 0,0,0 },{ 0,0,0 },
//      },
//        /*             |  red   | |  green | |  blue  | */
//      { /* Layer 1 */ {0x00000000,0x00000000,0x00000000},
//        /*    BAM round: |  0   ||  1   ||  2   ||  3   | */
//                      {0b00000000000000000000000000000000, 0,0},
//        /*               |      ||      ||      ||      | */
//        /*    Column:    76543210765432107654321076543210 (y-value) */
//                      {0b00000000000000000000000000000000, 0,0},{0,0,0},
//                      {0,0,0},{0,0,0},{0,0,0},{0,0,0},
//      },
//      { /* Layer 2 */ {0,0,0},{0,0,0},{0,0,0},{0,0,0},
//            {0,0,0},{0,0,0},{0,0,0},{0,0,0} },
//      { /* Layer 3 */ {0,0,0},{0,0,0},{0,0,0},{0,0,0},
//            {0,0,0},{0,0,0},{0,0,0},{0,0,0} },
//      { /* Layer 4 */ {0,0,0},{0,0,0},{0,0,0},{0,0,0},
//            {0,0,0},{0,0,0},{0,0,0},{0,0,0} },
//      { /* Layer 5 */ {0,0,0},{0,0,0},{0,0,0},{0,0,0},
//            {0,0,0},{0,0,0},{0,0,0},{0,0,0} },
//      { /* Layer 6 */ {0,0,0},{0,0,0},{0,0,0},{0,0,0},
//            {0,0,0},{0,0,0},{0,0,0},{0,0,0} },
//      { /* Layer 7 */ {0,0,0},{0,0,0},{0,0,0},{0,0,0},
//            {0,0,0},{0,0,0},{0,0,0},{0,0,0} }
//    }
//};
//const pCubeControlData_t pCubeData = &CubeData;

/*******************************************************************************
 * Functions
 ******************************************************************************/
/**
 * Call the LayerControl's init function.
 * 
 */
void
LedCube_init( void ) {
    LayerControl_init();
    return;
}

/**
 * First asserting the boundaries of the cube, then map the current pixel in the
 * CubeData structure array.
 * 
 */
void
LedCube_setPixel( const pCubeData_t _pCubeData[],
        const uint8_t _x, const uint8_t _y, const uint8_t _z,
        const uint8_t _red, const uint8_t _green, const uint8_t _blue ) {
    DEBUG_PRINTF_FUNCTION_CALL("%p, %u, %u, %u, %u, %u, %u", *_pCubeData, \
            _x, _y, _z, _red, _green, _blue);
    
    /********** Check conditions **********************************************/
    /* X, y, z positions within range */
    assert( LEDCUBE_MIN_XYZ <= _x && \
            LEDCUBE_MAX_XYZ >= _x );
    assert( LEDCUBE_MIN_XYZ <= _y && \
            LEDCUBE_MAX_XYZ >= _y );
    assert( LEDCUBE_MIN_XYZ <= _z && \
            LEDCUBE_MAX_XYZ >= _z );
    /* Intensities within range */
    assert( LEDCUBE_MIN_INTENSITY <= _red && \
            LEDCUBE_MAX_INTENSITY >= _red );
    assert( LEDCUBE_MIN_INTENSITY <= _green && \
            LEDCUBE_MAX_INTENSITY >= _green );
    assert( LEDCUBE_MIN_INTENSITY <= _blue && \
            LEDCUBE_MAX_INTENSITY >= _blue );
    
    /********** Calculate position ********************************************/
    /**
     * _x Ranges from 0 to 7 and selects the row, 0 for the back row and
     * 8 for the front row.
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
    _pCubeData[_z][_x].red = ((_red & 0x01UL) << _y) |
            ((_red   & 0x02UL) << (_y + 7))  |
            ((_red   & 0x04UL) << (_y + 14)) |
            ((_red   & 0x08UL) << (_y + 21));
    _pCubeData[_z][_x].green = ((_green & 0x01UL) << _y) |
            ((_green & 0x02UL) << (_y + 7))  |
            ((_green & 0x04UL) << (_y + 14)) |
            ((_green & 0x08UL) << (_y + 21));
    _pCubeData[_z][_x].blue = ((_blue & 0x01UL) << _y) |
            ((_blue  & 0x02UL) << (_y + 7))  |
            ((_blue  & 0x04UL) << (_y + 14)) |
            ((_blue  & 0x08UL) << (_y + 21));
    
    Uart1_printf("LedCube_setPixel(%u, %u, %u,  %u, %u, %u)\n", _x, _y, _z, _red, _green, _blue);
//    Uart1_putBits(pCubeData2->CubeData[_z][_x].blue, 32); Uart1_putc('\n');
     
//    LedCube_printLayerDataVF( &pCubeData->LayerData0, 0);
    
    return;
}

/**
 * Move the LedCube's LED data from the array to a structure which is used for
 * refreshing the LedCube's output.
 * 
 */
void
LedCube_update( void ) {
    // <editor-fold defaultstate="collapsed" desc="Layer 0 array to struct">
//    /********** Layer 0 *******************************************************/
//#if 0
//    /* Layer 0, row 0 */
//    pCubeData->LayerData0.PanelData1.red_1      = _pArray[0][0];
//    pCubeData->LayerData0.PanelData1.green_1    = _pArray[0][1];
//    pCubeData->LayerData0.PanelData1.blue_1     = _pArray[0][2];
//    /* Layer 0, row 1 */
//    pCubeData->LayerData0.PanelData1.red_2      = _pArray[1][0];
//    pCubeData->LayerData0.PanelData1.green_2    = _pArray[1][1];
//    pCubeData->LayerData0.PanelData1.blue_2     = _pArray[1][2];
//    /* Layer 0, row 2 */
//    pCubeData->LayerData0.PanelData2.red_1      = _pArray[2][0];
//    pCubeData->LayerData0.PanelData2.green_1    = _pArray[2][1];
//    pCubeData->LayerData0.PanelData2.blue_1     = _pArray[2][2];
//    /* Layer 0, row 3 */
//    pCubeData->LayerData0.PanelData2.red_2      = _pArray[3][0];
//    pCubeData->LayerData0.PanelData2.green_2    = _pArray[3][1];
//    pCubeData->LayerData0.PanelData2.blue_2     = _pArray[3][2];
//    /* Layer 0, row 4 */
//    pCubeData->LayerData0.PanelData3.red_1      = _pArray[4][0];
//    pCubeData->LayerData0.PanelData3.green_1    = _pArray[4][1];
//    pCubeData->LayerData0.PanelData3.blue_1     = _pArray[4][2];
//    /* Layer 0, row 5 */
//    pCubeData->LayerData0.PanelData3.red_2      = _pArray[5][0];
//    pCubeData->LayerData0.PanelData3.green_2    = _pArray[5][1];
//    pCubeData->LayerData0.PanelData3.blue_2     = _pArray[5][2];
//    /* Layer 0, row 6 */
//    pCubeData->LayerData0.PanelData4.red_1      = _pArray[6][0];
//    pCubeData->LayerData0.PanelData4.green_1    = _pArray[6][1];
//    pCubeData->LayerData0.PanelData4.blue_1     = _pArray[6][2];
//    /* Layer 0, row 7 */
//    pCubeData->LayerData0.PanelData4.red_2      = _pArray[7][0];
//    pCubeData->LayerData0.PanelData4.green_2    = _pArray[7][1];
//    pCubeData->LayerData0.PanelData4.blue_2     = _pArray[7][2];
//#else
//    pCubeData->LayerData0.PanelData1.red_1      = (pCubeData->CubeData[0][0][0] & 0x000000FF);
////    pCubeData->LayerData0.PanelData1_1.red_1    = (pCubeData->CubeData[0][0][0] & 0x0000FF00) >> 8;
////    pCubeData->LayerData0.PanelData1_2.red_1    = (pCubeData->CubeData[0][0][0] & 0x00FF0000) >> 16;
////    pCubeData->LayerData0.PanelData1_3.red_1    = (pCubeData->CubeData[0][0][0] & 0xFF000000) >> 24;
//#endif
//    // </editor-fold>
//    
//    // <editor-fold defaultstate="collapsed" desc="Layer 1 array to struct">
//    /********** Layer 1 *******************************************************/
//    /* Layer 1, row 0 */
//    pCubeData->LayerData1.PanelData1.red_1      = _pArray[0][0];
//    pCubeData->LayerData1.PanelData1.green_1    = _pArray[0][1];
//    pCubeData->LayerData1.PanelData1.blue_1     = _pArray[0][2];
//    /* Layer 1, row 1 */
//    pCubeData->LayerData1.PanelData1.red_2      = _pArray[1][0];
//    pCubeData->LayerData1.PanelData1.green_2    = _pArray[1][1];
//    pCubeData->LayerData1.PanelData1.blue_2     = _pArray[1][2];
//    /* Layer 1, row 2 */
//    pCubeData->LayerData1.PanelData2.red_1      = _pArray[2][0];
//    pCubeData->LayerData1.PanelData2.green_1    = _pArray[2][1];
//    pCubeData->LayerData1.PanelData2.blue_1     = _pArray[2][2];
//    /* Layer 1, row 3 */
//    pCubeData->LayerData1.PanelData2.red_2      = _pArray[3][0];
//    pCubeData->LayerData1.PanelData2.green_2    = _pArray[3][1];
//    pCubeData->LayerData1.PanelData2.blue_2     = _pArray[3][2];
//    /* Layer 1, row 4 */
//    pCubeData->LayerData1.PanelData3.red_1      = _pArray[4][0];
//    pCubeData->LayerData1.PanelData3.green_1    = _pArray[4][1];
//    pCubeData->LayerData1.PanelData3.blue_1     = _pArray[4][2];
//    /* Layer 1, row 5 */
//    pCubeData->LayerData1.PanelData3.red_2      = _pArray[5][0];
//    pCubeData->LayerData1.PanelData3.green_2    = _pArray[5][1];
//    pCubeData->LayerData1.PanelData3.blue_2     = _pArray[5][2];
//    /* Layer 1, row 6 */
////    pCubeData->LayerData1.PanelData4.red_1      = _pArray[6][0];
////    pCubeData->LayerData1.PanelData4.green_1    = _pArray[6][1];
////    pCubeData->LayerData1.PanelData4.blue_1     = _pArray[6][2];
////    /* Layer 1, row 7 */
////    pCubeData->LayerData1.PanelData4.red_2      = _pArray[7][0];
////    pCubeData->LayerData1.PanelData4.green_2    = _pArray[7][1];
////    pCubeData->LayerData1.PanelData4.blue_2     = _pArray[7][2];
//    // </editor-fold>
//    
//    // <editor-fold defaultstate="collapsed" desc="Layer 2 array to struct">
//    /********** Layer 2 *******************************************************/
//    /* Layer 2, row 0 */
//    pCubeData->LayerData2.PanelData1.red_1      = _pArray[0][0];
//    pCubeData->LayerData2.PanelData1.green_1    = _pArray[0][1];
//    pCubeData->LayerData2.PanelData1.blue_1     = _pArray[0][2];
//    /* Layer 2, row 1 */
//    pCubeData->LayerData2.PanelData1.red_2      = _pArray[1][0];
//    pCubeData->LayerData2.PanelData1.green_2    = _pArray[1][1];
//    pCubeData->LayerData2.PanelData1.blue_2     = _pArray[1][2];
//    /* Layer 2, row 2 */
//    pCubeData->LayerData2.PanelData2.red_1      = _pArray[2][0];
//    pCubeData->LayerData2.PanelData2.green_1    = _pArray[2][1];
//    pCubeData->LayerData2.PanelData2.blue_1     = _pArray[2][2];
//    /* Layer 2, row 3 */
//    pCubeData->LayerData2.PanelData2.red_2      = _pArray[3][0];
//    pCubeData->LayerData2.PanelData2.green_2    = _pArray[3][1];
//    pCubeData->LayerData2.PanelData2.blue_2     = _pArray[3][2];
//    /* Layer 2, row 4 */
//    pCubeData->LayerData2.PanelData3.red_1      = _pArray[4][0];
//    pCubeData->LayerData2.PanelData3.green_1    = _pArray[4][1];
//    pCubeData->LayerData2.PanelData3.blue_1     = _pArray[4][2];
//    /* Layer 2, row 5 */
//    pCubeData->LayerData2.PanelData3.red_2      = _pArray[5][0];
//    pCubeData->LayerData2.PanelData3.green_2    = _pArray[5][1];
//    pCubeData->LayerData2.PanelData3.blue_2     = _pArray[5][2];
//    /* Layer 2, row 6 */
////    pCubeData->LayerData2.PanelData4.red_1      = _pArray[6][0];
////    pCubeData->LayerData2.PanelData4.green_1    = _pArray[6][1];
////    pCubeData->LayerData2.PanelData4.blue_1     = _pArray[6][2];
////    /* Layer 2, row 7 */
////    pCubeData->LayerData2.PanelData4.red_2       = _pArray[7][0];
////    pCubeData->LayerData2.PanelData4.green_2    = _pArray[7][1];
////    pCubeData->LayerData2.PanelData4.blue_2     = _pArray[7][2];
//    // </editor-fold>
//    
//    // <editor-fold defaultstate="collapsed" desc="Layer 3 array to struct">
//    /********** Layer 3 *******************************************************/
//    /* Layer 3, row 0 */
//    pCubeData->LayerData3.PanelData1.red_1      = _pArray[0][0];
//    pCubeData->LayerData3.PanelData1.green_1    = _pArray[0][1];
//    pCubeData->LayerData3.PanelData1.blue_1     = _pArray[0][2];
//    /* Layer 3, row 1 */
//    pCubeData->LayerData3.PanelData1.red_2      = _pArray[1][0];
//    pCubeData->LayerData3.PanelData1.green_2    = _pArray[1][1];
//    pCubeData->LayerData3.PanelData1.blue_2     = _pArray[1][2];
//    /* Layer 3, row 2 */
//    pCubeData->LayerData3.PanelData2.red_1      = _pArray[2][0];
//    pCubeData->LayerData3.PanelData2.green_1    = _pArray[2][1];
//    pCubeData->LayerData3.PanelData2.blue_1     = _pArray[2][2];
//    /* Layer 3, row 3 */
//    pCubeData->LayerData3.PanelData2.red_2      = _pArray[3][0];
//    pCubeData->LayerData3.PanelData2.green_2    = _pArray[3][1];
//    pCubeData->LayerData3.PanelData2.blue_2     = _pArray[3][2];
//    /* Layer 3, row 4 */
//    pCubeData->LayerData3.PanelData3.red_1      = _pArray[4][0];
//    pCubeData->LayerData3.PanelData3.green_1    = _pArray[4][1];
//    pCubeData->LayerData3.PanelData3.blue_1     = _pArray[4][2];
//    /* Layer 3, row 5 */
//    pCubeData->LayerData3.PanelData3.red_2      = _pArray[5][0];
//    pCubeData->LayerData3.PanelData3.green_2    = _pArray[5][1];
//    pCubeData->LayerData3.PanelData3.blue_2     = _pArray[5][2];
//    /* Layer 3, row 6 */
////    pCubeData->LayerData3.PanelData4.red_1      = _pArray[6][0];
////    pCubeData->LayerData3.PanelData4.green_1    = _pArray[6][1];
////    pCubeData->LayerData3.PanelData4.blue_1     = _pArray[6][2];
////    /* Layer 3, row 7 */
////    pCubeData->LayerData3.PanelData4.red_2      = _pArray[7][0];
////    pCubeData->LayerData3.PanelData4.green_2    = _pArray[7][1];
////    pCubeData->LayerData3.PanelData4.blue_2     = _pArray[7][2];
//    // </editor-fold>
//    
//    // <editor-fold defaultstate="collapsed" desc="Layer 4 array to struct">
//    /********** Layer 4 *******************************************************/
//    /* Layer 4, row 0 */
//    pCubeData->LayerData4.PanelData1.red_1      = _pArray[0][0];
//    pCubeData->LayerData4.PanelData1.green_1    = _pArray[0][1];
//    pCubeData->LayerData4.PanelData1.blue_1     = _pArray[0][2];
//    /* Layer 4, row 1 */
//    pCubeData->LayerData4.PanelData1.red_2      = _pArray[1][0];
//    pCubeData->LayerData4.PanelData1.green_2    = _pArray[1][1];
//    pCubeData->LayerData4.PanelData1.blue_2     = _pArray[1][2];
//    /* Layer 4, row 2 */
//    pCubeData->LayerData4.PanelData2.red_1      = _pArray[2][0];
//    pCubeData->LayerData4.PanelData2.green_1    = _pArray[2][1];
//    pCubeData->LayerData4.PanelData2.blue_1     = _pArray[2][2];
//    /* Layer 4, row 3 */
//    pCubeData->LayerData4.PanelData2.red_2      = _pArray[3][0];
//    pCubeData->LayerData4.PanelData2.green_2    = _pArray[3][1];
//    pCubeData->LayerData4.PanelData2.blue_2     = _pArray[3][2];
//    /* Layer 4, row 4 */
//    pCubeData->LayerData4.PanelData3.red_1      = _pArray[4][0];
//    pCubeData->LayerData4.PanelData3.green_1    = _pArray[4][1];
//    pCubeData->LayerData4.PanelData3.blue_1     = _pArray[4][2];
//    /* Layer 4, row 5 */
//    pCubeData->LayerData4.PanelData3.red_2      = _pArray[5][0];
//    pCubeData->LayerData4.PanelData3.green_2    = _pArray[5][1];
//    pCubeData->LayerData4.PanelData3.blue_2     = _pArray[5][2];
//    /* Layer 4, row 6 */
////    pCubeData->LayerData4.PanelData4.red_1      = _pArray[6][0];
////    pCubeData->LayerData4.PanelData4.green_1    = _pArray[6][1];
////    pCubeData->LayerData4.PanelData4.blue_1     = _pArray[6][2];
////    /* Layer 4, row 7 */
////    pCubeData->LayerData4.PanelData4.red_2      = _pArray[7][0];
////    pCubeData->LayerData4.PanelData4.green_2    = _pArray[7][1];
////    pCubeData->LayerData4.PanelData4.blue_2     = _pArray[7][2];
//    // </editor-fold>
//    
//    // <editor-fold defaultstate="collapsed" desc="Layer 5 array to struct">
//    /********** Layer 5 *******************************************************/
//    /* Layer 5, row 0 */
//    pCubeData->LayerData5.PanelData1.red_1      = _pArray[0][0];
//    pCubeData->LayerData5.PanelData1.green_1    = _pArray[0][1];
//    pCubeData->LayerData5.PanelData1.blue_1     = _pArray[0][2];
//    /* Layer 5, row 1 */
//    pCubeData->LayerData5.PanelData1.red_2      = _pArray[1][0];
//    pCubeData->LayerData5.PanelData1.green_2    = _pArray[1][1];
//    pCubeData->LayerData5.PanelData1.blue_2     = _pArray[1][2];
//    /* Layer 5, row 2 */
//    pCubeData->LayerData5.PanelData2.red_1      = _pArray[2][0];
//    pCubeData->LayerData5.PanelData2.green_1    = _pArray[2][1];
//    pCubeData->LayerData5.PanelData2.blue_1     = _pArray[2][2];
//    /* Layer 5, row 3 */
//    pCubeData->LayerData5.PanelData2.red_2      = _pArray[3][0];
//    pCubeData->LayerData5.PanelData2.green_2    = _pArray[3][1];
//    pCubeData->LayerData5.PanelData2.blue_2     = _pArray[3][2];
//    /* Layer 5, row 4 */
//    pCubeData->LayerData5.PanelData3.red_1      = _pArray[4][0];
//    pCubeData->LayerData5.PanelData3.green_1    = _pArray[4][1];
//    pCubeData->LayerData5.PanelData3.blue_1     = _pArray[4][2];
//    /* Layer 5, row 5 */
//    pCubeData->LayerData5.PanelData3.red_2      = _pArray[5][0];
//    pCubeData->LayerData5.PanelData3.green_2    = _pArray[5][1];
//    pCubeData->LayerData5.PanelData3.blue_2     = _pArray[5][2];
//    /* Layer 5, row 6 */
////    pCubeData->LayerData5.PanelData4.red_1      = _pArray[6][0];
////    pCubeData->LayerData5.PanelData4.green_1    = _pArray[6][1];
////    pCubeData->LayerData5.PanelData4.blue_1     = _pArray[6][2];
////    /* Layer 5, row 7 */
////    pCubeData->LayerData5.PanelData4.red_2      = _pArray[7][0];
////    pCubeData->LayerData5.PanelData4.green_2    = _pArray[7][1];
////    pCubeData->LayerData5.PanelData4.blue_2     = _pArray[7][2];
//    // </editor-fold>
//    
//    // <editor-fold defaultstate="collapsed" desc="Layer 6 array to struct">
//    /********** Layer 6 *******************************************************/
//    /* Layer 6, row 0 */
//    pCubeData->LayerData6.PanelData1.red_1      = _pArray[0][0];
//    pCubeData->LayerData6.PanelData1.green_1    = _pArray[0][1];
//    pCubeData->LayerData6.PanelData1.blue_1     = _pArray[0][2];
//    /* Layer 6, row 1 */
//    pCubeData->LayerData6.PanelData1.red_2      = _pArray[1][0];
//    pCubeData->LayerData6.PanelData1.green_2    = _pArray[1][1];
//    pCubeData->LayerData6.PanelData1.blue_2     = _pArray[1][2];
//    /* Layer 6, row 2 */
//    pCubeData->LayerData6.PanelData2.red_1      = _pArray[2][0];
//    pCubeData->LayerData6.PanelData2.green_1    = _pArray[2][1];
//    pCubeData->LayerData6.PanelData2.blue_1     = _pArray[2][2];
//    /* Layer 6, row 3 */
//    pCubeData->LayerData6.PanelData2.red_2      = _pArray[3][0];
//    pCubeData->LayerData6.PanelData2.green_2    = _pArray[3][1];
//    pCubeData->LayerData6.PanelData2.blue_2     = _pArray[3][2];
//    /* Layer 6, row 4 */
//    pCubeData->LayerData6.PanelData3.red_1      = _pArray[4][0];
//    pCubeData->LayerData6.PanelData3.green_1    = _pArray[4][1];
//    pCubeData->LayerData6.PanelData3.blue_1     = _pArray[4][2];
//    /* Layer 6, row 5 */
//    pCubeData->LayerData6.PanelData3.red_2      = _pArray[5][0];
//    pCubeData->LayerData6.PanelData3.green_2    = _pArray[5][1];
//    pCubeData->LayerData6.PanelData3.blue_2     = _pArray[5][2];
//    /* Layer 6, row 6 */
////    pCubeData->LayerData6.PanelData4.red_1      = _pArray[6][0];
////    pCubeData->LayerData6.PanelData4.green_1    = _pArray[6][1];
////    pCubeData->LayerData6.PanelData4.blue_1     = _pArray[6][2];
////    /* Layer 6, row 7 */
////    pCubeData->LayerData6.PanelData4.red_2      = _pArray[7][0];
////    pCubeData->LayerData6.PanelData4.green_2    = _pArray[7][1];
////    pCubeData->LayerData6.PanelData4.blue_2     = _pArray[7][2];
//    // </editor-fold>
//    
//    // <editor-fold defaultstate="collapsed" desc="Layer 7 array to struct">
//    /********** Layer 7 *******************************************************/
//    /* Layer 7, row 0 */
//    pCubeData->LayerData7.PanelData1.red_1      = _pArray[0][0];
//    pCubeData->LayerData7.PanelData1.green_1    = _pArray[0][1];
//    pCubeData->LayerData7.PanelData1.blue_1     = _pArray[0][2];
//    /* Layer 7, row 1 */
//    pCubeData->LayerData7.PanelData1.red_2      = _pArray[1][0];
//    pCubeData->LayerData7.PanelData1.green_2    = _pArray[1][1];
//    pCubeData->LayerData7.PanelData1.blue_2     = _pArray[1][2];
//    /* Layer 7, row 2 */
//    pCubeData->LayerData7.PanelData2.red_1      = _pArray[2][0];
//    pCubeData->LayerData7.PanelData2.green_1    = _pArray[2][1];
//    pCubeData->LayerData7.PanelData2.blue_1     = _pArray[2][2];
//    /* Layer 7, row 3 */
//    pCubeData->LayerData7.PanelData2.red_2      = _pArray[3][0];
//    pCubeData->LayerData7.PanelData2.green_2    = _pArray[3][1];
//    pCubeData->LayerData7.PanelData2.blue_2     = _pArray[3][2];
//    /* Layer 7, row 4 */
//    pCubeData->LayerData7.PanelData3.red_1      = _pArray[4][0];
//    pCubeData->LayerData7.PanelData3.green_1    = _pArray[4][1];
//    pCubeData->LayerData7.PanelData3.blue_1     = _pArray[4][2];
//    /* Layer 7, row 5 */
//    pCubeData->LayerData7.PanelData3.red_2      = _pArray[5][0];
//    pCubeData->LayerData7.PanelData3.green_2    = _pArray[5][1];
//    pCubeData->LayerData7.PanelData3.blue_2     = _pArray[5][2];
//    /* Layer 7, row 6 */
////    pCubeData->LayerData7.PanelData4.red_1      = _pArray[6][0];
////    pCubeData->LayerData7.PanelData4.green_1    = _pArray[6][1];
////    pCubeData->LayerData7.PanelData4.blue_1     = _pArray[6][2];
////    /* Layer 7, row 7 */
////    pCubeData->LayerData7.PanelData4.red_2      = _pArray[7][0];
////    pCubeData->LayerData7.PanelData4.green_2    = _pArray[7][1];
////    pCubeData->LayerData7.PanelData4.blue_2     = _pArray[7][2];
//    // </editor-fold>
//    
    return;
}

/**
 * Set all the data in the LedCube's LED data array to zero;
 * 
 */
void
LedCube_resetData( void ) {
#if 1
    uint8_t x, y;
    for(y=0;y<8;y++)
        for(x=0; x<3; x++)
            _pArray[y][x] = 0;
#else
    uint8_t x, z, colour;
    for( z = 0; z <= LEDCUBE_MAX_XYZ; z++ )
        for( x = 0; x <= LEDCUBE_MAX_XYZ; x++ )
            for( colour = 0; colour < 3; colour++ )
                pCubeData->CubeData[z][x][colour] = 0x00000000;
#endif
    
    return;
}

/**
 * Helper function to print the bits in a byte, separated by spaces, with zero
 * padding.
 * 
 */
void
_helperPrintByte(const uint8_t _b) {
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
