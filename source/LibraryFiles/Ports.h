/*******************************************************************************
 * Begin of file Ports.h
 * Author: Jeroen de Bruijn
 * Created on 02 August 2015 08:55 AM
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
 *  Controls the microcontroller ports.
 * 
 ******************************************************************************/

#ifndef PORT_H
#define	PORT_H

#ifdef	__cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <xc.h>

/*******************************************************************************
 * Defines
 ******************************************************************************/
/* Pins */
// <editor-fold defaultstate="collapsed" desc="Pins">
#define PORT_RA0        A0              /* Pin RA0 */
#define PORT_RA1        A1              /* Pin RA1 */
#define PORT_RA2        A2              /* Pin RA2 */
#define PORT_RA3        A3              /* Pin RA3 */
#define PORT_RA4        A4              /* Pin RA4 */
#define PORT_RA7        A7              /* Pin RA7 */
#define PORT_RA8        A8              /* Pin RA8 */
#define PORT_RA9        A9              /* Pin RA9 */
#define PORT_RA10       A10             /* Pin RA10 */
#define PORT_RB0        B0              /* Pin RB0 */
#define PORT_RB1        B1              /* Pin RB1 */
#define PORT_RB2        B2              /* Pin RB2 */
#define PORT_RB3        B3              /* Pin RB3 */
#define PORT_RB4        B4              /* Pin RB4 */
#define PORT_RB5        B5              /* Pin RB5 */
#define PORT_RB6        B6              /* Pin RB6 */
#define PORT_RB7        B7              /* Pin RB7 */
#define PORT_RB8        B8              /* Pin RB8 */
#define PORT_RB9        B9              /* Pin RB9 */
#define PORT_RB10       B10             /* Pin RB10 */
#define PORT_RB11       B11             /* Pin RB11 */
#define PORT_RB12       B12             /* Pin RB12 */
#define PORT_RB13       B13             /* Pin RB13 */
#define PORT_RB14       B14             /* Pin RB14 */
#define PORT_RB15       B15             /* Pin RB15 */
#define PORT_RC0        C0              /* Pin RC0 */
#define PORT_RC1        C1              /* Pin RC1 */
#define PORT_RC2        C2              /* Pin RC2 */
#define PORT_RC3        C3              /* Pin RC3 */
#define PORT_RC4        C4              /* Pin RC4 */
#define PORT_RC5        C5              /* Pin RC5 */
#define PORT_RC6        C6              /* Pin RC6 */
#define PORT_RC7        C7              /* Pin RC7 */
#define PORT_RC8        C8              /* Pin RC8 */
#define PORT_RC9        C9              /* Pin RC9 */
// </editor-fold>

/* Remappable Pins */
// <editor-fold defaultstate="collapsed" desc="Remappable Pins">
#define PORT_RP0        PORT_RB0        /* Remappable pin RP0 to RB0 */
#define PORT_RP1        PORT_RB1        /* Remappable pin RP1 to RB1 */
#define PORT_RP2        PORT_RB2        /* Remappable pin RP2 to RB2 */
#define PORT_RP3        PORT_RB3        /* Remappable pin RP3 to RB3 */
#define PORT_RP4        PORT_RB4        /* Remappable pin RP4 to RB4 */
#define PORT_RP5        PORT_RB5        /* Remappable pin RP5 to RB5 */
#define PORT_RP6        PORT_RB6        /* Remappable pin RP6 to RB6 */
#define PORT_RP7        PORT_RB7        /* Remappable pin RP7 to RB7 */
#define PORT_RP8        PORT_RB8        /* Remappable pin RP8 to RB8 */
#define PORT_RP9        PORT_RB9        /* Remappable pin RP9 to RB9 */
#define PORT_RP10       PORT_RB10       /* Remappable pin RP10 to RB10 */
#define PORT_RP11       PORT_RB11       /* Remappable pin RP11 to RB11 */
#define PORT_RP12       PORT_RB12       /* Remappable pin RP12 to RB12 */
#define PORT_RP13       PORT_RB13       /* Remappable pin RP13 to RB13 */
#define PORT_RP14       PORT_RB14       /* Remappable pin RP14 to RB14 */
#define PORT_RP15       PORT_RB15       /* Remappable pin RP15 to RB15 */
#define PORT_RP16       PORT_RC0        /* Remappable pin RP16 to RC0 */
#define PORT_RP17       PORT_RC1        /* Remappable pin RP17 to RC1 */
#define PORT_RP18       PORT_RC2        /* Remappable pin RP18 to RC2 */
#define PORT_RP19       PORT_RC3        /* Remappable pin RP19 to RC3 */
#define PORT_RP20       PORT_RC4        /* Remappable pin RP20 to RC4 */
#define PORT_RP21       PORT_RC5        /* Remappable pin RP21 to RC5 */
#define PORT_RP22       PORT_RC6        /* Remappable pin RP22 to RC6 */
#define PORT_RP23       PORT_RC7        /* Remappable pin RP23 to RC7 */
#define PORT_RP24       PORT_RC8        /* Remappable pin RP24 to RC8 */
#define PORT_RP25       PORT_RC9        /* Remappable pin RP25 to RC9 */
// </editor-fold>

