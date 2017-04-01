#ifndef _rtc_H_
#define _rtc_H_

#ifndef  _REG51_H_
#include <reg51.h> 
#endif

#ifndef  _INTRINS_H_
#include<intrins.h>
#endif

sbit scl1   =    P2^0;		   
sbit sda1   =    P2^1;

void rtc_start(void);
void rtc_stop(void);
void rtc_post(unsigned char a) ;
void rtc_write(unsigned char,unsigned char);
unsigned char rtc_read(unsigned char add);
void delay (unsigned int val );
//void delay11(unsigned int itime);

void rtc_write(unsigned char add ,unsigned char dat)
{
 rtc_start();
 rtc_post(0Xd0); //device addr in write mode//
 rtc_post(add); //byte addr//
 rtc_post(dat); //data//
 rtc_stop();
}


unsigned char rtc_read(unsigned char add)
{
 unsigned char v,i2;  
 rtc_start();
 rtc_post(0Xd0);  //device addr in write mode//
 rtc_post(add); //byte addr//
 _nop_();
 rtc_start();
 rtc_post(0Xd1); //device addr in read mode//
 v=0;
 sda1=1;
 for(i2=0;i2<=7;i2++)
 {
  scl1=0;
  _nop_();
  _nop_();
  scl1=1;
  v=v|sda1;
  if(i2<=6)
  v=v<<1;
 }
 scl1=0;
 delay(100); 
 rtc_stop();
 return(v); 		
}

		     				   
void rtc_start(void)
{
 scl1=1;
 sda1=1;
 _nop_();
 _nop_();
 sda1=0;
 scl1=0;
}


void rtc_post(unsigned char a)
{
 unsigned char i2,c;
 for(i2=0;i2<=7;i2++)
 {
  c=a&128;
  if(c==0)
  sda1=0;
  else
  sda1=1;
  scl1=1;
  _nop_();
  _nop_();
  scl1=0;
  a=a<<1;
 }	
 sda1=1;
 _nop_();
 _nop_();
 scl1=1;
 _nop_();
 _nop_();
 scl1=0;
}

void rtc_stop(void)
{
 sda1=0;
 scl1=1;
 _nop_();
 _nop_();
 sda1=1;
 scl1=0;
}
/*
void delay11(unsigned int itime)
{
 unsigned int p,q;
 for(p=0;p<itime;p++)
 for(q=0;q<3;q++);
}*/



#endif