void lcd_data(unsigned char data){
PORTD= (data & 0xF0);
PORTB|=(1<<PB3);//rs=1
PORTB|=(1<<PB2);//en
  _delay_ms(2);
PORTB&=~(1<<PB2);
  
PORTD= (data<<4);
PORTB|=(1<<PB3);
PORTB|=(1<<PB2);
  _delay_ms(2);
PORTB&=~(1<<PB2); 
}

void lcd_cmd(unsigned char comd){
PORTD=(comd & 0xF0);
PORTB&=~(1<<PB3);
PORTB|=(1<<PB2);
_delay_ms(2);
PORTB&=~(1<<PB2);
  
PORTD=(comd<<4);
PORTB&=~(1<<PB3);
PORTB|=(1<<PB2);
 _delay_ms(2);
PORTB&=~(1<<PB2);
}


void lcd_string(const char *str,unsigned char len){
char i=0;
  for(i=0;i<len;i++){
  lcd_data(str[i]);
  }
}

void lcd_initialize(){
   
 lcd_cmd(0x02);   // 4-bit mode
  lcd_cmd(0x28);   // 2 line display
  lcd_cmd(0x06);	//move cursor right after each letter
  lcd_cmd(0x0C);	//Display ON / Cursor OFF
  lcd_cmd(0x01);	//Clear Display
}
int count =0;
int first = 0;
int last = 0;

int main(){
    DDRD = 0xb11111100;
    DDRB|= (1<<DDB0)|(1<<DDB2)|(1<<DDB3);
    lcd_initialize();

    while(1){
        lcd_cmd(0x80);
        lcd_string("COUNT :",7);
 
     
  if(PINB&(1<<PINB5)){ 
   PORTD|=(1<<PD2);
   for(volatile long i = 0;i<300000; i++);
   PORTD &= ~(1<<PD2);
   first=1;
         
  if(first==1){
  for(volatile long i = 0; i < 30000; i++);
  if(PINB & (1<<PINB4)){ 
  PORTD|=(1<<PD3);
   count++;        
   first=0;
  PORTB|=(1<<PB0);
 for(volatile long i = 0; i < 300000; i++); 
PORTD&=~(1<<PD3);}
  }
  }
  
 if(PINB & (1<<PINB4)){ 
   PORTD|=(1<<PD3);
    for(volatile long i = 0; i < 300000; i++);
   PORTD&=~(1<<PD3);
   last=1;
 
   if(last==1){
  for(volatile long i = 0; i < 30000; i++);
 if(PINB & (1<<PINB5)){ 
  PORTD |= (1<<PD2);
   if(count > 0){
   count--;  
     last= 0;}
               
   PORTB|=(1<<PB0);
   for(volatile long i = 0; i < 300000; i++); 
   PORTD &= ~(1<<PD2);
  PORTB&=~(1<<PB0);}
   }
 }
  else {
      PORTD &= ~(1<<PD2);
      PORTB&=~(1<<PB0);
      PORTD &= ~(1<<PD3);
        }

  lcd_cmd(0xC0);
  lcd_data(count+'0');
    }}
    

    
