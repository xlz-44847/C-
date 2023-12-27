//����
//��һֻ����������������ͼ��ʾ���Թ��С�����һ��12 * 12��Ԫ���������Թ�����ɫ���ֱ�ʾ�������ɫ������·��
//�������������·�����ϡ��¡��������ߣ�ÿһ����һ�����ӡ�
//�ָ���һ�����S��һ���յ�T�����������������Ҫ����������ߵ��յ㡣
//
//����
//�������һ���������ڲ����ĵ�һ�����ĸ��ɿո�ָ����������ֱ��ʾ��������S��x.y�����յ������T��x, y�����ӵڶ��п�ʼ��12���У�ÿ����12���ַ��������Թ������������'X'��ʾ�����'.'��ʾ·.
//
//���
//���һ�������������������߳��Թ�������Ҫ�Ĳ�����

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
		// ��
		if (canmove(x - 1, y))
		{
			struct pos tmp = { x - 1,y };
			myqueue.push(tmp);
			mem[x - 1][y] = 1;
		}
		// ��
		if (canmove(x + 1, y))
		{
			struct pos tmp = { x + 1,y };
			myqueue.push(tmp);
			mem[x + 1][y] = 1;
		}
		// ��
		if (canmove(x, y - 1))
		{
			struct pos tmp = { x ,y - 1 };
			myqueue.push(tmp);
			mem[x][y - 1] = 1;
		}
		// ��
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