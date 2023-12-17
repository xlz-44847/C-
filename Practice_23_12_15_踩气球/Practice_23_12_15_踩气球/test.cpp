//描述
//六一儿童节，小朋友们做踩气球游戏，气球的编号是1～100，两位小朋友各踩了一些气球，要求他们报出自己所踩气球的编号的乘积。
//现在需要你编一个程序来判断他们的胜负，判断的规则是这样的：
//如果两人都说了真话，数字大的人赢；如果两人都说了假话，数字大的人赢；
//如果报小数字的人说的是真话而报大数字的人说谎，则报小数字的人赢（注意：只要所报的小数字是有可能的，即认为此人说了真话）。
//
//输入
//输入为两个数字，0 0表示结束；
//
//输出
//输出为获胜的数字。

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