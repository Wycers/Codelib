#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2e3 + 10;
long long read()
{
    long long x = 0, f = 1; char ch = getchar();
    while (ch < '0' || '9' < ch) { if (ch == '-') f = -1; ch = getchar(); }
    while ('0' <= ch && ch <= '9') { x = x * 10 + ch - 48; ch = getchar(); }
    return x * f;
}

int n, m, a, b, c, s1[N], s2[N];
long long f[N][N], sa[N], sb[N], ans;
long long dfs(int i, int j)
{
    if (f[i][j] != -1)
        return f[i][j];
    long long temp = c - sa[i] - sb[j], res = -1;
    if (temp <= 0)
        return -1;
    if (i - 1 >= 0)
        res = max(res, dfs(i - 1, j) + temp * a);
    if (j - 1 >= 0)
        res = max(res, dfs(i, j - 1) + temp * b);
    return (f[i][j] = res);
}
void solve()
{
    a = read(); b = read(); c = read();
    n = read(); m = read();
    ans = 0;

    for (int i = 1; i <= n; ++i)
        s1[i] = read();
    for (int i = 1; i <= m; ++i)
        s2[i] = read();
    sort(s1 + 1, s1 + n + 1);
    sort(s2 + 1, s2 + m + 1);

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            f[i][j] = -1;
    f[0][0] = 0;
    sa[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        sa[i] = sa[i - 1] + s1[i];
        f[i][0] = f[i - 1][0] + (c - sa[i]) * a;
    }

    sb[0] = 0;
    for (int i = 1; i <= m; i++)
    {
        sb[i] = sb[i - 1] + s2[i];
        f[0][i] = f[0][i - 1] + (c - sb[i]) * b;
    }

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            ans = max(ans, dfs(n, m));
    printf("%lld\n", ans);
}
int main()
{
    for (int T = read(); T; --T)
        solve();
    return 0;
}