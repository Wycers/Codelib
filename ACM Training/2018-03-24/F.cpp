#include <cstdio>
#include <cmath>
#define eps 1e-15
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

void solve() 
{
    int n = read(), ans = 1;
    for (int i = 2; i <= n; ++i) 
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {   
                ++cnt;
                n /= i;
            }
            ans *= (2 * cnt + 1);
            if (n == 1)
                break;
        }
    printf("%d\n", (ans + 1) / 2);
}

int main()
{
    for (int T = read(); T; T--)
        solve();
    return 0;
}