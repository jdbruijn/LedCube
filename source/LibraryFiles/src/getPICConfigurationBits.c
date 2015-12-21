/*******************************************************************************
 * Begin of file getPICConfigurationBits.c
 * Author: jdebruijn
 * Created on November 16, 2015, 4:11 PM
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
 * @brief Gets the configuration bits that are set in the microcontroller.
 * 
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "getPICConfigurationBits.h"

/*******************************************************************************
 * Structures
 ******************************************************************************/
/** @brief Internal typedef for a 16-bit unsigned word. */
typedef unsigned short _GPCB_UWord16;
/** @brief Internal typedef for a 32-bit unsigned word. */
typedef unsigned long _GPCB_UWord32;

/** @cond ignore
 * Internal typedef union for a 32-bit register.
 */
typedef union _tuReg32 {
    _GPCB_UWord32 Val32;

    struct {
        _GPCB_UWord16 LW;
        _GPCB_UWord16 HW;
    } Word;

    char Val[4];
} _GPCB_uReg32;

/** Internal structure for the Flash Configuration Word 1. */
typedef struct tagCW1BITS {
    union {
        struct {
            unsigned WDTPS : 4;
            unsigned FWPSA : 1;
            unsigned : 1;
            unsigned WINDIS : 1;
            unsigned FWDTEN : 1;
            unsigned ICS : 2;
            unsigned : 1;
            unsigned BKBUG : 1;
            unsigned GWRP : 1;
            unsigned GCP : 1;
            unsigned JTAGEN : 1;
        };
        struct {
            unsigned WDTPS0 : 1;
            unsigned WDTPS1 : 1;
            unsigned WDTPS2 : 1;
            unsigned : 4;
            unsigned ICS0 : 1;
            unsigned ICS1 : 1;
        };
    };
} CW1BITS;

/** Internal structure for the Flash Configuration Word 2. */
typedef struct tagCW2BITS {
    union {
        struct {
            unsigned POSCMD : 2;
            unsigned I2C1SEL : 1;
            unsigned : 1;
            unsigned IOL1WAY : 1;
            unsigned OSCIOFCN : 1;
            unsigned FCKSM : 2;
            unsigned FNOSC : 3;
            unsigned SOSCSEL : 2;
            unsigned WUTSEL : 2;
            unsigned IESO : 1;
        };
        struct {
            unsigned POSCMD0 : 1;
            unsigned POSCMD1 : 1;
            unsigned : 4;
            unsigned FCKSM0 : 1;
            unsigned FCKSM1 : 1;
            unsigned FNOSC0 : 1;
            unsigned FNOSC1 : 1;
            unsigned FNOSC2 : 1;
            unsigned SOSCSEL0 : 1;
            unsigned SOSCSEL1 : 1;
            unsigned WUTSEL0 : 1;
            unsigned WUTSEL1 : 1;
        };
    };
} CW2BITS;

/** Internal typedef union for the Flash Configuration Word 1. */
typedef union CWReg1_t {
    _GPCB_UWord32 Val32;

    struct {
        _GPCB_UWord16 LW;
        _GPCB_UWord16 HW;
    } Word;

    char Val[4];
    CW1BITS CW1bits;
} CWReg1_t;

/** Internal typedef union for the Flash Configuration Word 2. */
typedef union CWReg2_t {
    _GPCB_UWord32 Val32;

    struct {
        _GPCB_UWord16 LW;
        _GPCB_UWord16 HW;
    } Word;

    char Val[4];
    CW2BITS CW2bits;
} CWReg2_t;
/** @endcond ignore */

/*******************************************************************************
 * Functions
 ******************************************************************************/
/**
 * @brief Internal function to read a 32-bit value from an address.
 * 
 * @note    This gives a compiler warning because a value is not explicitly
 * returned from the function.
 * @param   addrhi High word of the address to read from.
 * @param   addrlo Low word of the address to read from.
 * @return  UWord32 32-bit value that was at the address of addrhi and addrlo.
 */
