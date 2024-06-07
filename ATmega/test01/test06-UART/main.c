#include "uarthd.h"


int main(void)
{
	initUART();
	char a = '0';
	int i = 0;
	uPuts("안녕하세요....^^..\r\n");
	
    while (1) 
    {
		//uPutc(a++);
		sprintf(buf, "ATmega128 터미널 출력 테스트 ...#%d", i++); bPrint();
		_delay_ms(1000);
		if(a > '9') a = '0';
    }
}

