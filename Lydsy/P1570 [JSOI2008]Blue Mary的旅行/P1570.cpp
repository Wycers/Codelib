#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
const int N = 50 + 10;
const int M = 2500 + 10;
const int V = 2 * N * N;
const int E = M * N * 4;
const int Inf = 0x3f3f3f3f;
using namespace std;
int n,m,t;
struct edge
{
    int to,next,w;
};
struct NetFlow
{
    edge e[E];int head[V],cnt;
    int h[V],S,T;
    void Clean()
    {
        cnt = -1;
        memset(head,-1,sizeof(head));
    }
    void Insert(int u,int v,int w)
    {
        e[++cnt] = (edge){v,head[u],w}; head[u] = cnt;
        e[++cnt] = (edge){u,head[v],0}; head[v] = cnt;
    }
    queue<int> q;
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
        int used = 0,v,w;
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
    int Dinic(int s,int t)
    {
        int ans = 0;
        S = s;T = t;
        while (Spfa())
            ans += Dfs(S,Inf);
        return ans;
    }
} G;
int Read();
int ed[M][3];
void Readin()
{
    n = Read(); m = Read(); t = Read();
    for (int i=1;i<=m;++i)
    {
        ed[i][0] = Read();
        ed[i][1] = Read();
        ed[i][2] = Read();
    }
}
#define get(x,dep) ((dep-1)*n+x)
#define S(x) (n * (x + 1) + 1)
void Work()
{
    G.Clean();
    int ans = 0;
    while (true)
    {
        ++ans;
        G.Clean();

        for (int j=1;j<=ans;++j)
            G.Insert(0,get(1,j),Inf);
        for (int i=1;i<=m;++i)
            for (int j=1;j<=ans;++j)
                G.Insert(get(ed[i][0],j),get(ed[i][1],j + 1),ed[i][2]);
        for (int j=2;j<=ans+1;++j)
            G.Insert(get(n,j),S(ans),Inf);

        if (G.Dinic(0,S(ans)) >= t)
        {
            printf("%d\n",ans);
            break;
        }
    }
}
int main()
{
    Readin();
    Work();
    return 0;
}
int Read()
{
    int x = 0;char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0',ch = getchar();
    return x;
}
