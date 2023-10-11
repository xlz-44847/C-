#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int* arr1 = (int*)malloc(sizeof(int) * n);
    int* arr2 = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]);
    }
    int* arr3 = (int*)malloc((sizeof(int)) * (n + m));
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            arr3[k] = arr2[j];
            j++;
            k++;
        }
    }
    if (i == n)
    {
        for (; k < n + m; k++, j++)
        {
            arr3[k] = arr2[i];
        }
    }
    else {
        for (; k < n + m; k++, i++)
        {
            arr3[k] = arr1[j];
        }
    }
    for (k = 0; k < n + m; k++)
    {
        printf("%d ", arr3[k]);
    }
    free(arr1);
    free(arr2);
    free(arr3);
    return 0;
}