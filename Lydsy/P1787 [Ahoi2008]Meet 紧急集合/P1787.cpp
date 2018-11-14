#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 500000 + 5;
int n,Q;
int Read()
{
    int x = 0;char ch = getchar();
    while (!('0' <= ch && ch <= '9')) ch = getchar();
    while ('0' <= ch && ch <= '9') {x = x * 10 + ch - 48; ch = getchar();}
    return x;
}

struct edge_
{
    int to,next;
} edge[2 * N];
int head[N],cnt = 0;
void Insert(int u,int v)
{
    edge[++cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

void Readin()
{
    int u,v;
    n = Read();Q = Read();
    for (int i=1;i<=n-1;i++)
    {
        u = Read(); v = Read();
        Insert(u,v);
        Insert(v,u);
    }
}

int deep[N],fa[N][20];
bool vis[N];
void Dfs(int now)
{
    vis[now] = true;
    for (int i=1;i<20;i++)
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
            fa[v][0] = now;
            Dfs(v);
        }
    }
}
int lca(int x,int y)
{
    if (deep[x] < deep[y]) swap(x,y);
    int t = deep[x] - deep[y];
    for (int i=0;i<=19;i++)
        if (t & (1 << i))
            x = fa[x][i];
    for (int i=19;i>=0;i--)
        if (fa[x][i] != fa[y][i])
        {
            x = fa[x][i];
            y = fa[y][i];
        }
    return x == y ? x : fa[x][0];
}

int dis(int x,int y,int &LCA)
{
    LCA = lca(x,y);
    return deep[x] + deep[y] - 2 * deep[LCA];
}
int Dis(int a,int b,int c,int &LCA)
{
    int temp = dis(a,b,LCA);
    temp += dis(LCA,c,a);
    return temp;
}
void Solve()
{
    int x,y,z,LCA;
    int temp,ans1,ans2;
    Dfs(1);
    while (Q--)
    {
        x = Read();y = Read();z = Read();ans1 = 0x7fffffff;
        temp = Dis(x,y,z,LCA);
        if (temp < ans1) {ans1 = temp;ans2 = LCA;}
        temp = Dis(x,z,y,LCA);
        if (temp < ans1) {ans1 = temp;ans2 = LCA;}
        temp = Dis(y,z,x,LCA);
        if (temp < ans1) {ans1 = temp;ans2 = LCA;}
        printf("%d %d\n",ans2,ans1);
    }
}
int main()
{
    Readin();
    Solve();
    return 0;
}
