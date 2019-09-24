/*
 * TIM0.h
 *
 *  Created on: Aug 18, 2019
 *      Author: dell
 */

#ifndef TIM0_H_
#define TIM0_H_

#include "TIM0_REG.h"
#include"STD_TYPES.h"
#include"MACROS.h"


/* OC0 PIN MODE */
#define OC0_FUNC	(OC0_DISC)
#define OC0_DISC	(0x00)
#define OC0_TOG	    (0x10)
#define OC0_CLR		(0x20)
#define OC0_SET		(0x30)


#define COMP_VALUE      (124)
#define	TOV0            (0)
#define	OCF0            (1)
#define i_bit           (7)

typedef enum{
	OVF,
	CTC = 0x08
}tMODE;

enum
{
	noclk,
	PreScaler1,
	PreScaler8,
	PreScaler64,
	PreScaler256,
	PreScaler1024,
};

enum{
	TIM0INT_DIS,
	TIM0OVFINT_EN,
	TIM0CTCINT_EN
};


void TIM0_Init(tMODE Timer0Mode,uint8 Prescaler);
void TIM0_Deinit(void);
void TIM0_msDelay(uint32 DelayTime);
void TIM0_usDelay(uint64 DelayTime);
void TIM0_IntEnable(tMODE Timer0Mode);
void TIM0_OVFISRCallBack(void(*OVFHANDLERptr)(void));
void TIM0_CTCISRCallBack(void(*CTCHANDLERptr)(void));

#endif /* TIM0_H_ */

