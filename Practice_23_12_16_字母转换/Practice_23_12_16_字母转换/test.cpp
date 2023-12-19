//描述
//通过栈交换字母顺序。给定两个字符串，要求所有的进栈和出栈序列（i表示进栈，o表示出栈），
//使得字符串2在求得的进出栈序列的操作下，变成字符串1。输出结果需满足字典序。例如TROT 到 TORT :
//[
//	i i i i o o o o
//		i o i i o o i o
//]
//
//输入
//给定两个字符串，第一个字符串是源字符串，第二个字符是目标目标字符串。
//
//输出
//所有的进栈和出栈序列, 输出结果需满足字典序

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
	while (cin >> s1 >> s2)//noj系统要求输入字符串这样子结束，我暂时还不能理解
	{
		int l1 = strlen(s1);
		int l2 = strlen(s2);
		cout << "[" << endl;
		dfs(l1, l2);
		cout << "]" << endl;
	}
}