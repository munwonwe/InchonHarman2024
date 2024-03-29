#include "project02.h"


int main(void)
{
    //Interrupt 사용	: INT4 ~ INT6 (Ext Int)
	//Pin assign	: PE4 ~ PE6
	//7-Segment 사용	: 4 Module - C type
	//Pin assign	: PAx - Segment img, PBx - module sel
	DDRA = 0x01;
	PORTA = 0x00;
	DDRD = 0xFF;
	DDRC = 0x0F;
	
	// 인터럽트 설정
	EIMSK = 0x70;	// 0111 0000b
	EICRB = 0x2a;	// 0010 1010  >> 7번비트는 00으로 하고 그 뒤부터 1 설정
	SREG |= 0x80;	// status Register - 인터럽트 허용
	sei();			// set interrupt - 인터럽트 시작
	
	Disp(t);

	while(1)
	{
		if(bott3 = 1)
		{
			Disp(t);
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
						break;
					case 2: //	counter stop
						break;
					default: break;
			}
			Disp(t);
			_delay_us(10);
		}

		while(bott2 == 7)
		{
			switch(state)
			{
				case 0: // reset & wait
				a = 0;
				arr[0] = 0x00;
				arr[1] = 0x00;
				arr[2] = 0x00;					
				arr[3] = 0x00;
				break;
				
				case 1: // counter start
				a++;
				if(a == 100)
				{
					state = 2;
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
			Disp(a);
			_delay_us(10);
		}
    }
	
}