#include <bits/stdc++.h>
using namespace std;
const int N = 25;
int n, pre[N]; 
long long a[N], b[N], res[2000000];
void dfs(int t, int now, long long w)
{
    if (w <= res[now])
        return;
    res[now] = w;
    for (int i = 1; i <= n; ++i)
    {
        if (now & (1 << (i - 1)))
            continue;
        if ((pre[i] & now) != pre[i])
            continue;
        dfs(t + 1, now | (1 << (i - 1)), w + a[i] * 1ll * t + b[i]);
    }       
}

int main()
{
    scanf("%d", &n);
    memset(pre, 0, sizeof pre);
    for (int i = 1, t; i <= n; ++i)
    {
        scanf("%lld%lld%d", a + i, b + i, &t);
        for (int j = 1, tmp; j <= t; ++j)
        {
            scanf("%d", &tmp);
            pre[i] |= (1 << (tmp - 1));
        }
    }
    memset(res, -1, sizeof res);
    dfs(1, 0, 0);
    long long ans = 0;
    for (int i = 1; i <= (1 << n) - 1; ++i)
        ans = max(ans, res[i]);
    printf("%lld\n", ans);
    return 0;
}