#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
const int M = 1e5 + 10;
const int Inf = 0x3f3f3f3f;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
int n, m, k, s, t;
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
void Init()
{
	n = read(); m = read(); k = read();
	int u, v, w;
	s = read(); t = read();
	for (int i = 1; i <= m; ++i)
	{
		u = read(); v = read(); w = read();
		Insert(u, v, w);
		Insert(v, u, w);
	}
}

queue<pair<int, int> > q;
bool vis[N][15]; int Dis[N][15];
void Spfa()
{
	Clr(vis, false); Clr(Dis, 0x3f);
	q.push(make_pair(s, 0)); vis[s][0] = true;  Dis[s][0] = 0;
	int u, v, used;
	while (!q.empty())
	{
		pair<int, int> now = q.front(); q.pop();
		u = now.first; used = now.second;
		for (int i = head[u]; i; i = e[i].next)
		{
			v = e[i].to;
			if (Dis[u][used] + e[i].w < Dis[v][used])
			{
				Dis[v][used] = Dis[u][used] + e[i].w;
				if (!vis[v][used])
				{
					q.push(make_pair(v, used));
					vis[v][used] = true;
				}
			}
			if (used < k && Dis[u][used] < Dis[v][used + 1])
			{
				Dis[v][used + 1] = Dis[u][used];
				if (!vis[v][used + 1])
				{
					q.push(make_pair(v, used + 1));
					vis[v][used + 1] = true;
				}
			}
		}
		vis[u][used] = false;
	}
	int ans = Inf;
	for (int i = 0; i <= k; ++i)
		ans = min(ans, Dis[t][i]);
	printf("%d\n", ans);
}
int main()
{
	Init();
	Spfa();
    return 0;
}


