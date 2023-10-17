#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#define ROW 5
#define COL 5

void ArrFind(int(*arr)[5], int row, int col, int num)
{
	int i = 0;
	int j = col - 1;
	while (i < col && j >= 0)
	{
		if (arr[i][j] < num)
		{
			i++;
		}
		else if (arr[i][j] > num)
		{
			j--;
		}
		else
		{
			printf("找到了，下标为：[%d][%d]\n", i, j);
			return;
		}
	}
	printf("找不到\n");
}

int main()
{
	int arr[ROW][COL] = {
		{1, 2, 3, 4, 5},
		{6, 8, 10, 12, 14},
		{15, 18, 21, 24, 27},
		{28, 32, 36, 40, 44},
		{45, 50, 55, 60, 65}
	};
	int num = 0;
	while (scanf("%d", &num) != EOF)
	{
		ArrFind(arr, ROW, COL, num);
	}
	return 0;
}