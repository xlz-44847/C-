#define _CRT_SECURE_NO_WARNINGS 

//��1��20���������У�ʹ�����к������A���㣺
//a.��������������֮��������
//b.��������������a������Bʹ�ã�A��B��ǰk��0 <= k <= 19������ͬ��B�ĵ�k + 1���A�ĵ�k + 1��С��(�����ֵ������еĵ�һ��)

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