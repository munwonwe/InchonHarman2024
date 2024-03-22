#include <stdio.h>

void test01();		//함수의 Prototype
void test02(int a); //프로시저 수행함수 return 값이 없는 함수들 단순히 구분하기 위한
void test03();
void test04();
void test05();
void test06();
void test07();
void test08();

void Dump(char* p, int len);

// ----- 함수의 설계 -----
// Prototype : void Copy(char* p1, char* p2);
// 함수명    : Copy
// 기능      : p2 문자열을 인수로 받아서 p1 문자열로 복사
// 인수      : 타겟문자열, 소스문자열 - char *p1, char *p2
// 리턴값    : void(없음)
void Copy(char* p1, char* p2);

// ----- 함수의 설계 -----
// Prototype : int Length (char* str)
// 함수명    : Length
// 기능      : 문자열을 인수로 받아서 문자열의 길이를 반환
// 인수      : 문자열 - char *str
// 리턴값    : 문자열의 길이 - int len
int length(char* str);

// ----- 함수의 설계 -----
// Prototype : int compare (char* s1, char* s2)
// 함수명    : Compare
// 기능      : 문자열을 인수 2개로 받아서 문자열의 길이 비교
// 인수      : 문자열 char* s1, char* s2
// 리턴값    : 문자열의 비교 값 - int com
int compare(char* s1, char* s2);


