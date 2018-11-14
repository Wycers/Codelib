#include <bitset>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
const int N = 1000 + 10;
using namespace std;
int n,m;
bitset<N> b[N];
struct edge_
{
    int to,next;
}edge[N * 10];
int head[N],cnt = 0;
void Insert(int u,int v)
{
    edge[++cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
bool vis[N];
void Dfs(int now)
{
    vis[now] = true;
    int v;
    for(int i=head[now];i;i=edge[i].next)
    {
        v = edge[i].to;
        if(!vis[v])
            Dfs(v);
        b[now] |= b[v];
    }
}
int ans;
void Readin()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        b[i][i] = 1;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        Insert(x,y);
    }
}
void Solve()
{
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)
        if(!vis[i])
            Dfs(i);
    for(int i=1;i<=n;i++)
        ans += b[i].count();
    printf("%d\n",n * (n - 1) / 2 - ans + n);
}
int main()
{
    Readin();
    Solve();
    return 0;
}
