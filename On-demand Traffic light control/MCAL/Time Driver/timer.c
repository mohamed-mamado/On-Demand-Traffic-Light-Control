/*
 * timer.c
 *
 * Created: 06-Sep-22 7:48:32 AM
 *  Author: LAPTOP
 */ 
#include "timer.h"

void timer_init(){
	// choose timer mode
	TCCR0 = 0x00; // Normal mode
	// Timer set initial value
	TCNT0 = 0x00; 
}
void timer_start(){
	// Timer start -> setting the clock source 
	TCCR0 |= (1<<0); //No prescaler
}
void clear_flag(unsigned int number_of_overflows){
	unsigned int overflowCounter = 0;
	while (overflowCounter < number_of_overflows){
		// will be repeared number_of_overflows
		// stop after one overflow -> 256 micro second
		// wait until the overflow flag to be set
		while((TIFR & (1<<0)) == 0);
		// clear the overflow flag
		TIFR |= (1<<0);
		
		overflowCounter++;
	}
}
void time_stop(){
	// time stop
	TCCR0 = 0x00;
}