#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//int howManyBits(int x) {
//	int n = 0;
//	x ^= (x << 1);
//	n += ((!!(x & ((~0) << (n + 16)))) << 4);
//	n += ((!!(x & ((~0) << (n + 8)))) << 3);
//	n += ((!!(x & ((~0) << (n + 4)))) << 2);
//	n += ((!!(x & ((~0) << (n + 2)))) << 1);
//	n += (!!(x & ((~0) << (n + 1))));
//	return n + 1;
//}

//void test(int* k)
//{
//	//int a = k;
//	int a = 8;
//	int* minheap = (int*)malloc(8 * sizeof(int));
//	if (minheap == NULL)
//	{
//		perror("malloc fail");
//		return;
//	}
//	//memset(minheap, 0, k * sizeof(int));
//	for (int i = 0; i < *k; i++)
//	{
//		minheap[i] = i;
//	}
//
//	for (int i = 0; i < *k; i++)
//	{
//		printf("%d ", *(minheap + i));
//		printf("%d ", minheap[i]);
//	}
//	printf("\n");
//	free(minheap);
//}
//
//int main()
//{
//	int x = 0;
//	int y = !(x >> 31);
//	//int k = howManyBits(0xd77f29d9);
//	int k = 8;
//	test(&k);
//}

void test(int x)
{
	int* arr = (int*)malloc(sizeof(int) * x);
	if (arr == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	for (int i = 0; i < x; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < x; i++)
	{
		printf("%d ", *(arr + i));
		printf("%d ", arr[i]);
	}
	//free(arr);
	//arr = NULL;
}

int main()
{
	test(3);
	return 0;
}