#define _CRT_SECURE_NO_WARNINGS 
//����һ���������飬��ɶ�����Ĳ���
//
//ʵ�ֺ���init() ��ʼ������Ϊȫ0
//ʵ��print()  ��ӡ�����ÿ��Ԫ��
//ʵ��reverse()  �����������Ԫ�ص����á�
//Ҫ���Լ�������Ϻ����Ĳ���������ֵ��
#include<stdio.h>
void ArrInit(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}
void ArrPrint(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void ArrReverse(int* arr, int size)
{
	int left = 0;
	int right = size-1;
	while (left < right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}
int main()
{
	int arr[10];
	int sz = sizeof(arr) / sizeof(arr[0]);
	ArrInit(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		arr[i] = i+1;
	}
	ArrPrint(arr, sz);
	ArrReverse(arr, sz);
	ArrPrint(arr, sz);
	
	return 0;
}