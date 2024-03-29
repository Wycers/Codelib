#include <cstdio>
#include <cmath>
const int N = 1e5 + 10;
const int Inf = 0x3f3f3f3f;
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

int n, a[N];
void solve()
{
    int n = read(), min = Inf;
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    for (int i = 1; i <= n; ++i)
        min = a[i] < min ? a[i] : min;
    long long s = 0;
    for (int i = 1; i <= n; ++i)
        s += a[i] - min;
    printf("%lld %lld\n", s, min + s);
}
int main()
{
    for (int T = read(); T; T--)
        solve();
    return 0;
}