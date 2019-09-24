/*
 * TIM0_REG.h
 *
 *  Created on: Sep 16, 2019
 *      Author: dell
 */

#ifndef TIM0_REG_H_
#define TIM0_REG_H_

/* TIMER0 REGISTERS */
#define TCNT0   *((volatile uint8*)0x52)
#define TCCR0   *((volatile uint8*)0x53)
#define TIMSK   *((volatile uint8*)0x59)
#define TIFR    *((volatile uint8*)0x58)
#define OCR0    *((volatile uint8*)0x5c)
#define TCNT0   *((volatile uint8*)0x52)
#define SREG    *((volatile uint8*)0x5F)

#endif /* TIM0_REG_H_ */
