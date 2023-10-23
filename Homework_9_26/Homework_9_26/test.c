#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

int my_atoi(char* s)
{
	assert(s);

	int cur = 0;
	int flag = 1;
	int ret = 0;
	while (s[cur] == ' ')
	{
		cur++;
	}
	if (s[cur] == '-')
	{
		flag = -1;
		cur++;
	}
	else if (s[cur] == '+')
	{
		cur++;
	}
	while (s[cur] >= '0' && s[cur] <= '9')
	{
		if (ret > INT_MAX / 10 && flag == 1)
		{
			return INT_MAX;
		}
		if (ret > INT_MAX / 10 && flag == -1)
		{
			return INT_MIN;
		}
		if (ret == INT_MAX / 10 && s[cur] > '6' && flag == 1)
		{
			return INT_MAX;
		}
		if (ret == INT_MAX / 10 && s[cur] > '7' && flag == -1)
		{
			return INT_MIN;
		}
		ret *= 10;
		ret += s[cur] - '0';
		cur++;
	}
	return ret*flag;
}

int main()
{
	printf("%d\n", atoi("  -2344-2+2+31111111ww"));
	printf("%d\n", my_atoi("  -2344-2+2+31111111ww"));
	return 0;
}


//int main()
//{
//	int arr[10] = { 1,2,3,4,5,1,2,3,4,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int num1 = 0;
//	int num2 = 0;
//	int assist = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		assist ^= arr[i];
//	}
//	int count = 0;
//	while (1)
//	{
//		if (assist % 2)
//		{
//			break;
//		}
//		else
//		{
//			assist >> 1;
//		}
//		++count;
//	}
//	for (int i = 0; i < sz; i++)
//	{
//		if ((arr[i] >> count) % 2 == 1)
//		{
//			num1 ^= arr[i];
//		}
//		else
//		{
//			num2 ^= arr[i];
//		}
//	}
//	printf("单身狗就是：%d和%d", num1, num2);
//	return 0;
//}

//char* my_strncat(char* dest, char* src, size_t num)
//{
//	assert(dest && src);
//	
//	char* ret = dest;
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	while (num--)
//	{
//		if (!(*dest++ = *src++))
//			return ret;
//	}
//	if (num == 0);
//	{
//		*dest = '\0';
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[20] = "Hello ";
//	char arr2[] = "world!";
//	printf("%s", my_strncat(arr1,arr2,10));
//	return 0;
//}

//char* my_strncpy(char* dest, const char* src, size_t num)
//{
//	assert(dest && src);
//
//	char* ret = dest;
//	while (num--)
//	{
//		if (*src == '\0')
//		{
//			*(dest++) = '\0';
//		}
//		else
//		{
//			*(dest++) = *(src++);
//		}
//	}
//	
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "Hello world!";
//	char arr2[20] = "xxxxxxxxx";
//	printf("arr1:%s\narr2:%s\n", arr1, my_strncpy(arr2, arr1, 5));
//	return 0;
//}