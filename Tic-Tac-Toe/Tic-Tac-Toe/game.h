#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>

#define ROW 3
#define COL 3

void BoardInit(char(*arr)[COL], size_t size);
void BoardPrint(char(*arr)[COL], int row, int col);
void ComputerMove(char(*arr)[COL], int row, int col);
void PlayerMove(char(*arr)[COL], int row, int col);
bool IfEnd(char(*arr)[COL], int row, int col);