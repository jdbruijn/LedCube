/*******************************************************************************
 * Begin of file CubeControlData.c
 * Author: jdebruijn
 * Created on October 31, 2015, 11:34 AM
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
 * 
 * Declares and controls the data of the whole LED cube using several functions.
 * 
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "CubeControlData.h"

/*******************************************************************************
 * Global variables
 ******************************************************************************/
/** The global declaration of CubeControlData containing two CubeData structure
 * arrays of the type @ref RowData_t.
 * This is where all the data for the LED Cube is stored.
 */
CubeControlData_t CubeControlData = {
    { /* CubeData0 */
        { /* Layer 0 */
            /* Colour:    |  red   |  |  green |  |  blue  | */
            /* Row 0 */ { 0x00000000, 0x00000000 ,0x00000000 }, /* (x-value) */
            /* Row 1 */ { 0x00000000, 0x00000000 ,0x00000000 }, /* (x-value) */
            /* Row 2 */ { 0x00000000, 0x00000000 ,0x00000000 }, /* (x-value) */
            /* Row 3 */ { 0x00000000, 0x00000000 ,0x00000000 }, /* (x-value) */
            /* Row 4 */ { 0x00000000, 0x00000000 ,0x00000000 }, /* (x-value) */
            /* Row 5 */ { 0x00000000, 0x00000000 ,0x00000000 }, /* (x-value) */
            /* Row 6 */ { 0x00000000, 0x00000000 ,0x00000000 }, /* (x-value) */
            /* Row 7 */ { 0x00000000, 0x00000000 ,0x00000000 }  /* (x-value) */
        },
        /**********************************************************************/
        { /* Layer 1 */
            /* BAM round:   |  3   ||  2   ||  1   ||  0   | */  
            /* Row 0 */ { 0b00000000000000000000000000000000, 0, 0 },
            /*              |      ||      ||      ||      | */
            /* Column:      76543210765432107654321076543210       (y-value) */
            /* Row 1 */ { 0b00000000000000000000000000000000, 0,0 },
                        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}
        },
        { /* Layer 2 */
            {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}, },
        { /* Layer 3 */
            {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}, },
        { /* Layer 4 */
            {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}, },
        { /* Layer 5 */
            {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}, },
        { /* Layer 6 */
            {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}, },
        { /* Layer 7 */
            {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}, }
    },
    { /* CubeData1 */
        { /* Layer 0 */
            {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}, },
        { /* Layer 1 */
            {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}, },
        { /* Layer 2 */
            {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}, },
        { /* Layer 3 */
            {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}, },
        { /* Layer 4 */
            {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}, },
        { /* Layer 5 */
            {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}, },
        { /* Layer 6 */
            {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}, },
        { /* Layer 7 */
            {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}, }
    },
    NULL, /* pCubeDataRead */
    NULL, /* pCubeDataWrite */
    { /* BamRoundMask */
        BAM_MASK_ROUND_0,
        BAM_MASK_ROUND_1,
        BAM_MASK_ROUND_2,
        BAM_MASK_ROUND_3
    },
    { /* BamRoundShift */
        0,
        8,
        16,
        24
    }
    
};

/** Constant pointer to the CubeControlData structure */
pCubeControlData_t const pCubeControlData = &CubeControlData;

/** Constant pointer to the CubeData0 structure array */
pCubeData_t const pCubeData0Base = &CubeControlData.CubeData0[0][0];

/** Constant pointer to the CubeData1 structure array */
pCubeData_t const pCubeData1Base = &CubeControlData.CubeData1[0][0];

/*******************************************************************************
 * Functions
 ******************************************************************************/
void
CubeControlData_init( pCubeControlData_t const _pCubeControlData ) {
    _pCubeControlData->pCubeDataRead = pCubeData0Base;
    _pCubeControlData->pCubeDataWrite = pCubeData1Base;
        
    DEBUG_PRINTF_FUNCTION_INITIALIZE_COMPLETE();
    return;
}

