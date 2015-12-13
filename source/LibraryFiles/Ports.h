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
 * For full license details see file "main.c" or "LICENSE" or go to
 * https://opensource.org/licenses/MIT
 * 
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file 
 * @brief Control macros for all I/O operations.
 * 
 * When first configuring all ports, the macro @ref PORT_INITIALIZE_ALL_PINS
 * should be called before configuring the I/O ports. This will to configure all
 * pins in a default state.
 * @note This file uses the defines for the ports that are defined in the
 * device's header file.
 * 
 ******************************************************************************/

#ifndef PORT_H
#define	PORT_H

#ifdef	__cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Defines
 ******************************************************************************/
/* Pins */
// <editor-fold defaultstate="collapsed" desc="Pins">
#define PORT_RA0    A0          /**< Pin RA0 */
#define PORT_RA1    A1          /**< Pin RA1 */
#define PORT_RA2    A2          /**< Pin RA2 */
#define PORT_RA3    A3          /**< Pin RA3 */
#define PORT_RA4    A4          /**< Pin RA4 */
#define PORT_RA7    A7          /**< Pin RA7 */
#define PORT_RA8    A8          /**< Pin RA8 */
#define PORT_RA9    A9          /**< Pin RA9 */
#define PORT_RA10   A10         /**< Pin RA10 */
#define PORT_RB0    B0          /**< Pin RB0 */
#define PORT_RB1    B1          /**< Pin RB1 */
#define PORT_RB2    B2          /**< Pin RB2 */
#define PORT_RB3    B3          /**< Pin RB3 */
#define PORT_RB4    B4          /**< Pin RB4 */
#define PORT_RB5    B5          /**< Pin RB5 */
#define PORT_RB6    B6          /**< Pin RB6 */
#define PORT_RB7    B7          /**< Pin RB7 */
#define PORT_RB8    B8          /**< Pin RB8 */
#define PORT_RB9    B9          /**< Pin RB9 */
#define PORT_RB10   B10         /**< Pin RB10 */
#define PORT_RB11   B11         /**< Pin RB11 */
#define PORT_RB12   B12         /**< Pin RB12 */
#define PORT_RB13   B13         /**< Pin RB13 */
#define PORT_RB14   B14         /**< Pin RB14 */
#define PORT_RB15   B15         /**< Pin RB15 */
#define PORT_RC0    C0          /**< Pin RC0 */
#define PORT_RC1    C1          /**< Pin RC1 */
#define PORT_RC2    C2          /**< Pin RC2 */
#define PORT_RC3    C3          /**< Pin RC3 */
#define PORT_RC4    C4          /**< Pin RC4 */
#define PORT_RC5    C5          /**< Pin RC5 */
#define PORT_RC6    C6          /**< Pin RC6 */
#define PORT_RC7    C7          /**< Pin RC7 */
#define PORT_RC8    C8          /**< Pin RC8 */
#define PORT_RC9    C9          /**< Pin RC9 */
// </editor-fold>

/* Remappable Pins */
// <editor-fold defaultstate="collapsed" desc="Remappable Pins">
#define PORT_RP0    PORT_RB0    /**< Remappable pin RP0 to @ref PORT_RB0 */
#define PORT_RP1    PORT_RB1    /**< Remappable pin RP1 to @ref PORT_RB1 */
#define PORT_RP2    PORT_RB2    /**< Remappable pin RP2 to @ref PORT_RB2 */
#define PORT_RP3    PORT_RB3    /**< Remappable pin RP3 to @ref PORT_RB3 */
#define PORT_RP4    PORT_RB4    /**< Remappable pin RP4 to @ref PORT_RB4 */
#define PORT_RP5    PORT_RB5    /**< Remappable pin RP5 to @ref PORT_RB5 */
#define PORT_RP6    PORT_RB6    /**< Remappable pin RP6 to @ref PORT_RB6 */
#define PORT_RP7    PORT_RB7    /**< Remappable pin RP7 to @ref PORT_RB7 */
#define PORT_RP8    PORT_RB8    /**< Remappable pin RP8 to @ref PORT_RB8 */
#define PORT_RP9    PORT_RB9    /**< Remappable pin RP9 to @ref PORT_RB9 */
#define PORT_RP10   PORT_RB10   /**< Remappable pin RP10 to @ref PORT_RB10 */
#define PORT_RP11   PORT_RB11   /**< Remappable pin RP11 to @ref PORT_RB11 */
#define PORT_RP12   PORT_RB12   /**< Remappable pin RP12 to @ref PORT_RB12 */
#define PORT_RP13   PORT_RB13   /**< Remappable pin RP13 to @ref PORT_RB13 */
#define PORT_RP14   PORT_RB14   /**< Remappable pin RP14 to @ref PORT_RB14 */
#define PORT_RP15   PORT_RB15   /**< Remappable pin RP15 to @ref PORT_RB15 */
#define PORT_RP16   PORT_RC0    /**< Remappable pin RP16 to @ref PORT_RC0 */
#define PORT_RP17   PORT_RC1    /**< Remappable pin RP17 to @ref PORT_RC1 */
#define PORT_RP18   PORT_RC2    /**< Remappable pin RP18 to @ref PORT_RC2 */
#define PORT_RP19   PORT_RC3    /**< Remappable pin RP19 to @ref PORT_RC3 */
#define PORT_RP20   PORT_RC4    /**< Remappable pin RP20 to @ref PORT_RC4 */
#define PORT_RP21   PORT_RC5    /**< Remappable pin RP21 to @ref PORT_RC5 */
#define PORT_RP22   PORT_RC6    /**< Remappable pin RP22 to @ref PORT_RC6 */
#define PORT_RP23   PORT_RC7    /**< Remappable pin RP23 to @ref PORT_RC7 */
#define PORT_RP24   PORT_RC8    /**< Remappable pin RP24 to @ref PORT_RC8 */
#define PORT_RP25   PORT_RC9    /**< Remappable pin RP25 to @ref PORT_RC9 */
// </editor-fold>

