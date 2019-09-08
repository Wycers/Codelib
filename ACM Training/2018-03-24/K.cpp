#include <cstdio>
#include <cstring>
const int N = 1e5 + 10;
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

int n;
char s[N];
void solve()
{
    int n = read();
    scanf("%s", s);
    if (n == 1) {
        printf("%s\n", s);
        return;
    }
    int len = strlen(s);
    for (int j = 0; j < len; j += 2 * n - 2)
        printf("%c", s[j]);
    for (int i = 1; i < n; ++i) 
        for (int j = 0; j < len; j += 2 * n - 2)
            if (j + i < len) 
            {
                printf("%c", s[j + i]);
                if (i < n - 1 && j + 2 * n - 2 - i < len)
                    printf("%c", s[j + 2 * n - 2 - i]);
            }
    printf("\n");
}
int main()
{
    for (int T = read(); T; T--)
        solve();
    return 0;
}