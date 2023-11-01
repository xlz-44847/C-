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
		printf("��ѡ�����֣�1.���ԣ�2.��ң���");
		scanf("%d", &input);
		if (input == 1 || input == 2)
		{
			break;
		}
		else
		{
			printf("�����������������\n");
		}
	}
	//4.play game
	while (1)
	{
		if (input == 1)
		{
			ComputerMove(board,ROW,COL);
			printf("���Իغ�\n");
			BoardPrint(board, ROW, COL);
			if (IfEnd(board,ROW,COL))
			{
				break;
			}
		}
		PlayerMove(board,ROW,COL);
		printf("��һغ�\n");
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
		printf("����������ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}