/*
 * main.c
 *
 *  Created on: Sep 16, 2019
 *      Author: dell
 */

#include "Sos.h"
#include "KPAD.h"
#include "lcd_drive.h"

#define MaxNumOfQus			6
#define MaxNumOfChar		17
uint8 NewQus=0;
uint8 PrevQus=1;
char Quistion[MaxNumOfQus][MaxNumOfChar]= {"Are u ready ^_^"
		,"ASCII of'E'= 70?"
		,"ASCII of'7'= 55?"
		,"47 = ASCII '0'?"
		,"97 = ASCII 'a'?"
		,"NULL= (void)0 ?"};
char ANS[MaxNumOfQus]= { 8, 0, 1, 0, 1, 0 };
char arr[10]={'0','1','2','3','4','5','6','7','8','9'};
static uint8 old=0,var2=0,var1=0,statevar=0,flag=1,result=0,currans=0, flagforres=0;

void Task_CalculateScore(void);
void TASK_CheckAnswer(void);
void Task_SendQuestion(void);

int main (void)
{
	DDRB = 1<<4;
	PORTB |= 1<<4;
	LCD_init();
	DDRD = 0xff;
	KPAD_Init();
	Sos_Init();
	//LCD_gotoRowColumn(2, 2);
	//LCD_displayString("first question");
	//sing(1);
	//sing(2);


	Sos_CreateTask(TASK_CheckAnswer,10,0);
	Sos_CreateTask(Task_SendQuestion,10,1);
	Sos_CreateTask(Task_CalculateScore,10,2);

	Sos_Run();

}

void TASK_Start()
{

}
uint8 DoneRepeat=1;
void Task_SendQuestion (void)
{

	if (NewQus != PrevQus && DoneRepeat)
	{
		LCD_clear();
		LCD_displayString(Quistion[NewQus]);
		PrevQus=NewQus ;
		DoneRepeat=1;
	}
	else
	{
		/*do nothing*/
	}
	if ((NewQus==MaxNumOfQus) && (DoneRepeat))
	{
		PORTB |= 1<<4;
		DoneRepeat=0;
		LCD_clear();
		LCD_displayString("You got : ");
		LCD_displayChar(arr[result]);
	}
}

void TASK_CheckAnswer(void)
{
	if(flag==1){
		PORTB &= ~(1<<4);
		var1 = KPAD_GetPressedKey();
		if(old!=var1 && var1!=0)
		{
			statevar=2;
		}
	}
	switch(statevar)
	{
	case 1 :

		break;
	case 2 :
		var2++;
		flag=0;
		old=var1;
		if(var2==5)
		{
			if(var1== 1)
			{
				currans=1;
				flagforres=1;
				if(DoneRepeat==0){
					LCD_clear();
				LCD_displayStringRowColumn("Press start", 0, 1);
				LCD_displayStringRowColumn("to play", 0, 2);
				PORTD = 0x02;
				}
			}
			else if(var1== 3)
			{
				currans=0;
				flagforres=1;
				if(DoneRepeat==0){
					LCD_clear();
				LCD_displayStringRowColumn("Press start", 0, 1);
				LCD_displayStringRowColumn("to play", 0, 2);
				PORTD = 0x02;
				}
			}
			else if(var1==2)
			{
				DoneRepeat=1;
				NewQus=0;
				PrevQus=1;
				result=0;
			}
			flag=1;
			statevar=3;
			var2=0;
		}
		break;
	case 3 :
	{
		if(var1==0)
		{
			old=0;
		}
	}
	break;
	}

}

void Task_CalculateScore (void)
{
	if (flagforres==1)
	{
		flagforres=0;
		if(ANS[PrevQus]==currans)
		{
			result++;
		}
		NewQus++;
	}
}
