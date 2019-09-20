#include <cstdio>
#include<iostream>
#include<ctime>
#include <algorithm>
#include <cstring>
#include<cstdlib>
#include <queue>
using namespace std;
const int N = 2e5 + 10;
int main()
{
    srand(time(0));
	int T = 2;
    printf("%d\n", T);
    int n;
    for (int t = 1; t <= T; ++t)
    {
        n = rand() % 100000 + 1;
        printf("%d\n", n);
        for (int i = 1; i <= n; ++i)
            printf("%d %s\n", rand() % n + 1, rand() & 1 ? "w" : "v");
    }
    puts("");
    return 0;
}