#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
const int M = 4e5 + 10;
int fa[N], siz[N];
int find(int x) 
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
struct Edge
{
    int to, next, w;
} edge[M];
int head[N], cnt = 0;
void insert(int u, int v, int w)
{
    edge[++cnt] = (Edge){v, head[u], w};
    head[u] = cnt;
}
struct Data
{
    int u, v, w;
};
inline bool cmp(const Data &a, const Data &b)
{
    return a.w > b.w;
}
vector<Data> vp;
int f[N], wf[N], dep[N], tot;
bool vis[N];
void dfs(int x)
{
    vis[x] = true; dep[x] = ++tot;
    for (int i = head[x]; i; i = edge[i].next)
    {
        int v = edge[i].to, w = edge[i].w;
        if (v == f[x])
            continue;
        if (vis[v] && dep[v] > dep[x])
            continue;
        if (vis[v] == false)
        {
            f[v] = x;
            wf[v] = w;
            dfs(v);
            continue;
        }
        
        int mn = w;
        for (int t = x; t != v; t = f[t])
            mn = min(mn, wf[t]);

        bool flag = true;
        if (w == mn)
            flag = false;
        else
            vp.push_back({x, v, w + mn});
        for (int t = x; t != v; t = f[t])
        {
            if (flag && wf[t] == mn)
                flag = false;
            else
                vp.push_back({t, f[t], wf[t] + mn});
            wf[t] = -1;
        }
    }
}
void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);

    memset(head, 0, sizeof head);
    cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        insert(u, v, w);
        insert(v, u, w);
    }

    vp.clear();
    memset(vis, false, sizeof(vis));
    memset(wf, -1, sizeof(wf));
    tot = 0;
    dfs(1);
    for (int i = 1; i <= n; i++)
        if (wf[i] != -1)
            vp.push_back({i, f[i], wf[i]});
    sort(vp.begin(), vp.end(), cmp);
    
    for (int i = 1; i <= n; i++)
        fa[i] = i, siz[i] = 1;
        
    unsigned long long ans = 0;
    for (auto &e : vp)
    {
        int fx = find(e.u), fy = find(e.v);
        ans += 1ull * e.w * siz[fx] * siz[fy];
        siz[fx] += siz[fy];
        fa[fy] = fx;
    }
    printf("%llu\n", ans);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}