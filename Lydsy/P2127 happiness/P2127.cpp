#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 1e4 + 10;
const int M = 5e5 + 10;
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
	int to, next, w;
};
struct Network
{
	edge e[M]; int head[N], cnt, S, T;
	void Init(int s, int t)
	{
		S = s, T = t;
		Clr(head, 0); 
		cnt = 1;	
	} 
	void Insert(int u, int v, int w)
	{
		e[++cnt] = (edge){v, head[u], w};
		head[u] = cnt;
	}
	void Ins1(int u, int v, int w)
	{
		Insert(u, v, w);
		Insert(v, u, 0);
	}
	void Ins2(int u, int v, int w)
	{
		Insert(u, v, w);
		Insert(v, u, w);
	}
	queue<int> q; int h[N];
	bool Spfa()
	{
		Clr(h, -1); 
		q.push(S); h[S] = 0;
		int u, v;
		while (!q.empty())
		{
			u = q.front(); q.pop();
			for (int i = head[u]; i; i = e[i].next)
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
	int Dfs(int u, int f)
	{
		if (u == T)
			return f;
		int v, w, used = 0;
		for (int i = head[u]; i; i = e[i].next)
		{
			v = e[i].to;
			if (e[i].w && h[v] == h[u] + 1)
			{
				w = Dfs(v, min(f - used, e[i].w));
				e[i].w -= w;
				e[i ^ 1].w += w;
				if ((used += w) == f)
					return used;
			}
		}
		if (!used)
			h[u] = -1;
		return used;
	}
	int Dinic()
	{
		int res = 0;
		while (Spfa())
			res += Dfs(S, Inf);
		return res;
	}
} G;
//Code
int n, m, a[110][110], b[110][110], mark[110][110], tot = 0;
void Init()
{
	G.Init(0, 10001);
	for (int i = 1, tag = 0; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			mark[i][j] = ++tag;	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)	
		{
			tot += (a[i][j] = read());
			a[i][j] <<= 1;
		}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)	
		{
			tot += (b[i][j] = read());
			b[i][j] <<= 1;
		}
	int x;
	for (int i = 1; i <= n - 1; ++i)
		for (int j = 1; j <= m; ++j)
		{
			tot += (x = read());
			a[i][j] += x; a[i + 1][j] += x;
			G.Ins2(mark[i][j], mark[i + 1][j], x);
		}
	for (int i = 1; i <= n - 1; ++i)
		for (int j = 1; j <= m; ++j)
		{
			tot += (x = read());
			b[i][j] += x; b[i + 1][j] += x;
			G.Ins2(mark[i][j], mark[i + 1][j], x);
		}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m - 1; ++j)
		{
			tot += (x = read());
			a[i][j] += x; a[i][j + 1] += x;
			G.Ins2(mark[i][j], mark[i][j + 1], x);
		}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m - 1; ++j)
		{
			tot += (x = read());
			b[i][j] += x; b[i][j + 1] += x;
			G.Ins2(mark[i][j], mark[i][j + 1], x);
		}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
		   G.Ins1(G.S, mark[i][j], a[i][j]);
		   G.Ins1(mark[i][j], G.T, b[i][j]);
		}
}
int main()
{
	n = read(); m = read();
	Init();
	printf("%d\n", tot - (G.Dinic() >> 1));
    return 0;
}


