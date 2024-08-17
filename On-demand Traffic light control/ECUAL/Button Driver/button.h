/*
 * button.h
 *
 * Created: 05-Sep-22 3:32:37 PM
 *  Author: LAPTOP
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO Driver/dio.h"
#define BUTTON_1_PORT PORT_C
#define BUTTON_1_PIN 1

#define BUTTON_2_PORT PORT_D
#define BUTTON_2_PIN 7


#define LOW 0
#define HIGH 1
// initialize

typedef enum {
	Ok, ERROR_but_init, ERROR_but_read
} buttonError;

buttonError BUTTON_init(uint8_t buttonPort, uint8_t buttonPin);
// button read
buttonError BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value);



#endif /* BUTTON_H_ */