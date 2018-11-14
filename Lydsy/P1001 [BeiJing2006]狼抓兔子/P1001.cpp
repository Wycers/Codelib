#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int n,m;
struct edge_
{
    int to,next,w;
} edge[6000005];
int head[1000005],cnt = 0;
void Insert(int u,int v,int w)
{
    edge[++cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
void Ins(int u,int v,int w)
{
    Insert(u,v,w);
    Insert(v,u,w);
}
int Cal(int x,int y)
{
    return m * (x - 1) + y;
}
void Readin()
{
    int w;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<m;j++)
        {
            scanf("%d",&w);
            Ins(Cal(i,j),Cal(i,j + 1),w);
        }
    for (int i=1;i<n;i++)
        for (int j=1;j<=m;j++)
        {
            scanf("%d",&w);
            Ins(Cal(i,j),Cal(i + 1,j),w);
        }
    for (int i=1;i<n;i++)
        for (int j=1;j<m;j++)
        {
            scanf("%d",&w);
            Ins(Cal(i,j),Cal(i + 1,j + 1),w);
        }
}

int h[1000005];
queue<int> q;
bool Bfs()
{
    memset(h,-1,sizeof(h));
    h[1] = 0;
    q.push(1);
    int now,v,w;
    while (!q.empty())
    {
        now = q.front(); q.pop();
        for (int i=head[now];i;i=edge[i].next)
        {
            v = edge[i].to;
            if (edge[i].w && h[v] == -1)
            {
                h[v] = h[now] + 1;
                q.push(v);
            }
        }
    }
    return h[n * m] != -1;
}

int Dfs(int u,int f)
{
    if(u == n * m)
        return f;
    int w,used = 0,v;
    for (int i=head[u];i;i=edge[i].next)
    {
        v = edge[i].to;
        if (h[v] == h[u] + 1)
        {
            w = Dfs(v,min(edge[i].w,f - used));
            edge[i].w -= w;
            edge[i + 1].w += w;
            used += w;
            if(used == f)
                return f;
        }
    }
    if (!used)
        h[u] = -1;
    return used;
}

int ans = 0;
void Dinic()
{
    while (Bfs())
        ans += Dfs(1,0x7fffffff);
}

int main()
{
    Readin();
    Dinic();
    printf("%d\n",ans);
    return 0;
}
