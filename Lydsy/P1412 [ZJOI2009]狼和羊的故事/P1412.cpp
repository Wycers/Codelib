#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
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
int n, m, mp[110][110];
void Init()
{
	n = read(); m = read();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			mp[i][j] = read();
}
const int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int P(int x, int y)
{
	return (x - 1) * m + y;
}
void Build()
{
	G.Init(0, n * m + 1);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			if (mp[i][j] == 1)
				G.Insert(G.S, P(i, j), Inf);
			if (mp[i][j] == 2)
				G.Insert(P(i, j), G.T, Inf);
			for (int k = 0; k < 4; ++k)
			{
				int dx = i + d[k][0], dy = j + d[k][1];
				if (dx < 1 || dx > n || dy < 1 || dy > m || mp[i][j] == 2)
					continue;
				if (mp[i][j] != 1 || mp[dx][dy] != 1)
					G.Insert(P(i, j), P(dx, dy), 1);
			}
		}
}

int main()
{
	Init();
	Build();
	printf("%d\n", G.Dinic());
    return 0;
}


