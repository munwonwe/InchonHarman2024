#include <stdio.h>

void test01();		//�Լ��� Prototype
void test02(int a); //���ν��� �����Լ� return ���� ���� �Լ��� �ܼ��� �����ϱ� ����
void test03();
void test04();
void test05();
void test06();
void test07();
void test08();

void Dump(char* p, int len);

// ----- �Լ��� ���� -----
// Prototype : void Copy(char* p1, char* p2);
// �Լ���    : Copy
// ���      : p2 ���ڿ��� �μ��� �޾Ƽ� p1 ���ڿ��� ����
// �μ�      : Ÿ�ٹ��ڿ�, �ҽ����ڿ� - char *p1, char *p2
// ���ϰ�    : void(����)
void Copy(char* p1, char* p2);

// ----- �Լ��� ���� -----
// Prototype : int Length (char* str)
// �Լ���    : Length
// ���      : ���ڿ��� �μ��� �޾Ƽ� ���ڿ��� ���̸� ��ȯ
// �μ�      : ���ڿ� - char *str
// ���ϰ�    : ���ڿ��� ���� - int len
int length(char* str);

// ----- �Լ��� ���� -----
// Prototype : int compare (char* s1, char* s2)
// �Լ���    : Compare
// ���      : ���ڿ��� �μ� 2���� �޾Ƽ� ���ڿ��� ���� ��
// �μ�      : ���ڿ� char* s1, char* s2
// ���ϰ�    : ���ڿ��� �� �� - int com
int compare(char* s1, char* s2);


main()
{
	int n;
	void* pF[] = {test01, test02, test03, test04, test05, test06, test07, test08};
	void (*pFunc)();
	while (1)
	{
		printf("\n\n\n\n\n");
		printf("1. ����Ű�� ���� ���ڿ� ��� �̼�\n");
		printf("2. ���ڿ��� ���ڹ迭\n");
		printf("3. �������� ��ġ ����\n");
		printf("4. �����͸� �̿��� ���ڿ� ����� �Լ�\n");
		printf("5. ����ü �׽�Ʈ\n");
		printf("6. ǥ���Լ� �׽�Ʈ\n");
		printf("7. Length �Լ� �׽�Ʈ\n");
		printf("8. �� �Լ�\n");
		printf("0. ��       ��\n");
		printf("==================================\n");

		scanf("%d", &n);

		if (n == 0) return;
		pFunc = pF[n - 1];
		pFunc();
	}

	//test01();
	//test02(1);
	//test03();
	//test04();
}


