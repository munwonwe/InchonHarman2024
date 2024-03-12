#include <stdio.h>

int test01()
{
	char* str[] = {"Zero", "One", "Two", "Three", "Four", "Five",
					"six", "seven", "eight", "nine"}; //문자열 포인터 배열

	printf("숫자 키를 입력하세요.\n");
	printf("끝내기를 원하는 경우엔 'Q'를 눌러주세요\n");
	int n = 1;
	while (n)
	{
		printf(">");
		char c = getch(); // no echo : 키값을 출력하지 않고 반환
		//char c1 = getchar() // [enter] 필요.
		//아스키코드에서 0은 30 부분에 있고 1은 31에 있음. '0' = 0x30,           -0x30 해주면 0이 나옴 (아스키코드)
		
		int m = c - 0x30; // ASCII --> num
		printf("%c : %s\n", c, str[m]);


		/*
		if (c == '1')
		{
			printf("%c : One\n",c);
		}
		else if (c == '2')
		{
			printf("%c : Two\n",c);
		}
		else if (c == '3')
		{
			printf("%c : three\n",c);
		}
		else if (c == '4')
		{
			printf("%c : four\n",c);
		}
		else if (c == '5')
		{
			printf("%c : five\n",c);
		}
		else if (c == '6')
		{
			printf("%c : six\n",c);
		}
		else if (c == '7')
		{
			printf("%c : seven\n",c);
		}
		else if (c == '8')
		{
			printf("%c : eight\n",c);
		}
		else if (c == '9')
		{
			printf("%c : nine\n",c);
		}
		else if (c == '0')
		{
			printf("%c : zero\n",c);
		}
		else if (c | 0x20 == 'q') //40H 60H
		// 0x20 = 16진수 표기법, 0010xxxx, 4=0100, 60=0110
		// 대문자든 소문자든 무조건 소문자로 변환이 된다.
		{
			break;
		}
		else
		{
			printf("숫자를 다시 입력하세요\n");
		}
		
		switch (c)
		{
			case '1': printf("%c : one\n", c);
			break;

			case '2': printf("%c : Two\n", c);
			break;

			case '3': printf("%c : three\n", c);
			break;

			case '4': printf("%c : four\n", c);
			break;

			case '5': printf("%c : five\n", c);
			break;

			case '6': printf("%c : six\n", c);
			break;

			case '7': printf("%c : seven\n", c);
			break;

			case '8': printf("%c : eight\n", c);
			break;

			case '9': printf("%c : nine\n", c);
			break;

			case '0': printf("%c : zero\n", c);
			break;

			case 'q':
			case 'Q': n = 0; break;
		}
		*/
	}
}


void test02(int a);
void test03();
void Dump(char* p, int len);
void Copy(char* p1, char* p2);


main()
{
	//test01();
	//test02(1); //1은 아무 의미 없음, 아규먼트를 받아 줄 때에는 이와 같이 던져줄 수 있는 예시일 뿐
	test03();
}

void test02(int a)
{
	char ca[] = "Hello"; //ca[0]부터 h가 들어간다.ca[4]에는 o가 들어가있다, ca[5]번째에는 null이 들어간다(\n)
	for (int i = 0; i < 10; i++) // 0 ~ 5까지 i값이 변동이 된다.
	{
		printf("ca[%d] : %c (%2x) [%08x]\n", i, ca[i], ca[i], ca + i);
	}
	int ia[] = {10,20,30,40,50 };
	for (int i = 0; i < 10; i++) // 0 ~ 5까지 i값이 변동이 된다.
	{
		printf("ia[%d] : %d (08x) [%08x]\n", i, ia[i], ia[i], ia + i);
	}

	int ia2[3][2] = {10,20,30,40,50,60};
	for (int y = 0; y < 3; y++) // 0 ~ 5까지 i값이 변동이 된다.
	{
		for (int x = 0; x < 2; x++)
		{
			printf("ia2[%d][%d] : %d [%08x]\n", y, x, ia2[y][x], ia2 + y);
		}
	}
}
void test03()
{
	char buf[100]; //안전 메모리 공간 확보
	char* pBuf;    //안전 메모리 공간중의 출력 위치
	unsigned int addr;      //출력 위치 지정을 위한 입력변수(주소)
	char kBuf[100]; //출력 문자열 입력 공간

	printf("안전공간의 주소는 %d[%08x] 입니다.\n", (unsigned int) buf, (unsigned int) buf);
	printf("입력을 시작할 주소를 입력하세요 :");
	scanf("%d", &addr); // 안전공간 주소 참고
	pBuf = buf + addr;
	printf("문자열을 입력하세요 :");
	scanf("%s", kBuf); //키보드로 입력받을 때 문자열을 입력 받을 충분한 공간을 만들어줘야 한다.
	strcpy(pBuf, kBuf); //문자열 복사 함수
	Copy(pBuf, kBuf);
	Dump(buf, 100);
}


void Copy(char* p1, char* p2)
{
	while (*p2) *p1++ = *p2++; *p1 = 0; //p2가 소스가 되고 p1이 타겟이 된다. p2의 값이 null이 아니라면 p1의 값에다가 p2에 있는 값을 복사해서 넣어라.
	//p2가 null의 위치에 왔을 때 p1은 0이 된다.
}
void Dump(char *p, int len) //메모리 공간 출력 범용 함수
{
	for (int i = 0; i < len; i++) // 안전공간 메모리 덤프
	{
		if(i % 16 == 0)  printf("\n%08x ", p); //주소값을 찍는다.
		if (i % 8 == 0)  printf(" ");
		printf("%02x ", (unsigned char)*p++); // p자체는 캐릭터포인터인데 *p는 그 주소의 자체에 있는 값을 찍는다.
		
	}
}