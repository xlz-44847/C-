//描述
//有一只电子老鼠被困在如下图所示的迷宫中。这是一个12 * 12单元的正方形迷宫，黑色部分表示建筑物，白色部分是路。
//电子老鼠可以在路上向上、下、左、右行走，每一步走一个格子。
//现给定一个起点S和一个终点T，求出电子老鼠最少要几步从起点走到终点。
//
//输入
//本题包含一个测例。在测例的第一行有四个由空格分隔的整数，分别表示起点的坐标S（x.y）和终点的坐标T（x, y）。从第二行开始的12行中，每行有12个字符，描述迷宫的情况，其中'X'表示建筑物，'.'表示路.
//
//输出
//输出一个整数，即电子老鼠走出迷宫至少需要的步数。

#include<iostream>
#include<queue>

using namespace std;
struct pos {
	int x;
	int y;
};
queue<struct pos> myqueue;

char arr[14][14];
int mem[14][14];
int xa, ya, xb, yb;
int cou,flag;

bool canmove(int x, int y)
{
	if (arr[x][y] == 'X' || mem[x][y] == 1)
		return false;
	return true;
}

void bfs()
{
	int size = myqueue.size();
	if (size == 0)
		return;
	while (size--)
	{
		struct pos now = myqueue.front();
		myqueue.pop();
		int x = now.x;
		int y = now.y;
		if (x == xb && y == yb)
		{
			flag = 1;
			return;
		}
		// 上
		if (canmove(x - 1, y))
		{
			struct pos tmp = { x - 1,y };
			myqueue.push(tmp);
			mem[x - 1][y] = 1;
		}
		// 下
		if (canmove(x + 1, y))
		{
			struct pos tmp = { x + 1,y };
			myqueue.push(tmp);
			mem[x + 1][y] = 1;
		}
		// 左
		if (canmove(x, y - 1))
		{
			struct pos tmp = { x ,y - 1 };
			myqueue.push(tmp);
			mem[x][y - 1] = 1;
		}
		// 右
		if (canmove(x, y + 1))
		{
			struct pos tmp = { x ,y + 1 };
			myqueue.push(tmp);
			mem[x][y + 1] = 1;
		}
	}
	cou++;
	bfs();
}

int main()
{
	cin >> xa >> ya >> xb >> yb;
	for (int i = 0; i < 14; i++)
	{
		arr[i][0] = arr[i][13] = arr[0][i] = arr[13][i] = 'X';
	}
	for (int i = 1; i <= 12; i++)
	{
		for (int j = 1; j <= 12; j++)
		{
			arr[i][j] = getchar();
			if (arr[i][j] != 'X' && arr[i][j] != '.')
				j--;
		}
	}
	struct pos begin = { xa,ya };
	myqueue.push(begin);
	mem[xa][ya] = 1;
	bfs();
	cout << cou << endl;
	return 0;
}