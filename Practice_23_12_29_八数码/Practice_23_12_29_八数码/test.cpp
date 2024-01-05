//����
//�ھŹ��������1��8��8�����ֻ���һ���ǿո���ո����ڵ����ֿ����ƶ����ո��λ�ã��ʸ�����״̬������Ҫ�����ܵ���Ŀ��״̬����0��ʾ�ո񣩣�
//1 2 3
//4 5 6
//7 8 0
//
//����
//����һ��������״̬��
//
//���
//�������Ŀ��״̬����С���������ܵ���ʱ��� - 1��

#include<iostream>
#include<queue>

using namespace std;
typedef struct s {
	int a[9];
}s;

queue<s> q;

int dest[9];
char mem[1000000000];

int Sum(int* arr)
{
	int ret = 0;
	for (int i = 0; i < 9; i++)
	{
		ret *= 10;
		ret += arr[i];
	}
	return ret;
}
bool cmp(int* a1, int* a2)
{
	for (int i = 0; i < 9; i++)
	{
		if (a1[i] != a2[i])
			return false;
	}
	return true;
}
int main()
{
	for (int i = 0; i < 9; i++)
	{
		cin >> dest[i];
	}
	int cou = 0;
	s begin = { {1,2,3,4,5,6,7,8,0} };
	q.push(begin);
	mem[Sum(begin.a)] = 1;
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
			s now = q.front();
			q.pop();
			int* arr = now.a;
			if (cmp(arr, dest))
			{
				cout << cou << endl;
				return 0;
			}
			for (int i = 0; i < 9; i++)
			{
				if (arr[i] == 0)
				{
					if (i % 3 != 0)
					{
						swap(arr[i], arr[i - 1]);
						int sum = Sum(arr);
						if (mem[sum] == 0)
						{
							s tmp = { sum / 100000000,sum / 10000000 % 10,sum / 1000000 % 10,sum / 100000 % 10,sum / 10000 % 10,sum / 1000 % 10,sum / 100 % 10,sum / 10 % 10,sum % 10 };
							q.push(tmp);
							mem[sum] = 1;
						}
						swap(arr[i], arr[i - 1]);
					}
					if (i % 3 != 2)
					{
						swap(arr[i], arr[i + 1]);
						int sum = Sum(arr);
						if (mem[sum] == 0)
						{
							s tmp = { sum / 100000000,sum / 10000000 % 10,sum / 1000000 % 10,sum / 100000 % 10,sum / 10000 % 10,sum / 1000 % 10,sum / 100 % 10,sum / 10 % 10,sum % 10 };
							q.push(tmp);
							mem[sum] = 1;
						}
						swap(arr[i], arr[i + 1]);
					}
					if (i > 2)
					{
						swap(arr[i], arr[i - 3]);
						int sum = Sum(arr);
						if (mem[sum] == 0)
						{
							s tmp = { sum / 100000000,sum / 10000000 % 10,sum / 1000000 % 10,sum / 100000 % 10,sum / 10000 % 10,sum / 1000 % 10,sum / 100 % 10,sum / 10 % 10,sum % 10 };
							q.push(tmp);
							mem[sum] = 1;
						}
						swap(arr[i], arr[i - 3]);
					}
					if (i < 6)
					{
						swap(arr[i], arr[i + 3]);
						int sum = Sum(arr);
						if (mem[sum] == 0)
						{
							s tmp = { sum / 100000000,sum / 10000000 % 10,sum / 1000000 % 10,sum / 100000 % 10,sum / 10000 % 10,sum / 1000 % 10,sum / 100 % 10,sum / 10 % 10,sum % 10 };
							q.push(tmp);
							mem[sum] = 1;
						}
						swap(arr[i], arr[i + 3]);
					}
				}
			}
		}
		cou++;
	}
}