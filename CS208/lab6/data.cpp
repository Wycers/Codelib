#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <ctime>
using namespace std;
int main()
{
    srand(time(0));
    int T = 5;
    printf("%d\n", T);
    while (T--)
    {
        int n = rand() % 100 + 1;
        printf("%d\n", n);
        for (int i = 1; i <= n; ++i)
            printf("%d ", rand() % n + 1);
    }
    return 0;
}