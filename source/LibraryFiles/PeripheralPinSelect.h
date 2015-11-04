/*******************************************************************************
 * Begin of file PeripheralPinSelect.h
 * Author: Jeroen de Bruijn
 * Created on 02 August 2015, 14:53
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
 *  Links the microcontroller peripherals to specified ports.
 * 
 ******************************************************************************/

#ifndef PERIPHERALPINSELECT_H
#define	PERIPHERALPINSELECT_H

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
/* Input functionality definitions */
// <editor-fold defaultstate="collapsed" desc="Input functionality definitions">
#define PPS_IN_INT1         _INT1R          /* External Interrupt 1 tied to RPn */
#define PPS_IN_INT2         _INT2R          /* External Interrupt 2 tied to RPn */
#define PPS_IN_T2CK         _T2CKR          /* Timer2 External Clock tied to RPn */
#define PPS_IN_T3CK         _T3CKR          /* Timer3 External Clock tied to RPn */
#define PPS_IN_T4CK         _T4CKR          /* Timer4 External Clock tied to RPn */
#define PPS_IN_T5CK         _T5CKR          /* Timer5 External Clock tied to RPn */
#define PPS_IN_IC1          _IC1R           /* Input Capture 1 tied to RPn */
#define PPS_IN_IC2          _IC2R           /* Input Capture 2 tied to RPn */
#define PPS_IN_IC3          _IC3R           /* Input Capture 3 tied to RPn */
#define PPS_IN_IC4          _IC4R           /* Input Capture 4 tied to RPn */
#define PPS_IN_IC5          _IC5R           /* Input Capture 5 tied to RPn */
#define PPS_IN_OCFA         _OCFAR          /* Output Compare Fault A tied to RPn */
#define PPS_IN_OCFB         _OCFBR          /* Output Compare Fault B tied to RPn */
#define PPS_IN_U1RX         _U1RXR          /* UART1 Receive tied to RPn */
#define PPS_IN_U1CTS        _U1CTSR         /* UART1 Clear-to-Send tied to RPn */
#define PPS_IN_U2RX         _U2RXR          /* UART2 Receive tied to RPn */
#define PPS_IN_U2CTS        _U2CTSR         /* UART2 Clear-to-Send tied to RPn */
#define PPS_IN_SDI1         _SDI1R          /* SPI1 Data Input tied to RPn */
#define PPS_IN_SCK1IN       _SCK1R          /* SPI1 Clock Input tied to RPn */
#define PPS_IN_SS1IN        _SS1R           /* SPI1 Slave Select Input tied to RPn */
#define PPS_IN_SDI2         _SDI2R          /* SPI2 Data Input tied to RPn */
#define PPS_IN_SCK2IN       _SCK2R          /* SPI2 Clock Input tied to RPn */
#define PPS_IN_SS2IN        _SS2R           /* SPI2 Slave Select Input tied to RPn */
// </editor-fold>

/* Output functionality definitions */
// <editor-fold defaultstate="collapsed" desc="Output functionality definitions">
#define PPS_OUT_NULL        0               /* The pin is an I/O Port pin */
#define PPS_OUT_C1OUT       1               /* RPn tied to Comparator 1 Output */
#define PPS_OUT_C2OUT       2               /* RPn tied to Comparator 2 Output */
#define PPS_OUT_U1TX        3               /* RPn tied to UART1 Transmit */
#define PPS_OUT_U1RTS       4               /* RPn tied to UART1 Ready To Send */
#define PPS_OUT_U2TX        5               /* RPn tied to UART2 Transmit */
#define PPS_OUT_U2RTS       6               /* RPn tied to UART2 Ready To Send */
#define PPS_OUT_SDO1        7               /* RPn tied to SPI1 Data Output */
#define PPS_OUT_SCK1OUT     8               /* RPn tied to SPI1 Clock Output */
#define PPS_OUT_SS1OUT      9               /* RPn tied to SPI1 Slave Select Output */
#define PPS_OUT_SDO2        10              /* RPn tied to SPI2 Data Output */
#define PPS_OUT_SCK2OUT     11              /* RPn tied to SPI2 Clock Output */
#define PPS_OUT_SS2OUT      12              /* RPn tied to SPI2 Slave Select Output */
#define PPS_OUT_OC1         18              /* RPn tied to Output Compare 1 */
#define PPS_OUT_OC2         19              /* RPn tied to Output Compare 2 */
#define PPS_OUT_OC3         20              /* RPn tied to Output Compare 3 */
#define PPS_OUT_OC4         21              /* RPn tied to Output Compare 4 */
#define PPS_OUT_OC5         22              /* RPn tied to Output Compare 5 */
// </editor-fold>

