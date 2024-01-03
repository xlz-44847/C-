//����
//�ڹ��������У�����߷����г��������ƣ����׻�˵�ġ������ա�����ͼ��ʾ��������������K����һ���ܵ���ĸ��ӣ����к�ɫ�ĸ������ܵ����λ�ã���
//����һ200 * 200��С�Ĺ����������̣������н���һ����������ĵ�ǰλ�ã�S����Ŀ��λ�ã�T���������������Ҫ���������ܴӵ�ǰλ�õ���Ŀ��λ�á�
//
//����
//�����������������������ݵĵ�һ����һ������N��1 <= N <= 1000������ʾ�����ĸ�������������ÿһ�����ĸ��Կո�ָ����������ֱ��ʾ��ǰλ�ü�Ŀ��λ�õĺᡢ������C��x, y����G��x, y����������1��ʼ��
//
//���
//����ÿ���������ڵ�����һ�������һ������������ӵ�ǰλ������Ŀ��λ�����ٵ�������

#include<iostream>
#include<queue>

using namespace std;

int vary[8][2] = { {-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2} };

int mem[201][201];

struct pos {
	int ox;
	int oy;
	int nx;
	int ny;
};

queue<struct pos> myqueue;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int bx, by, ex, ey;
		cin >> bx >> by >> ex >> ey;
		int flag = 0, cou = 0;
		memset(mem, 0, sizeof(mem));
		struct pos begin = { -1,-1,bx,by };
		myqueue.push(begin);
		while (1)
		{
			cou++;
			int size = myqueue.size();
			while (size--)
			{
				struct pos now = myqueue.front();
				myqueue.pop();
				int ox = now.ox, oy = now.oy, nx = now.nx, ny = now.ny;
				for (int i = 0; i < 8; i++)
				{
					struct pos tmp = { nx,ny,nx + vary[i][0],ny + vary[i][1] };
					if ((tmp.nx != ox || tmp.ny != oy) && tmp.nx > 0 && tmp.ny > 0 && tmp.nx < 200 && tmp.ny < 200 && mem[tmp.nx][tmp.ny] != 1)
					{
						if (tmp.nx == ex && tmp.ny == ey)
						{
							flag = 1;
							cout << cou << endl;
							break;
						}
						myqueue.push(tmp);
						mem[tmp.nx][tmp.ny] = 1;
					}
				}
				if (flag == 1)
				{
					break;
				}
			}
			if (flag)
			{
				while (!myqueue.empty())
				{
					myqueue.pop();
				}
				break;
			}
		}
	}
	return 0;
}