/*******************************************************************************
 * Macro's
 ******************************************************************************/
/**
 * Macro's and helper macro's to join defines and arguments. The functions below
 * will use the macro's to join defines.
 * 
 * @Note	The macro's need a second helper macro in order to expand multiple
 * defines.
 * 
 * For details about macro replacement and argument substitution
 * @see http://stackoverflow.com/a/1489985
 */
#define _HELPER_JOIN_PIN(func, pin) func ## pin
#define _JOIN_PIN(func, pin) _HELPER_JOIN_PIN(func, pin)
#define _HELPER_JOIN_ASSIGN(func, pin, val) _JOIN_PIN(func, pin) = val
#define _JOIN_ASSIGN(func, pin, val) _HELPER_JOIN_ASSIGN(func, pin, val)
#define _HELPER_JOIN_TOGGLE(func, pin) \
                _JOIN_PIN(func, pin) = ~ _JOIN_PIN(func, pin)
#define _JOIN_TOGGLE(func, pin) _HELPER_JOIN_TOGGLE(func, pin)

/**
 * Configure all pins to be in digital mode instead of analog mode.
 * 
 * @Note    PPS pins can also be called by their RPn name. For example: 
 * <code>PORT_RP16</code> instead of <code>PORT_RC0</code>.
 * @param   none
 * @return  none
 * @Example <code>Port_ConfigureAllPinsDigital();</code>
 */
#define Port_ConfigureAllPinsDigital() AD1PCFG = 0xFFFF

/**
 * Configure selected pin as digital input.
 * 
 * @Note    PPS pins can also be called by their RPn name. For example: 
 * <code>PORT_RP16</code> instead of <code>PORT_RC0</code>.
 * @param   pin Pin which has to be configure as digital input\n
 * - PORT_RA0\n
 * - PORT_RA1\n
 * - ...\n
 * - PORT_RC9
 * @return  none
 * @Example <code>Port_ConfigurePinDigitalIn(PORT_RA1);</code>
 */
#define Port_ConfigurePinDigitalIn(pin) _JOIN_ASSIGN(_TRIS, pin, 1); \
                _JOIN_ASSIGN(_OD, pin, 0)

/**
 * Configure selected pin as digital output.
 * 
 * @Note    PPS pins can also be called by their RPn name. For example: 
 * <code>PORT_RP16</code> instead of <code>PORT_RC0</code>.
 * @param   pin Pin which has to be configured as normal digital output\n
 * - PORT_RA0\n
 * - PORT_RA1\n
 * - ...\n
 * - PORT_RC9
 * @return  none
 * @Example <code>Port_ConfigurePinDigitalOut(PORT_RA1);</code>
 */
#define Port_ConfigurePinDigitalOut(pin) _JOIN_ASSIGN(_TRIS, pin, 0); \
                _JOIN_ASSIGN(_OD, pin, 0)

/**
 * Configure selected pin as digital output.
 * 
 * @Note    PPS pins can also be called by their RPn name. For example: 
 * <code>PORT_RP16</code> instead of <code>PORT_RC0</code>.
 * @param   pin Pin which has to be configured as open-drain output\n
 * - PORT_RA0\n
 * - PORT_RA1\n
 * - ...\n
 * - PORT_RC9
 * @return  none
 * @Example <code>Port_ConfigurePinOpenDrainOut(PORT_RA1);</code>
 */
