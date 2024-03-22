#include <stdio.h>

void test01();		//ÇÔ¼öÀÇ Prototype
void test02(int a); //ÇÁ·Î½ÃÀú ¼öÇàÇÔ¼ö return °ªÀÌ ¾ø´Â ÇÔ¼öµé ´Ü¼øÈ÷ ±¸ºĞÇÏ±â À§ÇÑ
void test03();
void test04();
void test05();
void test06();
void test07();
void test08();

void Dump(char* p, int len);

// ----- ÇÔ¼öÀÇ ¼³°è -----
// Prototype : void Copy(char* p1, char* p2);
// ÇÔ¼ö¸í    : Copy
// ±â´É      : p2 ¹®ÀÚ¿­À» ÀÎ¼ö·Î ¹Ş¾Æ¼­ p1 ¹®ÀÚ¿­·Î º¹»ç
// ÀÎ¼ö      : Å¸°Ù¹®ÀÚ¿­, ¼Ò½º¹®ÀÚ¿­ - char *p1, char *p2
// ¸®ÅÏ°ª    : void(¾øÀ½)
void Copy(char* p1, char* p2);

// ----- ÇÔ¼öÀÇ ¼³°è -----
// Prototype : int Length (char* str)
// ÇÔ¼ö¸í    : Length
// ±â´É      : ¹®ÀÚ¿­À» ÀÎ¼ö·Î ¹Ş¾Æ¼­ ¹®ÀÚ¿­ÀÇ ±æÀÌ¸¦ ¹İÈ¯
// ÀÎ¼ö      : ¹®ÀÚ¿­ - char *str
// ¸®ÅÏ°ª    : ¹®ÀÚ¿­ÀÇ ±æÀÌ - int len
int length(char* str);

// ----- ÇÔ¼öÀÇ ¼³°è -----
// Prototype : int compare (char* s1, char* s2)
// ÇÔ¼ö¸í    : Compare
// ±â´É      : ¹®ÀÚ¿­À» ÀÎ¼ö 2°³·Î ¹Ş¾Æ¼­ ¹®ÀÚ¿­ÀÇ ±æÀÌ ºñ±³
// ÀÎ¼ö      : ¹®ÀÚ¿­ char* s1, char* s2
// ¸®ÅÏ°ª    : ¹®ÀÚ¿­ÀÇ ºñ±³ °ª - int com
int compare(char* s1, char* s2);


