#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#include "local_debug.h"
#else
#define debug(...)
#endif
#define pb push_back
#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define per(i, a, n) for (int i = (n)-1; i >= (a); --i)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
const ll mod = 998244353;

ll dist[505][505], a[505][505];
ll ans[505];
signed main()
{
    freopen("test.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%lld", &a[i][j]);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = a[i][j];
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    {
                        if (dist[i][j] > dist[i][k] + dist[k][j])
                            dist[i][j] = dist[i][k] + dist[k][j];
                    }
        ll ret = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    ans[k] = min(dist[i][k], dist[j][k]);
                }
                sort(ans + 1, ans + n + 1);
                for (int k = 1; k <= n; k++)
                    ret += ans[k] * (n - k) % mod;
            }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                ret += a[i][j] * (n * (n - 1) / 2 - 1) % mod;
            }
        }
        printf("%lld\n", ret % mod);
    }
    return 0;
}