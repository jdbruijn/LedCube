/*******************************************************************************
 * Begin of file getPICConfigurationBits.h
 * Author: jdebruijn
 * Created on November 16, 2015, 4:10 PM
 * 
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 * 
 * Copyright (c) 2015 Jeroen de Bruijn <vidavidorra@gmail.com>
 * 
 * This file is part of LedCube which is released under The MIT License (MIT).
 * For full license details see file "main.c" or "LICENSE.md" or go to
 * https://opensource.org/licenses/MIT
 * 
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**/
/** @file
 * @brief Gets the configuration bits that are set in the microcontroller.
 * 
 * @note    This file is designed for the PIC24FJ64GA004, so the documentation
 * of the configuration bits can differ if a different PIC is used. The compiler
 * will give a compiler warning if this file is not used with a PIC24FJ64GA004.
 * Also the structures for the Flash Configuration Words are based on that PIC.
 * Therefore it's recommended to check whether the documentation and structure
 * layout is compatible to the used PIC microcontroller.
 * @bug     @ref _getPICConfigurationBits_readLatch gives a compiler warning
 * "warning: control reaches end of non-void function", because a value is not
 * explicitly returned from the function.
 * 
 ******************************************************************************/

#ifndef GETPICCONFIGURATIONBITS_H
#define GETPICCONFIGURATIONBITS_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Condition checks
 ******************************************************************************/
#ifndef __PIC24FJ64GA004__
# warning "This file is designed for the PIC24FJ64GA004, so the documentation"
# warning "of the configuration bits can differ if a different PIC is used."
# warning "Also the structures for the Flash Configuration Words are based on"
# warning "that PIC. Therefore it's recommended to check the documentation."
#endif

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <xc.h>
#include <stdbool.h>
#include "Uart.h"

/*******************************************************************************
 * Defines
 ******************************************************************************/
#ifndef PRINTF
/** 
 * @brief Wrapper for PRINTF to an actual printf function, in this case @ref
 * Uart1_printf.
 */
# define PRINTF Uart1_printf
#endif

#ifdef __CONFIG1_BASE
/** @brief Base address for Flash Configuration Word 1 */
# define _CONFIG1_BASE_ADDRESS __CONFIG1_BASE
#else
# error "__CONFIG1_BASE is not defined. Enter the base address of Flash Configuration Word 1 manually."
# error "For the Configuration Word Addresses @see PIC24FJ64GA004 Family Data Sheet.pdf TABLE 24-1."
#endif

#ifdef __CONFIG2_BASE
/** @brief Base address for Flash Configuration Word 2 */
# define _CONFIG2_BASE_ADDRESS __CONFIG2_BASE
#else
# error "__CONFIG2_BASE is not defined. Enter the base address of Flash Configuration Word 2 manually."
# error "For the Configuration Word Addresses @see PIC24FJ64GA004 Family Data Sheet.pdf TABLE 24-1."
#endif

/********** Result descriptions for Flash Configuration Word 1 ************/
#define JTAGEN_DESC "JTAGEN: JTAG Port Enable bit"
#define JTAGEN_1 "[JTAGEN_ON] JTAG port is enabled"
#define JTAGEN_0 "[JTAGEN_OFF] JTAG port is disabled"
#define GCP_DESC "GCP: General Segment Program Memory Code Protection bit"
#define GCP_1 "[GCP_OFF] Code protection is disabled"
#define GCP_0 "[GCP_ON] Code protection is enabled for the entire program memory space"
#define GWRP_DESC "GWRP: General Segment Code Flash Write Protection bit"
#define GWRP_1 "[GWRP_OFF] Writes to program memory are allowed"
#define GWRP_0 "[GWRP_ON] Writes to program memory are disabled"
#define BKBUG_DESC "!DEBUG: Background Debugger Enable bit"
#define BKBUG_1 "[BKBUG_OFF] Device resets into Operational mode"
#define BKBUG_0 "[BKBUG_ON] Device resets into Debug mode"
#define ICS_DESC "ICS<1:0>: Emulator Pin Placement Select bits"
#define ICS_11 "[ICS_PGx1] Emulator EMUC1/EMUD1 pins are shared with PGC1/PGD1"
#define ICS_10 "[ICS_PGx2] Emulator EMUC2/EMUD2 pins are shared with PGC2/PGD2"
#define ICS_01 "[ICS_PGx3] Emulator EMUC3/EMUD3 pins are shared with PGC3/PGD3"
#define ICS_00 "Reserved; do not use"
#define FWDTEN_DESC "FWDTEN: Watchdog Timer Enable bit"
#define FWDTEN_1 "[FWDTEN_ON] Watchdog Timer is enabled"
#define FWDTEN_0 "[FWDTEN_OFF] Watchdog Timer is disabled"
#define WINDIS_DESC "WINDIS: Windowed Watchdog Timer Disable bit"
#define WINDIS_1 "[WINDIS_ON] Standard Watchdog Timer is enabled"
#define WINDIS_0 "[WINDIS_OFF] Windowed Watchdog Timer is enabled; FWDTEN must be '1'"
#define FWPSA_DESC "FWPSA: WDT Prescaler Ratio Select bit"
#define FWPSA_1 "[FWPSA_PR128] Prescaler ratio of 1:128"
#define FWPSA_0 "[FWPSA_PR32] Prescaler ratio of 1:32"
#define WDTPS_DESC "WDTPS<3:0>: Watchdog Timer Postscaler Select bits"
#define WDTPS_1111 "[WDTPS_PS32768] 1:32768"
#define WDTPS_1110 "[WDTPS_16384] 1:16384"
#define WDTPS_1101 "[WDTPS_8192] 1:8192"
#define WDTPS_1100 "[WDTPS_4096] 1:4096"
#define WDTPS_1011 "[WDTPS_2048] 1:2048"
#define WDTPS_1010 "[WDTPS_1024] 1:1024"
#define WDTPS_1001 "[WDTPS_512] 1:512"
#define WDTPS_1000 "[WDTPS_256] 1:256"
#define WDTPS_0111 "[WDTPS_128] 1:128"
#define WDTPS_0110 "[WDTPS_64] 1:64"
#define WDTPS_0101 "[WDTPS_32] 1:32"
#define WDTPS_0100 "[WDTPS_16] 1:16"
#define WDTPS_0011 "[WDTPS_8] 1:8"
#define WDTPS_0010 "[WDTPS_4] 1:4"
#define WDTPS_0001 "[WDTPS_2] 1:2"
#define WDTPS_0000 "[WDTPS_1] 1:1"

