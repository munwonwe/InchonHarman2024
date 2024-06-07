#include "ADC.h"

int main(void)
{
	int read;
	DDRB = 0xFF;
	
	DDRD = 0xFF;
	DDRC = 0x0F;
	//SegPort(&PORTC, &PORTD);
	//SegType(1);
	
	ADC_init(0); // 0 : ch number
	while(1)
	{
		//while(!(ADCSRA & ( 1 << ADIF)));
		read = read_ADC();
		SegDisp(read);
	}
	return 0;
}