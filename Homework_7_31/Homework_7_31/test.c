#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
	int count = 0;
	int money = 20;
	int bottle = 0;
	while (money--)
	{
		count++;
		bottle++;
	}
	while (bottle != 0)
	{
		bottle -= 2;
		count++;
		bottle++;
	}
	printf("最多能喝%d瓶(最后一瓶是借一个瓶子换来的)\n", count);
	return 0;
}
//#include <stdio.h>
//int main()
//{
//    int i = 0;
//    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//    for (i = 0; i <= 12; i++)
//    {
//        arr[i] = 0;
//        printf("hello bit\n");
//    }
//    return 0;
//}

