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
 *  Control the data of the Whole LedCube.
 * 
 ******************************************************************************/

#ifndef CUBEDATA_H
#define	CUBEDATA_H

//#ifdef __cplusplus
//extern "C" {
//#endif

/*******************************************************************************
 * Switches
 ******************************************************************************/
// @todo New File: Add switches, for example NAME_ENABLE_SELFTEST_YES or remove this block

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <xc.h>
#include <stdint.h>
#include <stddef.h>

/*******************************************************************************
 * Defines
 ******************************************************************************/
// @todo New File: Add defines or remove this block

/*******************************************************************************
 * Macro's
 ******************************************************************************/
// @todo New File: Add macro's or remove this block
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
}RowControlData_t, *pRowControlData_t, *pCubeData_t;

typedef struct {
    RowControlData_t CubeData0[8][8];
    RowControlData_t CubeData1[8][8];
    pCubeData_t pCubeDataBase;
    const BamRoundMasks_t BamRoundMask[4];
    const uint8_t BamRoundShift[4];
}CubeControlData_t, *pCubeControlData_t;
extern pCubeControlData_t pCubeControlData;
extern pCubeData_t const pCubeData0Base;
extern pCubeData_t const pCubeData1Base;

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
void
CubeData_init( const pCubeControlData_t _pCubeControlData );

void
resetData( const pCubeData_t _pCubeData[] );

#ifdef	__cplusplus
}
#endif

#endif	/* CUBEDATA_H */
/* End of file CubeData.h */
