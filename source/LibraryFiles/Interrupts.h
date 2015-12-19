/*******************************************************************************
 * Begin of file Interrupts.h
 * Author: jdebruijn
 * Created on September 9, 2015, 7:31 PM
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
 * @brief Definitions for the interrupt priority.
 * 
 ******************************************************************************/

#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#ifdef __cplusplus
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
/* Possible interrupt priorities:
 * 7 = Interrupt is priority 7 (highest priority interrupt)
 * 6 = Interrupt is priority 6
 * 5 = Interrupt is priority 5
 * 4 = Interrupt is priority 4
 * 3 = Interrupt is priority 3
 * 2 = Interrupt is priority 2
 * 1 = Interrupt is priority 1
 * 0 = Interrupt source is disabled
 */
#define INT_U1RX_PRIO           1   /**< Interrupt priority for UART1 receive */
#define INT_T3_PRIO             1   /**< Interrupt priority for timer 3 */

/*******************************************************************************
 * Constant macros
 ******************************************************************************/
/**
 * @brief Disable interrupts.
 *
 * Disable interrupts by saving the current CPU interrupt priority level to a
 * variable and setting the CPU interrupt priority level to 7 (the highest
 * level).
 * Using the predefined SET_AND_SAVE_CPU_IPL macro for setting and saving the
 * CPU interrupt priority level.
 */
#define INTERRUPTS_DISSABLE_AND_SAVE_CPU_IPL() uint16_t cpuIntPrio = 0; \
                SET_AND_SAVE_CPU_IPL(cpuIntPrio, 7)

/**
 * @brief Restore the previous CPU interrupt priority level from the saved
 * variable.
 *
 * Using the predefined RESTORE_CPU_IPL macro for restoring the CPU interrupt
 * priority level. This doesn't necessary mean that interrupts are enabled after
 * this macro, because the CPU interrupt priority level is only restored to it's
 * original value. So if it original value was 7 (interrupts disabled) it will
 * be restored to the same value, resulting in an interrupts disabled situation.
 * @Note    The macro INTERRUPTS_DISSABLE_AND_SAVE_CPU_IPL must be in the same
 * scope as this macro.
 */
#define INTERRUPTS_RESTORE_CPU_IPL() RESTORE_CPU_IPL(cpuIntPrio)

#ifdef __cplusplus
}
#endif

#endif /* INTERRUPTS_H */
/* End of file Interrupts.h */
