/*******************************************************************************
 * Begin of file Interrupts.h
 * Author: jdebruijn
 * Created on September 9, 2015, 7:31 PM
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
 *  Definitions for the interrupt priority.
 * 
 ******************************************************************************/

#ifndef INTERRUPTS_H
#define	INTERRUPTS_H

#ifdef	__cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <xc.h>
#include <stdint.h>

/*******************************************************************************
 * Defines
 ******************************************************************************/
/**
 * 7 = Interrupt is priority 7 (highest priority interrupt)
 * 6 = Interrupt is priority 6
 * 5 = Interrupt is priority 5
 * 4 = Interrupt is priority 4
 * 3 = Interrupt is priority 3
 * 2 = Interrupt is priority 2
 * 1 = Interrupt is priority 1
 * 0 = Interrupt source is disabled
 */
#define INT_U1RX_PRIO           1
#define INT_T3_PRIO             1

/*******************************************************************************
 * Macros
 ******************************************************************************/
/**
 * Disable interrupts by saving the current CPU interrupt priority level to a
 * variable and setting the CPU interrupt priority level to 7 (the highest
 * level).
 * Using the predefined SET_AND_SAVE_CPU_IPL macro for setting and saving the
 * CPU interrupt priority level.
 */
#define INTERRUPTS_DISSABLE_AND_SAVE_CPU_IPL() uint16_t cpuIntPrio = 0; \
                SET_AND_SAVE_CPU_IPL(cpuIntPrio, 7)

/**
 * Restore the previous CPU interrupt priority level from the saved variable.
 * Using the predefined RESTORE_CPU_IPL macro for restoring the CPU interrupt
 * priority level. This doesn't necessary mean that interrupts are enabled after
 * this macro, because the CPU interrupt priority level is only restored to it's
 * original value. So if it original value was 7 (interrupts disabled) it will
 * be restored to the same value, resulting in an interrupts disabled situation.
 * @Note    The macro INTERRUPTS_DISSABLE_AND_SAVE_CPU_IPL must be in the same
 * scope as this macro.
 */
#define INTERRUPTS_RESTORE_CPU_IPL() RESTORE_CPU_IPL(cpuIntPrio)

#ifdef	__cplusplus
}
#endif

#endif	/* INTERRUPTS_H */
/* End of file Interrupts.h */
