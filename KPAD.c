/***************************************************************************************************************
 *************************************
 * KPAD.c                            *
 * Author    : AHMED ASHRY           *
 * DATE      : Sep 23, 2019          *
 * VERSION   : 001                   *
 *************************************
 ***************************************************************************************************************/

/*******************************************************************************************************************
 * include(s)
 *******************************************************************************************************************/
#include "KPAD.h"

/*******************************************************************************************************************
 * shared function definition(s)
 *******************************************************************************************************************/
/*..................................................................................
 * name:                KPAD_Init
 * description:         Initialize Keypad buttons
 * sync/async:          synchronous
 * reentrancy:          reentrant
 * parameters (in):     none
 * parameters (in/out): none
 * parameters (out):    none
 * return:              none
 * remarks:             none
 * example:             none
 *..................................................................................*/
void KPAD_Init(void)
{

	DIO_SetPinDirection(COL_1,OUTPUT);
	DIO_SetPinDirection(COL_2,OUTPUT);
	DIO_SetPinDirection(COL_3,OUTPUT);

	DIO_SetPinDirection(ROW_1,INPUT);
	DIO_SetPinDirection(ROW_2,INPUT);
	DIO_SetPinDirection(ROW_3,INPUT);

	DIO_WritePin(ROW_1,OUTPUT);
	DIO_WritePin(ROW_2,OUTPUT);
	DIO_WritePin(ROW_3,OUTPUT);

//	/* Initialize column counter, row counter */
//	uint8 COL_Counter , ROW_Counter;
//	/* index of addressed column */
//	enCOL_t COL = COL_1;
//	/* index of addressed row */
//	enROW_t ROW = ROW_1;

//	/* initialize all columns as inputs */
//	for(ROW_Counter = 0; ROW_Counter < NUM_OF_ROW; ROW_Counter++)
//	{
//		/* Configure the Column as input */
//		DIO_SetPinDirection(ROW,INPUT);
//		/* go to next row */
//		ROW++;
//	}
//
//	/* Configure all row pins to be pulled up */
//	for(ROW_Counter = 0; ROW_Counter < NUM_OF_ROW; ROW_Counter++)
//	{
//		DIO_WritePin(ROW,HIGH);
//		/* go to next row */
//		ROW++;
//	}
//
//	/* initialize all rows as inputs */
//	for(COL_Counter = 0; COL_Counter < NUM_OF_COL; COL_Counter++)
//	{
//		/* Configure the row as output */
//		DIO_SetPinDirection(COL,OUTPUT);
//		/* go to next column */
//		COL++;
//	}
}


/*..................................................................................
 * name:                KPAD_GetPressedKey
 * description:         Return index of pressed key
 * sync/async:          synchronous
 * reentrancy:          reentrant
 * parameters (in):     none
 * parameters (in/out): none
 * parameters (out):    none
 * return:              Index of the pressed key
 * remarks:             none
 * example:             none
 *..................................................................................*/
uint8 KPAD_GetPressedKey(void)
{
	/* Initialize column counter, row counter, and pressed button index */
	uint8 COL_Counter , ROW_Counter , Index = LOW , FirstFoundKeyFlag = LOW;
//	/* index of addressed column */
//	uint8 COL = 18;
	/* index of addressed row */
//	uint8 ROW ;

	/* Looping on columns of the Key Pad */
	for(COL_Counter = LOW + COL_1; COL_Counter < NUM_OF_COL + COL_1; COL_Counter++)
	{
		/* Activate the current Column */
		DIO_WritePin(COL_Counter,LOW);

		/* Looping on rows of the Key Pad */
		for(ROW_Counter = LOW + ROW_1; ROW_Counter < NUM_OF_ROW + ROW_1; ROW_Counter++)
		{
			/* check if any first key pressed */
			if((!(DIO_ReadPin(ROW_Counter))) && (!FirstFoundKeyFlag))
			{
				/* set pressed button index */
				Index = (NUM_OF_ROW * (ROW_Counter - ROW_1)) + (COL_Counter - COL_1) + 1u;
				/* Ignore any other pressed keys */
				FirstFoundKeyFlag = HIGH;
			}
		}
		/* Deactivate the current Column */
		DIO_WritePin(COL_Counter,HIGH);
	}

	/* return  pressed button index */
	return Index;
}
