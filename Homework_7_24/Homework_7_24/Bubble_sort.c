#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

void Bubble_Sort(int* arr,int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
extern void ArrPrint(int*,int);
int main()
{
	int arr[10] = { 2,4,6,1,5,9,7,3,8,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	ArrPrint(arr,sz);
	Bubble_Sort(arr,sz);
	ArrPrint(arr, sz);
	return 0;
}