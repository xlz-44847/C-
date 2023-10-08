#define _CRT_SECURE_NO_WARNINGS 
//创建一个整形数组，完成对数组的操作
//
//实现函数init() 初始化数组为全0
//实现print()  打印数组的每个元素
//实现reverse()  函数完成数组元素的逆置。
//要求：自己设计以上函数的参数，返回值。
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