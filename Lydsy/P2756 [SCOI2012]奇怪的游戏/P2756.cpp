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
const int N = 1e5 + 10;
const int M = 1e5 + 10;
const int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const ll Inf = 1LL << 50;

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
	int to, next; ll w;
};
struct Network
{
	edge e[M]; int head[N], cur[N], cnt;
	int S, T;
	void Init(int s, int t)
	{
		S = s, T = t;
		Clre(head);
		cnt = 1;
	}
	void Insert(int u, int v, ll w)
	{
		e[++cnt] = (edge){v, head[u], w}; head[u] = cnt;
		e[++cnt] = (edge){u, head[v], 0}; head[v] = cnt;	
	}
	int q[2005]; int h[N];
	bool Spfa()
	{
		int t = 0, w = 1; q[0] = S;
		memset(h, -1, sizeof(h)); h[S] = 0;
		int u, v;
		while (t != w)
		{
			u = q[t++];
			for (int i = head[u]; i; i = e[i].next)
			{
				v = e[i].to;
				if (e[i].w && h[v] == -1)
				{
					h[v] = h[u] + 1;
					q[w++] = v;	
				}	
			}
		}
		return h[T] != -1;
	}
	ll Dfs(int u, ll f)
	{
		if (u == T)
			return f;
		int v; ll w, used = 0;
		for (int i = cur[u]; i; i = e[i].next)
		{
			v = e[i].to;
			if (e[i].w && h[v] == h[u] + 1 && (w = Dfs(v, min(f - used, e[i].w))))
			{
				e[i].w -= w;
				e[i ^ 1].w += w;
				if (e[i].w) cur[u] = i;
				if ((used += w) == f)
					return f;	
			}	
		}
		if (!used) h[u] = -1;
		return used;
	}
	ll Dinic()
	{
		ll res = 0, temp;
		while (Spfa())
		{
			for (int i = S; i <= T; ++i)
				cur[i] = head[i];
			if ((temp = Dfs(S, Inf)) == 0)
				break;
			res += temp;
		}
		return res;	
	}
		
} G;

//Code'
int n, m, c[45][45];ll mp[45][45], s0, c0, c1, s1, mx; 

#define Mir(i,j) ((i - 1) * m + j)
bool Judge(ll x)
{
	G.Init(0, n * m + 1);
	int dx, dy; ll tot = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (c[i][j])
			{
				G.Insert(G.S, Mir(i, j), x - mp[i][j]); tot += x - mp[i][j];
				for (int k = 0; k < 4; ++k)
				{
					dx = i + d[k][0]; dy = j + d[k][1];
					if (dx < 1 || dx > n || dy < 1 || dy > m)	
						continue;
					G.Insert(Mir(i, j), Mir(dx, dy), Inf);
				}
			}
			else 
				G.Insert(Mir(i, j), G.T, x - mp[i][j]);	
	if (G.Dinic() == tot)
		return true;
	return false;
}

void Work()
{
	ll l = mx, r = Inf, mid, ans;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (Judge(mid))
			r = mid - 1;
		else
			l = mid + 1;	
	}
	printf("%lld\n", (ll)l * c1 - s1);
}

bool Init()
{
	n = read(); m = read(); mx = -1; c1 = c0 = s0 = s1 = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			mp[i][j] = (ll)read();
			c[i][j] = (i + j) & 1;
			mx = max(mx, mp[i][j]);
		}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (c[i][j])
				++c1, s1 += mp[i][j];
			else
				++c0, s0 += mp[i][j];
	if (c0 != c1)
	{
		ll x = (s0 - s1) / (c0 - c1);	
		if (x >= mx && Judge(x))
			printf("%lld\n", x * c1 - s1);
		else
			puts("-1");
		return true;
	}
	return false;
}

int main()
{
	int T = read();
	while (T--)
	{
		if (Init())
			continue;
		Work();
	}
    return 0;
}


