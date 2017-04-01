#ifndef __GSM_H_
#define __GSM_H_


unsigned char w=0, no1[10];


void gsm_cmd(char *a)
{
 while(*a)					      
 uart_putch(*a++);  
}


void gsm_enter()
{
 uart_putch(10);
 uart_putch(13);         
}


void gsm_check()
{
 unsigned char get[10],m=0,j; 

  lcd_cmd(0x01);
 lcd_puts(" gsm checking ");
 
 check:

 gsm_cmd("at");
 gsm_enter();
 delay_ms(1000);
 
 j=0;
 /*
 while(j<10)
 {
  get[0]=uart_getch();
  
   if(get[0]=='O')
   {
    get[0]=uart_getch();
    if(get[0]=='K')
    m=1;
    break;
   }
   j++ ;
  }
  if(m==0)
  goto check;  */

  lcd_cmd(0x01);		
  lcd_puts("MODEM IS CONNECTED");
}



void gsm_init_lcd()
{
  unsigned char get[10],m=0,j,n=0;
 
  check:

  gsm_cmd("at+cmgf=1");
  gsm_enter();
   delay_ms(1000);
   j=0;
/*
  while(j<10)
  {
   get[0]=uart_getch();
  
   if(get[0]=='O')
   {
    get[0]=uart_getch();
    if(get[0]=='K')
    m=1;
    break;
   }
   j++ ;
  }
  if(m==0)
  goto check;
			  */
   lcd_cmd(0x01);
   lcd_puts("TEXT MODE OK");

    

 

  check1:

  gsm_cmd("ate0");
  gsm_enter();
   delay_ms(1000);
 // get[0]=uart_getch();
  
  j=0;

 /* while(j<10)
  {
   get[0]=uart_getch();
  
   if(get[0]=='O')
   {
    get[0]=uart_getch();
    if(get[0]=='K')
    n=1;
    break;
   }
   j++ ;
  }
  if(n==0)
  goto check1;	   */

  lcd_cmd(0x01);
  lcd_puts("REDY TO DO");  
}

void gsm_send_num_mesg(unsigned char *num,unsigned char *mes)
{
 unsigned char get[17],*num1,*mes1,j,n=0;
   
 num1=num;
 mes1=mes;

 check:

 gsm_cmd("at+cmgs=");

 uart_putch('"');
 while(*num)
 uart_putch(*num++);
 uart_putch('"');

 gsm_enter();

 
 while(*mes)
 uart_putch(*mes++);
 
 num=num1;
 mes=mes1;


 uart_putch(0x1a);
 
  j=0;
 /*
  while(j<10)
  {
   get[0]=uart_getch();
  
   if(get[0]=='+')
   {
    get[0]=uart_getch();
    if(get[0]=='C')
	 get[0]=uart_getch();
	  if(get[0]=='M')
	   get[0]=uart_getch();
	  if(get[0]=='G')
	   get[0]=uart_getch();
	  if(get[0]=='S')
	  {
       n=1;
       break;
	  }
   }
   j++ ;
  }
  if(n==0)
  goto check;	*/

  delay_ms(5000);
 
 
  lcd_cmd(0x01);
  lcd_puts("M HAS BEEN SENT");
 
}

#endif
