//����
//���׻÷�����򵥵Ļ÷����ֽоŹ�������1, 2, 3, 4, 5, 6, 7, 8, 9�Ÿ�������ɵ�һ���������еľ�����Խ��ߡ����С�����ĵĺͶ�Ϊ15��
//
//����
//��
//
//���
//���ֵ���������е����������Ļ÷�����ÿ��������֮���һ���ո���β�޿ո�ÿ���÷����һ�����С�

#include<iostream>

using namespace std;

int arr[10];
int mem[10];

bool check()
{
	for (int i = 0; i < 3; i++)
	{
		if (arr[1 + i * 3] + arr[2 + i * 3] + arr[3 + i * 3] != 15 || arr[1 + i] + arr[4 + i] + arr[7 + i] != 15)
			return false;
	}
	if (arr[1] + arr[5] + arr[9] != 15 || arr[3] + arr[5] + arr[7] != 15)
		return false;
	return true;
}

void dfs(int cou)
{
	if (cou == 10)
	{
		if (check())
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cout << arr[j + 1 + 3 * i];
					if (j != 2)
						cout << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		return;
	}
	for (int i = 1; i < 10; i++)
	{
		if (mem[i] == 0)
		{
			arr[cou] = i;
			mem[i] = 1;
			dfs(cou + 1);
			mem[i] = 0;
		}
	}
}

int main()
{
	dfs(1);
	return 0;
}