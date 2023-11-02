#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2
#define minecount 10

void BoardInit(char(*arr)[COLS], char c, int size);
void SetMine(char(*arr)[COLS], int num);
void BoardPrint(char(*arr)[COLS], int row, int col);
void FineMine(char(*mine)[COLS], char(*show)[COLS], int row, int col);