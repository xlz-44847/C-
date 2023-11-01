#define _CRT_SECURE_NO_WARNINGS 

#include"game.h"

void menu()
{
	printf("**********************************\n");
	printf("**********************************\n");
	printf("****   1.play        0.exit   ****\n");
	printf("**********************************\n");
	printf("**********************************\n");
}
void game()
{
	//1.creat a container for the information of board
	char board[ROW][COL];
	//2.initialize board
	BoardInit(board, sizeof(board));
	//BoardPrint(board, ROW, COL);
	//3.first move
	int input = 0;
	while (1)
	{
		printf("请选择先手（1.电脑；2.玩家）：");
		scanf("%d", &input);
		if (input == 1 || input == 2)
		{
			break;
		}
		else
		{
			printf("输入错误，请重新输入\n");
		}
	}
	//4.play game
	while (1)
	{
		if (input == 1)
		{
			ComputerMove(board,ROW,COL);
			printf("电脑回合\n");
			BoardPrint(board, ROW, COL);
			if (IfEnd(board,ROW,COL))
			{
				break;
			}
		}
		PlayerMove(board,ROW,COL);
		printf("玩家回合\n");
		BoardPrint(board, ROW, COL);
		if (IfEnd(board,ROW,COL))
		{
			break;
		}
		input = 1;
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		char board[ROW][COL] = {0};
		menu();
		printf("请输入您的选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}