//����
//��һ��ƿװ��8��ƣ�û��������ֻ�зֱ�װ5���3��Ŀվ�ƿ�����һ����8��Ʒֳ�����4��������ٵĲ�������𰸡�
//
//����
//����������������m��n��k������n + k = m����mΪż������ʾ��һ����ƿװ��m��ͣ�ֻ�������ֱ�װn���k��Ŀվ�ƿ�������ټ����ܹ����Ʒֳ�����m / 2�
//
//���
//������ٵĴ�����

#include<iostream>
#include<queue>

using namespace std;

typedef struct state {
	int w8;
	int w5;
	int w3;
}state;

int mem[9][6][4];

queue<state> q;

int main()
{
	int m, n, k;
	cin >> m >> n >> k;
	state begin = { 8,0,0 };
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
			state now = q.front();
			q.pop();
			int w8 = now.w8, w5 = now.w5, w3 = now.w3;
			if (w8 == m / 2 && w5 == m / 2)
			{
				cout << cou << endl;
				return 0;
			}
			int t8 = w8, t5 = w5, t3 = w3;
			if (w8 != 0)
			{
				//8->5
				t8 = (w5 + w8) > 5 ? (w5 + w8 - 5) : 0;
				t5 = (w5 + w8) > 5 ? 5 : (w5 + w8);
				t3 = w3;
				if (mem[t8][t5][t3] == 0)
				{
					state tmp = { t8,t5,t3 };
					q.push(tmp);
				}
				//8->3
				t8 = (w3 + w8) > 3 ? (w3 + w8 - 3) : 0;
				t5 = w5;
				t3 = (w3 + w8) > 3 ? 3 : (w3 + w8);
				if (mem[t8][t5][t3] == 0)
				{
					state tmp = { t8,t5,t3 };
					q.push(tmp);
				}
			}
			if (w5 != 0)
			{
				//5->8
				t8 = (w5 + w8) > 8 ? 8 : (w5 + w8);
				t5 = (w5 + w8) > 8 ? (w5 + w8 - 8) : 0;
				t3 = w3;
				if (mem[t8][t5][t3] == 0)
				{
					state tmp = { t8,t5,t3 };
					q.push(tmp);
				}
				//5->3
				t8 = w8;
				t5 = (w5 + w3) > 3 ? (w5 + w3 - 3) : 0;
				t3 = (w5 + w3) > 3 ? 3 : (w3 + w5);
				if (mem[t8][t5][t3] == 0)
				{
					state tmp = { t8,t5,t3 };
					q.push(tmp);
				}
			}
			if (w3 != 0)
			{
				//3->5
				t8 = w8;
				t5 = (w5 + w3) > 5 ? 5 : (w5 + w3);
				t3 = (w5 + w3) > 5 ? (w5 + w3 - 5) : 0;
				if (mem[t8][t5][t3] == 0)
				{
					state tmp = { t8,t5,t3 };
					q.push(tmp);
				}
				//3->8
				t8 = (w3 + w8) > 8 ? 8 : (w3 + w8);
				t5 = w5;
				t3 = (w3 + w8) > 8 ? (w3 + w8 - 8) : 0;
				if (mem[t8][t5][t3] == 0)
				{
					state tmp = { t8,t5,t3 };
					q.push(tmp);
				}
			}
		}
		cou++;
	}
}