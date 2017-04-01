
void uart_init(void);
void send_to_modem (unsigned char s[]);
void enter (void);
void ch_send_to_modem (unsigned char single_char);
void delay(unsigned int value);

void uart_init(void)
 {
  TMOD=0x20;
  TH1=0xfd;
  SCON=0x50;
  TR1=1;
 }
 



 void ch_send_to_modem(unsigned char single_char)
  {
      
  SBUF=single_char;
  while(TI==0);
  TI=0;
  
  }

   
    
  			