#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
	int a = 487;
	printf("原数字二进制：");
	for (int i = 31; i >= 0; i--)
	{
		printf("%d", (a >> i) % 2);
	}
	printf("\n奇数位二进制：");
	for (int i = 30; i >= 0; i -= 2)
	{
		printf(" %d", (a >> i) % 2);
	}
	printf("\n偶数位二进制：");
	for (int i = 31; i >= 0; i -= 2)
	{
		printf("%d ", (a >> i) % 2);
	}
	return 0;
}