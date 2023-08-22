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
    int n = 5;
    printf("%d\n", n);
    for (int i = 0; i < n; ++i)
    {
        int a = rand() % 10;
        int b = rand() % 10;
        printf("%d %d\n", a, a + b > 100 ? 100 : a + b);
    }
    return 0;
}
