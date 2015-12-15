/*******************************************************************************
 * Begin of file System.c
 * Author: Jeroen de Bruijn
 * Created on 15 July 2015, 11:43
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
 * @brief Sets the system settings.
 * 
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "System.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
void
ConfigureOscillator( void ) {
    // @todo Unlock OSCCON register before writing it.
    /********** Configure OSCCON register *************************************/
//    /* NOSC<2:0>: New Oscillator Selection bits
//     * 111 = Fast RC Oscillator with Postscaler (FRCDIV)
//     * 110 = Reserved
//     * 101 = Low-Power RC Oscillator (LPRC)
//     * 100 = Secondary Oscillator (SOSC)
//     * 011 = Primary Oscillator with PLL module (XTPLL, HSPLL, ECPLL)
//     * 010 = Primary Oscillator (XT, HS, EC)
//     * 001 = Fast RC Oscillator with Postscaler and PLL module (FRCPLL)
//     * 000 = Fast RC Oscillator (FRC)
//     */
//    OSCCONbits.NOSC = 0b001;
//    
//    /* CLKLOCK: Clock Selection Lock Enabled bit (Set Only bit)
//     * If FSCM is enabled (FCKSM1 = 1):
//     * 1 = Clock and PLL selections are locked
//     * 0 = Clock and PLL selections are not locked and may be modified by setting the OSWEN bit
//     * If FSCM is disabled (FCKSM1 = 0):
//     * Clock and PLL selections are never locked and may be modified by setting the OSWEN bit.
//     */
//    //OSCCONbits.CLKLOCK = 0;
//    
//    /* CF: Clock Fail Detect bit
//     * 1 = FSCM has detected a clock failure
//     * 0 = No clock failure has been detected
//     */
//    OSCCONbits.CF = 0;
//    
//    /* SOSCEN: 32 kHz Secondary Oscillator (SOSC) Enable bit
//     * 1 = Enable Secondary Oscillator
//     * 0 = Disable Secondary Oscillator
//     */
//    OSCCONbits.SOSCEN = 0;
//    
//    /* OSWEN: Oscillator Switch Enable bit
//     * 1 = Initiate an oscillator switch to the clock source specified by the NOSC<2:0> bits
//     * 0 = Oscillator switch is complete
//     */
//    OSCCONbits.OSWEN = 0;
    
    /********** Configure CLKDIV register *************************************/
    /* FRC Postscaler Select bits:
     * 111 = 31.25 kHz (divide-by-256)
     * 110 = 125 kHz (divide-by-64)
     * 101 = 250 kHz (divide-by-32)
     * 100 = 500 kHz (divide-by-16)
     * 011 = 1 MHz (divide-by-8)
     * 010 = 2 MHz (divide-by-4)
     * 001 = 4 MHz (divide by 2)
     * 000 = 8 MHz (divide by 1)
     */
//    CLKDIVbits.RCDIV = 0b000;
    
    return;
}

/* End of file System.c */
