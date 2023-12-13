#define _CRT_SECURE_NO_WARNINGS 

//把1到20这重新排列，使得排列后的序列A满足：
//a.任意相邻两个数之和是素数
//b.不存在满足条件a的序列B使得：A和B的前k（0 <= k <= 19）项相同且B的第k + 1项比A的第k + 1项小。(即按字典序排列的第一项)

#include<stdio.h>
#include<stdbool.h>
#include<math.h>

int prime[41] = { -1 };
//int arr[10];
int arr[20];
//int mem[11];
int mem[21];
int flag;

bool isprime(int x)
{
	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}

void dfs(int count)
{
	if (count == 20)
	//if(count == 10)
	{
		flag = 1;
		return;
	}
	for (int i = 1; i <= 20; i++)
	//for (int i = 1; i <= 10; i++)
	{
		if (mem[i] == 1)
		{
			continue;
		}
		arr[count] = i;
		mem[i] = 1;
		if (count == 0 ||
			(count != 19 && prime[arr[count] + arr[count - 1]]) ||
			(count == 19 && prime[arr[count] + arr[count - 1]] && prime[arr[count] + arr[0]]))
		{
			dfs(count + 1);
			if (flag == 1)
			{
				return;
			}
		}
		mem[i] = 0;
	}
}

int main()
{
	for (int i = 1; i < 41; i++)
	{
		prime[i] = isprime(i);
	}
	dfs(0);
	for (int i = 0; i < 20; i++)
	//for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}