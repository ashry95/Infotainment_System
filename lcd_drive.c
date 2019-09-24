/*
* lcd_drive.c
*
* Created: 9/23/2019 11:17:30 PM
*  Author: smart
*/
#include "std_types.h"
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "lcd_drive.h"
#include "lcd_cfg.h"

void LCD_init (void)
{
	LCD_HWPORT_DIR = 0xFF;
	LCD_HWPORT &= ~(1<<LCD_RW);
	_delay_ms(15);
	LCD_sendCommand(0x03);
	_delay_ms(5);
	LCD_sendCommand(0x03);
	_delay_ms(11);
	LCD_sendCommand(0x03);
	LCD_sendCommand(0x02);                  /* send for 4 bit initialization of LCD*/
	LCD_sendCommand(0x28);                        /* 2 line, 16*2 matrix in 4-bit mode*/
	LCD_sendCommand(0x0c);                       /* Display on cursor off*/
	LCD_sendCommand(0x06);                       /* take courser on to next position (shift cursor to right)*/
	LCD_sendCommand(0x01);                       /* Clear display screen*/
	_delay_ms(2);
}
void LCD_sendCommand (uint8 LCD_Command)
{
	#ifdef LCD_4BIT_MODE
	LCD_HWPORT = (LCD_HWPORT & 0x0F) | (LCD_Command & 0xF0); /* upper nibble of 8 bit */
	LCD_HWPORT &= ~ (1<<LCD_RS);
	LCD_HWPORT |= (1<<LCD_EN);
	_delay_us(2);
	LCD_HWPORT &= ~ (1<<LCD_EN);
	
	_delay_us(200);
	
	LCD_HWPORT = (LCD_HWPORT & 0x0F) | (LCD_Command << 4);  /* lower nibble of 8 bit */
	LCD_HWPORT |= (1<<LCD_EN);
	_delay_us(2);
	LCD_HWPORT &= ~ (1<<LCD_EN);
	#endif
	
	#ifdef LCD_8BIT_MODE
	LCD_HWPORT_1 = (LCD_Command) /* upper nibble of 8 bit */
	LCD_HWPORT_1 &= ~ (1<<LCD_RS);
	LCD_HWPORT_2 |= (1<<LCD_EN);
	_delay_us(2);
	LCD_HWPORT_2 &= ~ (1<<LCD_EN);
	#endif
}
void LCD_displayChar (char LCD_Character)
{
	#ifdef LCD_4BIT_MODE
	LCD_HWPORT = (LCD_HWPORT & 0x0F) | (LCD_Character & 0xF0);
	LCD_HWPORT |= (1<<LCD_RS);
	LCD_HWPORT|= (1<<LCD_EN);
	_delay_us(2);
	LCD_HWPORT &= ~ (1<<LCD_EN);
	
	_delay_us(200);
	
	LCD_HWPORT = (LCD_HWPORT & 0x0F) | (LCD_Character << 4);
	LCD_HWPORT |= (1<<LCD_EN);
	_delay_us(1);
	LCD_HWPORT &= ~ (1<<LCD_EN);
	_delay_ms(1);
	#endif
	
	#ifdef LCD_8BIT_MODE
	LCD_HWPORT_1 = (LCD_Character);
	LCD_HWPORT_2 |= (1<<LCD_RS);
	LCD_HWPORT_2 |= (1<<LCD_EN);
	_delay_us(2);
	LCD_HWPORT_2 &= ~ (1<<LCD_EN);
	#endif
}

void LCD_displayString (const char * LCD_String)
{
	uint8 LCD_loop=0U;

	while(LCD_String[LCD_loop]!=0)
	{
		LCD_displayChar (LCD_String[LCD_loop]);
		LCD_loop++;
	}
}

void LCD_displayStringRowColumn (const char * LCD_RCString, uint8 LCD_DispRow, uint8 LCD_DispColumn)
{
	LCD_displayString(LCD_RCString);
}

void LCD_clear (void)
{
	LCD_sendCommand (0x01);                   /*hex 01 to clear display*/
	_delay_ms(1);
	LCD_sendCommand (0x80);                   /*hex 80 to cursor at home */
}
void LCD_gotoRowColumn (uint8 LCD_Row, uint8 LCD_Column)
{
	switch (LCD_Column)
	{
		case 1 :
		LCD_sendCommand(0x80 + LCD_Row);
		break;
		
		case 2:
		LCD_sendCommand(0xC0 + LCD_Row);
		break;
		default :
		/*Do nothing*/
		break;
	}

}
