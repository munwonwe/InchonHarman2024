#include "newtest.h"

int main()
{
	int read;

	DDRB = 0xFF;
	
	DDRD = 0xFF; // PORTD 출력으로 설정
	DDRC = 0x0F; // PORTC 하위 4비트를 출력으로 설정

	ADC_init(0); //ADC 초기화 및 0번 채널 설정

	while (1)
	{
		read = read_ADC();
		SegDisp(read);
	}
}

