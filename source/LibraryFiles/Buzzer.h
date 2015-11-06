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
 * For full license details see file "main.c" or "LICENSE.md" or go to
 * https://opensource.org/licenses/MIT
 * 
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 * 
 * Description:
 *  Controls a buzzer using the Output Compare peripheral.
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
#define T2_TCKPS                8
#define BUZZER_MAX_FREQUENCY    16000   // Hz
#define BUZZER_MIN_FREQUENCY    40      // Hz
#define BUZZER_MAX_TIME         250000  // ms (250 s)
#define BUZZER_MIN_TIME         10      // ms
    
/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * Initialize the on-board buzzer.
 * 
 * @param   void
 * @return  void
 * @Example <code>Buzzer_init();</code>
 */
void
Buzzer_init( void );

/**
 * Create a short (250 ms) beep.
 * 
 * @param   void
 * @return  void
 * @Example <code>Buzzer_beep();</code>
 */
void
Buzzer_beep( void );

/**
 * Create a short (50 ms) beep.
 * 
 * @param   void
 * @return  void
 * @Example <code>Buzzer_shortBeep();</code>
 */
void
Buzzer_shortBeep( void );

/**
 * Make a sound with a frequency of _frequency Hz and for _time amount of
 * milliseconds.
 * 
 * @Note    _frequency must be between 40 and 16000 Hz and _time must be between
 * 10 ms and 250000 ms (250 s).
 * @Note    The output frequency has a maximum deviation of 1.1%.
 * @param   _frequency Frequency to set in Hz
 * @param   _time Time to create a sound in ms
 * @return  void
 * @Example <code>Buzzer_set(10000, 500);</code>
 */
void
Buzzer_set( uint16_t _frequency, uint32_t _time );

#ifdef BUZZER_ENABLE_SELF_TEST_YES
/**
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
