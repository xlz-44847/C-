#include <stdio.h>

int Check(char ch, char* s2)
{
    int check = 0;
    while (s2[check] != '\0')
    {
        if (ch == s2[check])
        {
            return 0;
        }
        else
        {
            check++;
        }
    }
    return 1;
}//存在返回0，不存在返回1

int main() {
    char str1[100] = { 0 };
    char str2[100] = { 0 };
    gets(str1);
    gets(str2);
    int slow = 0;
    int fast = 0;
    
    while (str1[slow] != '\0' || str1[fast] != '\0')
    {
        //slow找到一个str2字符
        while (str1[slow] != '\0' && (Check(str1[slow], str2)))
        {
            slow++;
        }
        //fast找到一个非str2字符
        while (fast <= slow)
        {
            fast++;
        }
        while (str1[fast] != '\0' && !(Check(str1[fast], str2)))
        {
            fast++;
        }
        char tmp = str1[fast];
        str1[fast] = str1[slow];
        str1[slow] = tmp;
    }
    printf("%s", str1);
    return 0;
}