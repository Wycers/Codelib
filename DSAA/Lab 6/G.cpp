#include <cstdio>
#include <cstring>
#include <algorithm>
#pragma comment(linker,"/STACK:1024000000,1024000000")
using namespace std;
const int N = 2e5 + 10;
struct Edge
{
    int to, next;
} edge[N];
int head[N], cnt = 0;
int w[N], ct[N];
void insert(int u, int v)
{
    edge[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
}
int dfs(int now)
{
    if (ct[now])
        return ct[now];
    ct[now] = 1;
    for (int i = head[now]; i; i = edge[i].next)
        ct[now] += dfs(edge[i].to);
    return ct[now];
}
void solve()
{
    memset(head, 0, sizeof head); cnt = 0;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)    
        scanf("%d", w + i);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        if (w[u] == w[v])
            continue;
        if (w[u] > w[v])
            insert(v, u);
        else 
            insert(u, v);
    }

    memset(ct, 0, sizeof ct);
    int ans = 1;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, dfs(i));
    printf("%d\n", ans);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}