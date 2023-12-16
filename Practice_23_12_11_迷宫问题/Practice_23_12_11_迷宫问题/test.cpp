//����
//��һ��20��20���Թ������������յ����꣬�ʴ�����Ƿ��ܵ����յ㡣
//
//����
//�������������ĵ�һ����һ������n����ʾ�����ĸ�����
//��������n��������ÿ������ռ21�У�
//��һ���ĸ�����x1��y1��x2��y2����ֹ���λ�ã�������㿪ʼ����
//��x1��y1������㣬��x2��y2�����յ㡣
//����20��ÿ��20���ַ�����.����ʾ�ո񣻡�X����ʾǽ��
//
//���
//ÿ�����������ռһ�У����Yes��No��

#define _CRT_SECURE_NO_WARNINGS//���ð�ȫ��������
#pragma warning(disable:6031)//���� 6031 �İ�ȫ����
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
		//��
		if (canmove(x - 1, y))
		{
			pos p = { x - 1,y };
			myqueue.push(p);
			mem[x - 1][y] = 1;
		}
		//��
		if (canmove(x + 1, y))
		{
			pos p = { x + 1,y };
			myqueue.push(p);
			mem[x + 1][y] = 1;
		}
		//��
		if (canmove(x, y - 1))
		{
			pos p = { x ,y - 1 };
			myqueue.push(p);
			mem[x][y - 1] = 1;
		}
		//��
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