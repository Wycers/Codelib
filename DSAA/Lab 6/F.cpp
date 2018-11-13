#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
struct Edge
{
    int to, next;
} edge[N];
int head[N], cnt = 0;
void insert(int u, int v)
{
    edge[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
}
int c[N], ct[N], dep;
void dfs(int now, int fa, int k)
{
    if (c[now] == 1)
        ++ct[k];
    if (k > dep)
        dep = k;
    for (int i = head[now]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa)
            continue;
        dfs(v, now, k + 1);
    }
}
void solve()
{
    memset(head, 0, sizeof head); cnt = 0;
    memset(ct, 0, sizeof ct); dep = 0;
    int n; 
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", c + i);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        insert(u, v);
        insert(v, u);
    }
    dfs(1, 0, 1);
    bool ans = false;
    for (int i = 1; i <= dep; ++i)
        if (ct[i] & 1)
            ans = true;
    puts(ans ? "YES" : "NO");
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}