#include <cstdio>
#include <algorithm>
#include <cmath>
const int N = 1005;
using namespace std;
int n,m,Q;
int Read()
{
    int x = 0;char ch = getchar();
    while (!('0' <= ch && ch <= '9')) ch = getchar();
    while ('0' <= ch && ch <= '9') {x = x * 10 + ch - 48; ch = getchar();}
    return x;
}

struct edge_
{
    int to,next,l;
} edge[2 * N];
int head[N],cnt = 0;
void Insert(int u,int v,int l)
{
    edge[++cnt].to = v;
    edge[cnt].l = l;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
void Readin()
{
    int u,v,l;
    n = Read();Q = Read();
    m = log(n) / log(2);
    for (int i=1;i<=n - 1;i++)
    {
        u = Read();v = Read();l = Read();
        Insert(u,v,l);
        Insert(v,u,l);
    }
}

int deep[N],dis[N],fa[N][10];
bool vis[N];
void Dfs(int now)
{
    vis[now] = true;
    for (int i=1;i<=m;i++)
    {
        if (deep[now] < (1 << i))
            break;
        fa[now][i] = fa[fa[now][i - 1]][i - 1];
    }
    int v;
    for (int i=head[now];i;i=edge[i].next)
    {
        v = edge[i].to;
        if (!vis[v])
        {
            deep[v] = deep[now] + 1;
            dis[v] = dis[now] + edge[i].l;
            fa[v][0] = now;
            Dfs(v);
        }
    }
}

int lca(int x,int y)
{
    if (deep[x] < deep[y]) swap(x,y);
    int t = deep[x] - deep[y];
    for (int i=0;i<=m;i++)
        if (t & (1 << i))
            x = fa[x][i];
    for (int i=m;i>=0;i--)
        if (fa[x][i] != fa[y][i])
        {
            x = fa[x][i];
            y = fa[y][i];
        }
    return x == y ? x : fa[x][0];
}

void Solve()
{
    int u,v,t;
    dis[1] = 0;
    Dfs(1);
    while (Q--)
    {
        u = Read();v = Read();
        t = lca(u,v);
        printf("%d\n",dis[u] + dis[v] - 2 * dis[t]);
    }
}
int main()
{
    Readin();
    Solve();
    return 0;
}
