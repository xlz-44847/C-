//����
//��һ����.��X��ʾ��ͼ�Σ�ͼ�����ϡ��¡����ҡ����ϡ����¡����ϡ�����8�����򶼱���������ͨ�ģ�����ͼ���м䲻����ֿն��������ͼ�εı߳���
//
//����
//���ȸ���m��n��x��y�ĸ����������������m��n��ͼ�Σ�x��y��ʾ�����λ�ã�ȫ0��ʾ������
//
//���
//�����ͼ�ε��ܳ���

#include<iostream>

using namespace std;

char exam[10][10];
int m, n, x, y;
char block[10][10];

void dfs(int x1, int y1)
{
	if (block[x1][y1] == 1 || exam[x1][y1] != 'X')
		return;
	block[x1][y1] = 1;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			dfs(x1 + i, y1 + j);
		}
	}
}

int sum()
{
	int ret = 0;
	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (block[i][j] == 1)
			{
				ret += 4 - block[i - 1][j] - block[i + 1][j] - block[i][j - 1] - block[i][j + 1];
			}
		}
	}
	return ret;
}

int main()
{
	while (1)
	{
		cin >> m >> n >> x >> y;
		if (m == 0)
		{
			break;
		}
		memset(exam, 0, sizeof(exam));
		memset(block, 0, sizeof(block));
		for (int i = 1; i < m + 1; i++)
		{
			for (int j = 1; j < n + 1; j++)
			{
				while (1)
				{
					exam[i][j] = getchar();
					if (exam[i][j] == 'X' || exam[i][j] == '.')
					{
						break;
					}
				}
			}
		}
		dfs(x, y);
		int cir = sum();
		cout << cir << endl;
	}
	return 0;
}