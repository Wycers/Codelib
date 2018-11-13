#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
struct Edge
{
    int to, next;
} edge[N];
int head[N], cnt;
void insert(int u, int v)
{
    edge[++cnt] = { v, head[u]};
    head[u] = cnt;
}
int n, d, tag;
void dfs(int now, int fa, int dis)
{
    if (dis > d)
    {
        tag = now;
        d = dis;
    }
    for (int i = head[now]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (fa == v)
            continue;
        dfs(v, now, dis + 1);
    }
}
void solve()
{
    memset(head, 0, sizeof head);
    cnt = 0;

    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        insert(u, v);
        insert(v, u);
    }
    d = 0; tag = 1;
    dfs(1, 0, 0);
    d = 0;
    dfs(tag, 0, 0);
    printf("%d\n", d);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}