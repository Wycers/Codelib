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
    int n = 4;
    printf("%d 3\n", n);
    for (int i = 0; i < n; ++i)
    {
        long long a = 1ll * rand() * rand() * rand() % 100;
        long long b = 1ll * rand() * rand() * rand() % 100;
        long long c = 1ll * rand() * rand() * rand() % 100;
        printf("%I64d %I64d %I64d\n", a, b, c);
    }
    return 0;
}