/* Input Pin */
// <editor-fold defaultstate="collapsed" desc="Input Pin">
#define _PPS_IN_PORT_B0     0               /* Input function tied to RP0 */
#define _PPS_IN_PORT_B1     1               /* Input function tied to RP1 */
#define _PPS_IN_PORT_B2     2               /* Input function tied to RP2 */
#define _PPS_IN_PORT_B3     3               /* Input function tied to RP3 */
#define _PPS_IN_PORT_B4     4               /* Input function tied to RP4 */
#define _PPS_IN_PORT_B5     5               /* Input function tied to RP5 */
#define _PPS_IN_PORT_B6     6               /* Input function tied to RP6 */
#define _PPS_IN_PORT_B7     7               /* Input function tied to RP7 */
#define _PPS_IN_PORT_B8     8               /* Input function tied to RP8 */
#define _PPS_IN_PORT_B9     9               /* Input function tied to RP9 */
#define _PPS_IN_PORT_B10    10              /* Input function tied to RP10 */
#define _PPS_IN_PORT_B11    11              /* Input function tied to RP11 */
#define _PPS_IN_PORT_B12    12              /* Input function tied to RP12 */
#define _PPS_IN_PORT_B13    13              /* Input function tied to RP13 */
#define _PPS_IN_PORT_B14    14              /* Input function tied to RP14 */
#define _PPS_IN_PORT_B15    15              /* Input function tied to RP15 */
#define _PPS_IN_PORT_C0     16              /* Input function tied to RP16 */
#define _PPS_IN_PORT_C1     17              /* Input function tied to RP17 */
#define _PPS_IN_PORT_C2     18              /* Input function tied to RP18 */
#define _PPS_IN_PORT_C3     19              /* Input function tied to RP19 */
#define _PPS_IN_PORT_C4     20              /* Input function tied to RP20 */
#define _PPS_IN_PORT_C5     21              /* Input function tied to RP21 */
#define _PPS_IN_PORT_C6     22              /* Input function tied to RP22 */
#define _PPS_IN_PORT_C7     23              /* Input function tied to RP23 */
#define _PPS_IN_PORT_C8     24              /* Input function tied to RP24 */
#define _PPS_IN_PORT_C9     25              /* Input function tied to RP25 */
// </editor-fold>

/* Output Pin */
// <editor-fold defaultstate="collapsed" desc="Output Pin">
#define _PPS_OUT_PORT_B0    _RP0R           /* RP0 tied to output function */
#define _PPS_OUT_PORT_B1    _RP1R           /* RP1 tied to output function */
#define _PPS_OUT_PORT_B2    _RP2R           /* RP2 tied to output function */
#define _PPS_OUT_PORT_B3    _RP3R           /* RP3 tied to output function */
#define _PPS_OUT_PORT_B4    _RP4R           /* RP4 tied to output function */
#define _PPS_OUT_PORT_B5    _RP5R           /* RP5 tied to output function */
#define _PPS_OUT_PORT_B6    _RP6R           /* RP6 tied to output function */
#define _PPS_OUT_PORT_B7    _RP7R           /* RP7 tied to output function */
#define _PPS_OUT_PORT_B8    _RP8R           /* RP8 tied to output function */
#define _PPS_OUT_PORT_B9    _RP9R           /* RP9 tied to output function */
#define _PPS_OUT_PORT_B10   _RP10R          /* RP10 tied to output function */
#define _PPS_OUT_PORT_B11   _RP11R          /* RP11 tied to output function */
#define _PPS_OUT_PORT_B12   _RP12R          /* RP12 tied to output function */
#define _PPS_OUT_PORT_B13   _RP13R          /* RP13 tied to output function */
#define _PPS_OUT_PORT_B14   _RP14R          /* RP14 tied to output function */
#define _PPS_OUT_PORT_B15   _RP15R          /* RP15 tied to output function */
#define _PPS_OUT_PORT_C0    _RP16R          /* RP16 tied to output function */
#define _PPS_OUT_PORT_C1    _RP17R          /* RP17 tied to output function */
#define _PPS_OUT_PORT_C2    _RP18R          /* RP18 tied to output function */
#define _PPS_OUT_PORT_C3    _RP19R          /* RP19 tied to output function */
#define _PPS_OUT_PORT_C4    _RP20R          /* RP20 tied to output function */
#define _PPS_OUT_PORT_C5    _RP21R          /* RP21 tied to output function */
#define _PPS_OUT_PORT_C6    _RP22R          /* RP22 tied to output function */
#define _PPS_OUT_PORT_C7    _RP23R          /* RP23 tied to output function */
#define _PPS_OUT_PORT_C8    _RP24R          /* RP24 tied to output function */
#define _PPS_OUT_PORT_C9    _RP25R          /* RP25 tied to output function */
// </editor-fold>


