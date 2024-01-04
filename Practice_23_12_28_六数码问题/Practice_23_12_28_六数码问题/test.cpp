//描述
//现有一两行三列的表格如下：
//
//A B C
//D E F
//
//把1、2、3、4、5、6六个数字分别填入A、B、C、D、E、F格子中，每个格子一个数字且各不相同。每种不同的填法称为一种布局。如下：
//
//1 3 5
//2 4 6
//布局1
//
//2 5 6
//4 3 1
//布局2
//
//定义α变换如下：把A格中的数字放入B格，把B格中的数字放入E格，把E格中的数字放入D格，把D格中的数字放入A格。
//定义β变换如下：把B格中的数字放入C格，把C格中的数字放入F格，把F格中的数字放入E格，把E格中的数字放入B格。
//
//问：对于给定的布局，可否通过有限次的α变换和β变换变成下面的目标布局：
//
//1 2 3
//4 5 6
//目标布局

#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

typedef struct lis {
	int arr[6];
}lis;

int standard[6] = { 1,2,3,4,5,6 };
int mem[6][6][6][6][6][6];
queue<lis> myqueue;

bool cmp(int* cmp1, int* cmp2)
{
	for (int i = 0; i < 6; i++)
	{
		if (cmp1[i] != cmp2[i])
			return false;
	}
	return true;
}

int main()
{
	lis begin;
	while (cin >> begin.arr[0] >> begin.arr[1] >> begin.arr[2] >> begin.arr[3] >> begin.arr[4] >> begin.arr[5])
	{
		myqueue.push(begin);
		mem[begin.arr[0]][begin.arr[1]][begin.arr[2]][begin.arr[3]][begin.arr[4]][begin.arr[5]] = 1;
		int flag = 0;
		memset(mem, 0, sizeof(mem));
		while (1)
		{
			if (myqueue.empty())
			{
				cout << "No" << endl;
				break;
			}
			int size = myqueue.size();
			while (size--)
			{
				lis now = myqueue.front();
				myqueue.pop();
				if (cmp(now.arr, standard))
				{
					flag = 1;
					cout << "Yes" << endl;
					break;
				}
				{
					lis tmp;
					tmp.arr[0] = now.arr[3];
					tmp.arr[1] = now.arr[0];
					tmp.arr[2] = now.arr[2];
					tmp.arr[3] = now.arr[4];
					tmp.arr[4] = now.arr[1];
					tmp.arr[5] = now.arr[5];
					if (mem[tmp.arr[0]][tmp.arr[1]][tmp.arr[2]][tmp.arr[3]][tmp.arr[4]][tmp.arr[5]] != 1)
					{
						myqueue.push(tmp);
						mem[tmp.arr[0]][tmp.arr[1]][tmp.arr[2]][tmp.arr[3]][tmp.arr[4]][tmp.arr[5]] = 1;
					}
				}
				{
					lis tmp;
					tmp.arr[0] = now.arr[0];
					tmp.arr[1] = now.arr[4];
					tmp.arr[2] = now.arr[1];
					tmp.arr[3] = now.arr[3];
					tmp.arr[4] = now.arr[5];
					tmp.arr[5] = now.arr[2];
					if (mem[tmp.arr[0]][tmp.arr[1]][tmp.arr[2]][tmp.arr[3]][tmp.arr[4]][tmp.arr[5]] != 1)
					{
						myqueue.push(tmp);
						mem[tmp.arr[0]][tmp.arr[1]][tmp.arr[2]][tmp.arr[3]][tmp.arr[4]][tmp.arr[5]] = 1;
					}
				}
			}
			if (flag == 1)
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
