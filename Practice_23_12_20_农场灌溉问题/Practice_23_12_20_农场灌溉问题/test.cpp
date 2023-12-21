//描述
//一农场由图所示的十一种小方块组成，蓝色线条为灌溉渠。若相邻两块的灌溉渠相连则只需一口水井灌溉。
//
//输入
//给出若干由字母表示的最大不超过50×50具体由(m，n)表示，的农场图
//
//输出
//编程求出最小需要打的井数。每个测例的输出占一行。当M = N = -1时结束程序。

#include<iostream>
#include<string.h>
using namespace std;

//struct Shape {
//	int left;
//	int up;
//	int right;
//	int down;
//};

int sharr[11][4] = {{1,1,0,0}, {0,1,1,0}, {1,0,0,1}, {0,0,1,1}, {0,1,0,1}, {1,0,1,0}, {1,1,1,0}, {1,1,0,1}, {1,0,1,1}, {0,1,1,1}, {1,1,1,1}};

char arr[52][52];
int block[52][52];
int m, n, cou;

//char s[9000];

void dfs(int x, int y)
{
	block[x][y] = cou;
	char site = arr[x][y];
	int* fea = sharr[site - 'A'];
	for (int i = 0; i < 4; i++)
	{
		if (fea[i] == 1)
		{
			if (i == 0 && block[x][y - 1] == 0 && arr[x][y - 1] != 0 && arr[x][y - 1] != 'A' && arr[x][y - 1] != 'C' && arr[x][y - 1] != 'E' && arr[x][y - 1] != 'H')
				dfs(x, y - 1);
			if (i == 1 && block[x - 1][y] == 0 && arr[x - 1][y] != 0 && arr[x - 1][y] != 'A' && arr[x - 1][y] != 'B' && arr[x - 1][y] != 'F' && arr[x - 1][y] != 'G')
				dfs(x - 1, y);
			if (i == 2 && block[x][y + 1] == 0 && arr[x][y + 1] != 0 && arr[x][y + 1] != 'B' && arr[x][y + 1] != 'D' && arr[x][y + 1] != 'E' && arr[x][y + 1] != 'J')
				dfs(x, y + 1);
			if (i == 3 && block[x + 1][y] == 0 && arr[x + 1][y] != 0 && arr[x + 1][y] != 'C' && arr[x + 1][y] != 'D' && arr[x + 1][y] != 'F' && arr[x + 1][y] != 'I')
				dfs(x + 1, y);
		}
	}
}

int main()
{
	while (1)
	{
		cin >> m >> n;
		if (m == -1)
		{
			break;
		}
		memset(block, 0, sizeof(block));
		memset(arr, 0, sizeof(arr));
		cou = 0;
		for (int i = 1; i < m + 1; i++)
		{
			for (int j = 1; j < n + 1; j++)
			{
				char c = getchar();
				while (c < 'A' || c>'K')
					c = getchar();
				arr[i][j] = c;
			}
		}
		//cin >> s;
		//int k = 0;
		//for (int i = 1; i < m + 1; i++)
		//{
		//	for (int j = 1; j < n + 1; j++)
		//	{
		//		while (s[k] < 'A' || s[k]>'K')
		//			k++;
		//		arr[i][j] = s[k];
		//	}
		//}
		//for (int i = 0; i < m + 2; i++)
		//{
		//	arr[i][0] = arr[i][n + 1] = '0';
		//}
		//for (int i = 0; i < n + 2; i++)
		//{
		//	arr[0][i] = arr[m + 1][i] = '0';
		//}
		for (int x = 1; x < m + 1; x++)
		{
			for (int y = 1; y < n + 1; y++)
			{
				if (block[x][y] == 0)
				{
					cou++;
					dfs(x, y);
				}
			}
		}
		cout << cou << endl;
	}
	return 0;
}