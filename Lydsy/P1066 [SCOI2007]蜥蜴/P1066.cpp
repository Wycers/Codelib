#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#define For(i,x,y) for (int i=x;i<=y;++i)
#define Dor(i,x,y) for (int i=x;i>=y;--i)
#define Clri(x) memset(x,0x3f,sizeof(x))
#define Clre(x) memset(x,0x00,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 1000;
const int M = 500000;
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
	int to,next,w;
};
struct Network
{
	edge e[M]; int head[N],cnt;
	int S,T;
	void Init(int s,int t)
	{
		S = s; T = t;
		Clre(head); cnt = 1;
	}
	void Insert(int u,int v,int w)
	{
		//printf("%d %d %d\n",u,v,w);
		e[++cnt] = (edge){v,head[u],w}; head[u] = cnt;
		e[++cnt] = (edge){u,head[v],0}; head[v] = cnt;
	}
	queue<int> q; int h[N];
	bool Spfa()
	{
		q.push(S); Clri(h); h[S] = 0;
		int u,v;
		while (!q.empty())
		{
			u = q.front(); q.pop();
			for (int i=head[u];i;i=e[i].next)
			{
				v = e[i].to;
				if (e[i].w && h[v] == Inf)
				{
					h[v] = h[u] + 1;
					q.push(v);	
				}	
			}
		}
		return h[T] != Inf;
	}
	int Dfs(int u,int f)
	{
		if (u == T)
			return f;
		int v,used = 0,w;
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
		if (!used) h[u] = Inf;
		return used;
	}
	int Dinic()
	{
		int ans = 0;
		while (Spfa())
		{
			ans += Dfs(S,Inf);
		}
		return ans;
	}
} G;
//Code
double Dis2(int x1,int y1,int x2,int y2)
{
	int x = abs(x1 - x2);
	int y = abs(y1 - y2);
	return x * x + y * y;
}
#define Mir(x) (x + nm)
int cnt = 0;
int mp[25][25],f[25][25];
void Init()
{
	int n = read(),m = read(),d = read();
	int nm = n * m,tag = 0;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			f[i][j] = ++tag;
	G.Init(0,2 * n * m + 1);
	
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=m;++j)
			if ((mp[i][j] = (getchar() - 48)) != 0)
				G.Insert(f[i][j],Mir(f[i][j]),mp[i][j]);
		getchar();
	}	
	bool flag = false;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
		{
			flag = false;
			for (int x = i - d;x <= i + d; ++x)
				for (int y = j - d;y <= j + d; ++y)
				{
					if (x < 1 || y < 1 || x > n || y > m)
						flag = true;
					else if (Dis2(x,y,i,j) <= d * d && mp[i][j] && mp[x][y])
						G.Insert(Mir(f[i][j]),f[x][y],Inf);
				}	
			if (flag)
				G.Insert(Mir(f[i][j]),G.T,Inf);
		}
	
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=m;++j)
			if (getchar() == 'L')
			{
				G.Insert(G.S,f[i][j],1);
				++cnt;	
			}
		getchar();
	}
}

int main()
{
	Init();
	printf("%d\n",cnt - G.Dinic());
    return 0;
}
