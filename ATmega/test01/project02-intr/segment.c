/*
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define __delay_t 500
#define OPMODE_MAX	3
#define STATE_MAX	3

uint8_t digit[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67, 0x77, 0x7c, 0x58, 0x5e, 0x79, 0x71};
char arr[5];

volatile int opmode = 0, state = 0;	//최적화 금지
int t = 0, a = 0;
int bott1 = 0, bott2 = 0; bott3 = 1;


ISR(INT4_vect) // INT4 인터럽트 처리 루틴 : sw1
{
	opmode++;
	bott1 = 7;
	bott2 = 8;
	bott3 = 0;
	if(opmode >= OPMODE_MAX) opmode = 0;
}

ISR(INT5_vect) // INT4 인터럽트 처리 루틴 : sw2
{
	state++;
	bott1 = 8;
	bott2 = 7;
	bott3 = 0;
	if(state >= STATE_MAX) state = 0;
}

ISR(INT6_vect) // INT4 인터럽트 처리 루틴 : sw3
{
	opmode = 0;
	state = 0;
	bott1 = 0;
	bott2 = 0;
	bott3 = 0;
	t = 0;
	a = 0;

}


void seg(unsigned long sel, uint8_t c)
{
	PORTC |= 0x0F;
	PORTC &= ~(1 << (3-sel));
	PORTD = c;
	_delay_ms(3);

}

void FND_4(char *inf) //segment Image 배열 (4바이트)
{
	for(int i=0; i<4; i++)
	{
		seg(i, *(inf+i));
		//seg(i, inf[i]);
	}
}
char* Disp(unsigned long num)	//10진 정수 입력받아서 16진수 문자열로 변환 : 65535 >> FFFF, 56506 > 0xDCBA
{						// 4digit 16진수 segment 출력
	int n1 = num % 16;			//A		나누기가 많이 들어가면 처리 속도가 늦어지고 제일 빠른 건 +이다
	int n2 = (num / 16) % 16;	//B
	int n3 = (num / 256) % 16;	//C
	int n4 = (num / 4096);		//D

	arr[0] = digit[n1];
	if (num > 15)	 arr[1] = digit[n2];
	if (num > 256)	 arr[2] = digit[n3];
	if (num > 4096)	 arr[3] = digit[n4];
	if(num == 0)
	{
		arr[1] = 0x00;
		arr[2] = 0x00;
		arr[3] = 0x00;
	}
	
	FND_4(arr);
	return arr;
}

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
			arr[0] = 0x40;
			arr[1] = 0x40;
			arr[2] = 0x40;
			arr[3] = 0x40;
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
*/