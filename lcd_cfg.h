/*
 * lcd_cfg.h
 *
 * Created: 9/23/2019 11:18:54 PM
 *  Author: smart
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define LCD_4BIT_MODE							1

#ifdef LCD_4BIT_MODE
#define LCD_HWPORT								PORTA
#define LCD_HWPORT_DIR							DDRA
#define LCD_EN									(3U)
#define LCD_RW									(2U)
#define LCD_RS									(1U)
#define LCD_D4									(4U)
#define LCD_D5									(5U)
#define LCD_D6									(6U)
#define LCD_D7									(7U)
#endif

#ifdef LCD_8BIT_MODE
#define LCD_HWPORT_1							PORTA
#define LCD_HWPORT_2							PORTB
#define LCD_HWPORT_DIR_2						DDRB
#define LCD_HWPORT_DIR_1						DDRA
#define LCD_EN									(3U)
#define LCD_RW									(2U)
#define LCD_RS									(1U)
#define LCD_D0									(0U)
#define LCD_D1									(1U)
#define LCD_D2									(2U)
#define LCD_D3									(3U)
#define LCD_D4									(4U)
#define LCD_D5									(5U)
#define LCD_D6									(6U)
#define LCD_D7									(7U)
#endif

#endif /* LCD_CFG_H_ */