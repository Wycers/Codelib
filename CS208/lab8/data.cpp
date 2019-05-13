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
    int n = 100000;
    printf("%d %d\n", n, 81727);
    for (int i = 0; i < n; ++i)
        printf("%d ", rand());
    return 0;
}