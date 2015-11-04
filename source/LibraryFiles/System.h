/*******************************************************************************
 * Begin of file System.h
 * Author: Jeroen de Bruijn
 * Created on 15 July 2015, 11:43
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
 *  Sets the system settings.
 * 
 ******************************************************************************/

#ifndef SYSTEM_H
#define	SYSTEM_H

#ifdef	__cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <xc.h>

/*******************************************************************************
 * Defines (Microcontroller MIPs)
 ******************************************************************************/
/* Frequency of the device oscillator */
#define FOSC            8000000UL
/* FRC Postscaler (see settings in ConfigureOscillator()) */
#define FRCDIV          1
/* PLL, if configured (FNOSC setting) */
#define PLL_MUL         4
/* System frequency (device oscillator frequency times PLL_MUL) */
#define SYS_FREQ        ((FOSC * PLL_MUL) / FRCDIV)
/* Instruction Cycle Frequency */
#define FCY             (SYS_FREQ / 2)
/* Peripheral Bus Clock Frequency */
#define FPB             FCY

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/   
/**
 * Configure the system oscillator.
 * 
 * @Note    Settings must be confirm Configuration Bits Settings.
 * @param   void
 * @return  void
 * @Example <code>ConfigureOscillator();</code>
 */
void
ConfigureOscillator( void );

#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */
/* End of file System.h */
