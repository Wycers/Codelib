#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 510;
const int P = 998244353;
int n, a[N][N], d[N][N];
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            d[i][j] = 0x3f3f3f3f;
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                d[i][j] = min(d[i][j], a[i][k] + a[k][j]);
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            printf("%d ", d[i][j]);
        puts("");
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = j + 1; k <= n; ++k)
            {
                if (i == j || i == k || j == k)
                    continue;
                ans += (d[j][k] << 1) + a[i][j] + a[i][k];
                printf("%d\n", (d[j][k] << 1) + a[i][j] + a[i][k]);
                ans %= P;
            }
    printf("%lld\n", ans >> 1);
}
int main()
{
    freopen("test.in", "r", stdin);
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}