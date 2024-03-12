#include <stdio.h>

int test01()
{
	char* str[] = {"Zero", "One", "Two", "Three", "Four", "Five",
					"six", "seven", "eight", "nine"}; //문자열 포인터 배열

	printf("숫자 키를 입력하세요.\n");
	printf("끝내기를 원하는 경우엔 'Q'를 눌러주세요\n");
	int n = 1;
	while (n) //안녕하세요
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

main()
{
	//test01();
	test02(1);
}

void test02(int a)
{
	char ca[] = "Hello"; //ca[0]부터 h가 들어간다.ca[4]에는 o가 들어가있다, ca[5]번째에는 null이 들어간다(\n)
	for (int i = 0; i < 10; i++) // 0 ~ 5까지 i값이 변동이 된다.
	{
		printf("ca[%d] : %c (%2x)\n", i, ca[i], ca[i]);
	}
	ca[2] -= 1;
	ca[3] -= 1;
	for (int i = 0; i < 10; i++) // 0 ~ 5까지 i값이 변동이 된다.
	{
		printf("ca[%d] : %c (%2x)\n", i, ca[i], ca[i]);
	}
}
