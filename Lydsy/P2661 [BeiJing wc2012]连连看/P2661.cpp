#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 5000;
const int M = 1e4;
const int Inf = 0x3f3f3f3f;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
//Struct
struct edge
{
	int to,  next,  w,  c;
};
struct Network
{
    edge e[M];
    int head[N], cnt, S, T, ans;
    int cur[N];
    void Init(int s, int t)
    {
        cnt = 1;
        S = s; T = t;
        Clr(head,  0);
    }
    void Insert(int u, int v, int w, int c)
    {
        e[++cnt] = (edge){v, head[u], w, -c}; head[u] = cnt;
        e[++cnt] = (edge){u, head[v], 0,  c}; head[v] = cnt;
    }
	queue<int> q;
    int d[N]; bool vis[N];
    bool Spfa()
    {
        memset(d, 0x3f, sizeof(d));
        memset(vis, false, sizeof(vis));
        q.push(T); d[T] = 0; vis[T] = true; 
        int u, v;
        while (!q.empty())
        {
            u = q.front(); q.pop();
            for (int i=head[u];i;i=e[i].next)
            {
                v = e[i].to;
                if (e[i ^ 1].w && d[u] + e[i ^ 1].c < d[v])
                {
                    d[v] = d[u] + e[i ^ 1].c;
                    if (!vis[v])
                    {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
            vis[u] = false;
        }
        return d[S] != Inf;
    }
    int Dfs(int u, int f)
    {
        vis[u] = true;
        if (u == T)
            return f;
        int v, w, used = 0;
        for (int i = cur[u]; i; i = e[i].next)
        {
            v = e[i].to;
            if (!vis[v] && d[u] - e[i].c == d[v] && e[i].w)
            {
                w = Dfs(v, min(e[i].w, f - used));
                ans += w * e[i].c;
                e[i].w -= w;
                if (e[i].w) cur[u]=head[u];
                e[i ^ 1].w += w;
                if ((used += w) == f)
                    return f;
            }
        }
        return used;
    }
    int Zkw()
    {
    	int res = 0; ans = 0;
        while (Spfa())
        {
            for (int i = S; i <= T; i++)
				cur[i] = head[i];
            vis[T] = true;
            while (vis[T])
            {
            	Clr(vis, false);
                res += Dfs(S, Inf);
            }
        }
        return res;
    }
} G;
//Code
int gcd(int x, int y)
{
	return y == 0 ? x : gcd(y, x % y);
}
int n, m;
bool jud(int x,int y)
{
	if (x < y)
		swap(x, y);
	int t = int(sqrt(x * x - y * y));
	return (gcd(x, y) == 1 && x * x - y * y == t * t);
}
void Work()
{
	G.Init(0, 2001);
	for (int i = n; i <= m; ++i)
		for (int j = n; j <= m; ++j)
			if (jud(i, j) && i != j)
				G.Insert(i, j + 1000, 1, i + j);
	for (int i = n; i <= m; ++i)
	{
		G.Insert(G.S, i, 1, 0);
		G.Insert(i + 1000, G.T, 1, 0);
	}
}
int main()
{
	n = read(); m = read();
	Work();
	printf("%d ", G.Zkw() / 2);
	printf("%d\n", - G.ans / 2);
    return 0;
}