/********** Result descriptions for Flash Configuration Word 2 ************/
#define IESO_DESC "IESO: Internal External Switchover bit"
#define IESO_1 "[IESO_ON] IESO mode (Two-Speed Start-up) is enabled"
#define IESO_0 "[IESO_OFF] IESO mode (Two-Speed Start-up) is disabled"
#define WUTSEL_DESC "WUTSEL<1:0>: Voltage Regulator Standby Mode Wake-up Time Select bits"
#define WUTSEL_11 "[WUTSEL_LEG] Default regulator start-up time is used"
#define WUTSEL_01 "[WUTSEL_FST] Fast regulator start-up time is used"
#define WUTSEL_x0 "Reserved; do not use"
#define SOSCSEL_DESC "SOSCSEL<1:0>: Secondary Oscillator Power Mode Select bits"
#define SOSCSEL_11 "[SOSCSEL_SOSC] Default (High Drive Strength) mode"
#define SOSCSEL_01 "[SOSCSEL_LPSOSC] Low-Power (Low Drive Strength) mode"
#define SOSCSEL_x0 "Reserved; do not use"
#define FNOSC_DESC "FNOSC<2:0>: Initial Oscillator Select bits"
#define FNOSC_111 "[FNOSC_FRCDIV] Fast RC Oscillator with Postscaler (FRCDIV)"
#define FNOSC_110 "Reserved"
#define FNOSC_101 "[FNOSC_LPRC] Low-Power RC Oscillator (LPRC)"
#define FNOSC_100 "[FNOSC_SOSC] Secondary Oscillator (SOSC)"
#define FNOSC_011 "[FNOSC_PRIPLL] Primary Oscillator with PLL module (XTPLL, HSPLL, ECPLL)"
#define FNOSC_010 "[FNOSC_PRI] Primary Oscillator (XT, HS, EC)"
#define FNOSC_001 "[FNOSC_FRCPLL] Fast RC Oscillator with Postscaler and PLL module (FRCPLL)"
#define FNOSC_000 "[FNOSC_FRC] Fast RC Oscillator (FRC)"
#define FCKSM_DESC "FCKSM<1:0>: Clock Switching and Fail-Safe Clock Monitor Configuration bits"
#define FCKSM_1x "[FCKSM_CSDCMD] Clock switching and Fail-Safe Clock Monitor are disabled"
#define FCKSM_01 "[FCKSM_CSECMD] Clock switching is enabled, Fail-Safe Clock Monitor is disabled"
#define FCKSM_00 "[FCKSM_CSECME] Clock switching is enabled, Fail-Safe Clock Monitor is enabled"
#define OSCIOFCN_DESC "OSCIOFCN: OSCO Pin Configuration bit:"
#define OSCIOFCN_1 "[OSCIOFNC_OFF] OSCO/CLKO/RA3 functions as CLKO (FOSC/2)"    /* If POSCMD<1:0> = 11 or 00: */
#define OSCIOFCN_0 "[OSCIOFNC_ON] OSCO/CLKO/RA3 functions as port I/O (RA3)"    /* If POSCMD<1:0> = 11 or 00: */
#define OSCIOFCN_x "OSCIOFCN has no effect on OSCO/CLKO/RA3"                    /* If POSCMD<1:0> = 10 or 01: */
#define IOL1WAY_DESC "IOL1WAY: IOLOCK One-Way Set Enable bit"
#define IOL1WAY_1 "[IOL1WAY_ON] The IOLOCK (OSCCON<6>) bit can be set once, provided the unlock sequence has been completed. Once set, the Peripheral Pin Select registers cannot be written to a second time."
#define IOL1WAY_0 "[IOL1WAY_OFF] The IOLOCK (OSCCON<6>) bit can be set and cleared as needed, provided the unlock sequence has been completed"
#define I2C1SEL_DESC "I2C1SEL: I2C1 Pin Select bit"
#define I2C1SEL_1 "[I2C1SEL_PRI] Use default SCL1/SDA1 pins"
#define I2C1SEL_0 "[I2C1SEL_SEC] Use alternate SCL1/SDA1 pins"
#define POSCMD_DESC "POSCMD<1:0:> Primary Oscillator Configuration bits"
#define POSCMD_11 "[POSCMOD_NONE] Primary oscillator is disabled"
#define POSCMD_10 "[POSCMOD_HS] HS Oscillator mode is selected"
#define POSCMD_01 "[POSCMOD_XT] XT Oscillator mode is selected"
#define POSCMD_00 "[POSCMOD_EC] EC Oscillator mode is selected"

