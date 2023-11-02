#define _CRT_SECURE_NO_WARNINGS 

#include"game.h"

void BoardInit(char(*arr)[COLS], char c, int size)
{
	memset(arr, c, size);
}

void SetMine(char(*arr)[COLS], int num)
{
	while(num)
	{
		int x = rand() % ROW + 1;
		int y = rand() % ROW + 1;
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			num--;
		}
	}
}

void BoardPrint(char(*arr)[COLS], int row, int col)
{
	printf(">Minesweeper<\n");
	for (int i = 0; i < col-1; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i < row - 1; i++)
	{
		printf("%d ", i);
		for (int j = 1; j < col - 1; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}

void BoardShow(char(*mine)[COLS], char(*show)[COLS], int row, int col, int x, int y)
{
	char count = 0;
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			count += mine[i][j] - '0';
		}
	}
	show[x][y] = count + '0';
	if (show[x][y] == '0')
	{
		show[x][y] = ' ';
		for (int i = x - 1; i <= x + 1; i++)
		{
			for (int j = y - 1; j <= y + 1; j++)
			{
				if (show[i][j] == '#' && i >= 1 && i <= row - 2 && j >= 1 && j <= col - 2)
				{
					BoardShow(mine, show, row, col, i, j);
				}
			}
		}
	}
}

int sum(char(*show)[COLS], int row, int col)
{
	int ret = 0;
	for (int i = 1; i < row- 1; i++)
	{
		for (int j = 1; j < col - 1; j++)
		{
			if (show[i][j] == '#')
			{
				ret++;
			}
		}
	}
	return ret;
}

void FineMine(char(*mine)[COLS], char(*show)[COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	while (sum(show,row,col)>minecount)
	{
		BoardPrint(show, row, col);
		printf("��ѡ������(�磺1 1)��>");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= row - 2 && y > 0 && y <= col - 2)
		{
			if (show[x][y] != '#')
			{
				printf("��λ���Ѿ���ɨ����������ѡ��\n");
			}
			else
			{
				if (mine[x][y] == '1')
				{
					printf("��Ǹ��������\n");
					BoardPrint(show, row, col);
					BoardPrint(mine, row, col);
					return;
				}
				else
				{
					BoardShow(mine, show, row, col, x, y);
				}
			}
		}
		else
		{
			printf("���������������������\n");
		}
	}
	printf("��ϲ����ȡ��ʤ��\n");
	BoardPrint(show, row, col);
	BoardPrint(mine, row, col);
}