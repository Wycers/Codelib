#include <cstdio>
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
    srand(time(0));
	int n = 2;
    puts("2");
    printf("%d\n", n);
    for (int j = 1; j <= 1; ++j)
    {
        for (int i = 1; i <= n; ++i)
            printf("%c", 'a');
        puts("");
    }
    printf("%d\n", n);
    for (int j = 1; j <= 1; ++j)
    {

        for (int i = 1; i <= n; ++i)
            printf("%c", 'a');
        puts("");
    }
    return 0;
}