#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
int main()
{
	int i = 0,flag = -1;
	double sum = 0.0;
	for (i = 1; i <= 100; i++)
	{
		flag *= -1;
		sum += flag*1.0 / i;
	}
	printf("%lf", sum);
}

//int main()
//{
//	int arr[10];
//	int max = 0;
//	for (int i = 0; i < 10; i++)
//		scanf("%d", &arr[i]);
//	max = arr[0];
//	for (int i = 1; i < 10; i++)
//	{
//		if (arr[i] > max)
//			max = arr[i];
//	}
//	printf("The largest number is %d.\n", max);
//	return 0;
//}

//int main()
//{
//	for (int i = 1; i <= 9; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-2d ", j, i, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int num1,num2,i = 0;
//	scanf("%d%d", &num1,&num2);
//	for (i = num1 < num2 ? num1 : num2; i > 0; i--)
//	{
//		if (num1 % i == 0 && num2 % i == 0)
//		{
//			printf("%d", i);
//			break;
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int i;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if ((i % 4 == 0 && i % 100 != 0)|| i%400 == 0)
//			printf("%d ", i);
//	}
//	return 0;
//}

//int prime(int x)
//{
//	for (int i = 2; i < x / 2; i++)
//	{
//		if (x % i == 0)
//			return 0;
//	}
//	return 1;
//		
//}
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (prime(i))
//			printf("%d ", i);
//	}
//	return 0;
//}

//int main()
//{
//	int a,b,c;
//	scanf("%d%d%d", &a, &b, &c);
//	if(a < b)
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if(a < c)
//	{
//		int tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if(b < c)
//	{
//		int tmp = c;
//		c = b;
//		b = tmp;
//	}
//	printf("%d %d %d",a,b,c);
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for(i=1;i<=100;i++)
//	{
//		if (i % 3 == 0)
//			printf("%d ", i);
//	}
//	return 0;
//}