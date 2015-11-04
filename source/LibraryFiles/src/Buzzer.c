/*******************************************************************************
 * Begin of file Buzzer.c
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
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "Buzzer.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
/**
 * Setup the I/O and timer 2 to be used for PWM.
 * 
 */
void
Buzzer_init( void ) {
    /********** Configure Output Compare Module *******************************/
    OC1CON = 0x0000;            // Turn off Output Compare 1 Module
    
    PR2 = 499;                  // PWM period (4 kHz)
    OC1RS = 0;                  // Initialize Secondary Compare register with 0% duty cycle
    OC1R = 0;                   // Initialize Compare register with 0% duty cycle
    
    OC1CONbits.OCTSEL = 0;      // Use timer 2 as clock source
    OC1CONbits.OCM = 0b110;     // PWM mode, Fault pin is disabled
    
    /********** Configure Timer 2 *********************************************/
    T2CONbits.TON = 0;          // Stop the timer during config
    /**
     * TCKPS<1:0>: Timerx Input Clock Prescale bits
     * 11 = 1:256 prescaler value
     * 10 = 1:64 prescaler value
     * 01 = 1:8 prescaler value
     * 00 = 1:1 prescaler value
     */
    T2CONbits.TCKPS = 0b01;
    T2CONbits.TCS = 0;          // Use Internal clock (Fosc/2) as clock source
    T2CONbits.T32 = 0;          // Form 2 seperate 16-bit timers
    T2CONbits.TON = 1;          // Enable timer
    
    DEBUG_PRINTF_FUNCTION_INITIALIZE_COMPLETE();
    return;
}

/**
 * Beep for 250 ms at a frequency of 4 kHz.
 * 
 */
void
Buzzer_beep( void ) {
    PR2 = 499;                  // 4 kHz
    OC1RS = (PR2 >> 1);         // 50% duty cycle
    __delay_ms(250);
    OC1RS = 0;                  // 0% duty cycle (buzzer is turned off)
    
    return;
}

/**
 * Beep for 50 ms at a frequency of 4 kHz.
 * 
 */
void
Buzzer_shortBeep( void ) {
    PR2 = 499;                  // 4 kHz
    OC1RS = (PR2 >> 1);         // 50% duty cycle
    __delay_ms(50);
    OC1RS = 0;                  // 0% duty cycle (buzzer is turned off)
    
    return;
}

/**
 * Calculate the PWM period and set 50% duty cycle.
 * 
 */
void
Buzzer_set( uint16_t _frequency, uint32_t _time ) {
    /********** Check conditions **********************************************/
    ASSERT( _frequency >= BUZZER_MIN_FREQUENCY && \
            _frequency <= BUZZER_MAX_FREQUENCY );
    ASSERT( _time >= BUZZER_MIN_TIME && \
            _time <= BUZZER_MAX_TIME );
    
    /********** Set frequency *************************************************/
    /**
     * "PWM Period = [(PRy + 1) * TCY * (TMRy Prescale Value)]
     * PWM Frequency = 1/[PWM Period]" (Output Compare, Equation 4-1: 
     * Calculating the PWM Period, Microchip)
     * 
     * PWM Period = 1/[PWM Frequency]
     * PR = ((1 / _frequency) / (( 1/PBCLK) * Timer Prescaler)) -1
     *    = (1 / (_frequency * (Timer Prescaler / PBCLK))) - 1
     */
    PR2 = (1 / (_frequency * ((float)T2_TCKPS / FPB))) - 1;
    OC1RS = (PR2 >> 1);         // 50% duty cycle
    __delay_ms(_time);
    OC1RS = 0;                  // 0% duty cycle (buzzer is turned off)
    
    return;
}

#ifdef BUZZER_ENABLE_SELF_TEST_YES
/**
 * Self test using beep and set functions.
 * 
 */
void
Buzzer_selfTest( void ) {
    uint16_t i;
    
    for( i=0; i<3; i++ ) {
        Buzzer_beep();
        __delay_ms(100);
    }
    
    for( i=40; i<=20000; i+=100 ) {       
        Buzzer_set(i, 100);
    }
    
    for( i=0; i<3; i++ ) {
        __delay_ms(100);
        Buzzer_beep();
    }
    
    return;
}
#endif /* BUZZER_ENABLE_SELF_TEST_YES */
/* End of file Buzzer.c */
