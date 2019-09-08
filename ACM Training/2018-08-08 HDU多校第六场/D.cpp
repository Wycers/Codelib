#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 610;
int n, L[N], R[N], H[N], W[N], li[N], ri[N];

struct P
{
    int x, y;
    P () {}
    P(int x, int y) : x(x), y(y) {}
    bool operator == (const P &b) const 
    {
        return 1ll * x * b.y - 1ll * y * b.x == 0;
    }
    bool operator < (const P &b) const 
    {
        return 1ll * x * b.y - 1ll * y * b.x < 0;
    }
} p[N];
long long dp[N][N];
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d%d%d", H + i, L + i, R + i, W + i);
    for (int i = 1; i <= n; ++i)
    {
        p[i] = P(L[i], H[i]);
        p[i + n] = P(R[i], H[i]);
    }
    sort(p + 1, p + 2 * n + 1);
    int cnt = unique(p + 1, p + 2 * n + 1) - p - 1;
    for (int i = 1; i <= n; ++i)
    {
        li[i] = lower_bound(p + 1, p + cnt + 1, P(L[i], H[i])) - p;
        ri[i] = lower_bound(p + 1, p + cnt + 1, P(R[i], H[i])) - p;
    }
    for (int len = 1; len <= cnt; ++len)
        for (int l = 1; l + len - 1 <= cnt; ++l)
        {
            int r = l + len - 1;
            dp[l][r] = (1ll << 60);
            int mx = -1, tag;
            for (int i = 1; i <= n; ++i)
                if (l <= li[i] && ri[i] <= r && W[i] > mx)
                {
                    mx = W[i];
                    tag = i;
                }
            if (mx == -1)
                dp[l][r] = 0;
            else
                for (int i = li[tag]; i <= ri[tag]; ++i)
                    dp[l][r] = min(dp[l][r], dp[l][i - 1] + dp[i + 1][r] + mx);
        }
    printf("%lld\n", dp[1][cnt]);
}

int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}