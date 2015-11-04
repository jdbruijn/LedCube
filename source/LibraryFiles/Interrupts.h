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

#ifdef	__cplusplus
}
#endif

#endif	/* INTERRUPTS_H */
/* End of file Interrupts.h */
