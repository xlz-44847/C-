//描述
//给一个20×20的迷宫、起点坐标和终点坐标，问从起点是否能到达终点。
//
//输入
//多个测例。输入的第一行是一个整数n，表示测例的个数。
//接下来是n个测例，每个测例占21行，
//第一行四个整数x1，y1，x2，y2是起止点的位置（坐标从零开始），
//（x1，y1）是起点，（x2，y2）是终点。
//下面20行每行20个字符，’.’表示空格；’X’表示墙。
//
//输出
//每个测例的输出占一行，输出Yes或No。

#define _CRT_SECURE_NO_WARNINGS//禁用安全函数警告
#pragma warning(disable:6031)//禁用 6031 的安全警告
#include<iostream>
#include<queue>

using namespace std;

typedef struct pos
{
	int x;
	int y;
}pos;

queue<pos> myqueue;
char arr[22][22];
int mem[22][22];
int flag = 0;

bool canmove(int x, int y)
{
	if (arr[x][y] == 'X')
		return false;
	else
		if (mem[x][y] == 1)
			return false;
		else
			return true;
}

void bfs(pos end)
{
	if (myqueue.empty() || flag == 1)
	{
		return;
	}
	int size = myqueue.size();
	while (size--)
	{
		pos now = myqueue.front();
		myqueue.pop();
		int x = now.x;
		int y = now.y;
		if (end.x == x && end.y == y)
		{
			flag = 1;
			return;
		}
		//上
		if (canmove(x - 1, y))
		{
			pos p = { x - 1,y };
			myqueue.push(p);
			mem[x - 1][y] = 1;
		}
		//下
		if (canmove(x + 1, y))
		{
			pos p = { x + 1,y };
			myqueue.push(p);
			mem[x + 1][y] = 1;
		}
		//左
		if (canmove(x, y - 1))
		{
			pos p = { x ,y - 1 };
			myqueue.push(p);
			mem[x][y - 1] = 1;
		}
		//右
		if (canmove(x, y + 1))
		{
			pos p = { x ,y + 1 };
			myqueue.push(p);
			mem[x][y + 1] = 1;
		}
	}
	bfs(end);
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		flag = 0;
		memset(mem, 0, sizeof(mem));
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		getchar();
		for (int i = 0; i < 22; i++)
		{
			arr[0][i] = arr[21][i] = arr[i][0] = arr[i][21] = 'X';
		}
		for (int i = 1; i < 21; i++)
		{
			for (int j = 1; j < 21; j++)
			{
				cin >> arr[i][j];
			}
			getchar();
		}
		pos begin = { x1 + 1,y1 + 1 };
		pos end = { x2 + 1,y2 + 1 };
		myqueue.push(begin);
		mem[x1 + 1][y1 + 1] = 1;
		bfs(end);
		if (flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		/*for (int i = 0; i < 22; i++)
		{
			for (int j = 0; j < 22; j++)
			{
				cout << arr[i][j];
			}
			cout << endl;
		}*/
	}

	return 0;
}