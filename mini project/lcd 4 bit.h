#ifndef __LCD_4_BIT_H__
#define __LCD_4_BIT_H__

#ifndef  _REG51_H_
#include <reg51.h> 
#endif

#ifndef  _DELAY_H_
#include "delay.h"
#endif

#pragma SAVE
#pragma REGPARMS

void lcd_init ();
void lcd_reset();
void delay_ms(unsigned int value);
void lcd_cmd(unsigned char value);
void lcd_data(unsigned char value);
void lcd_puts(char *value);

#define lcddata P1

sbit rs = P1^2;
sbit en = P1^3;

void lcd_reset()
{
 lcddata=0xff;
 delay_ms(20);
 lcddata=0x30+0x02;
 lcddata=0x30;
 delay_ms(10);
 lcddata=0x30+0x02;
 lcddata=0x30;
 delay_ms(1);
 lcddata=0x30+0x02;
 lcddata=0x30;
 delay_ms(1);
 lcddata=0x20+0x02;
 lcddata=0x20;
 delay_ms(1);
}


void lcd_init (void)
{
 lcd_reset();         // Call LCD reset
 
 lcd_cmd(0x28);       // 4-bit mode - 2 line - 5x7 font.
 lcd_cmd(0x0e);       // Display no cursor - no blink.
 lcd_cmd(0x06);       // Automatic Increment - No Display shift.
 lcd_cmd(0x80);       // Address DDRAM with 0 offset 80h.
 lcd_cmd(0x01);        //CLR LCD 
}

void lcd_cmd(unsigned char value)
{
   unsigned char n;
   n=value;
   value=value&(0x0f0);				  // commands send to variable (value) because we need to divide 8-bit data 
   lcddata = value;					 //  as nibbles (4 bits) we need to send data to lcd as a 4-bit data  
   rs =0;							 // Howover  we have only four data lines and three control lines that's why 
   //rw =0;							 // The value in the 'value' variable  should be divided into two nibbles 
   en =1;							 // and send it to lcd ( For EX The 'value' variable  contins  '28' data 
   delay_ms(100);						 // it should divided as '2' and '8' then these are send to lcd.
   en =0;
   value=n;
   value=value<<4;			         // 'value' varible shifted 4 times  
   value=value &(0x0f0);
   lcddata = value;
   rs =0;
   //rw =0;																	
   en =1;
   delay_ms(100);
   en =0;
}

void lcd_data(unsigned char value)
{
  unsigned char n;
  n=value;
  value=value&(0x0f0);
  lcddata = value;
  rs =1;
  //rw =0;
  en =1;
  delay_ms(100);
  en =0;
  value=n;
  value=value<<4;
  value=value &(0x0f0);
  lcddata = value;
  rs =1;
  //rw =0;
  en =1;
  delay_ms(100);
  en =0;
}

void lcd_puts(char *value)
{
 while(*value)
 lcd_data(*value++);
}




#endif



			  
