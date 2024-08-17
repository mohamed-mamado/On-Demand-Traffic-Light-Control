/*
 * led.h
 *
 * Created: 05-Sep-22 3:33:56 PM
 *  Author: LAPTOP
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Driver/dio.h"

typedef enum {
	ok, ERROR_led_init, ERROR_led_on, ERROR_led_off, ERROR_led_toggle
} ledError;

ledError LED_init(uint8_t ledPort, uint8_t ledPin);
ledError LED_on(uint8_t ledPort, uint8_t ledPin);
ledError LED_off(uint8_t ledPort, uint8_t ledPin);
ledError LED_toggle(uint8_t ledPort, uint8_t ledPin);




#endif /* LED_H_ */