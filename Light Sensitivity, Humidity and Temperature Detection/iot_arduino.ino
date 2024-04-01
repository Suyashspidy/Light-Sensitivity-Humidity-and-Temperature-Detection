void setup() {
  // put your setup code here, to run once:
  usart_init();
  _delay_ms(10);
pinMode(13,1);
 pinMode(12,1);

    
usart_str_tx("AT\r\n");
_delay_ms(100);


usart_str_tx("AT+CWMODE=3\r\n");
_delay_ms(100);



usart_str_tx("AT+CIPMUX=0\r\n");
_delay_ms(100);


usart_str_tx("AT+CWJAP=\"Hmm hmm hmm\",\"123456789\"\r\n");
_delay_ms(1400);

}
char x=0;
void loop() {
  
char val,data;
int i=0;
  
      usart_str_tx("AT+CIPSTART=\"TCP\",\"184.106.153.149\",80\r\n");
      delay(10);
      usart_str_tx("AT+CIPSEND=97\r\n");
      delay(10);
      usart_str_tx("GET https://api.thingspeak.com/channels/430421/fields/1.json?api_key=CNPHP4VW0IF8ZYQY&results=1\r\n");
      while(i!=21)
      {
      val=usart_rx();
      if(val==':')
      {
        i++;
      }
      }
    val=usart_rx();
    data=usart_rx();
    usart_tx(data);
    usart_str_tx("\r\n");
    if(data=='A')
    {
      digitalWrite(13,1);
    }
    else if(data=='a')
    {
        digitalWrite(13,0);
    }
    
    else if(data=='B')
    {
      digitalWrite(12,1);
    }
    
    else if(data=='b')
    {
      digitalWrite(12,0);
    }
    
    else
    {
    digitalWrite(12,0);
    digitalWrite(13,0);
    }  

}

                char usart_rx()
                {
                while(!(UCSR0A&(1<<RXC0)));
                return UDR0;
                }

                
                
                void usart_tx(char data)
                {
                
                UDR0=data;
                while(!(UCSR0A&(1<<UDRE0)));
                 
                }
                
                
            
                void usart_init()
                {
                /*Set baud rate */
                UBRR0H = 0;
                UBRR0L = 103;
               // Enable receiver and transmitter 
                UCSR0B = (1<<RXEN0)|(1<<TXEN0);
                /* Set frame format: 8data, 2stop bit */
                UCSR0C = (1<<USBS0)|(3<<UCSZ00);
                }





              
              void usart_str_tx(char *str)
              {
                unsigned int i=0;
                while(str[i]!='\0')
                {
                  usart_tx(str[i]);
                  i++;
                }
              }



