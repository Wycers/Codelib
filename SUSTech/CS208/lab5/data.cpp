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
    int T = rand() % 50 + 50;
    printf("%d\n", T);
    while (T--)
    {
        long long x = 1LL * rand() * rand();
        long long y = 1LL * rand() * rand();
        long long n = 1LL * rand() * rand();
        printf("%I64d %I64d %I64d\n", n % 1000000000, x % 1000000000, y % 1000000000);
        // long long x = 1LL * rand();
        // long long y = 1LL * rand();
        // long long n = 1LL * rand();
        // printf("%I64d %I64d %I64d\n", n % 1000000000, x % 1000000000, y % 1000000000);
    }
    return 0;
}