//����
//��ʬҪ���ѼѼ������ˣ��ѼѰѻ�԰������һ�£����õ��˻�԰�ĵ�ͼ���Զ�ά�������ʽ��ʾ���Լ����ͼѼѼҵ�λ�á�
//��԰��ĳЩλ���еش̣���ʬ����ʱ��ÿ����Ҫ����һ����λ������ֵ����ʬ��һ������������ֵ������������Ľ�ʬ�ܷ�������ǰ������ļ���ܵĻ������ٻ��Ѷ���ʱ�䡣
//
//����
//����ĵ�һ�а�������������m��n��t������m��n�еĵ�ͼ�ͽ�ʬ������ֵt��
//m, n����С��200����������t��С��10������������2�п�ʼ��m����m��n�еĻ�԰��ͼ������!������㣬 + ��ʾ�ѼѼҡ� * ����ͨ·��w����ش̡�
//
//���
//�����ʬ����ѼѼ�������Ҫ���ѵ�ʱ�䡣����޷��������� - 1��
#include<iostream>
#include<queue>

using namespace std;
char arr[201][201];
int vary[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };
int mem[201][201][11];
typedef struct info {
	int x;
	int y;
	int hp;
};

queue<info> q;

int main()
{
	int m, n, t;
	cin >> m >> n >> t;
	for (int i = 0; i <= m + 1; i++)
	{
		arr[i][0] = arr[i][n + 1] = '1';
	}
	for (int i = 0; i <= n + 1; i++)
	{
		arr[0][i] = arr[m + 1][i] = '1';
	}
	int bx = 0, by = 0, ex = 0, ey = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			arr[i][j] = getchar();
			if (arr[i][j] != '!' && arr[i][j] != '+' && arr[i][j] != '*' && arr[i][j] != 'w')
				j--;
			if (arr[i][j] == '!')
			{
				bx = i;
				by = j;
				arr[i][j] = '*';
			}
			if (arr[i][j] == '+')
			{
				ex = i;
				ey = j;
				arr[i][j] = '*';
			}
		}
	}
	info begin = { bx,by,t };
	q.push(begin);
	int cou = 0;
	while (1)
	{
		if (q.empty())
		{
			cout << -1 << endl;
			return 0;
		}
		int size = q.size();
		while (size--)
		{
			info now = q.front();
			q.pop();
			int x = now.x, y = now.y, hp = now.hp;
			if (x == ex && y == ey)
			{
				cout << cou << endl;
				return 0;
			}
			if (hp > 0)
			{
				for (int i = 0; i < 4; i++)
				{
					if (arr[x + vary[i][0]][y + vary[i][1]] == '*' && mem[x + vary[i][0]][y + vary[i][1]][hp] == 0)
					{
						info tmp = { x + vary[i][0],y + vary[i][1],hp };
						mem[x + vary[i][0]][y + vary[i][1]][hp] = 1;
						q.push(tmp);
					}
					if (arr[x + vary[i][0]][y + vary[i][1]] == 'w' && mem[x + vary[i][0]][y + vary[i][1]][hp - 1] == 0)
					{
						info tmp = { x + vary[i][0],y + vary[i][1],hp - 1 };
						mem[x + vary[i][0]][y + vary[i][1]][hp - 1] = 1;
						q.push(tmp);
					}
				}
			}
		}
		cou++;
	}
	
}