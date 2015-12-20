/*******************************************************************************
 * Begin of file PeripheralPinSelect.h
 * Author: Jeroen de Bruijn
 * Created on 02 August 2015, 14:53
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
 * @brief Links the microcontroller peripherals to specified ports.
 * 
 ******************************************************************************/

#ifndef PERIPHERALPINSELECT_H
#define PERIPHERALPINSELECT_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <xc.h>
#include "Macro.h"

/*******************************************************************************
 * Defines
 ******************************************************************************/
/* Input functionality definitions */
// <editor-fold defaultstate="collapsed" desc="Input functionality definitions">
#define PPS_IN_INT1         _INT1R      /**< External Interrupt 1 tied to RPn */
#define PPS_IN_INT2         _INT2R      /**< External Interrupt 2 tied to RPn */
#define PPS_IN_T2CK         _T2CKR      /**< Timer2 External Clock tied to RPn */
#define PPS_IN_T3CK         _T3CKR      /**< Timer3 External Clock tied to RPn */
#define PPS_IN_T4CK         _T4CKR      /**< Timer4 External Clock tied to RPn */
#define PPS_IN_T5CK         _T5CKR      /**< Timer5 External Clock tied to RPn */
#define PPS_IN_IC1          _IC1R       /**< Input Capture 1 tied to RPn */
#define PPS_IN_IC2          _IC2R       /**< Input Capture 2 tied to RPn */
#define PPS_IN_IC3          _IC3R       /**< Input Capture 3 tied to RPn */
#define PPS_IN_IC4          _IC4R       /**< Input Capture 4 tied to RPn */
#define PPS_IN_IC5          _IC5R       /**< Input Capture 5 tied to RPn */
#define PPS_IN_OCFA         _OCFAR      /**< Output Compare Fault A tied to RPn */
#define PPS_IN_OCFB         _OCFBR      /**< Output Compare Fault B tied to RPn */
#define PPS_IN_U1RX         _U1RXR      /**< UART1 Receive tied to RPn */
#define PPS_IN_U1CTS        _U1CTSR     /**< UART1 Clear-to-Send tied to RPn */
#define PPS_IN_U2RX         _U2RXR      /**< UART2 Receive tied to RPn */
#define PPS_IN_U2CTS        _U2CTSR     /**< UART2 Clear-to-Send tied to RPn */
#define PPS_IN_SDI1         _SDI1R      /**< SPI1 Data Input tied to RPn */
#define PPS_IN_SCK1IN       _SCK1R      /**< SPI1 Clock Input tied to RPn */
#define PPS_IN_SS1IN        _SS1R       /**< SPI1 Slave Select Input tied to RPn */
#define PPS_IN_SDI2         _SDI2R      /**< SPI2 Data Input tied to RPn */
#define PPS_IN_SCK2IN       _SCK2R      /**< SPI2 Clock Input tied to RPn */
#define PPS_IN_SS2IN        _SS2R       /**< SPI2 Slave Select Input tied to RPn */
// </editor-fold>

/* Output functionality definitions */
// <editor-fold defaultstate="collapsed" desc="Output functionality definitions">
#define PPS_OUT_NULL        0           /**< The pin is an I/O Port pin */
#define PPS_OUT_C1OUT       1           /**< RPn tied to Comparator 1 Output */
#define PPS_OUT_C2OUT       2           /**< RPn tied to Comparator 2 Output */
#define PPS_OUT_U1TX        3           /**< RPn tied to UART1 Transmit */
#define PPS_OUT_U1RTS       4           /**< RPn tied to UART1 Ready To Send */
#define PPS_OUT_U2TX        5           /**< RPn tied to UART2 Transmit */
#define PPS_OUT_U2RTS       6           /**< RPn tied to UART2 Ready To Send */
#define PPS_OUT_SDO1        7           /**< RPn tied to SPI1 Data Output */
#define PPS_OUT_SCK1OUT     8           /**< RPn tied to SPI1 Clock Output */
#define PPS_OUT_SS1OUT      9           /**< RPn tied to SPI1 Slave Select Output */
#define PPS_OUT_SDO2        10          /**< RPn tied to SPI2 Data Output */
#define PPS_OUT_SCK2OUT     11          /**< RPn tied to SPI2 Clock Output */
#define PPS_OUT_SS2OUT      12          /**< RPn tied to SPI2 Slave Select Output */
#define PPS_OUT_OC1         18          /**< RPn tied to Output Compare 1 */
#define PPS_OUT_OC2         19          /**< RPn tied to Output Compare 2 */
#define PPS_OUT_OC3         20          /**< RPn tied to Output Compare 3 */
#define PPS_OUT_OC4         21          /**< RPn tied to Output Compare 4 */
#define PPS_OUT_OC5         22          /**< RPn tied to Output Compare 5 */
// </editor-fold>

