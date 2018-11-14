#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <iostream>
const int N = 6e2 + 10;
const int M = 15e5 + 10;
const int Inf = 0x3f3f3f3f;
using namespace std;
int n,m;
struct edge
{
    int to,next,w;
};
struct Network
{
    edge e[M];
    int head[N],cnt,S,T;
    void Insert(int u,int v,int w)
    {
        e[++cnt] = (edge){v,head[u],w}; head[u] = cnt;
        e[++cnt] = (edge){u,head[v],0}; head[v] = cnt;
    }
    void Init(int s,int t)
    {
        S = s,T = t;
        cnt = 1;
        memset(head,0,sizeof(head));
    }
    queue<int> q;
    int h[N];
    bool Spfa()
    {
        memset(h,-1,sizeof(h));
        q.push(S); h[S] = 0;
        int u,v;
        while (!q.empty())
        {
            u = q.front(); q.pop();
            for (int i=head[u];i;i=e[i].next)
            {
                v = e[i].to;
                if (e[i].w && h[v] == -1)
                {
                    h[v] = h[u] + 1;
                    q.push(v);
                }
            }
        }
        return h[T] != -1;
    }

    int Dfs(int u,int f)
    {
        if (u == T)
            return f;
        int v,w,used = 0;
        for (int i=head[u];i;i=e[i].next)
        {
            v = e[i].to;
            if (e[i].w && h[v] == h[u] + 1)
            {
                w = Dfs(v,min(e[i].w,f - used));
                e[i].w -= w;
                e[i ^ 1].w += w;
                if ((used += w) == f)
                    return f;
            }
        }
        if (!used) h[u] = -1;
        return used;
    }
    int Dinic()
    {
        int ans = 0;
        while (Spfa())
            ans += Dfs(S,Inf);
        return ans;
    }
} G;

int num[50][50],mp[50][50],ind[N],tot;
bool vis[N];
struct Tuopu
{
    int st[N],head[N],cnt,top;
    edge e[M];
    void Insert(int u,int v)
    {
        ++ind[v];
        e[++cnt] = (edge){v,head[u],1}; head[u] = cnt;
    }
    void Work()
    {
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j)
                if (!ind[num[i][j]])
                    st[++top] = num[i][j];
        int u,v;
        while (top)
        {
            u = st[top--];
            vis[u] = true;
            for (int i=head[u];i;i=e[i].next)
            {
                v = e[i].to;
                if (!(--ind[v]))
                    st[++top] = v;
            }
        }
    }
} Tp;
void Build()
{
    int v;
    G.Init(0,n * m + 2);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            if (vis[num[i][j]])
            {
                if (mp[i][j] > 0)
                {
                    G.Insert(G.S,num[i][j],mp[i][j]);
                    tot += mp[i][j];
                }
                else
                    G.Insert(num[i][j],G.T,-mp[i][j]);
                for (int k=Tp.head[num[i][j]];k;k=Tp.e[k].next)
                {
                    v = Tp.e[k].to;
                    if (vis[v])
                        G.Insert(v,num[i][j],Inf);
                }
            }
}
void Init()
{
    int cnt,x,y;
    cnt = Tp.cnt = 0;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            num[i][j] = ++cnt;
    cnt = 0;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
        {
            scanf("%d%d",&mp[i][j],&cnt);
            for (int k=1;k<=cnt;++k)
            {
                scanf("%d%d",&x,&y);
                Tp.Insert(num[i][j],num[++x][++y]);
            }
            if (j != m)
                Tp.Insert(num[i][j + 1],num[i][j]);
        }
    Tp.Work();
    Build();
}
int main()
{
    Init();
    printf("%d\n",tot - G.Dinic());
    return 0;
}
