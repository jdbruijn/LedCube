/*******************************************************************************
 * Begin of file Buzzer.h
 * Author: jdebruijn
 * Created on July 26, 2015, 2:54 PM
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
 * @brief Controls a buzzer using the Output Compare peripheral.
 * 
 ******************************************************************************/

#ifndef BUZZER_H
#define	BUZZER_H

#ifdef	__cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Switches
 ******************************************************************************/
#define BUZZER_ENABLE_SELF_TEST_NO

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <xc.h>
#include <stdint.h>
#include "Debug.h"
#include "Delay.h"
#include "MyAssert.h"

/*******************************************************************************
 * Defines
 ******************************************************************************/
#define T2_TCKPS                8       /**< Timer 2 prescaler. */
#define BUZZER_MIN_FREQUENCY    40      /**< Minimum buzzer frequency in Hz. */
#define BUZZER_MAX_FREQUENCY    16000   /**< Maximum buzzer frequency in Hz. */
#define BUZZER_MIN_TIME         10      /**< Minimum buzzer time in ms. */
/** Maximum buzzer time in ms. Same as maximum delay time @ref DELAY_MAX_MS. */
#define BUZZER_MAX_TIME         DELAY_MAX_MS
    
/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * @brief Initialize the on-board buzzer.
 */
void
Buzzer_init( void );

/**
 * @brief Create a short (250 ms) beep with a frequency of 4 kHz.
 */
void
Buzzer_beep( void );

/**
 * @brief Create a very short (50 ms) beep with a frequency of 4 kHz.
 */
void
Buzzer_shortBeep( void );

/**
 * @brief Make a sound with adjustable frequency and duration time.
 * 
 * The sound is created using a PWM-signal with  a duty cycle of fifty percent.
 * @note    _frequency must be between @ref BUZZER_MIN_FREQUENCY and @ref
 * BUZZER_MAX_FREQUENCY, and _time must be between @ref BUZZER_MIN_TIME and @ref
 * BUZZER_MAX_TIME.
 * @note    The output frequency has a maximum deviation of 1.1%.
 * @param   _frequency Frequency of the sound in Hz. Ranging from @ref
 * BUZZER_MIN_FREQUENCY to @ref BUZZER_MAX_FREQUENCY.
 * @param   _time Duration of the sound in ms. Ranging from @ref BUZZER_MIN_TIME
 * to @ref BUZZER_MAX_TIME.
 */
void
Buzzer_set( uint16_t _frequency, uint32_t _time );

#ifdef BUZZER_ENABLE_SELF_TEST_YES
/** @todo remove selftest and add seperate unit test
 * Run a self test on the buzzer. I.e. first beep three times than go from
 * lowest frequency to highest frequency followed by three beeps.
 * 
 * @Note    This self tests takes about 22 seconds.
 * @param   void
 * @return  void
 * @Example <code>Buzzer_selfTest();</code>
 */
void
Buzzer_selfTest( void ); 
#endif /* BUZZER_ENABLE_SELF_TEST_YES */

#ifdef	__cplusplus
}
#endif

#endif	/* BUZZER_H */
/* End of file Buzzer.h */
