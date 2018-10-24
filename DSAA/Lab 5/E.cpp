#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 5e5 + 10;
string a, b;
int n, m, nx[N];
void getnext()
{
    nx[0] = -1;
    for (int i = 0, j = -1; i < n; )
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
    for (int i = 0; i < m; )
    {
        if (res == -1 || b[i] == a[res])
            ++i, ++res;
        else
            res = nx[res];
    }
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
        getnext();
        kmp();
    }
    return 0;
}