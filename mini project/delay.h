#ifndef __DELAY_H__
#define __DELAY_H__

#ifndef  __REG51_H__
#include <reg51.h> 
#endif

void delay_ms(unsigned int value)  //for 1 ms
{
 int i,j;
 for(i=0;i<value;i++)
 {
 for(j=0;j<50;j++);
 }
}

#endif