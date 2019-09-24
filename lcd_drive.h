/*
 * lcd_drive.h
 *
 * Created: 9/23/2019 11:17:53 PM
 *  Author: smart
 */ 


#ifndef LCD_DRIVE_H_
#define LCD_DRIVE_H_
#include "std_types.h"

void LCD_init (void);
void LCD_sendCommand (uint8 LCD_Command);
void LCD_displayChar (char LCD_Character);
void LCD_displayString (const char * LCD_String);
void LCD_displayStringRowColumn (const char * LCD_RCString, uint8 LCD_DispRow, uint8 LCD_DispColumn);
void LCD_clear (void);
void LCD_gotoRowColumn (uint8 LCD_Row, uint8 LCD_Column);


#endif /* LCD_DRIVE_H_ */