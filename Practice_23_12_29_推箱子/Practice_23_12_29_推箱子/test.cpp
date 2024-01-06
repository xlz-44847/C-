//����
//��������˶���������ӵ���Ϸ������һ���˽������ƶ���Ŀ��λ�ü����ʤ�����������дһ�������жϽ������Ƶ�Ŀ��λ��������Ҫ���ٲ���
//
//����
//�����ӵ�ƽ������Ϊ�̶���С��10 * 10����ʹ��10��10�����������ӵĳ�ʼ���档���У�0����ո�1����ǽ��2�������ӣ�3����Ŀ��λ�ã�4�����ˡ�
//ע����Ϸ��ֻ��һ�����ӣ�һ��Ŀ��λ�ã�һ���ˡ�
//
//���
//����������Ƶ�Ŀ��λ�õ���С�����������Ӳ����ܱ��Ƶ�Ŀ��λ�ã���� - 1��

#include<iostream>
#include<queue>

using namespace std;
typedef struct info {
	int xp;
	int yp;
	int xb;
	int yb;
}info;
queue<info> q;
char arr[12][12];
int mem[12][12][12][12];
int vary[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };
int main()
{
	int xp_b, yp_b, xb_b, yb_b, ex, ey;
	for (int i = 0; i < 12; i++)
	{
		arr[0][i] = arr[i][0] = arr[11][i] = arr[i][11] = '1';
	}
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == '2')
			{
				xb_b = i;
				yb_b = j;
				arr[i][j] = '0';
			}
			if (arr[i][j] == '3')
			{
				ex = i;
				ey = j;
				arr[i][j] = '0';
			}
			if (arr[i][j] == '4')
			{
				xp_b = i;
				yp_b = j;
				arr[i][j] = '0';
			}
		}
		getchar();
	}
	info begin = { xp_b,yp_b,xb_b,yb_b };
	q.push(begin);
	mem[xp_b][yp_b][xb_b][yb_b] = 1;
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
			int xp = now.xp, yp = now.yp, xb = now.xb, yb = now.yb;
			if (xb == ex && yb == ey)
			{
				cout << cou << endl;
				return 0;
			}
			for (int i = 0; i < 4; i++)
			{
				if (arr[xp + vary[i][0]][yp + vary[i][1]] != '1')
				{
					if (arr[xp + vary[i][0]][yp + vary[i][1]] == '0' && (xp + vary[i][0] != xb || yp + vary[i][1] != yb) && mem[xp + vary[i][0]][yp + vary[i][1]][xb][yb] == 0)
					{
						info tmp = { xp + vary[i][0], yp + vary[i][1],xb,yb };
						q.push(tmp);
						mem[xp + vary[i][0]][yp + vary[i][1]][xb][yb] = 1;
					}
					else if (xp + vary[i][0] == xb && yp + vary[i][1] == yb && arr[xb + vary[i][0]][yb + vary[i][1]] == '0' && mem[xp + vary[i][0]][yp + vary[i][1]][xb + vary[i][0]][yb + vary[i][1]] == 0)
					{
						info tmp = { xp + vary[i][0], yp + vary[i][1], xb + vary[i][0], yb + vary[i][1] };
						q.push(tmp);
						mem[xp + vary[i][0]][yp + vary[i][1]][xb + vary[i][0]][yb + vary[i][1]] = 1;
					}
				}
			}
		}
		cou++;
	}
}