/*******************************************************************************
 * Constant macros
 ******************************************************************************/
/**
 * @brief Configure all pins to be in digital mode instead of analog mode.
 */
#define _PORT_CONFIGURE_ALL_PINS_AS_DIGITAL AD1PCFG = 0xFFFF

/**
 * @brief Configure all pins to be outputs.
 */
#define _PORT_CONFIGURE_ALL_PINS_AS_OUTPUT                                     \
do {                                                                           \
    TRISA = 0x0000;                                                            \
    TRISB = 0x0000;                                                            \
    TRISC = 0x0000;                                                            \
} while (0)

/**
 * @brief Configure all pins to be in digital mode and be outputs.
 * 
 * Uses @ref _PORT_CONFIGURE_ALL_PINS_AS_DIGITAL and @ref
 * _PORT_CONFIGURE_ALL_PINS_AS_OUTPUT to configure the pins.
 */
#define PORT_INITIALIZE_ALL_PINS                                               \
do {                                                                           \
    _PORT_CONFIGURE_ALL_PINS_AS_DIGITAL;                                       \
    _PORT_CONFIGURE_ALL_PINS_AS_OUTPUT;                                        \
} while (0)

/*******************************************************************************
 * Function macros
 ******************************************************************************/
/**
 * Macros and helper macros to join defines and arguments. The functions below
 * will use the macros to join defines.
 * 
 * @note	The macros need a second helper macro in order to expand multiple
 * defines.
 * 
 * For details about macro replacement and argument substitution
 * @see http://stackoverflow.com/a/1489985
 */
#define _HELPER_JOIN_PIN(func, pin)         func ## pin
#define _JOIN_PIN(func, pin)                _HELPER_JOIN_PIN(func, pin)
#define _HELPER_JOIN_ASSIGN(func, pin, val) _JOIN_PIN(func, pin) = val
#define _JOIN_ASSIGN(func, pin, val)        _HELPER_JOIN_ASSIGN(func, pin, val)
#define _HELPER_JOIN_TOGGLE(func, pin)                                         \
                _JOIN_PIN(func, pin) = ~ _JOIN_PIN(func, pin)
#define _JOIN_TOGGLE(func, pin)             _HELPER_JOIN_TOGGLE(func, pin)

/**
 * @brief Configure selected pin as digital input.
 * 
 * @note    PPS pins can also be called by their RPn name. For example: 
 * @ref PORT_RP16 instead of @ref PORT_RC0.
 * @param   pin Pin which has to be configure as digital input\n
 * - @ref PORT_RA0  \n
 * - @ref PORT_RA1  \n
 * - ...            \n
 * - @ref PORT_RC8  \n
 * - @ref PORT_RC9  \n
 * or               \n
 * - @ref PORT_RP0  \n
 * - @ref PORT_RP1  \n
 * - ...            \n
 * - @ref PORT_RP24 \n
 * - @ref PORT_RP25 \n
 * For the complete list of possible pins see the list of defines above,
 * starting with @ref PORT_RA0.
 */
#define PORT_CONFIGURE_PIN_AS_DIGITAL_INPUT(pin)                               \
do {                                                                           \
    _JOIN_ASSIGN(_TRIS, pin, 1);                                               \
    _JOIN_ASSIGN(_OD, pin, 0);                                                 \
} while (0)

/**
 * @brief Configure selected pin as digital output.
 * 
 * @note    PPS pins can also be called by their RPn name. For example: 
 * @ref PORT_RP16 instead of @ref PORT_RC0.
 * @param   pin Pin which has to be configured as normal digital output. For
 * more info on how to use this parameter see the description of the @ref
 * PORT_CONFIGURE_PIN_AS_DIGITAL_INPUT macro.
 */
#define PORT_CONFIGURE_PIN_AS_DIGITAL_OUTPUT(pin)                              \
do {                                                                           \
    _JOIN_ASSIGN(_TRIS, pin, 0);                                               \
    _JOIN_ASSIGN(_OD, pin, 0);                                                 \
} while (0)

