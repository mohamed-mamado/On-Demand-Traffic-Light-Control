/*
 * timer.h
 *
 * Created: 06-Sep-22 7:48:15 AM
 *  Author: LAPTOP
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/registers.h"
#define MODE 0x00
#define INIT_value 0x00

void timer_init();
void timer_start();
void clear_flag(unsigned int number_of_overflows);
void time_stop();
#endif /* TIMER_H_ */