_GPCB_UWord32
_GPCB_readLatch(_GPCB_UWord16 addrhi,
                _GPCB_UWord16 addrlo)
{
    UNUSED(addrhi);
    UNUSED(addrlo);

    /*_ReadLatch: ;W0=TBLPAG,W1=Wn - data in W1:W0 */
    asm("   mov W0,TBLPAG");
    asm("   tblrdl [W1],W0");
    asm("   tblrdh [W1],W1");
    /* This gives a compiler warning because not explicitly returning a value
     * from the function, but since this is assembly, do not know how to prevent
     * warning.
     * The function is correct, since W1:W0 being used to return the tblrdl,
     * tblrdh. Could write less efficient code and use a temporary UWord32.
     */
}

/**
 * @brief Internal function to verify that the upper byte of a Flash
 * Configuration Word is '1111 1111' as it should be according to the
 * PIC24FJ64GA004 Family Data Sheet.pdf (page 209).
 * 
 * @param   _CW 32-bit Configuration Word to verify the upper byte from.
 * @return  bool True if the upper byte is successfully verified, false else.
 */
bool
_GPCB_verifyConfigUpperByte(_GPCB_UWord32 _CW)
{
    if ((_CW & 0x00FF0000) == 0x00FF0000) {
        return (true);
    } else {
        return (false);
    }
}

