#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 510;
const int P = 998244353;
int n, a[N][N], d[N][N], g[N][N], tag[N][N];
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &a[i][j]);
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            tag[i][j] = tag[j][i] = ++cnt;
    for (int i = 1; i <= cnt; ++i)
        for (int j = 1; j <= cnt; ++j)
            g[i][j] = 0x3f3f3f3f;
    for (int i = 1; i <= cnt; ++i)
        g[i][i] = 0;
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                if (i == j || i == k || j == k)
                    continue;
                g[tag[i][k]][tag[k][j]] = a[i][k] + a[k][j];
            }
    for (int i = 1; i <= cnt; ++i)
    {
        for (int j = 1; j <= cnt; ++j)
            printf("%d\t", g[i][j] == 0x3f3f3f3f ? 0 : g[i][j]);
        puts("");
    }
    for (int i = 1; i <= cnt; ++i)
        for (int j = 1; j <= cnt; ++j)
            d[i][j] = 0x3f3f3f3f;
    for (int k = 1; k <= cnt; ++k)
        for (int i = 1; i <= cnt; ++i)
            for (int j = 1; j <= cnt; ++j)
                d[i][j] = min(d[i][j], g[i][k] + g[k][j]);
    for (int i = 1; i <= cnt; ++i)
    {
        for (int j = 1; j <= cnt; ++j)
            printf("%d ", d[i][j]);
        puts("");
    }
    long long s = 0;
    for (int i = 1; i <= cnt; ++i)
        for (int j = i + 1; j <= cnt; ++j)
            s += d[i][j];
    cout << s << endl;
}
int main()
{
    freopen("test.in", "r", stdin);
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}