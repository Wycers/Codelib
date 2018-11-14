#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#define For(i,x,y) for (int i=x;i<=y;++i)
#define Dor(i,x,y) for (int i=x;i>=y;--i)
#define Clri(x) memset(x,0x3f,sizeof(x))
#define Clre(x) memset(x,0x00,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 100 + 10;
const int M = 500 + 10;
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
	int to,next; 
};
int n,m,W[N],V[N],D[N];
struct Tarjan
{
	int dfn[N],low[N],belong[N],scc[N],sz[N],w[N],d[N],val[N],scnt,dfsc;
	bool ins[N];
	edge e[M];int head[N],cnt;
	void Insert(int u,int v)
	{
		e[++cnt] = (edge){v,head[u]}; 
		head[u] = cnt;
	}
	void Init()
	{
		dfsc = cnt = scnt = 0;
		Clre(dfn); Clre(low); Clre(W); Clre(V);
	}
	stack<int> s;
	void tarjan(int u)
	{
		dfn[u] = low[u] = ++dfsc;
		ins[u] = true;
		s.push(u); int v;
		for (int i=head[u];i;i=e[i].next)
		{
			v = e[i].to;
			if (!dfn[v])
			{
				tarjan(v);
				low[u] = min(low[u],low[v]);	
			}
			else if (ins[v])
				low[u] = min(low[u],dfn[v]);
		}
		int now;
		if (low[u] == dfn[u])
		{
			++scnt;
			while (true)
			{
				++sz[scnt];
				now = s.top(); s.pop();
				W[scnt] += w[now]; V[scnt] += val[now];
				scc[now] = scnt;
				ins[now] = false;
				if (now == u)
					break;
			}
		}	
	}
	void Work()
	{
		for (int i=1;i<=n;++i)
			if (!scc[i])
				tarjan(i);
		for (int i=1;i<=n;++i)
			if (scc[d[i]] != scc[i])
				D[scc[i]] = scc[d[i]]; 	
	}
} T; 
int l[N],r[N];
void Rebuild()
{
	Clre(l); Clre(r);
	for (int i=1;i<=n;++i)
	{
		if (D[i] == 0)
			D[i] = n + 1;
		if (l[D[i]] != 0)
			r[i] = l[D[i]];
		l[D[i]] = i;
	}
}
int f[N][M],t[N][M];
void Dp(int i,int j)
{
	if (t[i][j] || !i || !j) return;
	Dp(r[i],j); //ฒปัก 
	int res = f[r[i]][j];
	for (int k=W[i];k<=j;++k)//ัก 
	{
		Dp(l[i],k - W[i]);
		Dp(r[i],j - k);
		res = max(res,f[l[i]][k - W[i]] + f[r[i]][j - k] + V[i]);
	}
	f[i][j] = res;
	++t[i][j];
}
void Readin()
{
	n = read(); m = read();
	for (int i=1;i<=n;++i)
		T.w[i] = read();
	for (int i=1;i<=n;++i)
		T.val[i] = read();
	T.Init();
	bool ind[N];int x;
	Clre(ind);
	for (int i=1;i<=n;++i)
	{
		T.d[i] = read();
		T.Insert(T.d[i],i); 
	}
}
int main()
{
	Readin();
	T.Work();
	Rebuild();
	Clre(t);
	Dp(n + 1,m);
	printf("%d\n",f[n + 1][m]);
    return 0;
}
