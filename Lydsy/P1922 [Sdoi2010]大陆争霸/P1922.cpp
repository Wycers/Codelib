#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<int, int> pa;
const int N = 3e3 + 10;
const int M = 1e5 + 10;
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
} e[M];
int head[N], cnt = 0;
void Insert(int u, int v, int w)
{
	e[++cnt] = (edge){v, head[u], w};
	head[u] = cnt;
}
//Code
int n, m, l[N]; 
vector<int> a[N];
void Readin()
{
	n = read(); m = read();
	int u, v, w; Clr(head, 0); 
	for (int i = 1; i <= m; ++i)
	{
		u = read(), v = read(); w = read();
		if (u == v)
			continue;
		Insert(u, v, w);
	}
	for (int i = 1; i <= n; ++i)
		a[i].clear();
	for (int i = 1; i <= n; ++i)
	{
		l[i] = read(); 
		for (int j = 1; j <= l[i]; ++j)
			a[read()].push_back(i);
	}
}

int Dis1[N], Dis2[N]; bool vis[N];
priority_queue<int, vector<pa>, greater<pa> > q;
void Dijkstra()
{
	Clr(Dis1, 0x3f); Clr(Dis2, 0); Clr(vis, false);
	q.push(make_pair(0, 1));
	Dis1[1] = 0;
	int u, v;
	while (!q.empty())
	{
		int u = q.top().second; q.pop();
		if (vis[u])
			continue;
		vis[u] = true;
		int mx = max(Dis1[u], Dis2[u]);
		for (int i = head[u]; i; i = e[i].next)
		{
			v = e[i].to;
			if (mx + e[i].w < Dis1[v])
			{
				Dis1[v] = mx + e[i].w;
				if (!l[v])
					q.push(make_pair(max(Dis1[v], Dis2[v]), v));
			}
		}
		for (int i = 0, lim = a[u].size(); i < lim; ++i)
		{
			v = a[u][i]; 
			Dis2[v] = max(Dis2[v], mx);
			if (!(--l[v]))
				q.push(make_pair(max(Dis1[v], Dis2[v]), v));
		}
	}
	printf("%d\n", max(Dis1[n], Dis2[n]));
}

int main()
{
	Readin();
	Dijkstra();
    return 0;
}

