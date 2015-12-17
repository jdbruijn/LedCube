/*******************************************************************************
 * Begin of file System.h
 * Author: Jeroen de Bruijn
 * Created on 15 July 2015, 11:43
 * 
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 * 
 * This file is part of LedCube.
 * 
 * Copyright (c) 2015  Jeroen de Bruijn  <vidavidorra@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file 
 * @brief Sets the system settings.
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
/** Frequency of the device oscillator. */
#define FOSC            8000000UL
/** FRC Postscaler (see settings in ConfigureOscillator()). */
#define FRCDIV          1
/** PLL, if configured (FNOSC setting). */
#define PLL_MUL         4
/** System frequency (device oscillator frequency times @ref PLL_MUL). */
#define SYS_FREQ        ((FOSC * PLL_MUL) / FRCDIV)
/** Instruction Cycle Frequency. */
#define FCY             (SYS_FREQ / 2)
/** Peripheral Bus Clock Frequency. */
#define FPB             FCY

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/   
/**
 * @brief Configure the system oscillator.
 * 
 * @note    Settings must be confirm Configuration Bits Settings.
 */
void
ConfigureOscillator( void );

#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */
/* End of file System.h */
