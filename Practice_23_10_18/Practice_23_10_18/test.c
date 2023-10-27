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
}//���ڷ���0�������ڷ���1

int main() {
    char str1[100] = { 0 };
    char str2[100] = { 0 };
    gets(str1);
    gets(str2);
    int slow = 0;
    int fast = 0;
    
    while (str1[slow] != '\0' || str1[fast] != '\0')
    {
        //slow�ҵ�һ��str2�ַ�
        while (str1[slow] != '\0' && (Check(str1[slow], str2)))
        {
            slow++;
        }
        //fast�ҵ�һ����str2�ַ�
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