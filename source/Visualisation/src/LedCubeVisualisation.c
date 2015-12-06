/*******************************************************************************
 * Begin of file LedCubeVisualisation.c
 * Author: jdebruijn
 * Created on December 6, 2015, 10:45 AM
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "LedCubeVisualisation.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
void
LedCubeVisualisation_sendVersion( void ) {
    LCV_START_TRANSMISSION_AND_BLOCK();
    
    LCV_SEND_STR(VERSION_STRING);
    
    LCV_END_TRANSMISSION_AND_BLOCK();
    
    return;
}

void
LedCubeVisualisation_sendRow( uint8_t _x, uint8_t _z,
                              pCubeData_t const _pCubeData ) {    
    uint8_t y;
    for(y = 0; y < CUBEDATA_MAX_Y_C; y++) {
        LCV_START_BLOCK();
        
        LCV_SEND_HEX_NUM(_x);
        LCV_SEND_HEX_NUM(y);
        LCV_SEND_HEX_NUM(_z);
        
        LCV_SEND_HEX_NUM(                                                      \
        (((_pCubeData + _z * CUBEDATA_MAX_Z_C +_x)->red >> y)          & 0x01) | 
        (((_pCubeData + _z * CUBEDATA_MAX_Z_C +_x)->red >> (y + 7))    & 0x02) |
        (((_pCubeData + _z * CUBEDATA_MAX_Z_C +_x)->red >> (y + 14))   & 0x04) |
        (((_pCubeData + _z * CUBEDATA_MAX_Z_C +_x)->red >> (y + 21))   & 0x08));
        
        LCV_SEND_HEX_NUM(                                                      \
        (((_pCubeData + _z * CUBEDATA_MAX_Z_C +_x)->green >> y)        & 0x01) | 
        (((_pCubeData + _z * CUBEDATA_MAX_Z_C +_x)->green >> (y + 7))  & 0x02) |
        (((_pCubeData + _z * CUBEDATA_MAX_Z_C +_x)->green >> (y + 14)) & 0x04) |
        (((_pCubeData + _z * CUBEDATA_MAX_Z_C +_x)->green >> (y + 21)) & 0x08));
        
        LCV_SEND_HEX_NUM(                                                      \
        (((_pCubeData + _z * CUBEDATA_MAX_Z_C +_x)->blue >> y)         & 0x01) | 
        (((_pCubeData + _z * CUBEDATA_MAX_Z_C +_x)->blue >> (y + 7))   & 0x02) |
        (((_pCubeData + _z * CUBEDATA_MAX_Z_C +_x)->blue >> (y + 14))  & 0x04) |
        (((_pCubeData + _z * CUBEDATA_MAX_Z_C +_x)->blue >> (y + 21))  & 0x08));
        
        LCV_END_BLOCK();
    }
    
    return;
}

void
LedCubeVisualisation_sendLayer( uint8_t _z,
                                pCubeData_t const _pCubeData ) {
    uint8_t x;
    
    for(x = 0; x < CUBEDATA_MAX_X_C; x++) {
        LedCubeVisualisation_sendRow(x, _z, _pCubeData);
    }
    
    return;
}

void
LedCubeVisualisation_sendCubeData( pCubeData_t const _pCubeData ) {
    uint8_t z;
    
    LCV_START_TRANSMISSION();
    
    for(z = 0; z < CUBEDATA_MAX_Z_C; z++) {
        LedCubeVisualisation_sendLayer(z, _pCubeData);
    }
    
    LCV_END_TRANSMISSION();
    
    return;
}

/* End of file LedCubeVisualisation.c */
