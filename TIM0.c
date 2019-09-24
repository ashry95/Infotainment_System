/*
 * TIM0.c
 *
 *  Created on: Aug 18, 2019
 *      Author: dell
 */

#include "TIM0.h"
#include "avr/interrupt.h"

void (*CBptr)(void);

void TIM0_Init(tMODE Timer0Mode , uint8 Prescaler)
{
	TCCR0 = Timer0Mode | OC0_FUNC | Prescaler;

    #if(Timer0Mode == CTC)
	   OCR0 = COMP_VALUE;
    #endif
}


void TIM0_Deinit(void)
{
	TCCR0 = noclk;
}


void TIM0_IntEnable(tMODE Timer0Mode)
{
    #if(Timer0Mode == CTC)
	   Set_Bit(SREG,i_bit);
	   TIMSK |= TIM0CTCINT_EN;
    #elif(Timer0Mode == OVF)
	   Set_Bit(SREG,i_bit);
	   TIMSK |= TIM0OVFINT_EN;
    #endif
}


void TIM0_msDelay(uint32 DelayTime)
{
	TCCR0 = CTC | PreScaler64;
	OCR0  = COMP_VALUE;

	while(DelayTime--)
	{
		Set_Bit(TIFR,OCF0);
		while(!(Get_Bit(TIFR,OCF0)));
	}
}


void TIM0_usDelay(uint64 DelayTime)
{
	uint8 temp1 , temp2;
	TCNT0 = 0;
	TCCR0 = CTC | PreScaler8;

	if(COMP_VALUE > DelayTime){
		OCR0 = DelayTime;
	}else{

		temp1 = DelayTime / COMP_VALUE;
		temp2 = DelayTime % COMP_VALUE;

		while(temp1--){

			OCR0 = COMP_VALUE;
			Set_Bit(TIFR,OCF0);
			while(!(Get_Bit(TIFR,OCF0)));
		}
		if(temp2){

			TCNT0 = 0;
			OCR0 = temp2;
			Set_Bit(TIFR,OCF0);
			while(!(Get_Bit(TIFR,OCF0)));

		}
	}
}


void TIM0_OVFISRCallBack(void(*OVFHANDLERptr)(void))
{
	CBptr = OVFHANDLERptr;
}


ISR(TIMER0_OVF_vect)
{
	CBptr();
}


void TIM0_CTCISRCallBack(void(*CTCHANDLERptr)(void))
{
	CBptr = CTCHANDLERptr;
}


ISR(TIMER0_COMP_vect)
{
	CBptr();
}

