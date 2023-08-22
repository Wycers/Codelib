#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#define Clr(x) memset(x,0x00,sizeof(x))
using namespace std;
const int N = 1e5 + 10;

int n, to[N], dfn[N], sz[N], cnt;
bool vis[N];
void dfs(int u)
{
    vis[u] = true;
    if (vis[to[u]])
    {
        sz[++cnt] = dfn[u] - dfn[to[u]] + 1;
        return;
    }
    dfn[to[u]] = dfn[u] + 1;
    dfs(to[u]);
}
long long getans()
{
    sort(sz + 1, sz + cnt + 1);
    
    sz[cnt - 1] += sz[cnt];
    long long res = 0;
    for (int i = 1, t = max(cnt - 1, 1); i <= t; ++i)
        res += 1ll * sz[i] * sz[i];
    return res;
}
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", to + i);

    cnt = 0;
    Clr(sz); Clr(dfn); Clr(vis);
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            dfs(i);
    
    printf("%lld\n", getans());
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}
