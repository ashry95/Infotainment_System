/*
 * DIO.h
 *
 *  Created on: Aug 17, 2019
 *      Author: dell
 */

#ifndef DIO_H_
#define DIO_H_

#include"STD_TYPES.h"
#include"MACROS.h"

#define PORTA *((uint8*)0x3B)
#define PORTB *((uint8*)0x38)
#define PORTC *((uint8*)0x35)
#define PORTD *((uint8*)0x32)

#define DDRA *((uint8*)0x3A)
#define DDRB *((uint8*)0x37)
#define DDRC *((uint8*)0x34)
#define DDRD *((uint8*)0x31)

#define PINA *((uint8*)0x39)
#define PINB *((uint8*)0x36)
#define PINC *((uint8*)0x33)
#define PIND *((uint8*)0x30)

#define HIGH 1
#define LOW 0

#define PIN0		0
#define PIN1		1
#define PIN2		2
#define PIN3		3
#define PIN4		4
#define PIN5		5
#define PIN6		6
#define PIN7		7
#define PIN8		8
#define PIN9		9
#define PIN10		10
#define PIN11		11
#define PIN12		12
#define PIN13		13
#define PIN14		14
#define PIN15		15
#define PIN16		16
#define PIN17		17
#define PIN18		18
#define PIN19		19
#define PIN20		20
#define PIN21		21
#define PIN22		22
#define PIN23		23
#define PIN24		24
#define PIN25		25
#define PIN26		26
#define PIN27		27
#define PIN28		28
#define PIN29		29
#define PIN30		30
#define PIN31		31

typedef enum{
	INPUT,
	OUTPUT
}tPortDir;


void DIO_WritePin (uint8 PinNum , uint8 PinValue);
uint8 DIO_ReadPin(uint8 PinNum);
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);

#endif /* DIO_H_ */
