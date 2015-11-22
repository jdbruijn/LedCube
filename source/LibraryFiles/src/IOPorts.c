/*******************************************************************************
 * Begin of file IOPorts.c
 * Author: Jeroen de Bruijn
 * Created on 02 August 2015, 21:01
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
#include "IOPorts.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
/**
 * Configure the used I/O ports using the PPS library.
 * 
 */
void
IOPorts_init( ) {
    /********** Assign I/Os to functionalities ********************************/
    PPSUnlock();
    
    /* LedDriver */
    PPSOutput(SPI1_SDO, PPS_OUT_SDO1);
    PPSOutput(SPI1_SCK, PPS_OUT_SCK1OUT);
    /* Anode Control */
    PPSOutput(SPI2_SDO, PPS_OUT_SDO2);
    PPSOutput(SPI2_SCK, PPS_OUT_SCK2OUT);
    /* USB to UART */
    PPSOutput(USB_TO_UART_TX, PPS_OUT_U1TX);
    PPSInput(PPS_IN_U1RX, USB_TO_UART_RX);
    PPSInput(PPS_IN_U1CTS, USB_TO_UART_CTS);
    PPSOutput(USB_TO_UART_RTS, PPS_OUT_U1RTS);
    /* Bluetooth */
//    PPSOutput(BT_UART_TX, PPS_OUT_U2TX);
//    PPSInput(PPS_IN_U2RX, BT_UART_RX);
//    PPSInput(PPS_IN_U2CTS, BT_UART_CTS);
//    PPSOutput(BT_UART_RTS, PPS_OUT_U2RTS);
    /* Buzzer */
    PPSOutput(BUZZER, PPS_OUT_OC1);
    
    PPSLock();

    /********** Configure I/Os ************************************************/
    Port_ConfigureAllPinsDigital();
    
    /* LedDriver */
    Port_ConfigurePinDigitalOut(SPI1_SDO);
    Port_ConfigurePinDigitalOut(SPI1_SCK);
    Port_ConfigurePinDigitalOut(LD_LE);
    /* Anode Conrol */
    Port_ConfigurePinDigitalOut(SPI2_SDO);
    Port_ConfigurePinDigitalOut(SPI2_SCK);
    Port_ConfigurePinDigitalOut(ANODE_LATCH);
    /* LedDriver & Anode Control */
#ifdef USE_OE_STATE_EXTENDER
    Port_ConfigurePinDigitalIn(OE);
#else
    Port_ConfigurePinDigitalOut(OE);
#endif
    /* USB to UART */
    Port_ConfigurePinDigitalIn(USB_TO_UART_RX);
    Port_ConfigurePinDigitalOut(USB_TO_UART_TX);
    Port_ConfigurePinDigitalOut(USB_TO_UART_CTS);
    Port_ConfigurePinDigitalIn(USB_TO_UART_RTS);
    /* Bluetooth */
//    Port_SetPinDigitalIn(BT_UART_TX);
//    Port_SetPinDigitalOut(BT_UART_RX);
//    Port_SetPinDigitalOut(BT_UART_CTS);
//    Port_SetPinDigitalIn(BT_UART_RTS);
//    Port_SetPinDigitalOut(BT_CMD_MLDP);
//    Port_SetPinDigitalOut(BT_WAKE_HW);
//    Port_SetPinDigitalOut(BT_WAKE_SW);
//    Port_SetPinDigitalIn(BT_CONNECTSTATUS);
//    Port_SetPinDigitalIn(BT_MLDP_EV);
//    Port_SetPinDigitalIn(BT_WS);
//    Port_SetPinDigitalOut(BT_PIO7);   // Bidirectional port
    /* Buzzer */
    Port_ConfigurePinDigitalOut(BUZZER);
    
    // @todo Initialize ports to standard value (for example 1 for OE to disable
    // all the outputs of the LEDs)
    
    return;
}

/* End of file IOPorts.c */
