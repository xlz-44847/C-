#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* convert(char* s, int numRows) {
    /*    int len = strlen(s);
        int group = 0;
        if(len%(2*numRows-2)==0)
            group = len/(2*numRows-2);
        else
            group = len/(2*numRows-2)+1;
        char* p = (char*)malloc(group*numRows*(numRows-1)*sizeof(char));
        for(int i=0;i<group;i++)
        {
            p[i*(numRows-1)] = s[i*(2*numRows-2)];
            for(int j=1;j<=numRows-2;j++)
            {
                p[i*(numRows-1)+j] = ' ';
            }
        }
        p[group*(numRows-1)] = '\n';
    */
    int len = strlen(s);
    int group = 0;
    if (numRows == 1)
        return s;
    else if (len % (2 * numRows - 2) == 0)
        group = len / (2 * numRows - 2);
    else
        group = len / (2 * numRows - 2) + 1;
    //char (*arr)[group * (numRows - 1) + 1] = (char(*)[group * (numRows - 1) + 1])malloc(numRows * (group * (numRows - 1) + 1) * sizeof(char));
    //char arr[numRows][group * (numRows - 1) + 1];
    char** arr = (char**)malloc(numRows * sizeof(char*));
    for (int i = 0; i < numRows; i++)
    {
        arr[i] = (char*)malloc((group * (numRows - 1) + 1) * sizeof(char));
    }
    //memset(arr, ' ',numRows * (group * (numRows - 1) + 1) * sizeof(char));
    for (int i = 0; i < numRows; i++)
    {
        memset(arr[i], ' ',(group * (numRows - 1) + 1) * sizeof(char));
        arr[i][group * (numRows - 1)] = '\n';
        //*(*(arr + i) + group * (numRows - 1)) = '\n';
    }
    int site = 0;
    for (int j = 0; j < group; j++)
    {
        for (int i = 0; i < numRows && s[site] != '\0'; i++)
        {
            arr[i][j * (numRows - 1)] = s[site++];
        }
        for (int i = numRows - 2 ; i > 0 && s[site] != '\0'; i--)
        {
            arr[i][j * (numRows - 1) + numRows - i-1] = s[site++];
        }
    }
    //memmove(p, arr, sizeof(arr));
    s[0] = '\0';
    for (int i = 0; i < numRows; i++)
    {
        strncat(s, arr[i], group * (numRows - 1) + 1);
        free(arr[i]);
    }
    free(arr);
    return s;
}

int main()
{
    char s[100] = "PAYPALISHIRING";
    int numRows = 4;
    convert(s, numRows);
    //for (int i = 0; i < numRows; i++)
    //{
    //    //printf("aa");
    //    printf("%c", (*p)[i]);
    //}
    printf("%s", s);
    return 0;
}