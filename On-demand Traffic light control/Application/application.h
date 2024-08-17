/*
 * application.h
 *
 * Created: 05-Sep-22 3:29:00 PM
 *  Author: LAPTOP
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "../ECUAL/Button Driver/button.h"
#include "../ECUAL/LED Driver/led.h"
#include "../MCAL/Time Driver/timer.h"
#include "../Utilities/registers.h"
#include "../Utilities/interrupts.h"

#define NUMBER_OF_OVERFLOWS 1920

void APP_init(void);
void APP_start(void);



#endif /* APPLICATION_H_ */