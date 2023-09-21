#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdbool.h>
#include<math.h>
//bool Is_prime(int x)
//{
//	for (int i = 2; i <= sqrt(x); i++)
//	{
//		if (x % i == 0)
//			return false;
//	}
//	return true;
//}
//
//int main()
//{
//	for (int i = 100; i <= 200; i++)
//		if (Is_prime(i))
//			printf("%d ",i);
//	return 0;
//}

//bool Is_leapyear(int year)//是闰年返回true，不是返回false
//{
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//		return true;
//	else
//		return false;
//}
//
//int main()
//{
//	for (int i = 1000; i <= 2000; i++)
//	{
//		if (Is_leapyear(i))
//			printf("%d ", i);
//	}
//	return 0;
//}


//int Swap(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
//int main()
//{
//	int a = 0, b = 0;
//	scanf("%d%d", &a, &b);
//	printf("Before swapping:a=%d,b=%d\n", a, b);
//	Swap(&a, &b);
//	printf("After swapping:a=%d,b=%d\n", a, b);
//	return 0;
//}

//void MulTablePrint(int x)
//{
//	for (int i = 1; i <= x; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-3d ", j, i, j * i);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	MulTablePrint(num);
//	return 0;
//}

int b = 0;

int a()
{
	b = b + 1;
}

int main()
{
	if (0, 1,0)
		return 0;
	int m = 0;
	m = a();
	printf("%d", b);
	return 0;
}