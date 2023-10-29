#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
int Search(int* arr, int sz, int k)
{
	int key = arr[0];
	int right = sz - 1;
	int left = 0;
	while (left < right)
	{
		while (left < right && arr[right] > key)
			right--;
		arr[left] = arr[right];
		while (left < right && arr[left] <=key )
			left++;
		arr[right] = arr[left];
	}
	if (left + 1 == k)
	{
		return key;
	}
	else if (left + 1 > k)
	{
		return Search(arr, left, k);
	}
	else
	{
		return Search(arr + left + 1, sz - left - 1, k - left - 1);
	}
}

int n;
int k;
int main()
{
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
	}
	scanf("%d", &k);
	printf("%d", Search(arr, n, k));
	return 0;
}

//int l = 1;
//
//
//void dfs(int** arr,size_t num)
//{
//	if (num == 0)
//	{
//		return;
//	}
//	for (int k = 0; k < (num >> 1); k++)
//	{
//		for (int i = 0; i < l; i++)
//		{
//			for (int j = 0; j < l; j++)
//			{
//				arr[i + l][j + k * l*2] = arr[i][j + k * l*2 + l];
//				arr[i + l][j + k * l*2 + l] = arr[i][j + k * l*2];
//			}
//		}
//	}
//	l <<= 1;
//	dfs(arr, num >> 1);
//}
//
//int main()
//{
//	int n = 0;
//	int** arr = NULL;
//	scanf("%d", &n);
//	int** pa = (int**)calloc((size_t)1 << n, sizeof(int*));
//	if (pa != NULL)
//		arr = pa;
//	else
//		return -1;
//	for (int i = 0; i < (1 << n); i++)
//	{
//		int* p = (int*)calloc((size_t)1 << n, sizeof(int));
//		if (p == NULL)
//			return -1;
//		arr[i] = p;
//	}
//	for (int i = 0; i < (1 << n); i++)
//	{
//		arr[0][i] = i + 1;
//	}
//	dfs(arr, (size_t)(1 << n));
//	for (int i = 0; i < (1 << n); i++)
//	{
//		for (int j = 0; j < (1 << n); j++)
//		{
//			printf("%d", arr[i][j]);
//			if (j != (1 << n) - 1)
//				printf(" ");
//		}
//		printf("\n");
//	}
//	for (int i = 0; i < (1 << n); i++)
//	{
//		free(arr[i]);
//		arr[i] = NULL;
//	}
//	free(arr);
//	arr = NULL;
//	return 0;
//}