void
getPICConfigBits(void)
{
    /* Base address of CW1: Flash Configuration Word 1 */
    _GPCB_uReg32 CW1Addr;
    /* Base address of CW1: Flash Configuration Word 2 */
    _GPCB_uReg32 CW2Addr;
    /* Value of CW1: Flash Configuration Word 1 */
    CWReg1_t CW1;
    /* Value of CW1: Flash Configuration Word 2 */
    CWReg2_t CW2;

    /* For the Configuration Word Addresses see PIC24FJ64GA004 Family Data
     * Sheet.pdf (page 209, TABLE 24-1).
     */
    CW1Addr.Val32 = _CONFIG1_BASE_ADDRESS;
    CW2Addr.Val32 = _CONFIG2_BASE_ADDRESS;

    /********** Read and verify Flash Configuration Word 1 ********************/
    uprintf("\n\nReading Flash Configuration Word 1...\n");
    CW1.Val32 = _GPCB_readLatch(CW1Addr.Word.HW,
                                CW1Addr.Word.LW);
    uprintf("Binary read value:\n");
    uputbits(CW1.Val32, 24);

    if (_GPCB_verifyConfigUpperByte(CW1.Val32) == true) {
        uprintf("\nSuccessfully verified the Flash Configuration Word 1"       \
            " with address 0x%.2X%.4X\n", CW1Addr.Word.HW, CW1Addr.Word.LW);

        /********** Document Flash Configuration Word 1 results ***************/
        /* JTAGEN (bit 14) */
        PRINT_DESC(JTAGEN_DESC);
        if (CW1.CW1bits.JTAGEN) {
            PRINT_RESULT(JTAGEN_1);
        } else {
            PRINT_RESULT(JTAGEN_0);
        }
        /* GCP (bit 13) */
        PRINT_DESC(GCP_DESC);
        if (CW1.CW1bits.GCP) {
            PRINT_RESULT(GCP_1);
        } else {
            PRINT_RESULT(GCP_0);
        }
        /* GWRP (bit 12) */
        PRINT_DESC(GWRP_DESC);
        if (CW1.CW1bits.GWRP) {
            PRINT_RESULT(GWRP_1);
        } else {
            PRINT_RESULT(GWRP_0);
        }
        /* !DEBUG (bit 11) */
        PRINT_DESC(BKBUG_DESC);
        if (CW1.CW1bits.BKBUG) {
            PRINT_RESULT(BKBUG_1);
        } else {
            PRINT_RESULT(BKBUG_0);
        }
        /* ICS (bit 9-8) */
        PRINT_DESC(ICS_DESC);
        if (CW1.CW1bits.ICS == 0b11) {
            PRINT_RESULT(ICS_11);
        } else if (CW1.CW1bits.ICS == 0b10) {
            PRINT_RESULT(ICS_10);
        } else if (CW1.CW1bits.ICS == 0b01) {
            PRINT_RESULT(ICS_01);
        } else if (CW1.CW1bits.ICS == 0b00) {
            PRINT_RESULT(ICS_00);
        }
        /* FWDTEN (bit 7) */
        PRINT_DESC(FWDTEN_DESC);
        if (CW1.CW1bits.FWDTEN) {
            PRINT_RESULT(FWDTEN_1);
        } else {
            PRINT_RESULT(FWDTEN_0);
        }
        /* WINDIS (bit 6) */
        PRINT_DESC(WINDIS_DESC);
        if (CW1.CW1bits.WINDIS) {
            PRINT_RESULT(WINDIS_1);
        } else {
            if (CW1.CW1bits.FWDTEN) {
                PRINT_RESULT(WINDIS_0);
            } else {
                PRINT_RESULT(WINDIS_0);
                uprintf("  DEBUG: %s:%d:%s(): WARNING: FWDTEN is not '1', "    \
                        "this setting has no effect!",
                        __FILE__, __LINE__, __FUNCTION__);
            }

        }
        /* FWPSA (bit 4) */
        PRINT_DESC(FWPSA_DESC);
        if (CW1.CW1bits.FWPSA) {
            PRINT_RESULT(FWPSA_1);
        } else {
            PRINT_RESULT(FWPSA_0);
        }
        /* WDTPS (bit 3-0) */
        PRINT_DESC(WDTPS_DESC);
        if (CW1.CW1bits.WDTPS == 0b1111) {
            PRINT_RESULT(WDTPS_1111);
        } else if (CW1.CW1bits.WDTPS == 0b1110) {
            PRINT_RESULT(WDTPS_1110);
        } else if (CW1.CW1bits.WDTPS == 0b1101) {
            PRINT_RESULT(WDTPS_1101);
        } else if (CW1.CW1bits.WDTPS == 0b1100) {
            PRINT_RESULT(WDTPS_1100);
        } else if (CW1.CW1bits.WDTPS == 0b1011) {
            PRINT_RESULT(WDTPS_1011);
        } else if (CW1.CW1bits.WDTPS == 0b1010) {
            PRINT_RESULT(WDTPS_1010);
        } else if (CW1.CW1bits.WDTPS == 0b1001) {
            PRINT_RESULT(WDTPS_1001);
        } else if (CW1.CW1bits.WDTPS == 0b1000) {
            PRINT_RESULT(WDTPS_1000);
        } else if (CW1.CW1bits.WDTPS == 0b0111) {
            PRINT_RESULT(WDTPS_0111);
        } else if (CW1.CW1bits.WDTPS == 0b0110) {
            PRINT_RESULT(WDTPS_0110);
        } else if (CW1.CW1bits.WDTPS == 0b0101) {
            PRINT_RESULT(WDTPS_0101);
        } else if (CW1.CW1bits.WDTPS == 0b0100) {
            PRINT_RESULT(WDTPS_0100);
        } else if (CW1.CW1bits.WDTPS == 0b0011) {
            PRINT_RESULT(WDTPS_0011);
        } else if (CW1.CW1bits.WDTPS == 0b0010) {
            PRINT_RESULT(WDTPS_0010);
        } else if (CW1.CW1bits.WDTPS == 0b0001) {
            PRINT_RESULT(WDTPS_0001);
        } else if (CW1.CW1bits.WDTPS == 0b0000) {
            PRINT_RESULT(WDTPS_0000);
        }
    } else {
        uprintf("\nVerifying Flash Configuration Word 1 with address"          \
            " 0x%.2X %.4X failed...\n", CW1Addr.Word.HW, CW1Addr.Word.LW);
    }
    uprintf("Done Reading Flash Configuration Word 1.\n");

    /********** Read and verify Flash Configuration Word 2 ********************/
    uprintf("\nReading Flash Configuration Word 2...\n");
    CW2.Val32 = _GPCB_readLatch(CW2Addr.Word.HW,
                                CW2Addr.Word.LW);
    uprintf("Binary read value:\n");
    uputbits(CW2.Val32, 24);

    if (_GPCB_verifyConfigUpperByte(CW2.Val32) == true) {
        uprintf("\nSuccessfully verified the Flash Configuration Word 2"       \
            " with address 0x%.2X%.4X\n", CW2Addr.Word.HW, CW2Addr.Word.LW);

        /********** Document Flash Configuration Word 2 results ***************/
        /* IESO (bit 15) */
        PRINT_DESC(IESO_DESC);
        if (CW2.CW2bits.IESO) {
            PRINT_RESULT(IESO_1);
        } else {
            PRINT_RESULT(IESO_0);
        }
        /* WUTSEL (bit 14-13) */
        PRINT_DESC(WUTSEL_DESC);
        if (CW2.CW2bits.WUTSEL == 0b11) {
            PRINT_RESULT(WUTSEL_11);
        } else if (CW2.CW2bits.WUTSEL == 0b01) {
            PRINT_RESULT(WUTSEL_01);
        } else {
            PRINT_RESULT(WUTSEL_x0);
        }
        /* SOSCSEL (bit 12-11) */
        PRINT_DESC(SOSCSEL_DESC);
        if (CW2.CW2bits.SOSCSEL == 0b11) {
            PRINT_RESULT(SOSCSEL_11);
        } else if (CW2.CW2bits.SOSCSEL == 0b01) {
            PRINT_RESULT(SOSCSEL_01);
        } else {
            PRINT_RESULT(SOSCSEL_x0);
        }
        /* FNOSC (bit 10-8) */
        PRINT_DESC(FNOSC_DESC);
        if (CW2.CW2bits.FNOSC == 0b111) {
            PRINT_RESULT(FNOSC_111);
        } else if (CW2.CW2bits.FNOSC == 0b110) {
            PRINT_RESULT(FNOSC_110);
        } else if (CW2.CW2bits.FNOSC == 0b101) {
            PRINT_RESULT(FNOSC_101);
        } else if (CW2.CW2bits.FNOSC == 0b100) {
            PRINT_RESULT(FNOSC_100);
        } else if (CW2.CW2bits.FNOSC == 0b011) {
            PRINT_RESULT(FNOSC_011);
        } else if (CW2.CW2bits.FNOSC == 0b010) {
            PRINT_RESULT(FNOSC_010);
        } else if (CW2.CW2bits.FNOSC == 0b001) {
            PRINT_RESULT(FNOSC_001);
        } else if (CW2.CW2bits.FNOSC == 0b000) {
            PRINT_RESULT(FNOSC_000);
        }
        /* FCKSM (bit 7-6) */
        PRINT_DESC(FCKSM_DESC);
        if (CW2.CW2bits.FCKSM == 0b01) {
            PRINT_RESULT(FCKSM_01);
        } else if (CW2.CW2bits.FCKSM == 0b00) {
            PRINT_RESULT(FCKSM_00);
        } else {
            PRINT_RESULT(FCKSM_1x);
        }
        /* OSCIOFCN (bit 5) */
        PRINT_DESC(OSCIOFCN_DESC);
        if (CW2.CW2bits.POSCMD == 0b11 || CW2.CW2bits.POSCMD == 00) {
            if (CW2.CW2bits.OSCIOFCN) {
                PRINT_RESULT(OSCIOFCN_1);
            } else {
                PRINT_RESULT(OSCIOFCN_0);
            }
        } else if (CW2.CW2bits.POSCMD == 0b10 || CW2.CW2bits.POSCMD == 01) {
            PRINT_RESULT(OSCIOFCN_x);
        }
        /* IOL1WAY (bit 4) */
        PRINT_DESC(IOL1WAY_DESC);
        if (CW2.CW2bits.IOL1WAY) {
            PRINT_RESULT(IOL1WAY_1);
        } else {
            PRINT_RESULT(IOL1WAY_0);
        }
        /* I2C1SEL (bit 2) */
        PRINT_DESC(I2C1SEL_DESC);
        if (CW2.CW2bits.I2C1SEL) {
            PRINT_RESULT(I2C1SEL_1);
        } else {
            PRINT_RESULT(I2C1SEL_0);
        }
        /* POSCMD (bit 1-0) */
        PRINT_DESC(POSCMD_DESC);
        if (CW2.CW2bits.POSCMD == 0b11) {
            PRINT_RESULT(POSCMD_11);
        } else if (CW2.CW2bits.POSCMD == 0b10) {
            PRINT_RESULT(POSCMD_10);
        } else if (CW2.CW2bits.POSCMD == 0b01) {
            PRINT_RESULT(POSCMD_01);
        } else if (CW2.CW2bits.POSCMD == 0b00) {
            PRINT_RESULT(POSCMD_00);
        }
    } else {
        uprintf("\nVerifying Flash Configuration Word 2 with address"          \
            " 0x%.2X %.4X failed...\n", CW2Addr.Word.HW, CW2Addr.Word.LW);
    }
    uprintf("Done Reading Flash Configuration Word 2.\n\n\n");

    return;
}
/* End of file getPICConfigurationBits.c */
