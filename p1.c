#include<stdio.h>
//1.n的阶乘
int main()
{
    int i,n,mul = 1;
    scanf("%d",&n);
    for(i = 1;i<=n;i++)
    {
        mul *= i;
    }
    printf("%d",mul);
    return 0;
}
