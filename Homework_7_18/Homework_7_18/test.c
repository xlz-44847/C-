#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,11 };
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0])-1;
	int mid = -1;
	int input = 0;
	scanf("%d", &input);
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] == input)
		{
			printf("找到了，数字下标是：%d\n", mid);
			break;
		}
		else if (arr[mid] < input)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	if (left > right)
		printf("找不到");
	return 0;
}

//#include<time.h>
//#include<stdlib.h>
//void menu()
//{
//	printf("***************************\n");
//	printf("***  1.play     0.exit  ***\n");
//	printf("***************************\n");
//}
//
//void game()
//{
//	int guess = 0;
//	int ans = rand() % 100 + 1;
//	while (1)
//	{
//		printf("请输入要猜的数字：>");
//		scanf("%d", &guess);
//		if (guess == ans)
//		{
//			printf("猜中啦\n");
//			break;
//		}
//		else if (guess < ans)
//			printf("猜小了\n");
//		else
//			printf("猜大了\n");
//	}
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择：>");
//		scanf("%d",&input);
//		switch(input)
//		{
//			case 1:
//				game();
//				break;
//			case 0:
//				printf("游戏结束\n");
//				break;
//			default:
//				printf("输入错误，请重新输入\n");
//				break;
//		}
//	} while (input);
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i / 10 == 9)
//			count++;
//		if (i % 10 == 9)
//			count++;
//	}
//	printf("%d\n", count);
//	return 0;
//}