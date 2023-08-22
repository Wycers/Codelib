#include <cstdio>
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
    srand(time(0));
    int n = 10, m = rand() % n + 1;
    printf("2\n");
    printf("%d %d\n", n, m);
    for (int i = 1; i <= n; ++i)
        printf("%d ", rand() + 1);
    puts("");m = rand() % n + 1;
    printf("%d %d\n", n, m);
    for (int i = 1; i <= n; ++i)
        printf("%d ", rand() + 1);
    puts("");
    return 0;
}