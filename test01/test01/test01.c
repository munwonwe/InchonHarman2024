#include <stdio.h>

int test01()
{
	char* str[] = {"Zero", "One", "Two", "Three", "Four", "Five",
					"six", "seven", "eight", "nine"}; //���ڿ� ������ �迭

	printf("���� Ű�� �Է��ϼ���.\n");
	printf("�����⸦ ���ϴ� ��쿣 'Q'�� �����ּ���\n");
	int n = 1;
	while (n)
	{
		printf(">");
		char c = getch(); // no echo : Ű���� ������� �ʰ� ��ȯ
		//char c1 = getchar() // [enter] �ʿ�.
		//�ƽ�Ű�ڵ忡�� 0�� 30 �κп� �ְ� 1�� 31�� ����. '0' = 0x30,           -0x30 ���ָ� 0�� ���� (�ƽ�Ű�ڵ�)
		
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
		// 0x20 = 16���� ǥ���, 0010xxxx, 4=0100, 60=0110
		// �빮�ڵ� �ҹ��ڵ� ������ �ҹ��ڷ� ��ȯ�� �ȴ�.
		{
			break;
		}
		else
		{
			printf("���ڸ� �ٽ� �Է��ϼ���\n");
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
	char ca[] = "Hello"; //ca[0]���� h�� ����.ca[4]���� o�� ���ִ�, ca[5]��°���� null�� ����(\n)
	for (int i = 0; i < 10; i++) // 0 ~ 5���� i���� ������ �ȴ�.
	{
		printf("ca[%d] : %c (%2x)\n", i, ca[i], ca[i]);
	}
	ca[2] -= 1;
	ca[3] -= 1;
	for (int i = 0; i < 10; i++) // 0 ~ 5���� i���� ������ �ȴ�.
	{
		printf("ca[%d] : %c (%2x)\n", i, ca[i], ca[i]);
	}
}