/*******************************************************************************
 * Macros
 ******************************************************************************/
/**
 * Macros and helper macros to join defines and arguments. The functions below
 * will use the macros to join defines.
 * 
 * @Note	The macros need a second helper macro in order to expand multiple
 * defines.
 * 
 * For details about macro replacement and argument substitution
 * @see http://stackoverflow.com/a/1489985
 */
#define _HELPER_JOIN_PPS_PIN(prefix, pin) prefix##pin
#define _JOIN_PPS_PIN(prefix, pin) _HELPER_JOIN_PPS_PIN(prefix, pin)

/**
 * Assign input functionality to a pin.
 * 
 * @Precondition    IOLOCK must be cleared.
 * @param   fn Function to be assigned to the pin.\n
 * FUNCTION             &#09 DESCRIPTION\n
 * - PPS_IN_INT1        &#09 External Interrupt 1\n
 * - PPS_IN_INT2        &#09 External Interrupt 2\n
 * - PPS_IN_T2CK        &#09 Timer2 External Clock\n
 * - PPS_IN_T3CK        &#09 Timer3 External Clock\n
 * - PPS_IN_T4CK        &#09 Timer4 External Clock\n
 * - PPS_IN_T5CK        &#09 Timer5 External Clock\n
 * - PPS_IN_IC1         &#09 Input Capture 1\n
 * - PPS_IN_IC2         &#09 Input Capture 2\n
 * - PPS_IN_IC3         &#09 Input Capture 3\n
 * - PPS_IN_IC4         &#09 Input Capture 4\n
 * - PPS_IN_IC5         &#09 Input Capture 5\n
 * - PPS_IN_OCFA        &#09 Output Compare Fault A\n
 * - PPS_IN_OCFB        &#09 Output Compare Fault B\n
 * - PPS_IN_U1RX        &#09 UART1 Receive\n
 * - PPS_IN_U1CTS       &#09 UART1 Clear-to-Send\n
 * - PPS_IN_U2RX        &#09 UART2 Receive\n
 * - PPS_IN_U2CTS       &#09 UART2 Clear-to-Send\n
 * - PPS_IN_SDI1        &#09 SPI1 Data Input\n
 * - PPS_IN_SCK1IN      &#09 SPI1 Clock Input\n
 * - PPS_IN_SS1IN       &#09 SPI1 Slave Select Input\n
 * - PPS_IN_SDI2        &#09 SPI2 Data Input\n
 * - PPS_IN_SCK2IN      &#09 SPI2 Clock Input\n
 * - PPS_IN_SS2IN       &#09 SPI2 Slave Select Input\n
 * @param   pin Pin which the functionality has to be assigned to.\n
 * - PORT_RP0\n
 * - PORT_RP1\n
 * - ...\n
 * - PORT_RP25
 * @return  none
 * @Example <code>PPSInput(PPS_IN_U1RX, PORT_RP11);</code>
 */
#define PPSInput(fn, pin) fn = _JOIN_PPS_PIN(_PPS_IN_PORT_, pin); Nop()

