#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define __delay_t 500

#define OPMODE_MAX	3
#define STATE_MAX	3

uint8_t digit[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67, 0x77, 0x7c, 0x58, 0x5e, 0x79, 0x71};
char arr[5];
char *PA = &PORTD, *PB = &PORTC;

unsigned long cnt = 0, tcnt = 0;

volatile int opmode = 0, state = 0;	//최적화 금지
int t = 0; 
unsigned long a = 0;
int bott1 = 0, bott2 = 0; bott3 = 1;
int timerup = 0, timerup_prev = 0,  timerdown = 0, timerdown_prev = 0;
int next = 0; //타이머 값 설정 후 다음으로 넘어가는 변수
int next_step = 0;

unsigned long aa = 0;
unsigned long bb = 0;
unsigned long cc = 0;
unsigned long dd = 0;
unsigned long ee = 0;



//extern char* Disp(unsigned long num);


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
	arr[1] = digit[n2];
	arr[2] = digit[n3];
	arr[3] = digit[n4];
	//if (num > 15)	 arr[1] = digit[n2];
	//if (num > 256)	 arr[2] = digit[n3];
	//if (num > 4096)	 arr[3] = digit[n4];
	/*if(num == 0)
	{
		arr[1] = 0x00;
		arr[2] = 0x00;
		arr[3] = 0x00;
	}
	*/
	
	FND_4(arr);
	return arr;
}

ISR(INT4_vect) // INT4 인터럽트 처리 루틴 : sw1
{
	if(next_step == 0)
	{
		opmode++;
		bott1 = 7;
		bott2 = 8;
		bott3 = 0;
		if(opmode >= OPMODE_MAX) opmode = 0;
	}
	
	timerup++;
}

ISR(INT5_vect) // INT4 인터럽트 처리 루틴 : sw2
{
	if(next_step == 0)
	{
		state++;
		if(state >= STATE_MAX) state = 0;
	}
	if(next_step == 1)
	{
		next++;
	}
	bott1 = 8;
	bott2 = 7;
	bott3 = 0;
	
}

ISR(INT6_vect) // INT4 인터럽트 처리 루틴 : sw3
{
	if(next_step == 0)
	{
		opmode = 0;
		state = 0;
		bott1 = 0;
		bott2 = 0;
		bott3 = 0;
		t = 0;
		a = 0;
	}
	
	timerdown++;

}

void setbotton()
{
	if (timerup > timerup_prev)
	{
		if (timerup == timerup_prev + 1)
		{
			a++;
			if (a >= 16)
			{
				a = 0;
			}
		}
		timerup_prev = timerup;
	}
	if (timerdown > timerdown_prev)
	{
		if (timerdown == timerdown_prev + 1)
		{
			a--;
			if (a < 0)
			{
				a = 15;
			}
		}
		timerdown_prev = timerdown;
	}
	{
		SegDisp(a);
		_delay_ms(5);
	}
}
void setbotton1()
{
	if (timerup > timerup_prev)
	{
		if (timerup == timerup_prev + 1)
		{
			a = a + 16;
			if (a >= 241)
			{
				a = 0;
			}
		}
		timerup_prev = timerup;
	}
	if (timerdown > timerdown_prev)
	{
		if (timerdown == timerdown_prev + 1)
		{
			a = a - 16;
			if (a < 0)
			{
				a = 240;
			}
		}
		timerdown_prev = timerdown;
	}
	{
		SegDisp(a);
		_delay_ms(5);
	}
}
void setbotton2()
{
	if (timerup > timerup_prev)
	{
		if (timerup == timerup_prev + 1)
		{
			a = a + 256;
			if (a >= 3841)
			{
				a = 0;
			}
		}
		timerup_prev = timerup;
	}
	if (timerdown > timerdown_prev)
	{
		if (timerdown == timerdown_prev + 1)
		{
			a = a-256;
			if (a < 0)
			{
				a = 3840;
			}
		}
		timerdown_prev = timerdown;
	}
	{
		SegDisp(a);
		_delay_ms(5);
	}
}
void setbotton3()
{
	if (timerup > timerup_prev)
	{
		if (timerup == timerup_prev + 1)
		{
			a = a + 4096;
			if (a >= 61441)
			{
				a = 0;
			}
		}
		timerup_prev = timerup;
	}
	if (timerdown > timerdown_prev)
	{
		if (timerdown == timerdown_prev + 1)
		{
			a = a - 4096;
			if (a < 0)
			{
				a = 61440;
			}
		}
		timerdown_prev = timerdown;
	}
	{
		SegDisp(a);
		_delay_ms(5);
	}
}

void swww()
{
	next_step = 1;
	switch(next)
	{
		case 0:
		while(next == 0)
		{
			setbotton3();
		}
		aa = a;
		a = 0;
		break;
		
		case 1:
		while(next == 1)
		{
			setbotton2();
		}
		bb = a;
		a = 0;
		break;
		
		case 2:
		while(next == 2)
		{
			setbotton1();
		}
		cc = a;
		a = 0;
		break;
		
		case 3:
		while(next == 3)
		{
			setbotton();
		}
		dd = a;
		a = 0;
		break;
		
		case 4:
		
		next_step = 0;
		ee = aa + bb + cc + dd;
		
		SegDisp(ee);
		_delay_us(10);
		break;
		
		default: break;
	}
}
