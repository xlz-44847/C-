#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

int dfs(int* arr, int left, int right, int k)
{
	int l = left, r = right;
	int s = arr[left];
	if (left < right)
	{
		while (l < r)
		{
			while (arr[r] > s && l < r)
			{
				r--;
			}
			arr[l] = arr[r];
			while (arr[l] <= s && l < r)
			{
				l++;
			}
			arr[r] = arr[l];
		}
		arr[l] = s;
		if (l + 1 == k)
		{
			return arr[l];
		}
		else if (l + 1 < k)
		{
			return dfs(arr, l + 1, right, k);
		}
		else
		{
			return dfs(arr, left, l - 1, k);
		}
	}
	else
	{
		return arr[left];
	}
}

int main()
{
	int n, arr[10000], k;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &k);
	int num = dfs(arr, 0, n - 1, k);
	printf("%d", num);
	return 0;
}