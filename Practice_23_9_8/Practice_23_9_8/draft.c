#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int Comp(int num1, int num2)
{
	return (num1 > num2 ? num1 : num2);
}
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", Comp(a, b));
	return 0;
}