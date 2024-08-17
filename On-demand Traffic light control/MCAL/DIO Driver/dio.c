/*
 * dio.c
 *
 * Created: 05-Sep-22 3:35:10 PM
 *  Author: LAPTOP
 */ 
// include .h 
// global variables
// function definition
#include "dio.h"


dioError DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction) // Initialize dio direction
{
	switch(portNumber)
	{
		case PORT_A:
		if(direction == IN)
		{
			DDRA &= ~(1<<pinNumber); // Input
			return OK;
		}
		else if(direction == OUT)
		{
			DDRA |= (1<<pinNumber); // Output
			return OK;
		}
		else
		{
			return ERROR_init; // Error handling
		}
		break;
		case PORT_B:
		if(direction == IN)
		{
			DDRB &= ~(1<<pinNumber); // Input
			return OK;
		}
		else if(direction == OUT) // Output
		{
			DDRB |= (1<<pinNumber);
			return OK;
		}
		else
		{
			return ERROR_init; // Error handling
		}
		break;
		case PORT_C:
		if(direction == IN)
		{
			DDRC &= ~(1<<pinNumber); // Input
			return OK;
		}
		else if(direction == OUT) // Output
		{
			DDRC |= (1<<pinNumber);
			return OK;
		}
		else
		{
			return ERROR_init; // Error handling
		}
		break;
		case PORT_D:
		if(direction == IN)
		{
			DDRD &= ~(1<<pinNumber); // Input
			return OK;
		}
		else if(direction == OUT)
		{
			DDRD |= (1<<pinNumber); // Output
			return OK;
		}
		else
		{
			return ERROR_init; // Error handling
		}
		break;
	}
}

dioError DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value)
{
	switch(portNumber)
	{
		case PORT_A:
		if(value == LOW)
		{
			PORTA &= ~(1<<pinNumber); // write 0
			return OK;
		}
		else if(value == HIGH)
		{
			PORTA |= (1<<pinNumber); // write 1
			return OK;
		}
		else
		{
			return ERROR_write; // error handling
		}
		break;
		
		case PORT_B:
		if(value == LOW)
		{
			PORTB &= ~(1<<pinNumber); // write 0
			return OK;
		}
		else if(value == HIGH)
		{
			PORTB |= (1<<pinNumber); // write 1
			return OK;
		}
		else
		{
			return ERROR_write; // Error handling
		}
		break;
		case PORT_C:
		if(value == LOW)
		{
			PORTC &= ~(1<<pinNumber); // write 0
			return OK;
		}
		else if(value == HIGH)
		{
			PORTC |= (1<<pinNumber); // write 1
			return OK;
		}
		else
		{
			return ERROR_write; // Error handling
		}
		break;
		case PORT_D:
		if(value == LOW)
		{
			PORTD &= ~(1<<pinNumber); // write 0
			return OK;
		}
		else if(value == HIGH)
		{
			PORTD |= (1<<pinNumber); // write 1
			return OK;
		}
		else
		{
			return ERROR_write; // Error handling
		}
		break;
	}
}
dioError DIO_toggle(uint8_t pinNumber, uint8_t portNumber)
{
	switch(portNumber)
	{
		case PORT_A:
		PORTA ^= (1<<pinNumber); // change state -> toggle bit
		return OK;
		break;
		case PORT_B:
		PORTB ^= (1<<pinNumber); // change state -> toggle bit
		return OK;
		break;
		case PORT_C:
		PORTC ^= (1<<pinNumber); // change state -> toggle bit
		return OK;
		break;
		case PORT_D:
		PORTD ^= (1<<pinNumber); // change state -> toggle bit
		return OK;
		break;
		default:
		return ERROR_toggle;
		break;
	}
}
dioError DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value)
{
	switch(portNumber)
	{
		case PORT_A:
		*value = (PINA & (1<<pinNumber))>>pinNumber; // get state -> read bit
		return OK;
		break;
		case PORT_B:
		*value = (PINB & (1<<pinNumber))>>pinNumber; // get state -> read bit
		return OK;
		break;
		case PORT_C:
		*value = (PINC & (1<<pinNumber))>>pinNumber; // get state -> read bit
		return OK;
		break;
		case PORT_D:
		*value = (PIND & (1<<pinNumber))>>pinNumber; // get state -> read bit
		return OK;
		break;
		default:
		return ERROR_read;
		break;
	}
}