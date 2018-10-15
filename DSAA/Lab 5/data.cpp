#include <cstdio>
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
    srand(time(0));
	int n = 10;
    puts("2");
    printf("%d\n", n);
    for (int j = 1; j <= n; ++j)
    {

        for (int i = 1; i <= n; ++i)
            printf("%c", rand() % 2 + 'a');
        puts("");
    }
    printf("%d\n", n);
    for (int j = 1; j <= n; ++j)
    {

        for (int i = 1; i <= n; ++i)
            printf("%c", rand() % 2 + 'a');
        puts("");
    }
    return 0;
}