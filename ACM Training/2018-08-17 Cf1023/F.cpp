#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x; char c;
    while ((c = getchar()) < '0' || c > '9');
    for (x = c - '0'; (c = getchar()) >= '0' && c <= '9';)
        x = x * 10 + c - '0';
    return x;
}
const int N = 5e5 + 10;
struct Edge
{
    int to, next, w;
} edge[N << 1];
int head[N], cnt = 0;
void insert(int u, int v, int w)
{
    edge[++cnt] = (Edge){v, head[u], w};
    head[u] = cnt;
}

int n, k, m, fa[N], u[N], v[N], w[N], t[N], dep[N], res[N], f[N];
int get(int x)
{
    return f[x] ? f[x] = get(f[x]) : x;
}
void dfs(int u)
{
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa[u])
            continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        t[v] = edge[i].w;
        dfs(v);
    }
}
void ins(int u, int v, int w)
{
    f[get(u)] = get(v);
    insert(u, v, w);
    insert(v, u, w);
}
int main()
{
    n = read(); k = read(); m = read();
    for (int i = 1; i <= k; ++i)
        ins(read(), read(), 1);
    for (int i = 1; i <= m; ++i)
    {
        u[i] = read(); v[i] = read(); w[i] = read();
        if (get(u[i]) != get(v[i]))
            ins(u[i], v[i], 0);
    }
    dfs(1);
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= m; ++i)
    {
        u[i] = get(u[i]);
        v[i] = get(v[i]);
        while (u[i] != v[i])
        {
            if (dep[u[i]] < dep[v[i]])
                swap(u[i], v[i]);
            res[u[i]] = w[i];
            f[u[i]] = fa[u[i]];
            u[i] = get(u[i]);
        }
    }
    long long ans = 0;
    for (int i = 2; i <= n; ++i)
        if (t[i])
            if (res[i])
                ans += res[i];
            else
                return 0 * puts("-1");
    cout << ans << endl;
    return 0;
}
