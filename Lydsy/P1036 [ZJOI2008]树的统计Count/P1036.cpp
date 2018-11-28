#include <cstdio>
#include <algorithm>
#define Inf 0x3f3f3f3f
const int N = 30005;
const int M = 60005;
using namespace std;
struct edge_
{
    int to,next;
} edge[M];
int head[N],cnt;
struct seg
{
    int l,r,sum,mx;
} tr[4 * N];

int n,q,sz = 0,v[N];
int size[N],deep[N],fa[N][15],pos[N],belong[N];
bool vis[N];
void Insert(int u,int v)
{
    edge[++cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
void Readin()
{
    int x,y;
    scanf("%d",&n);
    for (int i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        Insert(x,y);
        Insert(y,x);
    }
    for (int i=1;i<=n;i++)
        scanf("%d",v + i);
}

void Dfs1(int u)
{
    size[u] = 1;vis[u] = true;
    for (int i=1;i<=14;i++)
    {
        if (deep[u] < (1 << i))
            break;
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    int v;
    for (int i=head[u];i;i=edge[i].next)
    {
        v = edge[i].to;
        if (vis[v])
            continue;
        deep[v] = deep[u] + 1;
        fa[v][0] = u;
        Dfs1(v);
        size[u] += size[v];
    }
}
void Dfs2(int u,int chain)
{
    int k = 0,v;
    pos[u] = ++sz;
    belong[u] = chain;
    for (int i=head[u];i;i=edge[i].next)
    {
        v = edge[i].to;
        if (deep[v] > deep[u] && size[v] > size[k])
            k = v;
    }
    if (k == 0) return;
    Dfs2(k,chain);
    for (int i=head[u];i;i=edge[i].next)
    {
        v = edge[i].to;
        if (deep[v] > deep[u] && k != v)
            Dfs2(v,v);
    }
}
int lca(int x,int y)
{
    if (deep[x] < deep[y])
        swap(x,y);
    int t = deep[x] - deep[y];
    for (int i=0;i<=14;i++)
        if (t & (1 << i))
            x = fa[x][i];
    for (int i=14;i>=0;i--)
        if (fa[x][i] != fa[y][i])
        {
            x = fa[x][i];
            y = fa[y][i];
        }
    return x == y ? x : fa[x][0];
}
void Build(int k,int l,int r)
{
    tr[k].l = l;tr[k].r = r;
    if (l == r) return;
    int mid = (l + r) >> 1;
    Build(k << 1,l,mid);
    Build(k << 1 | 1,mid + 1,r);
}
void Change(int k,int x,int y)
{
    int l = tr[k].l,r = tr[k].r;
    int mid = (l + r) >> 1;
    if (l == r)
    {
        tr[k].sum = tr[k].mx = y;
        return;
    }
    if (x <= mid) Change(k << 1,x,y);
    else Change(k << 1 | 1,x,y);
    tr[k].sum = tr[k << 1].sum + tr[k << 1 | 1].sum;
    tr[k].mx = max(tr[k << 1].mx,tr[k << 1 | 1].mx);
}
int QuerySum(int k,int x,int y)
{
    int l = tr[k].l,r = tr[k].r;
    if (l == x && r == y)
        return tr[k].sum;
    int mid = (l + r) >> 1;
    if (y <= mid) return QuerySum(k << 1,x,y);
    else if (x > mid) return QuerySum(k << 1 |1,x,y);
    return QuerySum(k << 1,x,mid) + QuerySum(k << 1 | 1,mid + 1,y);
}
int QueryMx(int k,int x,int y)
{
    int l = tr[k].l,r = tr[k].r;
    int mid = (l + r) >> 1;
    if (l == x && r == y)
        return tr[k].mx;
    if (y <= mid) return QueryMx(k << 1,x,y);
    else if (x > mid) return QueryMx(k << 1 | 1,x,y);
    return max(QueryMx(k << 1,x,mid),QueryMx(k << 1 | 1,mid + 1,y));
}
int SolveSum(int x,int f)
{
    int sum = 0;
    while (belong[x] != belong[f])
    {
        sum += QuerySum(1,pos[belong[x]],pos[x]);
        x = fa[belong[x]][0];
    }
    sum += QuerySum(1,pos[f],pos[x]);
    return sum;
}
int SolveMx(int x,int f)
{
    int mx = -Inf;
    while (belong[x] != belong[f])
    {
        mx = max(mx,QueryMx(1,pos[belong[x]],pos[x]));
        x = fa[belong[x]][0];
    }
    mx = max(mx,QueryMx(1,pos[f],pos[x]));
    return mx;
}
void Solve()
{
    Build(1,1,n);
    for (int i=1;i<=n;i++)
        Change(1,pos[i],v[i]);
    int q,x,y,t;
    scanf("%d",&q);
    char ch[6];
    while (q--)
    {
        scanf("%s%d%d",ch,&x,&y);
        if (ch[0] == 'C')
        {
            v[x] = y;
            Change(1,pos[x],y);
        }
        else
        {
            t = lca(x,y);
            if (ch[1] == 'M')
                printf("%d\n",max(SolveMx(x,t),SolveMx(y,t)));
            else
                printf("%d\n",SolveSum(x,t) + SolveSum(y,t) - v[t]);
        }
    }
}
int main()
{
    Readin();
    Dfs1(1);
    Dfs2(1,1);
    Solve();
    return 0;
}