void test01()
{
	char* str[] = {"Zero", "One", "Two", "Three", "Four", "Five",
					"six", "seven", "eight", "nine"};

	printf("���� Ű�� �Է��ϼ���.\n");
	printf("�����⸦ ���ϴ� ��쿣 'Q'�� �����ּ���\n");
	int n = 1;
	while (n)
	{
		printf(">");
		char c = getch();

		
		if ((c | 0x20) == 'q') break;
		printf("%c : %s\n", c, str[c - 0x30]);   //printf("%c : %s\n", c, str[m]);


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
		// 0x20 = 16진수 ?�기�? 0010xxxx, 4=0100, 60=0110
		// ?�문자???�문?�든 무조�??�문?�로 변?�이 ?�다.
		{
			break;
		}
		else
		{
			printf("?�자�??�시 ?�력?�세??n");
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
void test02(int a)
{
	char ca[] = "Hello"; //ca[0]부??h가 ?�어간다.ca[4]?�는 o가 ?�어가?�다, ca[5]번째?�는 null???�어간다(\n)
	for (int i = 0; i < 10; i++) // 0 ~ 5까�? i값이 변?�이 ?�다.
	{
		printf("ca[%d] : %c (%2x) [%08x]\n", i, ca[i], ca[i], ca + i);
	}
	int ia[] = {10,20,30,40,50 };
	for (int i = 0; i < 10; i++) // 0 ~ 5까�? i값이 변?�이 ?�다.
	{
		printf("ia[%d] : %d (08x) [%08x]\n", i, ia[i], ia[i], ia + i);
	}

	int ia2[3][2] = {10,20,30,40,50,60};
	for (int y = 0; y < 3; y++) // 0 ~ 5까�? i값이 변?�이 ?�다.
	{
		for (int x = 0; x < 2; x++)
		{
			printf("ia2[%d][%d] : %d [%08x]\n", y, x, ia2[y][x], ia2 + y);
		}
	}
}
void test03()
{
	char buf[100]; //?�전 메모�?공간 ?�보
	char* pBuf;    //?�전 메모�?공간중의 출력 ?�치
	unsigned int addr;      //출력 ?�치 지?�을 ?�한 ?�력변??주소)
	char kBuf[100]; //출력 문자???�력 공간

	printf("���������� �ּҴ� %d[%08x] �Դϴ�.\n", (unsigned int) buf, (unsigned int) buf);
	printf("�Է��� ������ �ּҸ� �Է��ϼ��� :");
	scanf("%d", &addr); // ?�전공간 주소 참고
	pBuf = buf + addr;
	printf("���ڿ��� �Է��ϼ��� :");
	scanf("%s", kBuf); //?�보?�로 ?�력받을 ??문자?�을 ?�력 받을 충분??공간??만들?�줘???�다.
	strcpy(pBuf, kBuf); //문자??복사 ?�수
	Copy(pBuf, kBuf);
	Dump(buf, 100);
}
void test04()
{
	char* arr[10] = { "aaaaa", "bbbb", "ccc", "dd", "eeeeee" };
	char buf[100];
	printf("[6] "); scanf("%s", buf);
	arr[6] = buf;
	printf("[7]"); scanf("%s", buf + 50);
	arr[7] = buf + 50;

	for (int i = 0; i < 10; i++)
	{
		printf("arr[%d] : 0x%08x %s\n", i, arr[i], arr[i]);
	}
}
void test05()
{
	struct stTest
	{
		int i;
		float a;
		char name[20];
	} s1 = { 1, 3.14, "��õ���� �����"};

	struct stTest s2 = s1;

	printf("sizeof(struct stTest) : %d\n", sizeof(struct stTest));

	printf("struct stTest s1 : %d %f %s\n", s1.i, s1.a, s1.name);
	printf("struct stTest s1 : %d %f %s\n", s2.i, s2.a, s2.name);
}
void test06()
{
	char* s1;		//"Good";       //const ������ �ִ� Good, �� ������ �Ұ�����. (�����Ұ�����)
	char* s2;		//"afternoon";
	char buf[100];

	s1 = buf;		//Ȯ���� �� �� �������� �Է��� ���� �� ����.
	s2 = buf + 50;	//buf�� ���� �ȿ� �Է¹��� ������ �����ϴ� ��. buf�� ���� �Էµ� ���� s�� ���� �ȴ�.

	scanf("%s", s1);
	scanf("%s", s2);

	// strcat Test
	printf("s1 : %s(%d)\n", s1, strlen(s1));
	printf("s2 : %s(%d)\n", s2, strlen(s2));
	strcpy(buf, s1); 
	strcat(buf, s2); // s1 + s2 �� ������ ������, ���� ��������̸� �����Ұ��� ��� �ް� �ȴ�.
	printf("strcat(s1,s2) %s", buf);  //ĳ���� �����͸� �ǵ����ִ� �Լ� strcat,
	//sprintf(buf, "strcat(s1,s2) %s %s", s1, s2); // buf�� �ִ� ������ �޸𸮰����� ��¹��� ȭ���� �ƴ� buf�� ����, strcat �Լ��� ��������� �ִ� ���� Ÿ������ �ϸ� �������. �� ��� �Ұ���
	//printf("%s", buf);
	}
void test07()
{
	char buf[100];
	printf("���ڿ��� �Է��ϼ��� : "); 	scanf("%s", buf);
	printf("�Է��� ���ڿ��� ���̴� [ %d ] �Դϴ�.\n\n", Length(buf));
}
void test08()
{
	char a[100];
	char b[100];
	int c = 0;

	printf("���ڿ��� �Է��ϼ��� : ");
	scanf("%s", a);
	printf("���ڿ��� �Է��ϼ��� : ");
	scanf("%s", b);

	c = compare(a, b);

	printf("%d.\n\n", c);
}


void Copy(char* p1, char* p2)
{
	while (*p2) *p1++ = *p2++; *p1 = 0; //p2가 ?�스가 ?�고 p1???�겟이 ?�다. p2??값이 null???�니?�면 p1??값에?��? p2???�는 값을 복사?�서 ?�어??
	//p2가 null???�치???�을 ??p1?� 0???�다.
}
void Dump(char *p, int len) //메모�?공간 출력 범용 ?�수
{
	for (int i = 0; i < len; i++) // ?�전공간 메모�??�프
	{
		if(i % 16 == 0)  printf("\n%08x ", p); //주소값을 찍는??
		if (i % 8 == 0)  printf(" ");
		printf("%02x ", (unsigned char)*p++); // p?�체??캐릭?�포?�터?�데 *p??�?주소???�체???�는 값을 찍는??
		
	}
}

int Length(char* str) //str�� ���ڿ��� ���� �κ��� ����Ű�� ����, null�� ���ö����� �� ����Ʈ�� �������� ���� �ؾ� �Ѵ�. �����Ҷ����� +1�� ���������ش�.
{
	int len = 0; // ��ȯ�� ���ڿ��� ����
	
	while (1)
	{
		if (*(str + len) == 0) break; //str�� ��ġ���� len��°�� ���� 0�̶�� ��������, *�� �� �ּ��� �޸𸮰��� ������.
		len++;
	}
	return len;
}

int compare(char* s1, char* s2)
{
	int i = 0;

	//while(*s1 && *s2 && *s1 == *s2) 
		
	while (s1[i] != '\0' && s2[i] != '\0') // �� ���ڰ� ���� null�� �� ������ ���Ͽ� ��� ����.
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		else if (s1[i] > s2[i])
		{
			return 1;
		}
		else
		{
			return -1; 
		}
	}

	if (s1[i] == '\0' && s2[i] != '\0')  //s1�� null�̰� s2�� null�� �ƴ� ��쿣 s2�� ũ��.
	{
		return -1;
	}
	else if (s1[i] != '\0' && s2[i] == '\0')  //s1�� null�� �ƴϰ� s2�� null�̸� s1�� ũ��.
	{
		return 1;
	}
	return 0; // �� ���ڴ� ����.
}