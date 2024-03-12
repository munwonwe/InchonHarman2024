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
void test03();
void Dump(char* p, int len);
void Copy(char* p1, char* p2);


main()
{
	//test01();
	//test02(1); //1�� �ƹ� �ǹ� ����, �ƱԸ�Ʈ�� �޾� �� ������ �̿� ���� ������ �� �ִ� ������ ��
	test03();
}

void test02(int a)
{
	char ca[] = "Hello"; //ca[0]���� h�� ����.ca[4]���� o�� ���ִ�, ca[5]��°���� null�� ����(\n)
	for (int i = 0; i < 10; i++) // 0 ~ 5���� i���� ������ �ȴ�.
	{
		printf("ca[%d] : %c (%2x) [%08x]\n", i, ca[i], ca[i], ca + i);
	}
	int ia[] = {10,20,30,40,50 };
	for (int i = 0; i < 10; i++) // 0 ~ 5���� i���� ������ �ȴ�.
	{
		printf("ia[%d] : %d (08x) [%08x]\n", i, ia[i], ia[i], ia + i);
	}

	int ia2[3][2] = {10,20,30,40,50,60};
	for (int y = 0; y < 3; y++) // 0 ~ 5���� i���� ������ �ȴ�.
	{
		for (int x = 0; x < 2; x++)
		{
			printf("ia2[%d][%d] : %d [%08x]\n", y, x, ia2[y][x], ia2 + y);
		}
	}
}
void test03()
{
	char buf[100]; //���� �޸� ���� Ȯ��
	char* pBuf;    //���� �޸� �������� ��� ��ġ
	unsigned int addr;      //��� ��ġ ������ ���� �Էº���(�ּ�)
	char kBuf[100]; //��� ���ڿ� �Է� ����

	printf("���������� �ּҴ� %d[%08x] �Դϴ�.\n", (unsigned int) buf, (unsigned int) buf);
	printf("�Է��� ������ �ּҸ� �Է��ϼ��� :");
	scanf("%d", &addr); // �������� �ּ� ����
	pBuf = buf + addr;
	printf("���ڿ��� �Է��ϼ��� :");
	scanf("%s", kBuf); //Ű����� �Է¹��� �� ���ڿ��� �Է� ���� ����� ������ �������� �Ѵ�.
	strcpy(pBuf, kBuf); //���ڿ� ���� �Լ�
	Copy(pBuf, kBuf);
	Dump(buf, 100);
}


void Copy(char* p1, char* p2)
{
	while (*p2) *p1++ = *p2++; *p1 = 0; //p2�� �ҽ��� �ǰ� p1�� Ÿ���� �ȴ�. p2�� ���� null�� �ƴ϶�� p1�� �����ٰ� p2�� �ִ� ���� �����ؼ� �־��.
	//p2�� null�� ��ġ�� ���� �� p1�� 0�� �ȴ�.
}
void Dump(char *p, int len) //�޸� ���� ��� ���� �Լ�
{
	for (int i = 0; i < len; i++) // �������� �޸� ����
	{
		if(i % 16 == 0)  printf("\n%08x ", p); //�ּҰ��� ��´�.
		if (i % 8 == 0)  printf(" ");
		printf("%02x ", (unsigned char)*p++); // p��ü�� ĳ�����������ε� *p�� �� �ּ��� ��ü�� �ִ� ���� ��´�.
		
	}
}