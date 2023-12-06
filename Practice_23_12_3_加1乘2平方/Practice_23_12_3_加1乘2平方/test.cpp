#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

queue <int> q1;
int count1;
int arr[10001];

void bfs(int m, int n)
{
    if (m == n)
    {
        return;
    }
    count1++;
    int size = q1.size();
    while (size--)
    {
        int num = q1.front();
        q1.pop();
        if (num + 1 == n)
        {
            q1.push(n);
            return;
        }
        else
        {
            if (arr[num + 1] == 0)
            {
                q1.push(num + 1);
                arr[num + 1] = 1;
            }
        }
        if (q1.back() == n)
            return;
        if (num * 2 == n)
        {
            q1.push(n);
            return;
        }
        else
        {
            if (num * 2 < n && arr[num * 2] == 0)
            {
                q1.push(num * 2);
                arr[num * 2] = 1;
            }
        }
        if (q1.back() == n)
            return;
        if (num * num == n)
        {
            q1.push(n);
            return;
        }
        else
        {
            if (num * num < n && arr[num * num] == 0)
            {
                q1.push(num * num);
                arr[num * num] = 1;
            }
        }
        if (q1.back() == n)
            return;
    }
    bfs(m, n);
}

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    q1.push(m);
    bfs(m, n);
    printf("%d", count1);
    return 0;
}
