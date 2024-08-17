/*
 * dio.h
 *
 * Created: 05-Sep-22 3:34:57 PM
 *  Author: LAPTOP
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/registers.h"
// all internal driver typedefs
// all driver macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'
// Definition defines
#define IN 0
#define OUT 1
// Value defines
#define LOW 0
#define HIGH 1

typedef enum {
	OK, ERROR_write, ERROR_init, ERROR_toggle, ERROR_read
} dioError;

dioError DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction); // Initialize dio direction
dioError DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value); // Write data to dio
dioError DIO_toggle(uint8_t pinNumber, uint8_t portNumber); // toggle dio
dioError DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value); // Read dio




#endif /* DIO_H_ */