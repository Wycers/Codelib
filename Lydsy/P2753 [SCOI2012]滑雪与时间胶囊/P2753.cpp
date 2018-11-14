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
const int N = 1e5 + 10;
const int M = 2e6 + 10;
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
	int u, to, next, w;
} e[M];
int head[N], cnt = 0;
void Insert(int u, int v, int w)
{
	e[++cnt] = (edge){u, v, head[u], w};
	head[u] = cnt;
}
//Code
int n, m, h[N];
void Init()
{
	n = read(); m = read();
	for (int i = 1; i <= n; ++i)
		h[i] = read();
	int u, v, w;
	for (int i = 1; i <= m; ++i)
	{
		u = read(); v = read(); w = read();
		if (h[u] >= h[v])
			Insert(u, v, w);
		if (h[v] >= h[u])
			Insert(v, u, w);
	}
}
bool vis[N];
queue<int> q;
void Bfs()
{
	Clr(vis, false);
	q.push(1); vis[1] = true;
	int u, v;
	while (!q.empty())
	{
		u = q.front(); q.pop();
		for (int i = head[u]; i; i = e[i].next)
		{
			v = e[i].to;		
			if (!vis[v])
			{
				vis[v] = true;
				q.push(v);	
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i)
		res += vis[i];
	printf("%d ", res);
}

int fa[N];
int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
bool cmp(edge a, edge b)
{
	if (h[a.to] == h[b.to])
		return a.w < b.w;
	return h[a.to] > h[b.to];
}
void Work()
{
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	sort(e + 1, e + cnt + 1, cmp);
	int u, v, x, y; ll res = 0;
	for (int i = 1; i <= cnt; ++i)
	{
		u = e[i].u; v = e[i].to;
		if (!vis[u] || !vis[v])
			continue;
		x = find(u); y = find(v);
		if (x != y)
		{
			fa[x] = y;
			res += e[i].w;
		}
	}
	cout << res << endl;
}

int main()
{
	Init();
	Bfs();
	Work();
    return 0;
}


