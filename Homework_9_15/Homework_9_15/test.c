#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<assert.h>
char* my_strcpy(char* dest, char* src)
{
	assert(dest && src);
	char* ret = dest;
	while (*(dest++) = *(src++));
	return ret;
}

int main()
{
	char arr1[] = "Hello world!";
	char arr2[20] = "";
	printf("arr1:%s\narr2:%s\n",arr1,my_strcpy(arr2,arr1));
	return 0;
}

//size_t my_strlen(char* s)
//{
//	size_t ret = 0;
//	while (s[ret++] != '\0');
//	return ret - 1;
//}
//
//int main()
//{
//	char s[] = "Hello world!";
//	printf("�⺯����%zd\n", strlen(s));
//	printf("ģ��ʵ�֣�%zd\n",my_strlen(s));
//	return 0;
//}