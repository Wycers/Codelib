#include <cstdio>
#include <cmath>
#include <cstring>
const int N = 35;
int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || '9' < ch)
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

int n, m;
char c[N][N];
char opt[1005];
int angle[1005];
void solve() 
{
    int n, m;
    n = read(); m = read();
    for (int i = 0; i < n; ++i)
        scanf("%s", c[i]);
    scanf("%s", opt);
    int len = strlen(opt);
    angle[0] = opt[0] == 'L' ? -1 : 1; 
    for (int i = 1; i < len; ++i)
        angle[i] = angle[i - 1] + (opt[i] == 'L' ? -1 : 1);
    int cnt = angle[len - 1] % 4;
    if (cnt == 0)
    {
        printf("%d %d\n", n, m);
        for (int i = 0; i < n; ++i)
            printf("%s\n", c[i]);
        return;
    }
    if (cnt % 2 == 0)
    {
        printf("%d %d\n", n, m);
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = m - 1; j >= 0; --j)
                printf("%c", c[i][j]);
            printf("\n");
        }
        return;
    }
    
    if (cnt < 0)
        while (cnt < -2)
            cnt += 4;
    if (cnt > 0)
        while (cnt > 2)
            cnt -= 4;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (c[i][j] == '-')
                c[i][j] = '|';
            else if (c[i][j] == '|')
                c[i][j] = '-';

    if (cnt == -1)
    {
        printf("%d %d\n", m, n);
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = 0; j < n; ++j)
                printf("%c", c[j][i]);
            printf("\n");
        }
        return;
    }
    if (cnt == 1)
    {
        printf("%d %d\n", m, n);
        for (int i = 0; i < m; ++i)
        {
            for (int j = n - 1; j >= 0; --j)
                printf("%c", c[j][i]);
            printf("\n");
        }
        return;
    }
}

int main()
{
    for (int T = read(); T; T--) 
    {
        solve();
        printf("\n");
    }
    return 0;
}