#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
const int N = 100;
const int M = 6000;
const int Inf = 0x3f3f3f3f;
using namespace std;
int n,a1,a2,an,b1,b2,bn;
struct edge
{
    int to,next,w;
};
struct Network
{
    edge e[M];
    int head[N],cnt,S,T;
    void Clean()
    {
        cnt = 1;S = 0;T = 55;
        memset(head,0,sizeof(head));
    }
    void Insert(int u,int v,int w)
    {
        e[++cnt] = (edge){v,head[u],w}; head[u] = cnt;
        e[++cnt] = (edge){u,head[v],0}; head[v] = cnt;
    }
    queue<int> q; int h[N];
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
            if (h[v] == h[u] + 1)
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
char mp[N][N];
void Readin()
{
    getchar();
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=n;++j)
            mp[i][j] = getchar();
        getchar();
    }
}
void Init()
{
    G.Clean();
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
        {
            if (mp[i][j] == 'X')
                continue;
            G.Insert(i,j,mp[i][j] == 'N' ? Inf : 2);
        }
}
int main()
{
    while (~scanf("%d%d%d%d%d%d%d",&n,&a1,&a2,&an,&b1,&b2,&bn))
    {
        ++a1;++a2; ++b1;++b2;
        Readin();
        Init();
        G.Insert(G.S,a1,an); G.Insert(a2,G.T,an);
        G.Insert(G.S,b1,bn); G.Insert(b2,G.T,bn);
        if (G.Dinic() >= (an + bn))
        {
            Init();
            G.Insert(G.S,a1,an); G.Insert(a2,G.T,an);
            G.Insert(G.S,b2,bn); G.Insert(b1,G.T,bn);
            puts ((G.Dinic() >= (an + bn)) ? "Yes" : "No");
        }
        else
            puts("No");
    }
    return 0;
}
/*
4 0 1 1 2 3 1
XOXX
OXOX
XOXO
XXOX
4 0 2 1 1 3 2
XNXO
NXOX
XOXO
OXOX
*/
