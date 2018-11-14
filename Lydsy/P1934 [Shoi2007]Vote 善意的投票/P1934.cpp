#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define For(i,x,y) for (int i=x;i<=y;++i)
#define Dor(i,x,y) for (int i=x;i>=y;--i)
#define Clri(x) memset(x,0x3f,sizeof(x))
#define Clre(x) memset(x,0x00,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 305;
const int M = N * N;
const int Inf = 0x3f3f3f3f;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
struct edge
{
    int to,next,w;
};
struct Network
{
    edge e[2 * M];
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
        int v, w, used = 0;
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

int n, m, x, y, t;
void Init()
{
	n = read(); m = read();
    G.Init(0, n + 1);
	for (int i = 1; i <= n; ++i)
		if (t = read())
			G.Insert(G.S, i, 1);
		else 
			G.Insert(i, G.T, 1);
	for (int i = 1; i <= m; ++i)
	{
		G.Insert(x = read(), y = read(), 1);	
		G.Insert(y, x, 1);	
	}
}
int main()
{
    Init();
    printf("%d\n", G.Dinic());
    return 0;
}
