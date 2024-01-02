//描述
//独轮车的轮子上有红、黄、蓝、白、绿（依顺时针序）5种颜色，在一个如下图所示的20 * 20的迷宫内每走一个格子，轮子上的颜色变化一次。
//独轮车只能向前推或在原地转向。每走一格或原地转向90度均消耗一个单位时间。
//现给定一个起点（S）和一个终点（T），求独轮车以轮子上的指定颜色到达终点所需的最短时间。
//
//输入
//本题包含一个测例。测例中分别用一个大写字母表示方向和轮子的颜色，其对应关系为：E - 东、S - 南、W - 西、N - 北；R - 红、Y - 黄、B - 蓝、W - 白、G - 绿。
//在测试数据的第一行有以空格分隔的两个整数和两个大写字母，分别表示起点的坐标S（x, y）、轮子的颜色和开始的方向，
//第二行有以空格分隔的两个整数和一个大写字母，表示终点的坐标T（x, y）和到达终点时轮子的颜色，
//从第三行开始的20行每行内包含20个字符，表示迷宫的状态。其中'X'表示建筑物，'.'表示路.
//
//输出
//在单独的一行内输出一个整数，即满足题目要求的最短时间。

#include<iostream>
#include<queue>

using namespace std;

struct info {
	int x;
	int y;
	int c;
	int d;
};

queue<struct info> myqueue;

int sx, sy, tx, ty, sc, tc, sd;
char scolor, tcolor, sdire;
char puzzle[20][20];
int mem[20][20][5][4];
char color[5] = { 'R','Y','B','W','G' };
char direction[4] = { 'E','S','W','N' };

int vary[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int cou;

void bfs()
{
	int size = myqueue.size();
	while (size--)
	{
		struct info nsta = myqueue.front();
		myqueue.pop();
		int x = nsta.x, y = nsta.y, c = nsta.c, d = nsta.d;
		if (x == tx && y == ty && tc == c)
		{
			cout << cou << endl;
			return;
		}
		//前进
		if (puzzle[x + vary[d][0]][y + vary[d][1]] == '.' && mem[x + vary[d][0]][y + vary[d][1]][(c + 1) % 5][d] == 0)
		{
			struct info tmp = { x + vary[d][0], y + vary[d][1], (c + 1) % 5,d };
			myqueue.push(tmp);
			mem[x + vary[d][0]][y + vary[d][1]][(c + 1) % 5][d] = 1;
		}
		//左转
		if (mem[x][y][c][(d + 3) % 4] == 0)
		{
			struct info tmp = { x , y , c,(d + 3) % 4 };
			myqueue.push(tmp);
			mem[x][y][c][(d + 3) % 4] = 1;
		}
		//右转
		if (mem[x][y][c][(d + 1) % 4] == 0)
		{
			struct info tmp = { x , y , c,(d + 1) % 4 };
			myqueue.push(tmp);
			mem[x][y][c][(d + 1) % 4] = 1;
		}
	}
	cou++;
	bfs();
}

int main()
{
	cin >> sx >> sy;
	getchar();
	sx--;
	sy--;
	cin >> scolor;
	getchar();
	cin >> sdire;
	cin >> tx >> ty;
	getchar();
	tx--;
	ty--;
	cin >> tcolor;
	for (int i = 0; i < 5; i++)
	{
		if (scolor == color[i])
			sc = i;
		if (tcolor == color[i])
			tc = i;
	}
	for (int i = 0; i < 4; i++)
	{
		if (sdire == direction[i])
			sd = i;
	}
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			puzzle[i][j] = getchar();
			if (puzzle[i][j] != 'X' && puzzle[i][j] != '.')
				j--;
		}
	}
	struct info begin = { sx,sy,sc,sd };
	myqueue.push(begin);
	mem[sx][sy][sc][sd] = 1;
	bfs();
	return 0;
}