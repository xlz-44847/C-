#define _CRT_SECURE_NO_WARNINGS 
#include"game.h"

void menu()
{
	printf("************Minesweeper************\n");
	printf("***********************************\n");
	printf("****   1.play         0.exit   ****\n");
	printf("***********************************\n");
}

void game()
{
	char showboard[ROWS][COLS] = { 0 };
	char mineboard[ROWS][COLS] = { 0 };
	BoardInit(showboard, '#', sizeof(showboard));
	BoardInit(mineboard, '0', sizeof(mineboard));
	SetMine(mineboard, minecount);
	//BoardPrint(showboard, ROWS, COLS);
	//BoardPrint(mineboard, ROWS, COLS);
	FineMine(mineboard, showboard, ROWS, COLS);
	
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 0 :
			printf("�˳���Ϸ\n");
			break;
		case 1 :
			game();
			break;
		default:
			printf("ѡ���������������\n");
			break;
		}
	}while (input);
	return 0;
}