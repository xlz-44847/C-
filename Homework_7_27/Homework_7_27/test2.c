#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
	int a = 487;
	printf("ԭ���ֶ����ƣ�");
	for (int i = 31; i >= 0; i--)
	{
		printf("%d", (a >> i) % 2);
	}
	printf("\n����λ�����ƣ�");
	for (int i = 30; i >= 0; i -= 2)
	{
		printf(" %d", (a >> i) % 2);
	}
	printf("\nż��λ�����ƣ�");
	for (int i = 31; i >= 0; i -= 2)
	{
		printf("%d ", (a >> i) % 2);
	}
	return 0;
}