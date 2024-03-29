/*
#include "myhd.h"


uint8_t digit[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67, 0x77, 0x7c, 0x58, 0x5e, 0x79, 0x71};
char arr[5];

char *PA = &PORTA, *PB = &PORTB;


void SegPort(char *p1, char *p2)
{
	PA = p1; PB = p2;
}

volatile int opmode = 0, state = 0;	//최적화 금지




void seg(unsigned long sel, uint8_t c)
{
	*PB |= 0x0F;
	*PB &= ~(1 << (3-sel));
	*PA = c;
	_delay_ms(5);

}

void FND_4(char *inf) //segment Image 배열 (4바이트)
{
	for(int i=0; i<4; i++)
	{
		seg(i, *(inf+i));
		//seg(i, inf[i]);
	}
}
char* SegDisp(unsigned long num)	//10진 정수 입력받아서 16진수 문자열로 변환 : 65535 >> FFFF, 56506 > 0xDCBA
{						// 4digit 16진수 segment 출력
	int n1 = num % 16;			//A		나누기가 많이 들어가면 처리 속도가 늦어지고 제일 빠른 건 +이다
	int n2 = (num / 16) % 16;	//B
	int n3 = (num / 256) % 16;	//C
	int n4 = (num / 4096);		//D
	
	//int sm;
	//sm = (num > 4095) ? 4 : (num > 256) ? 3 : (num > 16) ? 2 : 1;

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
*/