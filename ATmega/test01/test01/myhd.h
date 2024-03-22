#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#define __delay_t 500

uint8_t digit[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67, 0x77, 0x7c, 0x58, 0x5e, 0x79, 0x71};		//전역변수
char arr[5];

void TogglePinA(int n) // n: n번째 비트, dl: delay in mili-second
{
	char b = 1 << n;
	PORTA |= b;
	_delay_ms(500);
	PORTA &= ~b;
	_delay_ms(500);
}
void LED(char *p, int n) //p는 PORTx의 포인터, n은 n 번째 비트
{
	char b = 1 << n;
	*p |= b;
	_delay_ms(500);
	*p &= ~b;
	_delay_ms(500);
	
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
char* Trans(unsigned long num)	//10진 정수 입력받아서 16진수 문자열로 변환 : 65535 >> FFFF, 56506 > 0xDCBA 
{						// 16진수 세그먼트 이미지 배열
	int n1 = num % 16;			//A		나누기가 많이 들어가면 처리 속도가 늦어지고 제일 빠른 건 +이다
	int n2 = (num / 16) % 16;	//B
	int n3 = (num / 256) % 16;	//C
	int n4 = (num / 4096);		//D
	arr[0] = digit[n1];
	if (num > 15)	 arr[1] = digit[n2];
	if (num > 256)	 arr[2] = digit[n3];
	if (num > 4096)	 arr[3] = digit[n4];
	
	//FND_4(arr);
	return arr;
}


void test1()
{
	DDRA |= 0x07; //A레지스터를(PORT) 0번째 bit를 출력용으로 사용, 나머지는 입력용, 기존에 있던 최하위비트 하나 빼고 기존에 있던 것이 0이면 0이고 1이면 1로
	DDRB &= ~0x01; // PORTB의 0번째 비트를 입력용으로 사용, 나머지는 그대로 유지
	
	//DDRA |= 0x01;
	//DDRA |= 0x02;
	int i = 0;
	
    while (1) //무한 루프가 기본, 임베디드 프로그래밍의 기본
    {
		if(PINB & 0x01 == 1)
		{
			TogglePinA(0); // PORTA의 0번째 비트를 점멸
			TogglePinA(1); // PORTA의 1번째 비트를 점멸
			TogglePinA(2); // PORTA의 2번째 비트를 점멸
		}
		
		PORTA |= 0x01;
		_delay_ms(300);
		PORTA &= ~0x01;
		_delay_ms(300);
		
		for(i=0; i<2; i++)
		{	
			PORTA = 0x01;			//PORT A도 8bit 출력레지스터다. 가장 최하위 비트는 1이여야만 한다. PORTA의 0번째 비트를 HIGH로 출력
			_delay_ms(300);
			PORTA = 0x02;			//PORTA의 모든 비트를 LOW로 출력
			_delay_ms(300);
			PORTA = 0x04;
			_delay_ms(300);
			PORTA = 0x08;
			_delay_ms(300);
			PORTA = 0x00;
			_delay_ms(300);
		}
		
		for(i=0; i<2; i++)
		{
			PORTA = 0x01;
			_delay_ms(300);
			PORTA = 0x00;
			_delay_ms(300);
			PORTA = 0x03;
			_delay_ms(300);
			PORTA = 0x00;
			_delay_ms(300);
			PORTA = 0x07;
			_delay_ms(300);
			PORTA = 0x00;
			_delay_ms(300);
			PORTA = 0x0F;
			_delay_ms(300);
			PORTA = 0x00;
			_delay_ms(300);
		}
	}
}
void test3()
{
	int i, j = 0;
	int mode = 0;
	
	DDRD = 0xFF;
	DDRC = 0x0F;
	DDRB &= ~0x01;
	
	while(1)
	{
		if(!((PINB & 0x01) == 1))
		{
			mode++;
			if(mode >= 3)
			{
				mode = 1;
			}
		}
		
		switch(mode)
		{
			case 0:
			PORTC |= 0x00;
			PORTD = 0b01000000;
			break;
			
			case 1:
			FND_4(Trans(j++));
			_delay_ms(10);
			break;
				
			case 2:
			FND_4(Trans(j));
			break;
		}
	}
	return 0;
}