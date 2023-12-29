//描述
//僵尸要来佳佳家做客了，佳佳把花园布置了一下，你拿到了花园的地图（以二维矩阵的形式表示）以及起点和佳佳家的位置。
//花园里某些位置有地刺，僵尸过的时候每次需要消耗一个单位的生命值，僵尸有一定数量的生命值，看看最聪明的僵尸能否在天亮前到达你的家里？能的话，最少花费多少时间。
//
//输入
//输入的第一行包含三个整数：m，n，t。代表m行n列的地图和僵尸的生命值t。
//m, n都是小于200的正整数，t是小于10的正整数，第2行开始的m行是m行n列的花园地图，其中!代表起点， + 表示佳佳家。 * 代表通路，w代表地刺。
//
//输出
//输出僵尸到达佳佳家最少需要花费的时间。如果无法到达，则输出 - 1。
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