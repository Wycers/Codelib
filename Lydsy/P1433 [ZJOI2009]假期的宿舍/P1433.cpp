#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define For(i,x,y) for (int i=x;i<=y;++i)
#define Dor(i,x,y) for (int i=x;i>=y;--i)
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 1e2 + 10;
const int M = 5e4 + 10;
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
	edge e[M];
	int head[N], cnt, S, T;
	void Init(int s, int t)
	{
		S = s, T = t;
		cnt = 1;
		Clr(head, 0);
	}
	void Insert(int u, int v, int w)
	{
		e[++cnt] = (edge){v, head[u], w}; head[u] = cnt;
		e[++cnt] = (edge){u, head[v], 0}; head[v] = cnt; 
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
				w = Dfs(v, min(e[i].w, f - used));
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
		int res = 0;
		while (Spfa())
			res += Dfs(S, Inf);
		return res;
	}
} G;
//Code
int n, live[60], gohome[60], tot;
void Work()
{
	n = read(); tot = 0;
	G.Init(0, 2 * n + 1);
	for (int i = 1; i <= n; ++i)
		if ((live[i] = read()) == 1)
			G.Insert(n + i, G.T, 1);
	for (int i = 1; i <= n; ++i)
	{
		gohome[i] = read();
		if(!live[i] || !gohome[i])
			G.Insert(G.S, i, 1), ++tot;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if(read() || i == j)
				G.Insert(i, j + n, 1);
	if (G.Dinic() == tot)
		puts("^_^");
	else
		puts("T_T");
}
int main()
{
	for (int T = read(); T; --T)
		Work();
    return 0;
}


