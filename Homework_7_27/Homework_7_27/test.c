#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
	int a = 10;
	int b = 20;
	printf("交换前：a = %d，b = %d\n", a, b);
	a = a ^ b;
	b = b ^ a;
	a = a ^ b;
	printf("交换后：a = %d，b = %d\n", a, b);

	return 0;
}
