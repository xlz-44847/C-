#define _CRT_SECURE_NO_WARNINGS 1



//堡垒问题
#include<stdio.h>
#include<string.h>
int n,sum,max;
char arr[4][4], tmp[4][4];

int check(int x,int y)
{
	if (arr[x][y] == 'X')
		return 0;
	for (int i = y-1; i >= 0; i--)
	{
		if (arr[x][i] == 'X')
		{
			break;
		}
		if (tmp[x][i] == '1')
		{
			return 0;
		}
	}
	for (int i = x - 1; i >= 0; i--)
	{
		if (arr[i][y] == 'X')
		{
			break;
		}
		if (tmp[i][y] == '1')
		{
			return 0;
		}
	}
	return 1;
}

void dfs(int count)
{
	if (count > n * n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				sum += tmp[i][j] - '0';
			}
		}
		if (sum > max)
		{
			max = sum;
		}
		sum = 0;
		return;
	}
	int x = count / n;
	int y = count % n;
	if (check(x,y))
	{
		tmp[x][y] = '1';
	}
	dfs(count + 1);
	tmp[x][y] = '0';
	dfs(count + 1);
}

int main()
{
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
		{
			break;
		}
		getchar();
		memset(arr, 0, sizeof(arr));
		memset(tmp, '0', sizeof(arr));
		sum = 0;
		max = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%c", &arr[i][j]);
			}
			getchar();
		}
		dfs(0);
		printf("%d\n", max);
	}
	return 0;
}

//装载问题
//#include<stdio.h>
//int c1, c2, n, w[10], wt, wm;
//
//void dfs(int count)
//{
//	if (count == n && wt<=c1)
//	{
//		if (wt > wm)
//		{
//			wm = wt;
//		}
//		return;
//	}
//	if (wt > c1)
//	{
//		return;
//	}
//	wt += w[count];
//	dfs(count + 1);
//	wt -= w[count];
//	dfs(count + 1);
//}
//
//int main()
//{
//	while (1)
//	{
//		int sum = 0;
//		scanf("%d %d %d", &c1, &c2, &n);
//		if (c1 == 0 && c2 == 0 && n == 0)
//		{
//			break;
//		}
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d", w + i);
//			sum += w[i];
//		}
//		wm = 0;
//		dfs(0);
//		if (sum - wm <= c2)
//		{
//			printf("Yes\n");
//		}
//		else
//		{
//			printf("No\n");
//		}
//	}
//}

//0-1背包
//#include<stdio.h>
//
//int c, n, w[10], p[10], value, wt,pt;
//
//void dfs(int count)
//{
//	if (count == n && wt<=c)
//	{
//		if (pt > value)
//		{
//			value = pt;
//		}
//		return;
//	}
//	if (wt > c)
//	{
//		return;
//	}
//	wt += w[count];
//	pt += p[count];
//	dfs(count + 1);
//	wt -= w[count];
//	pt -= p[count];
//	dfs(count + 1);
//}
//
//int main()
//{
//	while (1)
//	{
//		scanf("%d %d", &n, &c);
//		if (n == 0 && c == 0)
//		{
//			break;
//		}
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d", w + i);
//		}
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d", p + i);
//		}
//		value = 0;
//		dfs(0);
//		printf("%d\n", value);
//	}
//	return 0;
//}