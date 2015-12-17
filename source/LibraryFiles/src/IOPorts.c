/*******************************************************************************
 * Begin of file IOPorts.c
 * Author: Jeroen de Bruijn
 * Created on 02 August 2015, 21:01
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
 * @brief Initialize function for the I\Os.
 * 
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "IOPorts.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
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
    PPS_UNLOCK;
    
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
    
    PPS_LOCK;
    
    return;
}

/* End of file IOPorts.c */