main()
{
	int n;
	void* pF[] = {test01, test02, test03, test04, test05, test06, test07, test08};
	void (*pFunc)();
	while (1)
	{
		printf("\n\n\n\n\n");
		printf("1. ¼ıÀÚÅ°¿¡ ´ëÇÑ ¹®ÀÚ¿­ Ãâ·Â ¹Ì¼Ç\n");
		printf("2. ¹®ÀÚ¿­°ú ¹®ÀÚ¹è¿­\n");
		printf("3. Æ÷ÀÎÅÍÀÇ À§Ä¡ ÁöÁ¤\n");
		printf("4. Æ÷ÀÎÅÍ¸¦ ÀÌ¿ëÇÑ ¹®ÀÚ¿­ ÀÔÃâ·Â ÇÔ¼ö\n");
		printf("5. ±¸Á¶Ã¼ Å×½ºÆ®\n");
		printf("6. Ç¥ÁØÇÔ¼ö Å×½ºÆ®\n");
		printf("7. Length ÇÔ¼ö Å×½ºÆ®\n");
		printf("8. ºñ±³ ÇÔ¼ö\n");
		printf("0. Á¾       ·á\n");
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

	printf("¼ıÀÚ Å°¸¦ ÀÔ·ÂÇÏ¼¼¿ä.\n");
	printf("³¡³»±â¸¦ ¿øÇÏ´Â °æ¿ì¿£ 'Q'¸¦ ´­·¯ÁÖ¼¼¿ä\n");
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
		// 0x20 = 16ì§„ìˆ˜ ?œê¸°ë²? 0010xxxx, 4=0100, 60=0110
		// ?€ë¬¸ì???Œë¬¸?ë“  ë¬´ì¡°ê±??Œë¬¸?ë¡œ ë³€?˜ì´ ?œë‹¤.
		{
			break;
		}
		else
		{
			printf("?«ìë¥??¤ì‹œ ?…ë ¥?˜ì„¸??n");
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
	char ca[] = "Hello"; //ca[0]ë¶€??hê°€ ?¤ì–´ê°„ë‹¤.ca[4]?ëŠ” oê°€ ?¤ì–´ê°€?ˆë‹¤, ca[5]ë²ˆì§¸?ëŠ” null???¤ì–´ê°„ë‹¤(\n)
	for (int i = 0; i < 10; i++) // 0 ~ 5ê¹Œì? iê°’ì´ ë³€?™ì´ ?œë‹¤.
	{
		printf("ca[%d] : %c (%2x) [%08x]\n", i, ca[i], ca[i], ca + i);
	}
	int ia[] = {10,20,30,40,50 };
	for (int i = 0; i < 10; i++) // 0 ~ 5ê¹Œì? iê°’ì´ ë³€?™ì´ ?œë‹¤.
	{
		printf("ia[%d] : %d (08x) [%08x]\n", i, ia[i], ia[i], ia + i);
	}

	int ia2[3][2] = {10,20,30,40,50,60};
	for (int y = 0; y < 3; y++) // 0 ~ 5ê¹Œì? iê°’ì´ ë³€?™ì´ ?œë‹¤.
	{
		for (int x = 0; x < 2; x++)
		{
			printf("ia2[%d][%d] : %d [%08x]\n", y, x, ia2[y][x], ia2 + y);
		}
	}
}
void test03()
{
	char buf[100]; //?ˆì „ ë©”ëª¨ë¦?ê³µê°„ ?•ë³´
	char* pBuf;    //?ˆì „ ë©”ëª¨ë¦?ê³µê°„ì¤‘ì˜ ì¶œë ¥ ?„ì¹˜
	unsigned int addr;      //ì¶œë ¥ ?„ì¹˜ ì§€?•ì„ ?„í•œ ?…ë ¥ë³€??ì£¼ì†Œ)
	char kBuf[100]; //ì¶œë ¥ ë¬¸ì???…ë ¥ ê³µê°„

	printf("¾ÈÀü°ø°£ÀÇ ÁÖ¼Ò´Â %d[%08x] ÀÔ´Ï´Ù.\n", (unsigned int) buf, (unsigned int) buf);
	printf("ÀÔ·ÂÀ» ½ÃÀÛÇÒ ÁÖ¼Ò¸¦ ÀÔ·ÂÇÏ¼¼¿ä :");
	scanf("%d", &addr); // ?ˆì „ê³µê°„ ì£¼ì†Œ ì°¸ê³ 
	pBuf = buf + addr;
	printf("¹®ÀÚ¿­À» ÀÔ·ÂÇÏ¼¼¿ä :");
	scanf("%s", kBuf); //?¤ë³´?œë¡œ ?…ë ¥ë°›ì„ ??ë¬¸ì?´ì„ ?…ë ¥ ë°›ì„ ì¶©ë¶„??ê³µê°„??ë§Œë“¤?´ì¤˜???œë‹¤.
	strcpy(pBuf, kBuf); //ë¬¸ì??ë³µì‚¬ ?¨ìˆ˜
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
	} s1 = { 1, 3.14, "»ïÃµ°©ÀÚ µ¿¹æ»è"};

	struct stTest s2 = s1;

	printf("sizeof(struct stTest) : %d\n", sizeof(struct stTest));

	printf("struct stTest s1 : %d %f %s\n", s1.i, s1.a, s1.name);
	printf("struct stTest s1 : %d %f %s\n", s2.i, s2.a, s2.name);
}
void test06()
{
	char* s1;		//"Good";       //const ¿µ¿ª¿¡ ÀÖ´Â Good, Áï º¯ÇüÀÌ ºÒ°¡´ÉÇÔ. (¼öÁ¤ºÒ°¡¿µ¿ª)
	char* s2;		//"afternoon";
	char buf[100];

	s1 = buf;		//È®º¸°¡ ¾È µÈ °÷¿¡¼­´Â ÀÔ·ÂÀ» ¹ŞÀ» ¼ö ¾ø´Ù.
	s2 = buf + 50;	//bufÀÇ °ø°£ ¾È¿¡ ÀÔ·Â¹ŞÀº ³»¿ëÀ» ÀúÀåÇÏ´Â °Í. buf¿¡ ¸ÕÀú ÀÔ·ÂµÈ °ÍÀÌ s·Î Àü´Ş µÈ´Ù.

	scanf("%s", s1);
	scanf("%s", s2);

	// strcat Test
	printf("s1 : %s(%d)\n", s1, strlen(s1));
	printf("s2 : %s(%d)\n", s2, strlen(s2));
	strcpy(buf, s1); 
	strcat(buf, s2); // s1 + s2 ÀÇ ¿µ¿ªÀ» ÇÕÃÄÁÜ, ¸¸¾à »ó¼ö¿µ¿ªÀÌ¸é ¼öÁ¤ºÒ°¡ÇÑ Á¦¾î¸¦ ¹Ş°Ô µÈ´Ù.
	printf("strcat(s1,s2) %s", buf);  //Ä³¸¯ÅÍ Æ÷ÀÎÅÍ¸¦ µÇµ¹·ÁÁÖ´Â ÇÔ¼ö strcat,
	//sprintf(buf, "strcat(s1,s2) %s %s", s1, s2); // buf¿¡ ÀÖ´Â ¾ÈÀüÇÑ ¸Ş¸ğ¸®°ø°£¿¡ Ãâ·Â¹°À» È­¸éÀÌ ¾Æ´Ñ buf·Î º¸³¿, strcat ÇÔ¼ö°¡ »ó¼ö¿µ¿ª¿¡ ÀÖ´Â °ÍÀ» Å¸°ÙÀ¸·Î ÇÏ¸é °ï¶õÇØÁü. Áï »ç¿ë ºÒ°¡´É
	//printf("%s", buf);
	}
void test07()
{
	char buf[100];
	printf("¹®ÀÚ¿­À» ÀÔ·ÂÇÏ¼¼¿ä : "); 	scanf("%s", buf);
	printf("ÀÔ·ÂÇÑ ¹®ÀÚ¿­ÀÇ ±æÀÌ´Â [ %d ] ÀÔ´Ï´Ù.\n\n", Length(buf));
}
void test08()
{
	char a[100];
	char b[100];
	int c = 0;

	printf("¹®ÀÚ¿­À» ÀÔ·ÂÇÏ¼¼¿ä : ");
	scanf("%s", a);
	printf("¹®ÀÚ¿­À» ÀÔ·ÂÇÏ¼¼¿ä : ");
	scanf("%s", b);

	c = compare(a, b);

	printf("%d.\n\n", c);
}


void Copy(char* p1, char* p2)
{
	while (*p2) *p1++ = *p2++; *p1 = 0; //p2ê°€ ?ŒìŠ¤ê°€ ?˜ê³  p1???€ê²Ÿì´ ?œë‹¤. p2??ê°’ì´ null???„ë‹ˆ?¼ë©´ p1??ê°’ì—?¤ê? p2???ˆëŠ” ê°’ì„ ë³µì‚¬?´ì„œ ?£ì–´??
	//p2ê°€ null???„ì¹˜???”ì„ ??p1?€ 0???œë‹¤.
}
void Dump(char *p, int len) //ë©”ëª¨ë¦?ê³µê°„ ì¶œë ¥ ë²”ìš© ?¨ìˆ˜
{
	for (int i = 0; i < len; i++) // ?ˆì „ê³µê°„ ë©”ëª¨ë¦??¤í”„
	{
		if(i % 16 == 0)  printf("\n%08x ", p); //ì£¼ì†Œê°’ì„ ì°ëŠ”??
		if (i % 8 == 0)  printf(" ");
		printf("%02x ", (unsigned char)*p++); // p?ì²´??ìºë¦­?°í¬?¸í„°?¸ë° *p??ê·?ì£¼ì†Œ???ì²´???ˆëŠ” ê°’ì„ ì°ëŠ”??
		
	}
}

int Length(char* str) //strÀº ¹®ÀÚ¿­ÀÇ ½ÃÀÛ ºÎºĞÀ» °¡¸®Å°°í ÀÖÀ½, nullÀÌ ³ª¿Ã¶§±îÁö ÇÑ ¹ÙÀÌÆ®¾¿ Â÷·ÊÂ÷·Ê Á¡°Ë ÇØ¾ß ÇÑ´Ù. Áõ°¡ÇÒ¶§¸¶´Ù +1¾¿ Áõ°¡½ÃÄÑÁØ´Ù.
{
	int len = 0; // ¹İÈ¯ÇÒ ¹®ÀÚ¿­ÀÇ ±æÀÌ
	
	while (1)
	{
		if (*(str + len) == 0) break; //strÀÇ À§Ä¡¿¡¼­ len¹øÂ°ÀÇ °ªÀÌ 0ÀÌ¶ó¸é ºüÁ®³ª¿È, *´Â ±× ÁÖ¼ÒÀÇ ¸Ş¸ğ¸®°ªÀ» ÂüÁ¶ÇÔ.
		len++;
	}
	return len;
}

int compare(char* s1, char* s2)
{
	int i = 0;

	//while(*s1 && *s2 && *s1 == *s2) 
		
	while (s1[i] != '\0' && s2[i] != '\0') // µÎ ¹®ÀÚ°¡ ¼­·Î nullÀÌ µÉ ¶§±îÁö ºñ±³ÇÏ¿© °è¼Ó µ¹¸².
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

	if (s1[i] == '\0' && s2[i] != '\0')  //s1Àº nullÀÌ°í s2°¡ nullÀÌ ¾Æ´Ò °æ¿ì¿£ s2°¡ Å©´Ù.
	{
		return -1;
	}
	else if (s1[i] != '\0' && s2[i] == '\0')  //s1ÀÌ nullÀÌ ¾Æ´Ï°í s2°¡ nullÀÌ¸é s1ÀÌ Å©´Ù.
	{
		return 1;
	}
	return 0; // µÎ ¹®ÀÚ´Â °°´Ù.
}