#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

uint8_t digit[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67, 0x77, 0x7c, 0x58, 0x5e, 0x79, 0x71, 0x00};
char arr[5];

void ADC_init(unsigned char channel)
{
	ADMUX |= (1 << REFS0);
	
	ADCSRA |= 0x07;
	
	ADCSRA |= (1 << ADEN);
	ADCSRA |= (1 << ADFR);
	
	ADMUX = ((ADMUX & 0xE0) | channel);
	ADCSRA |= (1 << ADSC);
}

int read_ADC(void)
{
	while (!(ADCSRA & (1 << ADIF))); // Conversion 완료 기다림
	ADCSRA |= (1 << ADIF); // ADIF 플래그 클리어
	return ADC;
}

void seg(unsigned long sel, uint8_t c)
{
	PORTC |= 0x0F; // 모든 선택 핀을 끔
	PORTC &= ~(1 << sel); // 선택 핀 켜기
	PORTD = c; // 데이터 핀에 값 출력
	_delay_ms(5); // 잠깐 대기
}

void FND_4(char *inf)
{
	for (int i = 0; i < 4; i++)
	{
		seg(i, *(inf + i));
	}
}

char* SegDisp(unsigned long num)
{
	int n1 = num % 10;
	int n2 = (num / 10) % 10;
	int n3 = (num / 100) % 10;
	int n4 = (num / 1000);
	
	if(!(num / 1000))
	{
		n4 = 16;
	}
	
	if(!(num / 100))
	{
		n3 = 16;
	}
	
	if(!(num /10))
	{
		n2 = 16;
	}
	
	if(num>9999)
	{
		num = 0;
	}

	arr[0] = digit[n4];
	arr[1] = digit[n3];
	arr[2] = digit[n2];
	arr[3] = digit[n1];

	FND_4(arr);
	return arr;
}