#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<assert.h>

char* my_strstr(const char* s1, const char* s2)
{
	assert(s1 && s2);

	char* ret = s1;
	while (*s1 != '\0')
	{
		int cur = 0;
		while (*s1 != *s2)
		{
			s1++;
		}
		while (s1[cur] == s2[cur])
		{
			cur++;
			if (s2[cur] == '\0')
				return s1;	
		}
		s1++;
	}
	return NULL;
}

int main()
{
	char arr1[] = "abcdefgdefg";
	char arr2[] = "def";
	printf("%s\n", my_strstr(arr1, arr2));
	return 0;
}

//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//
//	char* ret = dest;
//	while (*dest != '\0')
//		dest++;
//	while (*dest++ = *src++);
//	return ret;
//}
//
//int main()
//{
//	char arr1[20] = "hello,";
//	char arr2[] = "world";
//	printf("%s\n", my_strcat(arr1, arr2));
//	return 0;
//}


//int my_strcmp(const char* e1, const char* e2)
//{
//	assert(e1 && e2);
//
//	while (*e1 == *e2)
//	{
//		if (*e1 == '\0')
//			return 0;
//		else
//		{
//			e1++;
//			e2++;
//		}
//	}
//	return *e1 - *e2;
//}
//
//int main()
//{
//	char arr1[] = "hello";
//	char arr2[] = "world";
//	char arr3[] = "world";
//	printf("%d ", my_strcmp(arr1, arr2));
//	printf("%d ", my_strcmp(arr2, arr3));
//}