#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//10101010 10101010 10101010 10101010 == 0x aa aa aa aa
//01010101 01010101 01010101 01010101 == 0x 55 55 55 55
#define SWAP(x) (x)=(((x)<<1)&0xaaaaaa)+(((x)>>1)&0x555555)
int main()
{
	int num = 0;
	printf("������һ�����֣�");
	scanf("%d", &num);
	printf("δת��������λ��");
	for (int i = 31; i >= 0; i--)
	{
		printf("%d", (num >> i) % 2);
		if (i % 2 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");
	SWAP(num);
	printf("ת���������λ��");
	for (int i = 31; i >= 0; i--)
	{
		printf("%d", (num >> i) % 2);
		if (i % 2 == 0)
		{
			printf(" ");
		}
	}
	return 0;
}

//#include<stddef.h>
//struct S {
//	char c;
//	double d;
//	short s;
//	int i;
//}s1;
//
//#define _offsetof(tp,m) ((unsigned int)(&(((tp*)0)->m)))
//
//int main()
//{
//	printf("�ٷ�offsetof���ԣ�\n");
//	printf("%zd\n", offsetof(struct S, c));
//	printf("%zd\n", offsetof(struct S, d));
//	printf("%zd\n", offsetof(struct S, s));
//	printf("%zd\n", offsetof(struct S, i));
//	printf("ģ��offsetof���ԣ�\n");
//	printf("%zd\n", _offsetof(struct S, c));
//	printf("%zd\n", _offsetof(struct S, d));
//	printf("%zd\n", _offsetof(struct S, s));
//	printf("%zd\n", _offsetof(struct S, i));
//	return 0;
//}