#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
const int N = 5000 + 10;
const int M = 10 * N;
const int Inf = 0x3f3f3f3f;
using namespace std;
int n,m,r,c;
bool mp[N][N];
void Readin()
{
    scanf("%d%d%d%d",&n,&m,&r,&c); getchar();
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
            mp[i][j] = getchar() == '.' ? true : false;
        getchar();
    }
}
struct edge
{
    int to,next,w;
};
struct NetFlow
{
    edge e[M];
    int head[N],cnt,S,T;
    void Clean()
    {
        cnt = 1;
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
        memset(h,-1,sizeof(h));
        h[S] = 0; q.push(S);
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
        int v,used = 0,w;
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
bool Judge(int x,int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return false;
    return true;
}
int tot = 0;
#define P(x,y) m * (x - 1) + y
void Build()
{
    G.Clean();
    int x,y;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            if (mp[i][j])
            {
                x = i + r,y = j + c;
                if (Judge(x,y) && mp[x][y])
                    G.Insert(P(i,j),P(x,y) + n * m,1);
                x = i + r,y = j - c;
                if (Judge(x,y) && mp[x][y])
                    G.Insert(P(i,j),P(x,y) + n * m,1);
                x = i + c,y = j + r;
                if (Judge(x,y) && mp[x][y])
                    G.Insert(P(i,j),P(x,y) + n * m,1);
                x = i + c,y = j - r;
                if (Judge(x,y) && mp[x][y])
                    G.Insert(P(i,j),P(x,y) + n * m,1);
            }

    G.S = 0;
    G.T = 2 * n * m + 1;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            if (mp[i][j])
            {
                G.Insert(G.S,P(i,j),1);
                G.Insert(P(i,j) + n * m,G.T,1);
                ++tot;
            }
}
int main()
{
    Readin();
    Build();
    printf("%d\n",tot - G.Dinic());
    return 0;
}
