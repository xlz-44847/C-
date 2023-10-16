#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int n = 0;
	int arr[1000] = { 1 };
	printf("请输入打印行数:>");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j >0; j--)
		{
			arr[j] = arr[j] + arr[j - 1];
		}
		for (int j = 0; j <= i; j++)
		{
			printf("%d ", arr[j]);
		}
		printf("\n");
	}
}
//int main()
//{
//	char murderer = 'A';
//	for (int i = 0; i < 4; i++, murderer++)
//	{
//		//D lying
//		if (murderer != 'A' && murderer == 'C' && murderer == 'D' && murderer == 'D')
//			break;
//		//C lying
//		if (murderer != 'A' && murderer == 'C' && murderer != 'D' && murderer != 'D')
//			break;
//		//B lying
//		if (murderer != 'A' && murderer != 'C' && murderer == 'D' && murderer != 'D')
//			break;
//		//A lying
//		if (murderer == 'A' && murderer == 'C' && murderer == 'D' && murderer != 'D')
//			break;
//	}
//	printf("merderer is %c", murderer);
//}

//int main()
//{
//	char arr[6] = { 0 ,'A','B','C','D','E' };
//	srand((unsigned int)time(NULL));
//	while(1)
//	{
//		for (int i = 0; i < 100; i++)
//		{
//			int m = rand() % 5 + 1;
//			int n = rand() % 5 + 1;
//			int tmp = arr[m];
//			arr[m] = arr[n];
//			arr[n] = tmp;
//		}
//		if (arr[2] == 'B' && arr[3] != 'A' || arr[2] != 'B' && arr[3] == 'A')
//			if (arr[2] == 'B' && arr[4] != 'E' || arr[2] != 'B' && arr[4] == 'E')
//				if (arr[1] == 'C' && arr[2] != 'D' || arr[1] != 'C' && arr[2] == 'D')
//					if (arr[5] == 'C' && arr[3] != 'D' || arr[5] != 'C' && arr[3] == 'D')
//						if (arr[4] == 'E' && arr[1] != 'A' || arr[4] != 'E' && arr[1] == 'A')
//							break;
//	}
//	for (int i = 1; i <= 5; i++)
//	{
//		printf("第%d名是：%c\n", i, arr[i]);
//	}
//	return 0;
//}