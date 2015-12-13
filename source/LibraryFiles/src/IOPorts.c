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
    /********** Configure I/Os ************************************************/
    PORT_INITIALIZE_ALL_PINS;
    
    /* LedDriver */
    PORT_CONFIGURE_PIN_AS_DIGITAL_OUTPUT(SPI1_SDO);
    PORT_CONFIGURE_PIN_AS_DIGITAL_OUTPUT(SPI1_SCK);
    PORT_CONFIGURE_PIN_AS_DIGITAL_OUTPUT(LD_LE);
    /* Anode Conrol */
    PORT_CONFIGURE_PIN_AS_DIGITAL_OUTPUT(SPI2_SDO);
    PORT_CONFIGURE_PIN_AS_DIGITAL_OUTPUT(SPI2_SCK);
    PORT_CONFIGURE_PIN_AS_DIGITAL_OUTPUT(ANODE_LATCH);
    /* LedDriver & Anode Control */
#ifdef USE_OE_STATE_EXTENDER
    PORT_CONFIGURE_PIN_AS_DIGITAL_INPUT(OE);
#else
    PORT_CONFIGURE_PIN_AS_DIGITAL_OUTPUT(OE);
#endif
    /* USB to UART */
    PORT_CONFIGURE_PIN_AS_DIGITAL_INPUT(USB_TO_UART_RX);
    PORT_CONFIGURE_PIN_AS_DIGITAL_OUTPUT(USB_TO_UART_TX);
    PORT_CONFIGURE_PIN_AS_DIGITAL_OUTPUT(USB_TO_UART_CTS);
    PORT_CONFIGURE_PIN_AS_DIGITAL_INPUT(USB_TO_UART_RTS);
    /* Bluetooth */
//    PORT_CONFIGURE_PIN_AS_DIGITAL_INPUT(BT_UART_TX);
//    PORT_CONFIGURE_PIN_AS_DIGITAL_OUTPUT(BT_UART_RX);
//    PORT_CONFIGURE_PIN_AS_DIGITAL_OUTPUT(BT_UART_CTS);
//    PORT_CONFIGURE_PIN_AS_DIGITAL_INPUT(BT_UART_RTS);
//    PORT_CONFIGURE_PIN_AS_DIGITAL_OUTPUT(BT_CMD_MLDP);
//    PORT_CONFIGURE_PIN_AS_DIGITAL_OUTPUT(BT_WAKE_HW);
//    PORT_CONFIGURE_PIN_AS_DIGITAL_OUTPUT(BT_WAKE_SW);
//    PORT_CONFIGURE_PIN_AS_DIGITAL_INPUT(BT_CONNECTSTATUS);
//    PORT_CONFIGURE_PIN_AS_DIGITAL_INPUT(BT_MLDP_EV);
//    PORT_CONFIGURE_PIN_AS_DIGITAL_INPUT(BT_WS);
//    PORT_CONFIGURE_PIN_AS_DIGITAL_OUTPUT(BT_PIO7);   // Bidirectional port
    /* Buzzer */
    PORT_CONFIGURE_PIN_AS_DIGITAL_OUTPUT(BUZZER);
    
    /********** Initialize I/Os to a default value ****************************/
    PORT_SET_PIN(OE);
    
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
    
    return;
}

/* End of file IOPorts.c */
