#define _CRT_SECURE_NO_WARNINGS 
//������A�е����ݺ�����B�е����ݽ��н�����������һ����
#include<stdio.h>
int main()
{
	int A[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int B[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("����ǰ��\n");
	printf("A:>");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
	printf("B:>");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", B[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		int tmp = A[i];
		A[i] = B[i];
		B[i] = tmp;
	}
	printf("\n������\n");
	printf("A:>");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
	printf("B:>");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", B[i]);
	}
	return 0;
}