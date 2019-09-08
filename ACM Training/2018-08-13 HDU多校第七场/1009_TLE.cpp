#include <iostream>
#include <cstdio>
#include <cstring>
const int N = 200005;
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int n, m;
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
int deep[N],Fa[N][20];
bool vis[N];
void Dfs(int now)
{
    vis[now] = true;
    for (int i=1;i<20;i++)
    {
        if (deep[now] < (1 << i))
            break;
        Fa[now][i] = Fa[Fa[now][i - 1]][i - 1];
    }
    int v;
    for (int i=head[now];i;i=edge[i].next)
    {
        v = edge[i].to;
        if (!vis[v])
        {
            deep[v] = deep[now] + 1;
            Fa[v][0] = now;
            Dfs(v);
        }
    }
}
int get(int x, int k)
{
    int res = x;
    for (int i = 0; i < 19; ++i)
        if (k & (1 << i))
        {
            if (res == 1)
                return n + 1;
            res = Fa[res][i];
        }
    return res;
}


int nxt[N], c[N][2], fa[N], sz[N], st[N];
bool rev[N];
inline bool isroot(int k)
{
    return c[fa[k]][0] != k && c[fa[k]][1] != k;
}
inline void pushup(int x)
{
    sz[x] = sz[c[x][0]] + sz[c[x][1]] + 1;
}
void pushdown(int k)
{
    int l = c[k][0], r = c[k][1];
    if (rev[k])
    {
        rev[k] ^= 1;
        rev[l] ^= 1;
        rev[r] ^= 1;
        swap(c[k][0], c[k][1]);
    }
}
void rotate(int x)
{
    int y = fa[x], z = fa[y], l, r;
    if (c[y][0] == x)
        l = 0;
    else
        l = 1;
    r = l ^ 1;
    if (!isroot(y))
    {
        if (c[z][0] == y)
            c[z][0] = x;
        else
            c[z][1] = x;
    }
    fa[x] = z;
    fa[y] = x;
    fa[c[x][r]] = y;
    c[y][l] = c[x][r];
    c[x][r] = y;
    pushup(y);
    pushup(x);
}
void splay(int x)
{
    int top = 0;
    st[++top] = x;
    for (int i = x; !isroot(i); i = fa[i])
    {
        st[++top] = fa[i];
    }
    for (int i = top; i; i--)
        pushdown(st[i]);
    while (!isroot(x))
    {
        int y = fa[x], z = fa[y];
        if (!isroot(y))
        {
            if (c[y][0] == x ^ c[z][0] == y)
                rotate(x);
            else
                rotate(y);
        }
        rotate(x);
    }
}
void access(int x)
{
    int t = 0;
    while (x)
    {
        splay(x);
        c[x][1] = t;
        t = x;
        x = fa[x];
    }
}
void rever(int x)
{
    access(x);
    splay(x);
    rev[x] ^= 1;
}
void link(int x, int y)
{
    rever(x);
    fa[x] = y;
    splay(x);
}
void cut(int x, int y)
{
    rever(x);
    access(y);
    splay(y);
    c[y][0] = fa[x] = 0;
}
void solve()
{
    n = read();
    memset(head, 0, sizeof head); cnt = 0;
    memset(vis, false, sizeof vis);
    for (int i = 2; i <= n; ++i)
        insert(read(), i);
    Dfs(1);
    for (int i = 1; i <= n; ++i)
    {
        int x = read();
        fa[i] = get(i, x);
        sz[i] = 1;
        if (fa[i] > n + 1)
            fa[i] = n + 1;
        nxt[i] = fa[i];
    }
    sz[n + 1] = 1;
    m = read();
    for (int i = 1; i <= m; ++i)
    {
        if (read() == 1)
        {
            rever(n + 1);
            int x = read();
            access(x);
            splay(x);
            printf("%d\n", sz[c[x][0]]);
        }
        else
        {
            int x = read(), y = read(), t = min(n + 1, get(x, y));
            cut(x, nxt[x]);
            link(x, nxt[x] = t);
        }
    }
}
int main()
{
    freopen("test.in", "r", stdin);
    for (int T = read(); T; --T)
        solve();
    return 0;
}