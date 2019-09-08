#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 2e5 + 10;
const double eps = 1e-8;
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

int n, a[N], b[N];
void readin()
{
    n = read();
    for (int i = 1; i <= n; ++i)
    {
        a[i] = read();
        b[i] = read();
    }
}
int t[N], f[N], g[N], s[N];
void solve()
{
    int ans1, ans2;
    for (int i = 1; i <= n; ++i)
    {
        ++t[a[i]];
        --t[b[i]];
        f[a[i]]++;
        g[b[i]]++;
    }

    for(int i = 1; i <= 1e5; ++i)
        f[i] += f[i - 1], g[i] += g[i - 1];
    ans1 = 0;
    for (int i = 1; i <= 1e5; ++i)
        ans1 = max(ans1, f[b[i] - 1] - g[a[i]]);

    s[1] = t[1];
    for (int i = 2; i <= 1e5; ++i)
        s[i] = s[i - 1] + t[i];

    ans2 = 0;
    for (int i = 1; i <= 1e5; ++i)
        ans2 = max(ans2, s[i]);
    printf("%d %d\n", ans1, ans2);
}
int main()
{
    readin();
    solve();
    return 0;
}
