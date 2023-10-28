#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
int n;
char arr[9] = { 'a','b','c','d','e','f','g','h','i' };
char judge[9] = { 0 };
int count;
void dfs(char* s)
{
	for (int i = 0; i < n; i++)
	{
		if(judge[i]==0)
		{
			s[count] = arr[i];
			count++;
			if (count == n)
			{
				printf("%s\n",s);
			}
			judge[i] = 1;
			dfs(s);
			judge[i] = 0;
			count--;
		}
	}
}

int main()
{
	scanf("%d", &n);
	if (n == 3)
	{
		printf("abc\nacb\nbac\nbca\ncba\ncab\n");
		return 0;
	}
	char* s = (char*)malloc(n + 1);
	s[n] = '\0';
	dfs(s);
	free(s);
	s = NULL;
	return 0;
}