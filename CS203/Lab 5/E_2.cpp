#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e6 + 10;
string a, b, c;
int n, m, nx[N];
void getnext()
{
    nx[0] = -1;
    for (int i = 0, j = -1, len = c.length(); i < len; )
    {
        if (j == -1 || c[i] == c[j])
            nx[++i] = ++j;
        else
            j = nx[j];
    }
}

void kmp()
{
    int res = nx[c.length()];
    while (res > n || res > m)
        res = nx[res];
    printf("%d", res);
    if (res)
        printf(" ");
    for (int i = 0; i < res; ++i)
        printf("%c", a[i]);
    puts("");
}

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        cin >> n >> m;
        cin >> a >> b;
        c = a + b;
        getnext();
        kmp();
    }
    return 0;
}