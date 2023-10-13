#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
	int num = 0;
	int sum = 0;
	scanf("%d", &num);
	for (int i = 0; i < 5; i++)
	{
		int tmp = 0;
		for (int j = 0; j < i + 1; j++)
		{
			tmp *= 10;
			tmp += num;
		}
		sum += tmp;
	}
	printf("Sn=%d\n", sum);
	return 0;
}

//int main()
//{
//	for (int i = 0; i <= 100000; i++)
//	{
//		int sum = 0;
//		int num = i;
//		int bit = 0;
//		while (num)
//		{
//			num /= 10;
//			bit++;
//		}
//		num = i;
//		for (int j = 0; j < bit; j++, num /= 10)
//		{
//			sum += (int)pow(num % 10, bit);
//		}
//		if (sum == i)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//void Print(char* arr, size_t sz, int n)
//{
//	if (n == sz / 2)
//	{
//		arr[sz / 2 - n] = '*';
//		arr[sz / 2 + n] = '*';
//		printf("%s\n", arr);
//		arr[sz / 2 - n] = ' ';
//		arr[sz / 2 + n] = ' ';
//		return;
//	}
//	n++;
//	printf("%s\n", arr);
//	arr[sz / 2 - n] = '*';
//	arr[sz / 2 + n] = '*';
//	Print(arr, sz, n);
//	arr[sz / 2 - n] = ' ';
//	arr[sz / 2 + n] = ' ';
//	printf("%s\n", arr);
//}
//
//int main()
//{
//	char arr[] = "      *      ";
//	int n = 0;
//	Print(arr,strlen(arr),n);
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	return 0;
//}