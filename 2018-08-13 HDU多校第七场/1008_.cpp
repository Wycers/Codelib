#include <cstdio>
#include <algorithm>
#include <cstring>
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n, q, s;
int fa[N], dep[N], siz[N], son[N], top[N], w[N];
int num, cnt, head[N];

inline int read()
{
    int x = 0; bool f = true; char c;
    for (f = 0; (c = getchar()) < '0' || c > '9'; f = c == '-');
    for (x = c ^ '0'; (c = getchar()) >= '0' && c <= '9'; x = (x << 1) + (x << 3) + (c ^ '0'));
    return f ? -x : x;
}

struct Edge
{
    int to, next;
} edge[N];
struct E
{
    int u, v, c;
} e[N];
void addedge(int u, int v)
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void dfs(int u)
{
    siz[u] = 1; son[u] = 0;
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa[u])
            continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        dfs(v);
        if (siz[v] > siz[son[u]])
            son[u] = v;
        siz[u] += siz[v];
    }
}
void build_tree(int u, int tp)
{
    w[u] = ++num;
    top[u] = tp;
    if (son[u])
        build_tree(son[u], top[u]);
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v != son[u] && v != fa[u])
            build_tree(v, v);
    }
}
ll sum[N << 2];
void pushUp(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void build(int l, int r, int rt)
{
    sum[rt] = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
}
void update(int p, int c, int l, int r, int rt)
{
    if (l == r)
    {
        sum[rt] = c;
        return;
    }
    int mid = (l + r) >> 1;
    if (mid >= p)
        update(p, c, lson);
    else
        update(p, c, rson);
    pushUp(rt);
}
ll query(int L, int R, int l, int r, int rt)
{
    if (L <= l && R >= r)
        return sum[rt];
    int mid = (l + r) >> 1;
    ll res = 0;
    if (mid >= L)
        res += query(L, R, lson);
    if (mid < R)
        res += query(L, R, rson);
    return res;
}
void change(int v, int c)
{
    if (dep[e[v].u] > dep[e[v].v])
        update(w[e[v].u], c, 1, n, 1);
    else
        update(w[e[v].v], c, 1, n, 1);
}
ll find(int v, int u)
{
    int t1 = top[v], t2 = top[u];
    ll res = 0;
    while (t1 != t2)
    {
        if (dep[t1] < dep[t2])
        {
            swap(t1, t2);
            swap(v, u);
        }
        res += query(w[t1], w[v], 1, n, 1);
        v = fa[t1];
        t1 = top[v];
    }
    if (v == u)
        return res;
    if (dep[v] > dep[u])
        swap(v, u);
    return res + query(w[son[v]], w[u], 1, n, 1);
}
int father[N], tag;
int getfa(int x)
{
    return father[x] == x ? x : father[x] = getfa(father[x]);
}
void solve()
{
    memset(head, -1, sizeof head);
    cnt = num = 0;
    n = read(); q = read();
    for (int i = 1; i <= n; ++i)
        father[i] = i;
    for (int i = 1; i <= n; i++)
    {
        e[i].u = read(); e[i].v = read(); e[i].c = read();
        int fu = getfa(e[i].u), fv = getfa(e[i].v);
        if (fu != fv)
        {
            father[fu] = fv;
            addedge(e[i].u, e[i].v);
            addedge(e[i].v, e[i].u);
        }
        else
            tag = i;
    }
    dfs(1);
    build_tree(1, 1);
    build(1, n, 1);
    for (int i = 1; i <= n; i++)
    {
        if (tag == i)
            continue;
        if (dep[e[i].u] > dep[e[i].v])
            update(w[e[i].u], e[i].c, 1, n, 1);
        else
            update(w[e[i].v], e[i].c, 1, n, 1);
    }
    while (q--)
    {
        int opt, x, y;
        opt = read(); x = read(); y = read();
        if (opt == 0)
        {
            if (x == tag)
                e[x].c = y;
            else
                change(x, y);
        }
        else
        {
            long long ans = 0x3f3f3f3f3f3f3f3f;
            ans = min(ans, find(x, y));
            ans = min(ans, find(x, e[tag].u) + find(e[tag].v, y) + 1ll * e[tag].c);
            ans = min(ans, find(x, e[tag].v) + find(e[tag].u, y) + 1ll * e[tag].c);
            printf("%lld\n", ans);
        }
    }
}
int main()
{
    for (int T = read(); T; --T)
        solve();
    return 0;
}