void
CubeControlData_switchCubeData( pCubeControlData_t const _pCubeControlData ) {
    DEBUG_PRINTF_FUNCTION_CALL("%p", _pCubeControlData);
    
    INTERRUPTS_DISSABLE_AND_SAVE_CPU_IPL();
    
    if(_pCubeControlData->pCubeDataRead == pCubeData0Base) {
        _pCubeControlData->pCubeDataRead = pCubeData1Base;
        _pCubeControlData->pCubeDataWrite = pCubeData0Base;
    } else {
        _pCubeControlData->pCubeDataRead = pCubeData0Base;
        _pCubeControlData->pCubeDataWrite = pCubeData1Base;
        
    }
    
    DEBUG_PRINTF_FUNCTION("pCubeDataRead: %p, pCubeDataWrite: %p",
                _pCubeControlData->pCubeDataRead,
                _pCubeControlData->pCubeDataWrite);
    
    INTERRUPTS_RESTORE_CPU_IPL();
    
    return;
}

void
CubeControlData_resetCubeData( pCubeData_t const _pCubeData ) {
    DEBUG_PRINTF_FUNCTION_CALL("%p", _pCubeData);
    
    uint8_t x, z;
    for(z = 0; z < CUBEDATA_MAX_Z_C; z++) {
        for(x = 0; x < CUBEDATA_MAX_X_C; x++) {
            (_pCubeData + z * CUBEDATA_MAX_Z_C + x)->red   = 0x00000000;
            (_pCubeData + z * CUBEDATA_MAX_Z_C + x)->green = 0x00000000;
            (_pCubeData + z * CUBEDATA_MAX_Z_C + x)->blue  = 0x00000000;
        }
    }
    
    return;
}

void
CubeControlData_copyCubeData( pCubeData_t const _pCubeDataFrom,
        pCubeData_t const _pCubeDataTo ) {
    DEBUG_PRINTF_FUNCTION_CALL("%p, %p", _pCubeDataFrom, _pCubeDataTo);
    
    INTERRUPTS_DISSABLE_AND_SAVE_CPU_IPL();
    
    uint8_t x, z;
    for(z = 0; z < CUBEDATA_MAX_Z_C; z++) {
        for(x = 0; x < CUBEDATA_MAX_X_C; x++) {
            (_pCubeDataTo + z * CUBEDATA_MAX_Z_C + x)->red   = \
                    (_pCubeDataFrom + z * CUBEDATA_MAX_Z_C + x)->red;
            (_pCubeDataTo + z * CUBEDATA_MAX_Z_C + x)->green = \
                    (_pCubeDataFrom + z * CUBEDATA_MAX_Z_C + x)->green;
            (_pCubeDataTo + z * CUBEDATA_MAX_Z_C + x)->blue  = \
                    (_pCubeDataFrom + z * CUBEDATA_MAX_Z_C + x)->blue;
        }
    }
    
    INTERRUPTS_RESTORE_CPU_IPL();
    
    return;
}

void
CubeControlData_printHexCubeData( pCubeData_t const _pCubeData ) {
    DEBUG_PRINTF_FUNCTION_CALL("%p", _pCubeData);
    
    uint8_t x, z;
    for(z = 0; z < 8; z++) {
        for(x = 0; x < 8; x++) {
            PRINTF("pCubeData[%u][%u].red  : 0x%.8lX\n", z, x,
                    (_pCubeData + z * CUBEDATA_MAX_Z_C + x)->red);
            PRINTF("pCubeData[%u][%u].green: 0x%.8lX\n", z, x,
                    (_pCubeData + z * CUBEDATA_MAX_Z_C + x)->green);
            PRINTF("pCubeData[%u][%u].blue : 0x%.8lX\n", z, x,
                    (_pCubeData + z * CUBEDATA_MAX_Z_C + x)->blue);
        }
    }
    
    return;
}
/* End of file CubeControlData.c */