/* Input Pin */
// <editor-fold defaultstate="collapsed" desc="Input Pin">
#define _PPS_IN_PORT_B0     0           /**< Input function tied to RP0 */
#define _PPS_IN_PORT_B1     1           /**< Input function tied to RP1 */
#define _PPS_IN_PORT_B2     2           /**< Input function tied to RP2 */
#define _PPS_IN_PORT_B3     3           /**< Input function tied to RP3 */
#define _PPS_IN_PORT_B4     4           /**< Input function tied to RP4 */
#define _PPS_IN_PORT_B5     5           /**< Input function tied to RP5 */
#define _PPS_IN_PORT_B6     6           /**< Input function tied to RP6 */
#define _PPS_IN_PORT_B7     7           /**< Input function tied to RP7 */
#define _PPS_IN_PORT_B8     8           /**< Input function tied to RP8 */
#define _PPS_IN_PORT_B9     9           /**< Input function tied to RP9 */
#define _PPS_IN_PORT_B10    10          /**< Input function tied to RP10 */
#define _PPS_IN_PORT_B11    11          /**< Input function tied to RP11 */
#define _PPS_IN_PORT_B12    12          /**< Input function tied to RP12 */
#define _PPS_IN_PORT_B13    13          /**< Input function tied to RP13 */
#define _PPS_IN_PORT_B14    14          /**< Input function tied to RP14 */
#define _PPS_IN_PORT_B15    15          /**< Input function tied to RP15 */
#define _PPS_IN_PORT_C0     16          /**< Input function tied to RP16 */
#define _PPS_IN_PORT_C1     17          /**< Input function tied to RP17 */
#define _PPS_IN_PORT_C2     18          /**< Input function tied to RP18 */
#define _PPS_IN_PORT_C3     19          /**< Input function tied to RP19 */
#define _PPS_IN_PORT_C4     20          /**< Input function tied to RP20 */
#define _PPS_IN_PORT_C5     21          /**< Input function tied to RP21 */
#define _PPS_IN_PORT_C6     22          /**< Input function tied to RP22 */
#define _PPS_IN_PORT_C7     23          /**< Input function tied to RP23 */
#define _PPS_IN_PORT_C8     24          /**< Input function tied to RP24 */
#define _PPS_IN_PORT_C9     25          /**< Input function tied to RP25 */
// </editor-fold>

/* Output Pin */
// <editor-fold defaultstate="collapsed" desc="Output Pin">
#define _PPS_OUT_PORT_B0    _RP0R       /**< RP0 tied to output function */
#define _PPS_OUT_PORT_B1    _RP1R       /**< RP1 tied to output function */
#define _PPS_OUT_PORT_B2    _RP2R       /**< RP2 tied to output function */
#define _PPS_OUT_PORT_B3    _RP3R       /**< RP3 tied to output function */
#define _PPS_OUT_PORT_B4    _RP4R       /**< RP4 tied to output function */
#define _PPS_OUT_PORT_B5    _RP5R       /**< RP5 tied to output function */
#define _PPS_OUT_PORT_B6    _RP6R       /**< RP6 tied to output function */
#define _PPS_OUT_PORT_B7    _RP7R       /**< RP7 tied to output function */
#define _PPS_OUT_PORT_B8    _RP8R       /**< RP8 tied to output function */
#define _PPS_OUT_PORT_B9    _RP9R       /**< RP9 tied to output function */
#define _PPS_OUT_PORT_B10   _RP10R      /**< RP10 tied to output function */
#define _PPS_OUT_PORT_B11   _RP11R      /**< RP11 tied to output function */
#define _PPS_OUT_PORT_B12   _RP12R      /**< RP12 tied to output function */
#define _PPS_OUT_PORT_B13   _RP13R      /**< RP13 tied to output function */
#define _PPS_OUT_PORT_B14   _RP14R      /**< RP14 tied to output function */
#define _PPS_OUT_PORT_B15   _RP15R      /**< RP15 tied to output function */
#define _PPS_OUT_PORT_C0    _RP16R      /**< RP16 tied to output function */
#define _PPS_OUT_PORT_C1    _RP17R      /**< RP17 tied to output function */
#define _PPS_OUT_PORT_C2    _RP18R      /**< RP18 tied to output function */
#define _PPS_OUT_PORT_C3    _RP19R      /**< RP19 tied to output function */
#define _PPS_OUT_PORT_C4    _RP20R      /**< RP20 tied to output function */
#define _PPS_OUT_PORT_C5    _RP21R      /**< RP21 tied to output function */
#define _PPS_OUT_PORT_C6    _RP22R      /**< RP22 tied to output function */
#define _PPS_OUT_PORT_C7    _RP23R      /**< RP23 tied to output function */
#define _PPS_OUT_PORT_C8    _RP24R      /**< RP24 tied to output function */
#define _PPS_OUT_PORT_C9    _RP25R      /**< RP25 tied to output function */
// </editor-fold>

