#include "myhd.h"

//unsigned long cnt = 0, tcnt = 0;

int main(void)
{
	DDRA = 0x01;
	PORTA = 0x00;
	DDRD = 0xFF;
	DDRC = 0x0F;
//	SegPort(&PORTD, &PORTC);

	EIMSK = 0x70;
//  TIMSK |= 0x01;	// 0000 0001b - Timer 0 TCNT overflow interrupt
	TIMSK |= 0x04;	// 0000 0100b - Timer 0 TCNT overflow interrupt (16bit)
//	TIMSK |= 0x40;	// 0100 0000b - Timer 2 TCNT overflow interrupt
//	TCCR0 = 0x01;
	TCCR1B = 0x01;	// 분주비 (Pre-Scaler)
//	TCCR2 = 0x04;	// 분주비 (Pre-Scaler) 
	EICRB = 0x2a;
	SREG |= 0x80;
	sei();
	
	
	while(1)
	{
		if(bott3 == 1)
		{
			SegDisp(0x00);
			_delay_us(10);
		}
		
		while(bott1 == 7)
		{
			switch(opmode)
			{
				case 0: // reset & wait
				t = 0;
				arr[0] = 0x00;
				arr[1] = 0x00;
				arr[2] = 0x00;
				arr[3] = 0x00;
				break;
				case 1: // counter start
				t++;
				if(t == 100)
				{
					opmode = 2;
					for(int i=0; i<10; i++)
					{
						PORTA = 0x01;
						_delay_ms(100);
						PORTA = 0x00;
						_delay_ms(100);
					}
				}
				break;
				case 2: //	counter stop
				break;
				default: break;
			}
			SegDisp(t);
			_delay_us(10);
		} 
	
		while(bott2 == 7)
		{
			switch(state)
			{
				case 0: // reset & wait
				a = 0;
				ee = 0;
				arr[0] = 0x00;
				arr[1] = 0x00;
				arr[2] = 0x00;
				arr[3] = 0x00;
				next = 0;
				break;
				
				case 1:
					swww();
					break;
				
				case 2: //	counter stop
				ee--;
				if(ee == 0)
				{
					state = 0;
					for(int i=0; i<10; i++)
					{
						PORTA = 0x01;
						_delay_ms(100);
						PORTA = 0x00;
						_delay_ms(100);
					}
				}
				break;
				default: break;
			}
			SegDisp(ee);
			_delay_us(10);
		}
	}
	
   /* while (1) 
    {
		if(cnt > 0x10000) cnt = 0;
		SegDisp(cnt);
    }*/
}


ISR(TIMER1_OVF_vect)
{
	tcnt++;
	//if(tcnt >= 10)	// 8bit timer 사용시
	{
		cnt++; tcnt = 0;
	}
}