/*******************************************************************************
 * Begin of file CubeControlData.h
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
 * @brief Provides Cube- and CubeControl data structures and functions.
 * 
 * Declares and controls the data of the whole LED cube using several functions.
 * 
 ******************************************************************************/

#ifndef CUBECONTROLDATA_H
#define	CUBECONTROLDATA_H

#ifdef __cplusplus
extern "C" {
#endif

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
/** Max coordinate for the x-axis */
#define CUBEDATA_MAX_X_C    8

/** Max coordinate for the y-axis */
#define CUBEDATA_MAX_Y_C    CUBEDATA_MAX_X_C

/** Max coordinate for the z-axis */
#define CUBEDATA_MAX_Z_C    CUBEDATA_MAX_X_C

/** Number of bits used for bit angle modulation (BAM) */
#define CUBEDATA_N_BAM_BITS 4

/*******************************************************************************
 * Enumerators
 ******************************************************************************/
/** 
 * The enumeration of the start row for the four PanelControl (PC) PCBs.
 */
typedef enum {
    PANEL_0 = 0,    /**< The fist PC PCB in the "bus" starting with row 0 */
    PANEL_1 = 2,    /**< The second PC PCB in the "bus" starting with row 2 */
    PANEL_2 = 4,    /**< The third PC PCB in the "bus" starting with row 4 */
    PANEL_3 = 6     /**< The fourth PC PCB in the "bus", starting with row 6 */
}Panels_t;

/**
 * The enumeration of masks for the four BAM rounds.
 */
typedef enum {
    BAM_MASK_ROUND_0 = 0x000000FF,  /**< Mask for bam round 0 */
    BAM_MASK_ROUND_1 = 0x0000FF00,  /**< Mask for bam round 1 */
    BAM_MASK_ROUND_2 = 0x00FF0000,  /**< Mask for bam round 2 */
    BAM_MASK_ROUND_3 = 0xFF000000   /**< Mask for bam round 3 */
}BamRoundMasks_t;

/*******************************************************************************
 * Structures
 ******************************************************************************/
/** @brief Structure of the RGB values of a single row of LEDs.
 * 
 * This contains 32-bit red, green and blue values where the data of a single
 * row with @ref CUBEDATA_MAX_Y_C LEDs in it.
 * These 32-bit values contains the state of the LEDs for the @ref
 * CUBEDATA_N_BAM_BITS BAM rounds and are classified as follows.
 * @note The uint32_t value is in binary format and spans all the columns in
 * that row.
 * 
 * | Description             |          |          |          |          |
 * | ----------------------- | :------: | :------: | :------: | :------: |
 * | BAM round               | 3        | 2        | 1        | 0        |
 * | uint32_t value (binary) | 00000000 | 00000000 | 00000000 | 00000000 |
 * | Column (y-value)        | 76543210 | 76543210 | 76543210 | 76543210 |
 */
typedef struct {
    /** Red colour data of a single row with @ref CUBEDATA_MAX_Y_C LEDs in it. */
    uint32_t red;
    /** Green colour data of a single row with @ref CUBEDATA_MAX_Y_C LEDs in it. */
    uint32_t green;
    /** Blue colour data of a single row with @ref CUBEDATA_MAX_Y_C LEDs in it. */
    uint32_t blue;
}RowData_t, *pCubeData_t;

/** @brief Structure with Cube- and CubeControl data.
 * 
 * This contains two @ref RowData_t structure arrays, pointers to the current
 * read and write structure arrays, masks for the BAM rounds and the shift
 * needed for each BAM round.
 */
typedef struct {
    /** First CubeData structure array where the LED data of the whole LedCube
     *  is stored in. So this is the data for all 512 LEDs \f$ { (8 \times 8 
     *  \times 8) } \f$ and the @ref CUBEDATA_N_BAM_BITS BAM rounds.
     */
    RowData_t               CubeData0[CUBEDATA_MAX_Z_C][CUBEDATA_MAX_X_C];
    /** Second CubeData structure array where the LED data of the whole LedCube
     *  is stored in. For more info see @ref CubeData0.
     */
    RowData_t               CubeData1[CUBEDATA_MAX_Z_C][CUBEDATA_MAX_X_C];
    /** Pointer to the current CubeData structure array where is read from.
     *  This can point to either @ref CubeData0 using @ref pCubeData0Base or to
     *  @ref CubeData1 using @ref pCubeData0Base.
     */
    pCubeData_t             pCubeDataRead;
    /** Pointer to the current CubeData structure array where is written to.
     *  This can point to either @ref CubeData0 using @ref pCubeData0Base or to
     *  @ref CubeData1 using @ref pCubeData0Base.
     */
    pCubeData_t             pCubeDataWrite;
    /** Constant array of type @ref BamRoundMasks_t that is used as a BAM mask
     *  for each BAM round.
     */
    BamRoundMasks_t const   BamRoundMask[CUBEDATA_N_BAM_BITS];
    /** Constant array containing the shift needed for each BAM round */
    uint8_t                 BamRoundShift[CUBEDATA_N_BAM_BITS];
}CubeControlData_t, *pCubeControlData_t;

/*******************************************************************************
 * Global variables
 ******************************************************************************/
/** Constant pointer to the CubeControlData structure */
extern pCubeControlData_t const pCubeControlData;

/** Constant pointer to the CubeData0 structure array */
extern pCubeData_t const pCubeData0Base;

/** Constant pointer to the CubeData1 structure array */
extern pCubeData_t const pCubeData1Base;

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * Initialize a CubeControlData structure. The @ref
 * CubeControlData_t::pCubeDataRead pointer points to @ref pCubeData0Base in the
 * beginning and the @ref CubeControlData_t::pCubeDataWrite pointer points to
 * @ref pCubeData1Base in the beginning.
 * 
 * @param   _pCubeControlData Pointer to a CubeControlData structure.
 */
void
CubeControlData_init( pCubeControlData_t const _pCubeControlData );

/**
 * @brief Switch the CubeData read- and write pointers.
 * @note    The switch is performed with interrupts disabled using the @ref
 * INTERRUPTS_DISSABLE_AND_SAVE_CPU_IPL and @ref INTERRUPTS_RESTORE_CPU_IPL
 * macros because the CubeData read takes place in an interrupt service routine.
 * 
 * @param   _pCubeControlData Pointer to a CubeControlData structure.
 */
void
CubeControlData_switchCubeData( pCubeControlData_t const _pCubeControlData );

/**
 * Reset a CubeData structure array.
 * 
 * @param   _pCubeData Pointer to a CubeData structure array.
 */
void
CubeControlData_resetCubeData( pCubeData_t const _pCubeData );

/**
 * Copy a CubeData structure array.
 * @note    The copy is performed with interrupts disabled using the @ref
 * INTERRUPTS_DISSABLE_AND_SAVE_CPU_IPL and @ref INTERRUPTS_RESTORE_CPU_IPL
 * macros because the CubeData read takes place in an interrupt service routine.
 * 
 * @param   _pCubeDataFrom Pointer to a CubeData structure array to copy from.
 * @param   _pCubeDataTo Pointer to a CubeData structure array to copy to.
 */
void
CubeControlData_copyCubeData( pCubeData_t const _pCubeDataFrom,
        pCubeData_t const _pCubeDataTo );

/**
 * Print the contents of a CubeData structure array hexadecimal.
 * 
 * @param   _pCubeData Pointer to a CubeData structure array.
 */
void
CubeControlData_printHexCubeData( pCubeData_t const _pCubeData );

#ifdef	__cplusplus
}
#endif

#endif	/* CUBECONTROLDATA_H */
/* End of file CubeControlData.h */
