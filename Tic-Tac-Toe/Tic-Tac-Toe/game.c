#define _CRT_SECURE_NO_WARNINGS 

#include"game.h"

void BoardInit(char(*arr)[COL],size_t size)
{
	memset(arr, ' ', size);
}

void BoardPrint(char(*arr)[COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j != col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i != row - 1)
		{
			for (int k = 0; k < 4*col-1; k++)
			{
				printf("-");
			}
			printf("\n");
		}
	}
}

void ComputerMove(char(*arr)[COL], int row, int col)
{
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (arr[x][y] == ' ')
		{
			arr[x][y] = '#';
			break;
		}
	}
}

void PlayerMove(char(*arr)[COL], int row, int col)
{
	int x, y;
	while(1)
	{
		printf("��������������,�ÿո�ֿ�����1 2����");
		scanf("%d%d", &x, &y);
		if (x<1 || x>row || y<1 || y>col)
		{
			printf("���������������������\n");
		}
		else
		{
			if (arr[x-1][y-1] == ' ')
			{
				arr[x-1][y-1] = '*';
				break;
			}
			else
			{
				printf("��λ���ѱ�ռ��\n");
			}
		}
	}
}

void Finish(char(*arr)[COL],int row,int col,char c)
{
	if (c == '#')
	{
		BoardPrint(arr, row, col);
		printf("�ǳ��ź���������\n");
		return;
	}
	if (c == '*')
	{
		BoardPrint(arr, row, col);
		printf("��ϲ����ȡ��ʤ��\n");
		return;
	}
	if (c == ' ')
	{
		BoardPrint(arr, row, col);
		printf("�����֣�ƽ��\n");
		return;
	}
}

bool IfWin(char(*arr)[COL], int row, int col)
{
	//row:
	char ch = 0;
	for (int i = 0; i < row; i++)
	{
		bool flag = true;
		for (int j = 0; j < col - 1; j++)
		{
			if (arr[i][j] == ' ')
			{
				flag = false;
				break;
			}
			if (arr[i][j] != arr[i][j + 1])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			ch = arr[i][0];
			Finish(arr, row, col, ch);
			return true;
		}
	}
	//col:
	for (int j = 0; j < col; j++)
	{
		bool flag = true;
		for (int i = 0; i < row - 1; i++)
		{
			if (arr[i][j] == ' ')
			{
				flag = false;
				break;
			}
			if (arr[i][j] != arr[i + 1][j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			ch = arr[0][j];
			Finish(arr, row, col, ch);
			return true;
		}
	}
	//main-diagonal
	bool flag = true;
	for (int i = 0, j = 0; i < row - 1 && j < col - 1; i++, j++)
	{
		if (arr[i][j] == ' ')
		{
			flag = false;
			break;
		}
		if (arr[i][j] != arr[i + 1][j + 1])
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		ch = arr[0][0];
		Finish(arr, row, col, ch);
		return true;
	}
	//counter-diagonal
	flag = true;
	for (int i = 0, j = col-1; i < row - 1 && j > 0; i++, j--)
	{
		if (arr[i][j] == ' ')
		{
			flag = false;
			break;
		}
		if (arr[i][j] != arr[i + 1][j - 1])
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		ch = arr[0][col-1];
		Finish(arr, row, col, ch);
		return true;
	}
	return false;
}

bool IfFull(char(*arr)[COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == ' ')
			{
				return false;
			}
		}
	}
	Finish(arr, row, col, ' ');
	return true;
}

bool IfEnd(char(*arr)[COL], int row, int col)
{
	if (IfWin(arr, row, col))
	{
		return true;
	}
	else if (IfFull(arr, row, col))
	{
		return true;
	}
	else
	{
		return false;
	}
}