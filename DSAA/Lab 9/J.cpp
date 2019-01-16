#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
struct Edge {
    int to, next, w;
} edge[N];
int head[N], cnt = 0;
void insert(int u, int v) 
{
    edge[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
}
int n, to[N], w[N], vis[N], wolf[N], fa[N];
int set(int now)
{
    if (wolf[now] == 1)
        return 0;
    wolf[now] = 1;
    int res = 1;
    for (int i = head[now]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        res += set(v);
    }
    return res;
}
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void solve()
{
    memset(head, 0, sizeof head);
    cnt = 0;
    char str[8];
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%s", to + i, str);
        w[i] = str[0] == 'w' ? 1 : 0;
        if (str[0] == 'v')
        {
            insert(to[i], i);
            fa[find(to[i])] = find(i);
        }
    }
    memset(vis, 0, sizeof vis);
    memset(wolf, 0, sizeof wolf);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (w[i] == 1 && find(i) == find(to[i]))
            ans += set(to[i]);
    printf("%d\n", ans);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}