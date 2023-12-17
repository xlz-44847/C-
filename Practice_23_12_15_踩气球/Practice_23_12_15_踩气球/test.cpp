//����
//��һ��ͯ�ڣ�С����������������Ϸ������ı����1��100����λС���Ѹ�����һЩ����Ҫ�����Ǳ����Լ���������ı�ŵĳ˻���
//������Ҫ���һ���������ж����ǵ�ʤ�����жϵĹ����������ģ�
//������˶�˵���滰�����ִ����Ӯ��������˶�˵�˼ٻ������ִ����Ӯ��
//�����С���ֵ���˵�����滰���������ֵ���˵�ѣ���С���ֵ���Ӯ��ע�⣺ֻҪ������С�������п��ܵģ�����Ϊ����˵���滰����
//
//����
//����Ϊ�������֣�0 0��ʾ������
//
//���
//���Ϊ��ʤ�����֡�

#include<iostream>
#include<algorithm>
using namespace std;

int nums[101];

bool check(int num)
{
	int tmp = num;
	for (int i = 1; i <= 100 && i <= num/2; i++)
	{
		if (nums[i] == 1)
		{
			continue;
		}
		if (tmp % i == 0)
		{
			tmp = tmp / i;
			nums[i] = 1;
		}
		if (tmp == 1)
		{
			return true;
		}
	}
	if (num <= 100 && nums[num] == 0)
	{
		nums[num] = 1;
		return true;
	}
	return false;
}

int main()
{
	int m, n;
	while (1)
	{
		cin >> m >> n;
		if (m == 0 && n == 0)
		{
			break;
		}
		int mi = min(m, n);
		int ma = max(m, n);
		memset(nums, 0, sizeof(nums));
		if (check(mi))
		{
			if (!check(ma))
			{
				memset(nums, 0, sizeof(nums));
				if (check(ma) && check(mi))
				{
					cout << ma << endl;
				}
				else
				{
					cout << mi << endl;
				}
			}
			else
			{
				cout << ma << endl;
			}
		}
		else
		{
			cout << ma << endl;
		}
	}
	return 0;
}