/*******************************************************************************
 * Constant macros
 ******************************************************************************/
/**
 * @brief Follow the necessary process to clear the IOLOCK bit in order to allow
 * I/O mapping to be modified.
 * 
 * @preconditions   IOL1WAY in the Configuration Bits must be OFF
 * @note    Use inline assembly to unlock the Peripheral Pin Selection (PPS).
 * First writing the unlock sequence (46h followed by 57h) to OSCCON<7:0> and
 * than clear the IOLOCK bit in the OSCCON to disable the I/O Lock.
 */
#define PPS_UNLOCK asm volatile ( "push w1      \n"                            \
                        "push   w2              \n"                            \
                        "push   w3              \n"                            \
                        "mov    #OSCCON, w1     \n"                            \
                        "mov    #0x46, w2       \n"                            \
                        "mov    #0x57, w3       \n"                            \
                        "mov.b  w2, [w1]        \n"                            \
                        "mov.b  w3, [w1]        \n"                            \
                        "bclr   OSCCON, #6      \n"                            \
                        "pop    w3              \n"                            \
                        "pop    w2              \n"                            \
                        "pop    w1" )

/**
 * @brief Follow the necessary process to set the IOLOCK bit to lock I/O mapping
 * from being modified.
 * 
 * @preconditions   IOL1WAY in the Configuration Bits must be OFF
 * @note    Use inline assembly to lock the Peripheral Pin Selection (PPS).
 * First writing the unlock sequence (46h followed by 57h) to OSCCON<7:0> and
 * than set the IOLOCK bit in the OSCCON to enable the I/O Lock.
 */
#define PPS_LOCK   asm volatile( "push w1       \n"                            \
                        "push   w2              \n"                            \
                        "push   w3              \n"                            \
                        "mov    #OSCCON, w1     \n"                            \
                        "mov    #0x46, w2       \n"                            \
                        "mov    #0x57, w3       \n"                            \
                        "mov.b  w2, [w1]        \n"                            \
                        "mov.b  w3, [w1]        \n"                            \
                        "bset   OSCCON, #6      \n"                            \
                        "pop    w3              \n"                            \
                        "pop    w2              \n"                            \
                        "pop    w1" )

/*******************************************************************************
 * Function macros
 ******************************************************************************/
