#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
const int N = 50;
const int M = 50;
const int Inf = 0x3f3f3f3f;
using namespace std;

struct edge
{
    int to,next,v;
};
struct NetWork
{
    edge e[M];
    int head[N],cnt,S,T;
    void Init(int s,int t)
    {
        cnt = 1;
        S = s;T = t;
        memset(head,0,sizeof(head));
    }
    void Insert(int u,int v,int w)
    {
        e[++cnt] = (edge){v,head[u],w}; head[u] = cnt;
        e[++cnt] = (edge){u,head[v],0}; head[v] = cnt;
    }
    queue<int> q;
    int h[N];
    bool Spfa()
    {
        memset(h,255,sizeof(h));
        q.push(S); h[S] = 0;
        int u,v;
        while (!q.empty())
        {
            u = q.front(); q.pop();
            for (int i=head[u];i;i=e[i].next)
            {
                v = e[i].to;
                if (e[i].v && h[v] == -1)
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
        int w,used = 0,v;
        for (int i=head[u];i;i=e[i].next)
        {
            v = e[i].to;
            if (h[v] == h[u] + 1)
            {
                w = Dfs(v,min(e[i].v,f - used));
                e[i].v -= w;
                e[i ^ 1].v += w;
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
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    G.Init(0,1);
    G.Insert(0,1,n);
    G.Insert(0,1,m);
    printf("%d\n",G.Dinic());
    return 0;
}
