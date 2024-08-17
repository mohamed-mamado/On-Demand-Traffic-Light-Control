/*
 * interrupts.h
 *
 * Created: 05-Sep-22 3:36:07 PM
 *  Author: LAPTOP
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_
/************************************************************************/
/*                  Interrupt vectors                                  */
/**********************************************************************/
/*  External Interrupt Vectors  */
/*  External Interrupt Request 0  */
#define EXT_INT_0 __vector_1
/*  External Interrupt Request 1  */
#define EXT_INT_1 __vector_2
/*  External Interrupt Request 2  */
#define EXT_INT_2 __vector_3

/*  Set Global Interrupts, Set the I-bit in status register to 1 */
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

/*  Clear Global Interrupts, Set the I-bit in status register to 0 */
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

/* ISR definition*/
#define ISA(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

#define rising_edge() MCUCR |= (1<<0) | (1<<1)


#define enable_interrupt_INT0() GICR |= (1<<6)


#endif /* INTERRUPTS_H_ */