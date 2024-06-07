#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

unsigned char buf[1024];

void initUART()
{
	// 9600 N81
	UBRR0H = 0;
	UBRR0L = 207; // Baud rate : 9600;
	
	UCSR0A |= (1 << 1);	// 0000 0010b, (1 << U2X0);
	
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0); //Rx, Tx Enable
	UCSR0C	= 0x06;	// Data bit: 8 x11x		0000 0110b		N81
					// Stop bit: 1 0xxx
}

void uPutc(char c)
{
	/*while(1)
	{
		//if (UCSR0A & (1 << UDRE0 == 1) break;
	}
	*/
	while(!(UCSR0A & (1 << UDRE0))); // Wait until data empty bit test 1
	UDR0 = c;	//send
}


void uPuts(char *str)
{
	while(*str) uPutc(*str++);
	/*
	while(1)
	{
		if(*str == 0) break;
		uPutc(*str);
		str++;		
	}
	*/
}

void bPrint()
{
	uPuts(buf);
}