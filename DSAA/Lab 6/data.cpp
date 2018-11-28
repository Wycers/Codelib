#include <cstdio>
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
    srand(time(0));
    int n = 2500;
    if (n & 1)
        --n;
	// int m = rand() % n + 1; 
    int m = 1025;
    printf("1\n%d %d\n", m,  n);
    n >>= 1;
    for (int i = 1; i <= n; ++i)
        printf("%d ", i);
    for (int i = 1; i <= n; ++i)
        printf("%d ", i);
    
    // int n = 2000;
	// int m = 1025;
    // printf("1\n%d %d\n", m,  n);
    // for (int i = 1; i <= n; ++i)
    // {
    //     int now = rand() % 5 + 1;
    //     printf("%d ", now);
    // }
    puts("");
    return 0;
}