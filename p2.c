#include <stdio.h>
#include <stdlib.h>

//2. 1!+2!+...+10!
int main()
{
    int i,j,mul = 1;
    int sum = 0;
    for(i=1;i<=10;i++)
    {
        mul = 1;
        for(j = 1;j<=i;j++)
        {
            mul *= j;
        }
        sum += mul;
    }
    printf("%d",sum);
    return 0;
}
