#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
void reverse(char* s, size_t num)
{
	int left = 0;
	int right = num - 1;
	while (left < right)
	{
		char tmp = s[left];
		s[left] = s[right];
		s[right] = tmp;
		left++;
		right--;
	}
}

void leftmove(char* s, int k, size_t size)
{
	reverse(s, k);
	reverse(s + k, size - k);
	reverse(s, size);
}

int IfMove(char* s1, char* s2)
{
	int cur = 0;
	while (cur < strlen(s1))
	{
		if (s1[cur] == s2[0])
		{
			char arr[20];
			strcpy(arr, s1);
			leftmove(arr, cur, strlen(s1));
			if (strcmp(arr, s2) == 0)
			{
				return 1;
			}
		}
		cur++;
	}
	return 0;
}

int main()
{
	char s1[20];
	char s2[20];
	while (scanf("%s%s", &s1, &s2) != EOF)
	{
		if (IfMove(s1,s2))
		{
			printf("旋转了\n");
		}
		else
		{
			printf("没有旋转\n");
		}
	}
	return 0;
}

//int main()
//{
//	char arr[] = "ABCDEF";
//	int k = 0;
//	scanf("%d", &k);
//	printf("左旋前：%s\n",arr);
//	size_t len = strlen(arr);
//	leftmove(arr, k, len);
//	printf("左旋后：%s\n", arr);
//	return 0;
//}