/**
 * @brief Configure selected pin as digital output.
 * 
 * @note    PPS pins can also be called by their RPn name. For example: 
 * @ref PORT_RP16 instead of @ref PORT_RC0.
 * @param   pin Pin which has to be configured as normal digital output. For
 * more info on how to use this parameter see the description of the @ref
 * PORT_CONFIGURE_PIN_AS_DIGITAL_INPUT macro.
 */
#define PORT_CONFIGURE_PIN_AS_OPEN_DRAIN_OUTPUT(pin) _JOIN_ASSIGN(_OD, pin, 1)

/**
 * @brief Set selected pin, i.e make the output high.
 * 
 * @note    PPS pins can also be called by their RPn name. For example: 
 * @ref PORT_RP16 instead of @ref PORT_RC0.
 * @param   pin Pin which has to be configured as normal digital output. For
 * more info on how to use this parameter see the description of the @ref
 * PORT_CONFIGURE_PIN_AS_DIGITAL_INPUT macro.
 */
#define PORT_SET_PIN(pin) _JOIN_ASSIGN(_LAT, pin, 1)

/**
 * @brief Clear selected pin, i.e make the output low.
 * 
 * @note    PPS pins can also be called by their RPn name. For example: 
 * @ref PORT_RP16 instead of @ref PORT_RC0.
 * @param   pin Pin which has to be configured as normal digital output. For
 * more info on how to use this parameter see the description of the @ref
 * PORT_CONFIGURE_PIN_AS_DIGITAL_INPUT macro.
 */
#define PORT_CLEAR_PIN(pin) _JOIN_ASSIGN(_LAT, pin, 0)



/**
 * @brief Toggle selected pin, invert the output.
 * 
 * @note    PPS pins can also be called by their RPn name. For example: 
 * @ref PORT_RP16 instead of @ref PORT_RC0.
 * @param   pin Pin which has to be configured as normal digital output. For
 * more info on how to use this parameter see the description of the @ref
 * PORT_CONFIGURE_PIN_AS_DIGITAL_INPUT macro.
 */
#define PORT_TOGGLE_PIN(pin) _JOIN_TOGGLE(_LAT, pin)

/**
 * @brief Pulse selected pin high for one instruction clock cycle.
 * 
 * @note    PPS pins can also be called by their RPn name. For example: 
 * @ref PORT_RP16 instead of @ref PORT_RC0.
 * @param   pin Pin which has to be configured as normal digital output. For
 * more info on how to use this parameter see the description of the @ref
 * PORT_CONFIGURE_PIN_AS_DIGITAL_INPUT macro.
 */
#define PORT_PULSE_PIN(pin) PORT_SET_PIN(pin); Nop(); PORT_CLEAR_PIN(pin)

/**
 * @brief Read the value on a port latch.
 * 
 * @note    PPS pins can also be called by their RPn name. For example: 
 * @ref PORT_RP16 instead of @ref PORT_RC0.
 * @param   pin Pin which has to be configured as normal digital output. For
 * more info on how to use this parameter see the description of the @ref
 * PORT_CONFIGURE_PIN_AS_DIGITAL_INPUT macro.
 */
#define PORT_READ_PIN_LATCH(pin) _JOIN_PIN(_LAT, pin)

/**
 * @brief Read the value on an I/O pin.
 * 
 * @note    PPS pins can also be called by their RPn name. For example: 
 * @ref PORT_RP16 instead of @ref PORT_RC0.
 * @param   pin Pin which has to be configured as normal digital output. For
 * more info on how to use this parameter see the description of the @ref
 * PORT_CONFIGURE_PIN_AS_DIGITAL_INPUT macro.
 */
#define PORT_READ_PIN(pin) _JOIN_PIN(_R, pin)

/**
 * @brief Reset all the settings of the selected pin.
 * 
 * This clears the output of the pin and makes it a normal digital output. This
 * is performed by setting and clearing the bits for this pin in the LATx, ODCx
 * and TRISx registers. The PORTx register does not need to be cleared because
 * this is the register for the data on an I/O pin, so it is only used for
 * reading the pin's state.
 * 
 * @note    This does not change the analog functionality of the pin. If it used
 * to be an analog pin the user still need to disable the analog functionality
 * for this specific pin.
 * @note    PPS pins can also be called by their RPn name. For example: 
 * @ref PORT_RP16 instead of @ref PORT_RC0.
 * @param   pin Pin which has to be configured as normal digital output. For
 * more info on how to use this parameter see the description of the @ref
 * PORT_CONFIGURE_PIN_AS_DIGITAL_INPUT macro.
 */
#define PORT_RESET_CONFIGURATION(pin)                                          \
do {                                                                           \
    PORT_CLEAR_PIN(pin);                                                       \
    PORT_CONFIGURE_PIN_AS_DIGITAL_OUTPUT(pin);                                 \
} while (0)

#ifdef	__cplusplus
}
#endif

#endif /* PORT_H */
/* End of file Ports.h */
