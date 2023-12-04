#define _CRT_SECURE_NO_WARNINGS 
//8ª ∫ÛŒ Ã‚
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int num = 1, flag;
int arr[8];

void print()
{
	printf("No %d:\n", num);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i] == j)
				printf("A");
			else
				printf(".");
		}
		printf("\n");
	}
}

bool check(int x, int y)
{
	for (int i = x-1; i >= 0; i--)
	{
		if (arr[i] == y || abs(arr[i] - y) == abs(x - i))
		{
			return false;
		}
	}
	return true;
}

void dfs(int count)
{
	if (count > 7)
	{
		print();
		num++;
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		if (check(count, i))
		{
			arr[count] = i;
			dfs(count + 1);
		}
	}
}

int main()
{
	dfs(0);
	return 0;
}

//int check(int x, int y)
//{
//	for (int i = y - 1; i >= 0; i--)
//	{
//		if (arr[x][i] == 'A')
//		{
//			return 0;
//		}
//	}
//	for (int i = x - 1; i >= 0; i--)
//	{
//		if (arr[i][y] == 'A')
//		{
//			return 0;
//		}
//	}
//	for (int i = 1; x - i >= 0 && y - i >= 0; i++)
//	{
//		if (arr[x - i][y - i] == 'A')
//		{
//			return 0;
//		}
//	}
//	for (int i = 1; x - i >= 0 && y + i < 8; i++)
//	{
//		if (arr[x - i][y + i] == 'A')
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//
//void dfs(int count)
//{
//	if (count == 64 && flag == 8)
//	{
//		printf("No %d:\n", num);
//		for (int i = 0; i < 8; i++)
//		{
//			for (int j = 0; j < 8; j++)
//			{
//				printf("%c", arr[i][j]);
//			}
//			printf("\n");
//		}
//		return;
//	}
//	if (count == 64)
//	{
//		return;
//	}
//	int x = count / 8;
//	int y = count % 8;
//	if (check(x, y))
//	{
//		arr[x][y] = 'A';
//		flag++;
//	}
//	dfs(count + 1);
//	arr[x][y] = '.';
//	flag--;
//	dfs(count + 1);
//}
//int main()
//{
//	memset(arr, '.', sizeof(arr));
//	dfs(0);
//	return 0;
//}