#define Port_ConfigurePinOpenDrainOut(pin) _JOIN_ASSIGN(_OD, pin, 1)

/**
 * Set selected pin, make the output high.
 * 
 * @Note    PPS pins can also be called by their RPn name. For example: 
 * <code>PORT_RP16</code> instead of <code>PORT_RC0</code>.
 * @param   pin Pin which has to be set\n
 * - PORT_RA0\n
 * - PORT_RA1\n
 * - ...\n
 * - PORT_RC9
 * @return  none
 * @Example <code>Port_SetPin(PORT_RA1);</code>
 */
#define Port_SetPin(pin) _JOIN_ASSIGN(_LAT, pin, 1)

/**
 * Clear selected pin, make the output low.
 * 
 * @Note    PPS pins can also be called by their RPn name. For example: 
 * <code>PORT_RP16</code> instead of <code>PORT_RC0</code>.
 * @param   pin Pin which has to be cleared\n
 * - PORT_RA0\n
 * - PORT_RA1\n
 * - ...\n
 * - PORT_RC9
 * @return  none
 * @Example <code>Port_ClearPin(PORT_RA1);</code>
 */
#define Port_ClearPin(pin) _JOIN_ASSIGN(_LAT, pin, 0)

/**
 * Reset all the settings of the selected pin.
 * 
 * @Note    This resets the LATx, ODCx and TRISx registers.
 * @Note    PPS pins can also be called by their RPn name. For example: 
 * <code>PORT_RP16</code> instead of <code>PORT_RC0</code>.
 * @param   pin Pin of which to reset the configuration\n
 * - PORT_RA0\n
 * - PORT_RA1\n
 * - ...\n
 * - PORT_RC9
 * @return  none
 * @Example <code>Port_ClearPin(PORT_RA1);</code>
 */
#define Port_ResetConfiguration(pin) Port_ClearPin(pin); \
                Port_ConfigurePinDigitalIn(pin)

/**
 * Toggle selected pin, invert the output.
 * 
 * @Note    PPS pins can also be called by their RPn name. For example: 
 * <code>PORT_RP16</code> instead of <code>PORT_RC0</code>.
 * @param   pin Pin which has to be set\n
 * - PORT_RA0\n
 * - PORT_RA1\n
 * - ...\n
 * - PORT_RC9
 * @return  none
 * @Example <code>Port_TogglePin(PORT_RA1);</code>
 */
#define Port_TogglePin(pin) _JOIN_TOGGLE(_LAT, pin)

/**
 * Pulse selected pin high for one instruction clock cycle.
 * 
 * @Note    PPS pins can also be called by their RPn name. For example: 
 * <code>PORT_RP16</code> instead of <code>PORT_RC0</code>.
 * @param   pin Pin which has to be set\n
 * - PORT_RA0\n
 * - PORT_RA1\n
 * - ...\n
 * - PORT_RC9
 * @return  none
 * @Example <code>Port_PulsePin(PORT_RA1);</code>
 */
#define Port_PulsePin(pin) Port_SetPin(pin); Nop(); Port_ClearPin(pin)

/**
 * Read the value on a port latch.
 * 
 * @Note    PPS pins can also be called by their RPn name. For example: 
 * <code>PORT_RP16</code> instead of <code>PORT_RC0</code>.
 * @param   pin Port latch to read\n
 * - PORT_RA0\n
 * - PORT_RA1\n
 * - ...\n
 * - PORT_RC9
 * @return  The value of the selected port latch, either a 0 or a 1
 * @Example <code>Port_ReadPinLatch(PORT_RA1);</code>
 */
#define Port_ReadPinLatch(pin) _JOIN_PIN(_LAT, pin)

/**
 * Read the value on a I/O pin.
 * 
 * @Note    PPS pins can also be called by their RPn name. For example: 
 * <code>PORT_RP16</code> instead of <code>PORT_RC0</code>.
 * @param   pin I/O pin to read\n
 * - PORT_RA0\n
 * - PORT_RA1\n
 * - ...\n
 * - PORT_RC9
 * @return  The value of the selected I/O pin, either a 0 or a 1
 * @Example <code>Port_ReadPin(PORT_RA1);</code>
 */
#define Port_ReadPin(pin) _JOIN_PIN(_R, pin)

#ifdef	__cplusplus
}
#endif

#endif /* PORT_H */
/* End of file Ports.h */
