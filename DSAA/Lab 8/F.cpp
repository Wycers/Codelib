#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
const int M = 2e5 + 10;
struct Edge
{
    int to, next, w;
} edge[M];
int head[N], d[N], cnt = 0;
void insert(int u, int v, int w)
{
    edge[++cnt] = (Edge){v, head[u], w};
    head[u] = cnt;
}
long long dis[N];
long long dfs(int now)
{
    if (dis[now] != -1)
        return dis[now];
    long long res = 0;
    for (int i = head[now]; i; i = edge[i].next)
        res = max(res, dfs(edge[i].to) + edge[i].w);
    return dis[now] = res;
}
void solve()
{
    memset(head, 0, sizeof head);
    memset(d, 0, sizeof d);
    memset(dis, -1, sizeof dis);
    cnt = 0;

    int n, m;
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        insert(x, y, z);
        ++d[y];
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i)
        if (d[i] == 0)
            ans = max(ans, dfs(i));
    printf("%lld\n", ans);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}