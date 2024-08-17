/*
 * application.c
 *
 * Created: 05-Sep-22 3:28:47 PM
 *  Author: LAPTOP
 */ 

#include "application.h"
//int button_click = 0;
uint8_t button_click;

void APP_init(void)
{
	int choise_init = 0;
	/*1. Set all LED pins to output*/
	/*DDRD |= (1<<PINA0); // pin 0 port A*/ 
	choise_init += LED_init(PORT_A,0); //red car
	/*DDRD |= (1<<PINA1); // pin 1 port A*/ 
	choise_init += LED_init(PORT_A,1); //yallow car
	/*DDRD |= (1<<PINA2); // pin 2 port A*/ 
	choise_init += LED_init(PORT_A,2); //green car
	/*DDRD |= (1<<PINB0); // pin 0 port B*/ 
	choise_init += LED_init(PORT_B,0); //red 
	/*DDRD |= (1<<PINB1); // pin 1 port B*/ 
	choise_init += LED_init(PORT_B,1); //yallow
	/*DDRD |= (1<<PINB2); // pin 2 port B*/  
	choise_init += LED_init(PORT_B,2); //green 
	
	/*2. Set direction for button pin to in input*/
	/*DDRD |= (1<<PIND2); // pin 2 port D*/
	choise_init += BUTTON_init(PORT_D, 2); //button
	if (choise_init != 0)
	{
		APP_init();
	}
	timer_init();
	
	
}

void APP_start(void)
{
	int choise = 0;
	int case_ord = 0;
	int count_ok = 0;
	int check = 0;
	while(1)
	{
		switch (choise){
			case 0:
			check = 0;
			button_click = 0;
			for(int i=0; i<10; i++){
			/*Turn on LED
			  PortA |= (1<<PORTA0) // Pin 0 port A */
			check += LED_on(PORT_A,0);
			/*Turn off LED
			  PortA &= ~(1<<PORTA1) // Pin 1 port A
			  PortA &= ~(1<<PORTA2) // Pin 2 port A */
			check += LED_off(PORT_A,1);
			check += LED_off(PORT_A,2);
			/*Turn off LED
			  PortB &= ~(1<<PORTA0) // Pin 0 port B
			  PortB &= ~(1<<PORTA1) // Pin 1 port B */
			check += LED_off(PORT_B,0);
			check += LED_off(PORT_B,1);
			/*Turn on LED
			  PortB |= (1<<PORTB2) // Pin 2 port B */
			LED_on(PORT_B,2);
			
			timer_start();
			clear_flag(NUMBER_OF_OVERFLOWS);
			time_stop();
			}
			if (check != 0)
			{
				case_ord = choise;
				choise = 0;
				break;
			} 
			case_ord = choise;
			choise = 1;
			break;
			
			case 1:
			check = 0;
			button_click = 0;
			count_ok = 0;
			for(int i=0; i<10; i++){
			check += LED_off(PORT_A,0); // turn off LED Pin 0 Port A
			/* toggle the LED
			    PORTA ^= (1<<PINA1); //pin 1 port A*/
			check += LED_toggle(PORT_A,1);
			check += LED_off(PORT_A,2); // turn off LED Pin 2 Port A
			
			check += LED_off(PORT_B,0); // turn off LED Pin 0 Port B
			check += LED_off(PORT_B,1); // turn off LED Pin 1 Port B
			check += LED_off(PORT_B,2); // turn off LED Pin 2 Port B
			
			check += BUTTON_read(PORT_D, 2, &button_click);
			if (button_click == HIGH)
			{
					choise = 3;
					count_ok++;
			}
			timer_start();
			clear_flag(NUMBER_OF_OVERFLOWS);
			time_stop();
			check += BUTTON_read(PORT_D, 2, &button_click);
			if (button_click == LOW && choise == 3 && count_ok < 3){
				i = 10;
			}
			else{
				choise = 1;
			}
			
			}
			if (choise == 3)
			{
				break;
			}
			if (case_ord == 2)
			{
				choise = 0;
			}
			else if (case_ord == 0)
			{
				if (check != 0)
				{
					choise = 0;
				}
				choise = 2;
			}
			break;
			
			case 2:
			check = 0;
			button_click = 0;
			count_ok = 0;
			for(int i=0; i<10; i++){
				check += LED_off(PORT_A,0); // turn off LED Pin 0 Port A
				check += LED_off(PORT_A,1); // turn off LED Pin 1 Port A
				check += LED_on(PORT_A,2); // turn on LED Pin 2 Port A
				
				check += LED_on(PORT_B,0); // turn on LED Pin 0 Port B
				check += LED_off(PORT_B,1); // turn off LED Pin 1 Port B
				check += LED_off(PORT_B,2); // turn off LED Pin 2 Port B
				
				check += BUTTON_read(PORT_D, 2, &button_click);
				if (button_click == HIGH)
				{
						choise = 3;
						count_ok++;
				}
				timer_start();
				clear_flag(NUMBER_OF_OVERFLOWS);
				time_stop();
				check += BUTTON_read(PORT_D, 2, &button_click);
				if (button_click == LOW && choise == 3 && count_ok < 3){
					i = 10;
				}
				else{
					choise = 1;
					}
			}
			if (choise == 3)
			{
				break;
			}
			if (check != 0)
			{
				choise = 0;
				break;
			}
			case_ord = choise;
			choise = 1;
			break;
			case 3:
			check = 0;
			button_click = 0;
			for(int i=0; i<10; i++){
				check += LED_off(PORT_A,0); // turn off LED Pin 0 Port A
				check += LED_toggle(PORT_A,1); // LED toggle Pin 1 Port A
				check += LED_off(PORT_A,2); // turn off LED Pin 2 Port A
					
				check += LED_off(PORT_B,0); // turn off LED Pin 0 Port B
				check += LED_toggle(PORT_B,1); // LED toggle Pin 1 Port B
				check += LED_off(PORT_B,2); // turn off LED Pin 2 Port B
	
				timer_start();
				clear_flag(NUMBER_OF_OVERFLOWS);
				time_stop();
			}
			choise = 0;
			break;
		}
	}
}

