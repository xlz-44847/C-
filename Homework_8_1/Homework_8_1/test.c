#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
size_t my_strlen(const char* str)
{
	size_t count = 0;
	while (str[count])
		count++;
	return count;
}
int main()
{
	char s1[] = "Hello world!";
	printf("%s\n%zd", s1, my_strlen(s1));
	return 0;
}

//char* my_strcpy(char* dest, const char* src)
//{
//	char* ret = dest;
//	while (*(dest++) = *(src++));
//	return ret;
//}
//int main()
//{
//	char s1[] = "Hello world!";
//	char s2[20] = { 0 };
//	my_strcpy(s2, s1);
//	printf("s1:%s\ns2:%s\n", s1, s2);
//	return 0;
//}

//int main()
//{
//	//int arr[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
//	int arr[20] = { 0 };
//	srand((unsigned int)time(NULL));
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("≈≈–Ú«∞£∫");
//	for (int i = 0; i < sz; i++)
//	{
//		arr[i] = rand() % 100 + 1;
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		if (arr[left] % 2 == 0)
//		{
//			if (arr[right] % 2 == 1)
//			{
//				int tmp = arr[left];
//				arr[left] = arr[right];
//				arr[right] = tmp;
//				left++;
//				right--;
//			}
//			else
//			{
//				right--;
//			}
//		}
//		else
//		{
//			left++;
//		}
//	}
//	printf("≈≈–Ú∫Û£∫");
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}