#define _CRT_SECURE_NO_WARNINGS 
//0-1±³°ü
#include<stdio.h>

int c, n, w[10], p[10], value, wt,pt;

void dfs(int count)
{
	if (count == n && wt<=c)
	{
		if (pt > value)
		{
			value = pt;
		}
		return;
	}
	if (wt > c)
	{
		return;
	}
	wt += w[count];
	pt += p[count];
	dfs(count + 1);
	wt -= w[count];
	pt -= p[count];
	dfs(count + 1);
}

int main()
{
	while (1)
	{
		scanf("%d %d", &n, &c);
		if (n == 0 && c == 0)
		{
			break;
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", w + i);
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", p + i);
		}
		value = 0;
		dfs(0);
		printf("%d\n", value);
	}
	return 0;
}