/*******************************************************************************
 * Begin of file CubeData.h
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
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 * 
 * Description:
 *  Declare and control the data of the whole LED cube.
 * 
 ******************************************************************************/

#ifndef CUBEDATA_H
#define	CUBEDATA_H

#ifdef __cplusplus
extern "C" {
#endif
// @todo Rename to CubeControlData
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <xc.h>
#include <stdint.h>
#include <stddef.h>
#include "Debug.h"
#include "Interrupts.h"

/*******************************************************************************
 * Defines
 ******************************************************************************/
/* Max coordinate for the x-axis */
#define CUBEDATA_MAX_X_C    8
/* Max coordinate for the y-axis */
#define CUBEDATA_MAX_Z_C    CUBEDATA_MAX_X_C
/* Max coordinate for the z-axis */
#define CUBEDATA_MAX_Z_C    CUBEDATA_MAX_X_C
/* Number of bits used for bit angle modulation (BAM) */
#define CUBEDATA_N_BAM_BITS 4

/*******************************************************************************
 * Enumerators
 ******************************************************************************/
typedef enum {
    PANEL_0 = 0,
    PANEL_1 = 2,
    PANEL_2 = 4,
    PANEL_3 = 6
}Panels_t;

typedef enum {
    BAM_MASK_ROUND_0 = 0x000000FF,
    BAM_MASK_ROUND_1 = 0x0000FF00,
    BAM_MASK_ROUND_2 = 0x00FF0000,
    BAM_MASK_ROUND_3 = 0xFF000000
}BamRoundMasks_t;

/*******************************************************************************
 * Structures
 ******************************************************************************/
typedef struct {
    uint32_t red;
    uint32_t green;
    uint32_t blue;
}RowData_t, *pCubeData_t;

typedef struct {
    RowData_t               CubeData0[CUBEDATA_MAX_Z_C][CUBEDATA_MAX_X_C];
    RowData_t               CubeData1[CUBEDATA_MAX_Z_C][CUBEDATA_MAX_X_C];
    pCubeData_t             pCubeDataRead;
    pCubeData_t             pCubeDataWrite;
    BamRoundMasks_t const   BamRoundMask[CUBEDATA_N_BAM_BITS];
    uint8_t                 BamRoundShift[CUBEDATA_N_BAM_BITS];
}CubeControlData_t, *pCubeControlData_t;

/*******************************************************************************
 * Global variables
 ******************************************************************************/
/* Constant pointer to the CubeControlData structure */
extern pCubeControlData_t const pCubeControlData;
/* Constant pointer to the CubeData0 structure array */
extern pCubeData_t const pCubeData0Base;
/* Constant pointer to the CubeData1 structure array */
extern pCubeData_t const pCubeData1Base;

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * Initialize the CubeControlData structure.
 * 
 * @param   _pCubeControlData, pointer to the CubeControlData structure.
 * @return  void
 * @Example <code>CubeControlData_init(pCubeControlData);</code>
 */
void
CubeData_init( pCubeControlData_t const _pCubeControlData );

/**
 * Switch the CubeData read- and write pointers.
 * 
 * @param   _pCubeControlData, pointer to the CubeControlData structure.
 * @return  void
 * @Example <code>CubeControlData_switchCubeData(pCubeControlData);</code>
 */
void
CubeData_switchCubeData( pCubeControlData_t const _pCubeControlData );

/**
 * Reset a CubeData structure array.
 * 
 * @param   _pCubeData, pointer to a CubeData structure array.
 * @return  void
 * @Example <code>
 * CubeControlData_resetCubeData(pCubeControlData->pCubeDataWrite);</code>
 */
void
CubeData_resetData( pCubeData_t const _pCubeData );

/**
 * Print the contents of a CubeData structure array hexadecimal.
 * 
 * @param   _pCubeData, pointer to a CubeData structure array.
 * @return  void
 * @Example <code>
 * CubeControlData_printCubeData(pCubeControlData->pCubeDataRead);</code>
 */
void
CubeControlData_printHexCubeData( pCubeData_t const _pCubeData );

#ifdef	__cplusplus
}
#endif

#endif	/* CUBEDATA_H */
/* End of file CubeData.h */
