#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>

int dp[201][201];

int main()
{
	char a[201], b[201];
	scanf("%s%s", a, b);
	int lena = strlen(a);
	int lenb = strlen(b);
	for (int i = 0; i <= lena; i++)
	{
		dp[i][0] = 0;
	}
	for (int i = 0; i <= lenb; i++)
	{
		dp[0][i] = 0;
	}
	for (int i = 1; i <= lena; i++)
	{
		for (int j = 1; j <= lenb; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
			}
		}
	}
	printf("%d", dp[lena][lenb]);
	return 0;
}