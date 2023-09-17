#define _CRT_SECURE_NO_WARNINGS 
#include<limits.h>
//int reverse(int x) {
//    int arr[10];
//    int i = 0;
//    while (x != 0)
//    {
//        arr[i] = x % 10;
//        x = x / 10;
//        ++i;
//    }
//    int sum = 0;
//    if (i == 10 && arr[9] > 2)
//        return 0;
//    else
//    {
//        for (int j = 0; j < i; j++)
//        {
//            sum += arr[j];
//            sum *= 10;
//        }
//        sum /= 10;
//        return sum;
//    }
//}
int reverse(int x) {
    int i = 0;
    while (x) {
        if (i < INT_MIN / 10 || i> INT_MAX / 10) { //注意，循环的过程中就要判断是否会溢出
            return 0;
        }
        i = i * 10 + x % 10;
        x = x / 10;
    }
    return i;
}
int main()
{
    reverse(2147483602);
    return 0;
}