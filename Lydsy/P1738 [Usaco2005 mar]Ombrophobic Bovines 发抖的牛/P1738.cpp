#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define pr(x) printf("%lld ",x)
#define pe printf("\n")
const int N = 500 + 10;
const int M = 15000 + 10;
const long long Inf = 0x3f3f3f3f3f3f3f3f;
using namespace std;
struct edge
{
    int to,next;
    long long w;
};

int S,T,head[N],cnt,h[N];
edge e[2 * M];
struct NetFlow
{
    void Clean(int s,int t)
    {
        S = s;T = t;
        cnt = 1;
        memset(head,0,sizeof(head));
    }
    void Insert(int u,int v,long long w)
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
    long long Dfs(int u,long long f)
    {
        if (u == T)
            return f;
        int v;long long w,used = 0;
        for (int i=head[u];i;i=e[i].next)
        {
            v = e[i].to;
            if (h[v] == h[u] + 1)
            {
                w = Dfs(v,min(e[i].w,f - used));
                e[i].w -= w;
                e[i ^ 1].w += w;
                used += w;
                if (used == f)
                    return f;
            }
        }
        if (!used)
            h[u] = -1;
        return used;
    }
    long long Dinic()
    {
        long long ans = 0;
        while (Spfa())
            ans += Dfs(S,Inf);
        return ans;
    }
} G;
int a[N],v[N],n,m;
long long f[N][N],sum = 0;
long long l = 0,r = 0;
long long Read()
{
    long long x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void Readin()
{
    n = Read(); m = Read();
    for (int i=1;i<=n;++i)
    {
        a[i] = Read();
        v[i] = Read();
        sum += a[i];
    }
    int u,v;
    long long w;
    memset(f,0x3f,sizeof(f));
    for (int i=1;i<=n;++i)
        f[i][i] = 0;
    for (int i=1;i<=m;++i)
    {
        u = Read(); v = Read(); w = Read();
        f[u][v] = min(f[u][v],w);
        f[v][u] = min(f[v][u],w);
        r += w;
    }
}
void Floyd()
{
    for (int k=1;k<=n;++k)
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
                f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
}
bool Judge(long long x)
{
    G.Clean(0,2 * n + 1);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            if (f[i][j] <= x)
                G.Insert(i,j + n,Inf);
    for (int i=1;i<=n;++i)
        G.Insert(S,i,(long long)a[i]);
    for (int i=1;i<=n;++i)
        G.Insert(i + n,T,(long long)v[i]);
    return (G.Dinic() == sum);
}
void Work()
{
    long long ans = -1,mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        pr(mid);
        if (Judge(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    printf("%lld\n",ans);
}
int main()
{
    freopen("2.in","r",stdin);
    Readin();
    Floyd();
    Work();
    return 0;
}
