/*
 * DIO.c
 *
 *  Created on: Aug 17, 2019
 *      Author: dell
 */


#include"DIO.h"

void DIO_WritePin(uint8 PinNum , uint8 PinValue)
{
	if(PinValue)
		{
			if((PinNum >= 0) && (PinNum <= 7)){
				Set_Bit(PORTA,PinNum);}
				else if((PinNum >= 8) && (PinNum <= 15)){
				Set_Bit(PORTB,(PinNum-8));}
				else if((PinNum >= 16) && (PinNum <= 23)){
				Set_Bit(PORTC,(PinNum-16));}
				else if((PinNum >= 24) && (PinNum <= 31)){
				Set_Bit(PORTD,(PinNum-24));}
		}

		else if(!(PinValue))
		{
			if((PinNum >= 0) && (PinNum <= 7)){
				Clear_Bit(PORTA,PinNum);}
			else if((PinNum >= 8) && (PinNum <= 15)){
				Clear_Bit(PORTB,(PinNum-8));}
			else if((PinNum >= 16) && (PinNum <= 23)){
				Clear_Bit(PORTC,(PinNum-16));}
			else if((PinNum >= 24) && (PinNum <= 31)){
				Clear_Bit(PORTD,(PinNum-24));}
		}
}


uint8 DIO_ReadPin(uint8 PinNum)
{
	uint8 PinValue=0;


	if((PinNum >= 0) && (PinNum <= 7)){
		PinValue = Get_Bit(PINA,PinNum);}
	else if((PinNum >= 8) && (PinNum <= 15)){
		PinValue = Get_Bit(PINB,(PinNum-8));}
	else if((PinNum >= 16) && (PinNum <= 23)){
		PinValue = Get_Bit(PINC,(PinNum-16));}
	else if((PinNum >= 24) && (PinNum <= 31)){
		PinValue = Get_Bit(PIND,(PinNum-24));}

	return PinValue;
}


void DIO_SetPinDirection(uint8 PinNum,tPortDir PinDirection)
{
	if(PinDirection)
	{
		if((PinNum >= 0) && (PinNum <= 7)){
			Set_Bit(DDRA,PinNum);}
			else if((PinNum >= 8) && (PinNum <= 15)){
			Set_Bit(DDRB,(PinNum-8));}
			else if((PinNum >= 16) && (PinNum <= 23)){
			Set_Bit(DDRC,(PinNum-16));}
			else if((PinNum >= 24) && (PinNum <= 31)){
			Set_Bit(DDRD,(PinNum-24));}
	}

	else if(PinDirection == 0)
	{
		if((PinNum >= 0) && (PinNum <= 7)){
			Clear_Bit(DDRA,PinNum);}
		else if((PinNum >= 8) && (PinNum <= 15)){
			Clear_Bit(DDRB,(PinNum-8));}
		else if((PinNum >= 16) && (PinNum <= 23)){
			Clear_Bit(DDRC,(PinNum-16));}
		else if((PinNum >= 24) && (PinNum <= 31)){
			Clear_Bit(DDRD,(PinNum-24));}
	}
}
