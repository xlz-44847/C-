#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int lengthOfLongestSubstring(char* s) {
    char* p = s;
    int len = 0;
    while (*p != '\0' && *(p + 1) != '\0')
    {
        char* p1 = p;
        int count = 1;
        for (p1 = p + 1; *p1 != '\0'; p1++)
        {
            int flag = 0;
            for (int i = 1; i <= p1 - p; i++)
            {
                flag = *p1 - *(p1 - i);
                if (flag == 0)
                    break;
            }
            if (flag)
                count++;
            else
                break;
        }
        if (count > len)
            len = count;
        p++;
    }
    return len;
}
int main()
{
    char* s = "abcabcbb";
    printf("%d", lengthOfLongestSubstring(s));
}