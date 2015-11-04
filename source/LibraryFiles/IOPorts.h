/*******************************************************************************
 * Begin of file IOPorts.h
 * Author: Jeroen de Bruijn
 * Created on 02 August 2015, 20:59
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
 *  Definitions for used I/O ports, and initializes them.
 * 
 ******************************************************************************/

#ifndef IOPORTS_H
#define	IOPORTS_H

#ifdef	__cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <xc.h>
#include "Ports.h"
#include "PeripheralPinSelect.h"

/*******************************************************************************
 * Defines
 ******************************************************************************/
/* LedDriver */
#define SPI1_SDO                PORT_RP19      /* Serial Data Out to LedDriver */
#define SPI1_SCK                PORT_RP21      /* Serial Clock to LedDriver */
#define LD_LE                   PORT_RP20      /* LE to LedDriver */
/* Anode Conrol */
#define SPI2_SDO                PORT_RP3       /* Serial Data Out to Anode Control */
#define SPI2_SCK                PORT_RP18      /* Serial Clock to Anode Control */
#define ANODE_LATCH             PORT_RP17
#define OE                      PORT_RP16      /* For both the LedDriver and Anode Control */
/* USB to UART */
#define USB_TO_UART_TX          PORT_RP14      /* USB to UART Tx */
#define USB_TO_UART_RX          PORT_RP12      /* USB to UART Rx */
#define USB_TO_UART_CTS         PORT_RP13      /* USB to UART Clear To Send */
#define USB_TO_UART_RTS         PORT_RP15      /* USB to UART Ready To Send */
/* Bluetooth */
#define BT_UART_TX              PORT_RP10      /* Bluetooth UART Tx */
#define BT_UART_RX              PORT_RP11      /* Bluetooth UART Rx */
#define BT_UART_CTS             PORT_RP6       /* Bluetooth UART Clear To Send */
#define BT_UART_RTS             PORT_RP22      /* Bluetooth UART Ready To Send */
#define BT_CMD_MLDP             PORT_RP24      /* Bluetooth Command or MLDP mode */
#define BT_WAKE_HW              PORT_RP9       /* Bluetooth Hardware Wake */
#define BT_WAKE_SW              PORT_RP25      /* Bluetooth Deep Sleep Wake */
#define BT_CONNECTSTATUS        PORT_RP8       /* Bluetooth Connected Status */
#define BT_MLDP_EV              PORT_RP7       /* Bluetooth MLDP Data Event */
#define BT_WS                   PORT_RP23      /* Bluetooth Activity indicator */
#define BT_PIO7                 PORT_RP5       /* Bluetooth PIO7 */
/* Buzzer */
#define BUZZER                  PORT_RP2       /* On-board buzzer */

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * Initialize all used I/Os.
 * 
 * @param   void
 * @return  void
 * @Example <code>IOPorts_init();</code>
 */
void
IOPorts_init( void );

#ifdef	__cplusplus
}
#endif

#endif /* IOPORTS_H */
/* End of file IOPorts.h */
