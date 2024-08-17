/*
 * button.c
 *
 * Created: 05-Sep-22 3:32:54 PM
 *  Author: LAPTOP
 */ 

#include "button.h"
// initialize 
buttonError BUTTON_init(uint8_t buttonPort, uint8_t buttonPin)
{
	int x;
	x = DIO_init(buttonPin, buttonPort, IN);
	if (x == 0)
	{
		return Ok;
	}
	else
	{
		return ERROR_but_init;
	}
}
// button read
buttonError BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value)
{
	int x;
	x = DIO_read(buttonPin, buttonPort, value);
	if (x == 0)
	{
		return Ok;
	}
	else
	{
		return ERROR_but_read;
	}
} 