/**
 * Assign pin to an output functionality.
 * 
 * @Preconditions   IOLOCK must be cleared.
 * @param   pin Pin which the functionality has to be assigned to.\n
 * - PORT_RP0\n
 * - PORT_RP1\n
 * - ...\n
 * - PORT_RP25
 * @param   fn Function to be assigned to the pin.\n
 * FUNCTION             &#09 DESCRIPTION\n
 * * PPS_OUT_NULL       &#09 The pin is an I/O Port pin\n
 * - PPS_OUT_C1OUT      &#09 Comparator 1 Output\n
 * - PPS_OUT_C2OUT      &#09 Comparator 2 Output\n
 * - PPS_OUT_U1TX       &#09 UART1 Transmit\n
 * - PPS_OUT_U1RTS      &#09 UART1 Ready To Send\n
 * - PPS_OUT_U2TX       &#09 UART2 Transmit\n
 * - PPS_OUT_U2RTS      &#09 UART2 Ready To Send\n
 * - PPS_OUT_SDO1       &#09 SPI1 Data Output\n
 * - PPS_OUT_SCK1OUT    &#09 SPI1 Clock Output\n
 * - PPS_OUT_SS1OUT     &#09 SPI1 Slave Select Output\n
 * - PPS_OUT_SDO2       &#09 SPI2 Data Output\n
 * - PPS_OUT_SCK2OUT    &#09 SPI2 Clock Output\n
 * - PPS_OUT_SS2OUT     &#09 SPI2 Slave Select Output\n
 * - PPS_OUT_OC1        &#09 Output Compare 1\n
 * - PPS_OUT_OC2        &#09 Output Compare 2\n
 * - PPS_OUT_OC3        &#09 Output Compare 3\n
 * - PPS_OUT_OC4        &#09 Output Compare 4\n
 * - PPS_OUT_OC5        &#09 Output Compare 5\n
 * @return  none
 * @Example <code>PPSInput(PORT_RP12, PPS_OUT_U1TX);</code>
 */
#define PPSOutput(pin, fn) _JOIN_PPS_PIN(_PPS_OUT_PORT_, pin) = fn; Nop()

/**
 * Follow the necessary process to clear the IOLOCK bit in order to allow 
 * I/O mapping to be modified.
 * 
 * @Preconditions   IOL1WAY in the Configuration Bits must be OFF
 * @Note    Use inline assembly to unlock the Peripheral Pin Selection (PPS).
 * First writing the unlock sequence (46h followed by 57h) to OSCCON<7:0> and
 * than clear the IOLOCK bit in the OSCCON to disable the I/O Lock.
 * @Example <code>PPSUnlock();</code>
 */
#define PPSUnlock() asm volatile    ( "push w1  \n" \
                        "push   w2              \n" \
                        "push   w3              \n" \
                        "mov    #OSCCON, w1     \n" \
                        "mov    #0x46, w2       \n" \
                        "mov    #0x57, w3       \n" \
                        "mov.b  w2, [w1]        \n" \
                        "mov.b  w3, [w1]        \n" \
                        "bclr   OSCCON, #6      \n" \
                        "pop    w3              \n" \
                        "pop    w2              \n" \
                        "pop    w1" )

/**
 * Follow the necessary process to set the IOLOCK bit to lock I/O mapping from
 * being modified.
 * 
 * @Preconditions   IOL1WAY in the Configuration Bits must be OFF
 * @Note    Use inline assembly to lock the Peripheral Pin Selection (PPS).
 * First writing the unlock sequence (46h followed by 57h) to OSCCON<7:0> and
 * than set the IOLOCK bit in the OSCCON to enable the I/O Lock.
 * @Example <code>PPSLock();</code>
 */
#define PPSLock()   asm volatile    ( "push w1  \n" \
                        "push   w2              \n" \
                        "push   w3              \n" \
                        "mov    #OSCCON, w1     \n" \
                        "mov    #0x46, w2       \n" \
                        "mov    #0x57, w3       \n" \
                        "mov.b  w2, [w1]        \n" \
                        "mov.b  w3, [w1]        \n" \
                        "bset   OSCCON, #6      \n" \
                        "pop    w3              \n" \
                        "pop    w2              \n" \
                        "pop    w1" )

#ifdef	__cplusplus
}
#endif

#endif	/* PERIPHERALPINSELECT_H */
/* End of file PeripheralPinSelect.h */
