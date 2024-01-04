//����
//����һ�������еı�����£�
//
//A B C
//D E F
//
//��1��2��3��4��5��6�������ֱַ�����A��B��C��D��E��F�����У�ÿ������һ�������Ҹ�����ͬ��ÿ�ֲ�ͬ�����Ϊһ�ֲ��֡����£�
//
//1 3 5
//2 4 6
//����1
//
//2 5 6
//4 3 1
//����2
//
//������任���£���A���е����ַ���B�񣬰�B���е����ַ���E�񣬰�E���е����ַ���D�񣬰�D���е����ַ���A��
//����±任���£���B���е����ַ���C�񣬰�C���е����ַ���F�񣬰�F���е����ַ���E�񣬰�E���е����ַ���B��
//
//�ʣ����ڸ����Ĳ��֣��ɷ�ͨ�����޴εĦ��任�ͦ±任��������Ŀ�겼�֣�
//
//1 2 3
//4 5 6
//Ŀ�겼��

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
