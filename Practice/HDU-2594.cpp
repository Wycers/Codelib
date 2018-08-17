#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 5e4 + 10;

string a, b;
int nx[N];
void getnext()
{
    nx[0] = -1;
    for (int i = 0, j = -1, len = a.length(); i < len; )
    {
        if (j == -1 || a[i] == a[j])
            nx[++i] = ++j;
        else
            j = nx[j];
    } 
}

void kmp()
{
    int res = 0;
    for (int i = 0, len = b.length(); i < len; )
    {
        if (res == -1 || b[i] == a[res])
            ++i, ++res;
        else
            res = nx[res];
    }
    for (int i = 0; i < res; ++i)
        printf("%c", a[i]);
    if (res)
        printf(" ");
    printf("%d\n", res);
}

int main()
{
    while (cin >> a >> b)
    {
        getnext();
        kmp();
    }
    return 0;
}