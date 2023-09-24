#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void Print(int x)
{
	if (x > 9)
		Print(x / 10);
	printf("%d ",x % 10);
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	Print(n);
}

//int rec_fac(int x)
//{
//	if (x < 2)
//		return 1;
//	else
//		return x * rec_fac(x - 1);
//}
//
//int norec_fac(int x)
//{
//	int ret = 1;
//	for (; x > 0; x--)
//		ret *= x;
//	return ret;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("递归：%d\n非递归：%d\n", rec_fac(n), norec_fac(n));
//}

//#include<stdio.h>
//#include<string.h>
//int rec_mystrlen(char* s)
//{
//	if (*s != '\0')
//	{
//		return 1 + rec_mystrlen(s + 1);
//	}
//	else
//		return 0;
//}
//
//int norec_mystrlen(char* s)
//{
//	int i = 0;
//	for (i = 0; s[i] != '\0'; i++);
//	return i;
//}
//
//int main()
//{
//	char arr[] = "Hello World";
//	printf("库函数：%d\n递归实现：%d\n非递归实现：%d\n",(int) strlen(arr), rec_mystrlen(arr), norec_mystrlen(arr));
//}

//#define SIZE 7
//char arr[SIZE];
//
//char* reverse_string(char* string)
//{
//	if (string[1] != '\0')
//	{
//		reverse_string(string + 1);
//	}
//	static i = 0;
//	arr[i] = string[0];
//	i = i + 1;
//	arr[i] = '\0';
//	if (i == SIZE - 1)
//		return arr;
//}
//
//int main()
//{
//	char s[] = "abcdef";
//	printf("逆序前：>%s\n逆序后：>%s\n", s, reverse_string(s));
//	return 0;
//}

//int DigitSum(int n)
//{
//	if (n < 10)
//		return n;
//	else
//		return (n % 10 + DigitSum(n / 10));
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("The sum of each digit is %d.\n", DigitSum(n));
//	return 0;
//}

//int Power(int x, int y)
//{
//	if (y <= 1)
//		return x;
//	else
//		return x * Power(x, y - 1);
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d%d", &n, &k);
//	printf("%d^%d=%d\n", n, k, Power(n, k));
//	return 0;
//}

//int Fib(int x)
//{
//	if (x <= 2)
//	{
//		return 1;
//	}
//	else
//		return(Fib(x - 1) + Fib(x - 2));
//}
//
//int main()
//{
//	int num = 0;
//	while (scanf("%d", &num) != EOF)
//	{
//		printf("递归方法：>\n\t输入为：%d\n\t输出为：%d\n", num, Fib(num));
//		int first = 1;
//		int second = 1;
//		int fibnum = 1;
//		for (int i = num; i > 2; i--)
//		{
//			fibnum = first + second;
//			first = second;
//			second = fibnum;
//		}
//		printf("非递归方法：>\n\t输入为：%d\n\t输出为：%d\n", num, fibnum);
//	}
//	
//	return 0;
//}