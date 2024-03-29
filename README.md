# InchonHarman2024
2024년 인천 하만과정 SW 구조 설계


오늘 배운 내용

void seg(int sel, uint8_t c)
{
	
	PORTC |= 0x0F;
	PORTC &= ~(1 << (3-sel));
	PORTD = c;
	_delay_ms(10)
}
void FND_4(char *inf); //segment Image 배열 (4바이트)
{
	for(int i=0; i<4; i++)
	{
		seg(i, *(inf+i));
		//seg(i, inf[i]);
	}
}
void Trans(int num) //정수를 입력받아서 16진수 문자열로 변환 : 65535 >> FFFF
{
	int n4 = num / 0x10000 //4096;
	int n3 = num / 256;
	int n2 = num / 16;
	int n1 = num / 1;
	
	num % 	
}