/**
 * @brief Assign input functionality to a pin.
 * 
 * @precondition    IOLOCK must be cleared.
 * @param   fn Function to be assigned to the pin.                            \n
 * FUNCTION                 DESCRIPTION                                       \n
 * - @ref PPS_IN_INT1       External Interrupt 1                              \n
 * - @ref PPS_IN_INT2       External Interrupt 2                              \n
 * - @ref PPS_IN_T2CK       Timer2 External Clock                             \n
 * - @ref PPS_IN_T3CK       Timer3 External Clock                             \n
 * - @ref PPS_IN_T4CK       Timer4 External Clock                             \n
 * - @ref PPS_IN_T5CK       Timer5 External Clock                             \n
 * - @ref PPS_IN_IC1        Input Capture 1                                   \n
 * - @ref PPS_IN_IC2        Input Capture 2                                   \n
 * - @ref PPS_IN_IC3        Input Capture 3                                   \n
 * - @ref PPS_IN_IC4        Input Capture 4                                   \n
 * - @ref PPS_IN_IC5        Input Capture 5                                   \n
 * - @ref PPS_IN_OCFA       Output Compare Fault A                            \n
 * - @ref PPS_IN_OCFB       Output Compare Fault B                            \n
 * - @ref PPS_IN_U1RX       UART1 Receive                                     \n
 * - @ref PPS_IN_U1CTS      UART1 Clear-to-Send                               \n
 * - @ref PPS_IN_U2RX       UART2 Receive                                     \n
 * - @ref PPS_IN_U2CTS      UART2 Clear-to-Send                               \n
 * - @ref PPS_IN_SDI1       SPI1 Data Input                                   \n
 * - @ref PPS_IN_SCK1IN     SPI1 Clock Input                                  \n
 * - @ref PPS_IN_SS1IN      SPI1 Slave Select Input                           \n
 * - @ref PPS_IN_SDI2       SPI2 Data Input                                   \n
 * - @ref PPS_IN_SCK2IN     SPI2 Clock Input                                  \n
 * - @ref PPS_IN_SS2IN      SPI2 Slave Select Input                           \n
 * @param   pin Pin which the functionality has to be assigned to.            \n
 * - @ref PORT_RP0                                                            \n
 * - @ref PORT_RP1                                                            \n
 * - ...                                                                      \n
 * - @ref PORT_RP24                                                           \n
 * - @ref PORT_RP25                                                           \n
 * For the complete list of possible pins see the list of defines above,
 * starting with @ref PORT_RP0.
 */
#define PPS_ASSIGN_INPUT(fn, pin)                                              \
    fn = MACRO_EXPAND_CONCATENATE_TWO(_PPS_IN_PORT_, pin);                     \
    Nop()

/**
 * @brief Assign pin to an output functionality.
 * 
 * @preconditions   IOLOCK must be cleared.
 * @param   pin Pin which the functionality has to be assigned to.            \n
 * - @ref PORT_RP0                                                            \n
 * - @ref PORT_RP1                                                            \n
 * - ...                                                                      \n
 * - @ref PORT_RP24                                                           \n
 * - @ref PORT_RP25                                                           \n
 * For the complete list of possible pins see the list of defines above,
 * starting with @ref PORT_RP0.
 * @param   fn Function to be assigned to the pin.                            \n
 * FUNCTION                 DESCRIPTION                                       \n
 * - @ref PPS_OUT_NULL      The pin is an I/O Port pin                        \n
 * - @ref PPS_OUT_C1OUT     Comparator 1 Output                               \n
 * - @ref PPS_OUT_C2OUT     Comparator 2 Output                               \n
 * - @ref PPS_OUT_U1TX      UART1 Transmit                                    \n
 * - @ref PPS_OUT_U1RTS     UART1 Ready To Send                               \n
 * - @ref PPS_OUT_U2TX      UART2 Transmit                                    \n
 * - @ref PPS_OUT_U2RTS     UART2 Ready To Send                               \n
 * - @ref PPS_OUT_SDO1      SPI1 Data Output                                  \n
 * - @ref PPS_OUT_SCK1OUT   SPI1 Clock Output                                 \n
 * - @ref PPS_OUT_SS1OUT    SPI1 Slave Select Output                          \n
 * - @ref PPS_OUT_SDO2      SPI2 Data Output                                  \n
 * - @ref PPS_OUT_SCK2OUT   SPI2 Clock Output                                 \n
 * - @ref PPS_OUT_SS2OUT    SPI2 Slave Select Output                          \n
 * - @ref PPS_OUT_OC1       Output Compare 1                                  \n
 * - @ref PPS_OUT_OC2       Output Compare 2                                  \n
 * - @ref PPS_OUT_OC3       Output Compare 3                                  \n
 * - @ref PPS_OUT_OC4       Output Compare 4                                  \n
 * - @ref PPS_OUT_OC5       Output Compare 5                                  \n
 */
#define PPS_ASSIGN_OUTPUT(pin, fn)                                             \
    MACRO_EXPAND_CONCATENATE_TWO(_PPS_OUT_PORT_, pin) = fn;                    \
    Nop()

#ifdef __cplusplus
}
#endif

#endif /* PERIPHERALPINSELECT_H */
/* End of file PeripheralPinSelect.h */
