/*******************************************************************************
 * Begin of file main.c
 * Author: Jeroen de Bruijn
 * Created on 02 August 2015, 10:48
 * 
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 * 
 * Copyright (c) 2015 Jeroen de Bruijn <vidavidorra@gmail.com>
 * 
 * This file is part of LedCube which is released under The MIT License (MIT).
 * For full license details see below, see file "LICENSE.md" or go to
 * https://opensource.org/licenses/MIT
 * 
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 * 
 * Description:
 *  Globally controls functions. 
 * 
 ******************************************************************************/

// <editor-fold defaultstate="collapsed" desc="The MIT License (MIT)">
/**
 * The MIT License (MIT)
 * 
 * Copyright (c) 2015 Jeroen de Bruijn <vidavidorra@gmail.com>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
// </editor-fold>

/*******************************************************************************
 * PIC24FJ64GA004 Configuration Bit Settings
 ******************************************************************************/
// <editor-fold defaultstate="collapsed" desc="PIC24FJ64GA004 Configuration Bits">
// CONFIG2
#pragma config POSCMOD = NONE           // Primary Oscillator Select (Primary oscillator disabled)
#pragma config I2C1SEL = PRI            // I2C1 Pin Location Select (Use default SCL1/SDA1 pins)
#pragma config IOL1WAY = OFF            // IOLOCK Protection (IOLOCK may be changed via unlocking seq)
#pragma config OSCIOFNC = OFF           // Primary Oscillator Output Function (OSC2/CLKO/RC15 functions as CLKO (FOSC/2))
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor (Clock switching and Fail-Safe Clock Monitor are disabled)
#pragma config FNOSC = FRCPLL           // Oscillator Select (Fast RC Oscillator with PLL module (FRCPLL))
#pragma config SOSCSEL = SOSC           // Sec Oscillator Select (Default Secondary Oscillator (SOSC))
#pragma config WUTSEL = LEG             // Wake-up timer Select (Legacy Wake-up Timer)
#pragma config IESO = ON                // Internal External Switch Over Mode (IESO mode (Two-Speed Start-up) enabled)

// CONFIG1
#pragma config WDTPS = PS32768          // Watchdog Timer Postscaler (1:32,768)
#pragma config FWPSA = PR128            // WDT Prescaler (Prescaler ratio of 1:128)
#pragma config WINDIS = ON              // Watchdog Timer Window (Standard Watchdog Timer enabled,(Windowed-mode is disabled))
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (Watchdog Timer is disabled)
#pragma config ICS = PGx1               // Comm Channel Select (Emulator EMUC1/EMUD1 pins are shared with PGC1/PGD1)
#pragma config GWRP = OFF               // General Code Segment Write Protect (Writes to program memory are allowed)
#pragma config GCP = OFF                // General Code Segment Code Protect (Code protection is disabled)
#pragma config JTAGEN = OFF             // JTAG Port Enable (JTAG port is disabled)
// </editor-fold>

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <xc.h>
#include <stdint.h>
#include "System.h"
#include "Buzzer.h"
#include "Delay.h"
#include "IOPorts.h"
#include "LedCube.h"
#include "Uart.h"

/*******************************************************************************
 * Main function
 ******************************************************************************/
/**
 * Main function of the code, this initializes and controls all other functions.
 * 
 * @param   argc, argument counter
 * @param   argv, array of function arguments
 * @return  uint8_t, error code
 */
int
main(int argc, char** argv) {
    ConfigureOscillator();
    
    // User code initialisation
    IOPorts_init();
    Uart1_init();
    Buzzer_init();
    Buzzer_shortBeep();
    
    LedCube_init();
    Port_ClearPin(OE);

    // Infinite loop for user code.
    while(1)
    {
        LedCube_setPixel(1,0,0, 0,0,1);
        uint8_t i = 0;
        for(i = 0; i < 16; i++) {
            LedCube_setPixel(3,4,2,  0, 0, 14);
            Delay_ms(500);
        }
        LedCube_update();
        LedCube_resetData();
        Delay_ms(5000);
        
    }
    
    // End, nothing comes beyond this point!
    while(1);
    
    return( 0 );
}
/* End of file main.c */