main()
{
	int n;
	void* pF[] = {test01, test02, test03, test04, test05, test06, test07, test08};
	void (*pFunc)();
	while (1)
	{
		printf("\n\n\n\n\n");
		printf("1. 숫자키에 대한 문자열 출력 미션\n");
		printf("2. 문자열과 문자배열\n");
		printf("3. 포인터의 위치 지정\n");
		printf("4. 포인터를 이용한 문자열 입출력 함수\n");
		printf("5. 구조체 테스트\n");
		printf("6. 표준함수 테스트\n");
		printf("7. Length 함수 테스트\n");
		printf("8. 비교 함수\n");
		printf("0. 종       료\n");
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

	printf("숫자 키를 입력하세요.\n");
	printf("끝내기를 원하는 경우엔 'Q'를 눌러주세요\n");
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
		// 0x20 = 16吏꾩닔 ?쒓린踰? 0010xxxx, 4=0100, 60=0110
		// ?�臾몄옄???뚮Ц?먮뱺 臾댁“嫄??뚮Ц?먮줈 蹂�?섏씠 ?쒕떎.
		{
			break;
		}
		else
		{
			printf("?レ옄瑜??ㅼ떆 ?낅젰?섏꽭??n");
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
	char ca[] = "Hello"; //ca[0]遺�??h媛� ?ㅼ뼱媛꾨떎.ca[4]?먮뒗 o媛� ?ㅼ뼱媛�?덈떎, ca[5]踰덉㎏?먮뒗 null???ㅼ뼱媛꾨떎(\n)
	for (int i = 0; i < 10; i++) // 0 ~ 5源뚯? i媛믪씠 蹂�?숈씠 ?쒕떎.
	{
		printf("ca[%d] : %c (%2x) [%08x]\n", i, ca[i], ca[i], ca + i);
	}
	int ia[] = {10,20,30,40,50 };
	for (int i = 0; i < 10; i++) // 0 ~ 5源뚯? i媛믪씠 蹂�?숈씠 ?쒕떎.
	{
		printf("ia[%d] : %d (08x) [%08x]\n", i, ia[i], ia[i], ia + i);
	}

	int ia2[3][2] = {10,20,30,40,50,60};
	for (int y = 0; y < 3; y++) // 0 ~ 5源뚯? i媛믪씠 蹂�?숈씠 ?쒕떎.
	{
		for (int x = 0; x < 2; x++)
		{
			printf("ia2[%d][%d] : %d [%08x]\n", y, x, ia2[y][x], ia2 + y);
		}
	}
}
void test03()
{
	char buf[100]; //?덉쟾 硫붾え由?怨듦컙 ?뺣낫
	char* pBuf;    //?덉쟾 硫붾え由?怨듦컙以묒쓽 異쒕젰 ?꾩튂
	unsigned int addr;      //異쒕젰 ?꾩튂 吏�?뺤쓣 ?꾪븳 ?낅젰蹂�??二쇱냼)
	char kBuf[100]; //異쒕젰 臾몄옄???낅젰 怨듦컙

	printf("안전공간의 주소는 %d[%08x] 입니다.\n", (unsigned int) buf, (unsigned int) buf);
	printf("입력을 시작할 주소를 입력하세요 :");
	scanf("%d", &addr); // ?덉쟾怨듦컙 二쇱냼 李멸퀬
	pBuf = buf + addr;
	printf("문자열을 입력하세요 :");
	scanf("%s", kBuf); //?ㅻ낫?쒕줈 ?낅젰諛쏆쓣 ??臾몄옄?댁쓣 ?낅젰 諛쏆쓣 異⑸텇??怨듦컙??留뚮뱾?댁쨾???쒕떎.
	strcpy(pBuf, kBuf); //臾몄옄??蹂듭궗 ?⑥닔
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
	} s1 = { 1, 3.14, "삼천갑자 동방삭"};

	struct stTest s2 = s1;

	printf("sizeof(struct stTest) : %d\n", sizeof(struct stTest));

	printf("struct stTest s1 : %d %f %s\n", s1.i, s1.a, s1.name);
	printf("struct stTest s1 : %d %f %s\n", s2.i, s2.a, s2.name);
}
void test06()
{
	char* s1;		//"Good";       //const 영역에 있는 Good, 즉 변형이 불가능함. (수정불가영역)
	char* s2;		//"afternoon";
	char buf[100];

	s1 = buf;		//확보가 안 된 곳에서는 입력을 받을 수 없다.
	s2 = buf + 50;	//buf의 공간 안에 입력받은 내용을 저장하는 것. buf에 먼저 입력된 것이 s로 전달 된다.

	scanf("%s", s1);
	scanf("%s", s2);

	// strcat Test
	printf("s1 : %s(%d)\n", s1, strlen(s1));
	printf("s2 : %s(%d)\n", s2, strlen(s2));
	strcpy(buf, s1); 
	strcat(buf, s2); // s1 + s2 의 영역을 합쳐줌, 만약 상수영역이면 수정불가한 제어를 받게 된다.
	printf("strcat(s1,s2) %s", buf);  //캐릭터 포인터를 되돌려주는 함수 strcat,
	//sprintf(buf, "strcat(s1,s2) %s %s", s1, s2); // buf에 있는 안전한 메모리공간에 출력물을 화면이 아닌 buf로 보냄, strcat 함수가 상수영역에 있는 것을 타겟으로 하면 곤란해짐. 즉 사용 불가능
	//printf("%s", buf);
	}
void test07()
{
	char buf[100];
	printf("문자열을 입력하세요 : "); 	scanf("%s", buf);
	printf("입력한 문자열의 길이는 [ %d ] 입니다.\n\n", Length(buf));
}
void test08()
{
	char a[100];
	char b[100];
	int c = 0;

	printf("문자열을 입력하세요 : ");
	scanf("%s", a);
	printf("문자열을 입력하세요 : ");
	scanf("%s", b);

	c = compare(a, b);

	printf("%d.\n\n", c);
}


void Copy(char* p1, char* p2)
{
	while (*p2) *p1++ = *p2++; *p1 = 0; //p2媛� ?뚯뒪媛� ?섍퀬 p1???�寃잛씠 ?쒕떎. p2??媛믪씠 null???꾨땲?쇰㈃ p1??媛믪뿉?ㅺ? p2???덈뒗 媛믪쓣 蹂듭궗?댁꽌 ?ｌ뼱??
	//p2媛� null???꾩튂???붿쓣 ??p1?� 0???쒕떎.
}
void Dump(char *p, int len) //硫붾え由?怨듦컙 異쒕젰 踰붿슜 ?⑥닔
{
	for (int i = 0; i < len; i++) // ?덉쟾怨듦컙 硫붾え由??ㅽ봽
	{
		if(i % 16 == 0)  printf("\n%08x ", p); //二쇱냼媛믪쓣 李띾뒗??
		if (i % 8 == 0)  printf(" ");
		printf("%02x ", (unsigned char)*p++); // p?먯껜??罹먮┃?고룷?명꽣?몃뜲 *p??洹?二쇱냼???먯껜???덈뒗 媛믪쓣 李띾뒗??
		
	}
}

int Length(char* str) //str은 문자열의 시작 부분을 가리키고 있음, null이 나올때까지 한 바이트씩 차례차례 점검 해야 한다. 증가할때마다 +1씩 증가시켜준다.
{
	int len = 0; // 반환할 문자열의 길이
	
	while (1)
	{
		if (*(str + len) == 0) break; //str의 위치에서 len번째의 값이 0이라면 빠져나옴, *는 그 주소의 메모리값을 참조함.
		len++;
	}
	return len;
}

int compare(char* s1, char* s2)
{
	int i = 0;

	//while(*s1 && *s2 && *s1 == *s2) 
		
	while (s1[i] != '\0' && s2[i] != '\0') // 두 문자가 서로 null이 될 때까지 비교하여 계속 돌림.
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

	if (s1[i] == '\0' && s2[i] != '\0')  //s1은 null이고 s2가 null이 아닐 경우엔 s2가 크다.
	{
		return -1;
	}
	else if (s1[i] != '\0' && s2[i] == '\0')  //s1이 null이 아니고 s2가 null이면 s1이 크다.
	{
		return 1;
	}
	return 0; // 두 문자는 같다.
}