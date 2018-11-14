#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 1000 + 10;
const int M = 20000 + 10;
int k,n,m;
struct edge
{
    int to,next;
} e[M];
int head[N],cnt = 0;
int pos[N / 10];
void Insert(int u,int v)
{
    e[++cnt] = (edge){v,head[u]};
    head[u] = cnt;
}
void Readin()
{
    int u,v;
    scanf("%d%d%d",&k,&n,&m);
    for (int i=1;i<=k;++i)
        scanf("%d",pos + i);
    for (int i=1;i<=m;++i)
    {
        scanf("%d%d",&u,&v);
        Insert(u,v);
    }
}

int time[N];
bool vis[N];
void Dfs(int now)
{
    vis[now] = true;
    ++time[now];
    int v;
    for (int i=head[now];i;i=e[i].next)
    {
        v = e[i].to;
        if (!vis[v])
            Dfs(v);
    }
}
void Work()
{
    for (int i=1;i<=k;++i)
    {
        memset(vis,false,sizeof(vis));
        Dfs(pos[i]);
    }
    int ans = 0;
    for (int i=1;i<=n;++i)
        if (time[i] == k)
            ++ans;
    printf("%d\n",ans);
}
int main()
{
    Readin();
    Work();
    return 0;
}
