//����
//���ֳ����������к졢�ơ������ס��̣���˳ʱ����5����ɫ����һ������ͼ��ʾ��20 * 20���Թ���ÿ��һ�����ӣ������ϵ���ɫ�仯һ�Ρ�
//���ֳ�ֻ����ǰ�ƻ���ԭ��ת��ÿ��һ���ԭ��ת��90�Ⱦ�����һ����λʱ�䡣
//�ָ���һ����㣨S����һ���յ㣨T��������ֳ��������ϵ�ָ����ɫ�����յ���������ʱ�䡣
//
//����
//�������һ�������������зֱ���һ����д��ĸ��ʾ��������ӵ���ɫ�����Ӧ��ϵΪ��E - ����S - �ϡ�W - ����N - ����R - �졢Y - �ơ�B - ����W - �ס�G - �̡�
//�ڲ������ݵĵ�һ�����Կո�ָ�������������������д��ĸ���ֱ��ʾ��������S��x, y�������ӵ���ɫ�Ϳ�ʼ�ķ���
//�ڶ������Կո�ָ�������������һ����д��ĸ����ʾ�յ������T��x, y���͵����յ�ʱ���ӵ���ɫ��
//�ӵ����п�ʼ��20��ÿ���ڰ���20���ַ�����ʾ�Թ���״̬������'X'��ʾ�����'.'��ʾ·.
//
//���
//�ڵ�����һ�������һ����������������ĿҪ������ʱ�䡣

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
		//ǰ��
		if (puzzle[x + vary[d][0]][y + vary[d][1]] == '.' && mem[x + vary[d][0]][y + vary[d][1]][(c + 1) % 5][d] == 0)
		{
			struct info tmp = { x + vary[d][0], y + vary[d][1], (c + 1) % 5,d };
			myqueue.push(tmp);
			mem[x + vary[d][0]][y + vary[d][1]][(c + 1) % 5][d] = 1;
		}
		//��ת
		if (mem[x][y][c][(d + 3) % 4] == 0)
		{
			struct info tmp = { x , y , c,(d + 3) % 4 };
			myqueue.push(tmp);
			mem[x][y][c][(d + 3) % 4] = 1;
		}
		//��ת
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