/*
 * main.c
 *
 *  Created on: Sep 16, 2019
 *      Author: dell
 */

#include "Sos.h"
#include "KPAD.h"
#include "lcd_drive.h"

#define MaxNumOfQus			5
#define MaxNumOfChar		5
uint8 NewQus=0;
uint8 PrevQus=0;
char Quistion[MaxNumOfQus][MaxNumOfChar]= {"Q1","Q2","Q3","Q4","Q5"};
char ANS[MaxNumOfQus]=					 {	1,	 1,	  0,	0,	1  };
char arr[10]={'0','1','2','3','4','5','6','7','8','9'};
static uint8 old=0,var2=0,var1=0,statevar=0,flag=1;


void Task_CalculateScore (void) ;
void TASK_CheckAnswer(void);
void Task_SendQuestion (void);


void TASK_CheckAnswer(void)
{
	if(flag==1){
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
			LCD_displayChar(arr[var1]);
			flag=1;
			statevar=3;
			var2=0;
		}
		break;
	case 3 :
	{

	}
	break;
	}
}



int main (void)
{
	LCD_init();
	DDRA = 0xff;
	KPAD_Init();
	Sos_Init();
	LCD_gotoRowColumn(2, 2);
	LCD_displayString("first question");
	//sing(1);
	//sing(2);



	Sos_CreateTask(Task_SendQuestion,100,1);


	Sos_Run();

	while(1);
}


void Task_SendQuestion (void)
{
	if (NewQus != PrevQus)
	{
		LCD_clear();
		LCD_displayString(Quistion[NewQus]);
		PrevQus=NewQus;
	}
	else
	{
		/*do nothing*/
	}
	if (NewQus==(MaxNumOfQus-1))
	{

	}
}


void Task_CalculateScore (void)
{
	if (NewQus != PrevQus)
	{

	}

}

