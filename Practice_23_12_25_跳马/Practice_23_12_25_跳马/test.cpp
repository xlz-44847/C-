//描述
//在国际象棋中，马的走法与中车象棋类似，即俗话说的“马走日”，下图所示即国际象棋中马（K）在一步能到达的格子（其中黑色的格子是能到达的位置）。
//现有一200 * 200大小的国际象棋棋盘，棋盘中仅有一个马，给定马的当前位置（S）和目标位置（T），求出马最少需要多少跳才能从当前位置到达目标位置。
//
//输入
//本题包含多个测例。输入数据的第一行有一个整数N（1 <= N <= 1000），表示测例的个数，接下来的每一行有四个以空格分隔的整数，分别表示马当前位置及目标位置的横、纵坐标C（x, y）和G（x, y）。坐标由1开始。
//
//输出
//对于每个测例，在单独的一行内输出一个整数，即马从当前位置跳到目标位置最少的跳数。

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