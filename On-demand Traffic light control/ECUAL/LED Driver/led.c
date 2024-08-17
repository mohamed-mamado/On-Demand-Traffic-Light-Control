/*
 * led.c
 *
 * Created: 05-Sep-22 3:33:43 PM
 *  Author: LAPTOP
 */ 

#include "led.h"
// Initialize LED
ledError LED_init(uint8_t ledPort, uint8_t ledPin)
{
	int x;
	x = DIO_init(ledPin, ledPort, OUT);
	if (x == 0)
	{
		return ok;
	}
	else
	{
		return ERROR_led_init;
	}
}
// LED on
ledError LED_on(uint8_t ledPort, uint8_t ledPin)
{
	int x;
	x = DIO_write(ledPin, ledPort, HIGH);
	if (x == 0)
	{
		return ok;
	}
	else
	{
		return ERROR_led_on;
	}
}
// LED off
ledError LED_off(uint8_t ledPort, uint8_t ledPin)
{
	int x;
	x = DIO_write(ledPin, ledPort, LOW);
	if (x == 0)
	{
		return ok;
	}
	else
	{
		return ERROR_led_off;
	}
}
// LED toggle 
ledError LED_toggle(uint8_t ledPort, uint8_t ledPin)
{
	int x;
	x = DIO_toggle(ledPin,ledPort);
	if (x == 0)
	{
		return ok;
	}
	else
	{
		return ERROR_led_toggle;
	}
}