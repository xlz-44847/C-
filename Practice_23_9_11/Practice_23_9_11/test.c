#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>

int check(char* p, int dest) //回文返回字符串长度，不回文返回-1
{
    int left = 0;
    int right = dest;
    while (left < right)
    {
        if (*(p + left) == *(p + right))
        {
            left++;
            right--;
        }
        else
            return -1;
    }
    if (left >= right)
    {
        return dest;
    }
    else
        return -1;
}

char* longestPalindrome(char* s) {
    char* po = s;
    int dest = 0;
    int count = 0;
    char* final = s;
    int con = 0;
    int len = strlen(s);
    while (po < s + len)
    {
        while (++dest < len - con)
        {
            if (*(po + dest) == *po)
            {
                int tem = check(po, dest);
                if (tem > count)
                {
                    count = tem;
                    final = po;
                }
            }
        }
        dest = 0;
        po++;
        con++;
    }
    *(final + count + 1) = '\0';
    return final;
}

int main()
{
    char a[] = "abbd";
    printf("%s", longestPalindrome(a));
    return 0;
}