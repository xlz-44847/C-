//����
//ͨ��ջ������ĸ˳�򡣸��������ַ�����Ҫ�����еĽ�ջ�ͳ�ջ���У�i��ʾ��ջ��o��ʾ��ջ����
//ʹ���ַ���2����õĽ���ջ���еĲ����£�����ַ���1���������������ֵ�������TROT �� TORT :
//[
//	i i i i o o o o
//		i o i i o o i o
//]
//
//����
//���������ַ�������һ���ַ�����Դ�ַ������ڶ����ַ���Ŀ��Ŀ���ַ�����
//
//���
//���еĽ�ջ�ͳ�ջ����, �������������ֵ���

#include<iostream>
#include<stack>

using namespace std;

stack<char> mystack;
char s1[20], s2[20];
char result[100];
int i, j;
char choice[2] = { 'i','o' };

void dfs(int l1, int l2)
{
	if (i + j == l1 + l2)
	{
		for (int k = 0; k < l1 + l2; k++)
		{
			printf("%c", result[k]);
			if (k != l1 + l2 - 1)
			{
				cout << " ";
			}
		}
		cout << "\n";
	}
	else
	{
		for (int k = 0; k < 2; k++)
		{
			result[i + j] = choice[k];
			if (k == 0)
			{
				if (i == l1)
				{
					continue;
				}
				mystack.push(s1[i]);
				i++;
				dfs(l1, l2);
				mystack.pop();
				i--;
			}
			else
			{
				if (mystack.empty())
				{
					continue;
				}
				char tmp = mystack.top();
				if (tmp == s2[j])
				{
					mystack.pop();
					j++;
					dfs(l1, l2);
					mystack.push(tmp);
					j--;
				}
			}
		}
	}
}

int main()
{
	while (cin >> s1 >> s2)//nojϵͳҪ�������ַ��������ӽ���������ʱ���������
	{
		int l1 = strlen(s1);
		int l2 = strlen(s2);
		cout << "[" << endl;
		dfs(l1, l2);
		cout << "]" << endl;
	}
}