/*******************************************************************************
 * Function macros
 ******************************************************************************/
#ifndef UNUSED
/** @brief Macro to suppress the "unused parameter" warnings. */
# define UNUSED(x) (void)(x)
#endif
/** @brief Macro for printing the configuration bit description with indent. */
#define PRINT_DESC(fmt, args...) PRINTF(" " fmt "\n", ##args)
/** @brief Macro for printing the configuration bit result with indent. */
#define PRINT_RESULT(fmt, args...) PRINTF("  " fmt "\n", ##args)

/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
/**
 * @brief Read the two Flash Configuration Words, verify and print the read
 * Flash Configuration Words in a user friendly format.
 * 
 * @note    The print of the read data is done using the @ref PRINTF wrapper.
 * 
 * #### Example output (without the asterisks):
 * @verbatim
 * Reading Flash Configuration Word 1...
 * Binary read value:
 * 111111110011111101111111
 * Successfully verified the Flash Configuration Word 1 with address 0x00ABFE
 *  JTAGEN: JTAG Port Enable bit
 *   [JTAGEN_OFF] JTAG port is disabled
 *  GCP: General Segment Program Memory Code Protection bit
 *   [GCP_OFF] Code protection is disabled
 *  GWRP: General Segment Code Flash Write Protection bit
 *   [GWRP_OFF] Writes to program memory are allowed
 *  !DEBUG: Background Debugger Enable bit
 *   [BKBUG_OFF] Device resets into Operational mode
 *  ICS<1:0>: Emulator Pin Placement Select bits
 *   [ICS_PGx1] Emulator EMUC1/EMUD1 pins are shared with PGC1/PGD1
 *  FWDTEN: Watchdog Timer Enable bit
 *   [FWDTEN_OFF] Watchdog Timer is disabled
 *  WINDIS: Windowed Watchdog Timer Disable bit
 *   [WINDIS_ON] Standard Watchdog Timer is enabled
 *  FWPSA: WDT Prescaler Ratio Select bit
 *   [FWPSA_PR128] Prescaler ratio of 1:128
 *  WDTPS<3:0>: Watchdog Timer Postscaler Select bits
 *   [WDTPS_PS32768] 1:32768
 * Done Reading Flash Configuration Word 1.
 * 
 * Reading Flash Configuration Word 2...
 * Binary read value:
 * 111111111111100101101101
 * Successfully verified the Flash Configuration Word 2 with address 0x00ABFC
 *  IESO: Internal External Switchover bit
 *   [IESO_ON] IESO mode (Two-Speed Start-up) is enabled
 *  WUTSEL<1:0>: Voltage Regulator Standby Mode Wake-up Time Select bits
 *   [WUTSEL_LEG] Default regulator start-up time is used
 *  SOSCSEL<1:0>: Secondary Oscillator Power Mode Select bits
 *   [SOSCSEL_SOSC] Default (High Drive Strength) mode
 *  FNOSC<2:0>: Initial Oscillator Select bits
 *   [FNOSC_FRCPLL] Fast RC Oscillator with Postscaler and PLL module (FRCPLL)
 *  FCKSM<1:0>: Clock Switching and Fail-Safe Clock Monitor Configuration bits
 *   [FCKSM_CSECMD] Clock switching is enabled, Fail-Safe Clock Monitor is disabled
 *  OSCIOFCN: OSCO Pin Configuration bit:
 *   OSCIOFCN has no effect on OSCO/CLKO/RA3
 *  IOL1WAY: IOLOCK One-Way Set Enable bit
 *   [IOL1WAY_OFF] The IOLOCK (OSCCON<6>) bit can be set and cleared as needed, provided the unlock sequence has been completed
 *  I2C1SEL: I2C1 Pin Select bit
 *   [I2C1SEL_PRI] Use default SCL1/SDA1 pins
 *  POSCMD<1:0:> Primary Oscillator Configuration bits
 *   [POSCMOD_XT] XT Oscillator mode is selected
 * Done Reading Flash Configuration Word 2.
 * @endverbatim
 */
void
getPICConfigBits( void );

#ifdef  __cplusplus
}
#endif

#endif /* GETPICCONFIGURATIONBITS_H */
/* End of file getPICConfigurationBits.h */
