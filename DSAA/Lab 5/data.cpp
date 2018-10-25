#include <cstdio>
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
    srand(time(0));
	int n = 4, c = 2;
    printf("%d\n", n);
    for (int j = 1; j <= n; ++j)
    {
        for (int i = 1, len = rand() % 5 + 1; i <= len; ++i)
            printf("%c", 'a' + rand() % c);
        puts("");
    }
    for (int i = 1; i <= 5; ++i)
    {
        int now = rand() % (c + 1);
        if (now == c)
            printf("%c", '-');
        else    
            printf("%c", 'a' + now);
    }
    puts("");
    return 0;
}