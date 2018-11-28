#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
const int N = 1e5 + 10;
const int M = 1e6 + 10;
const int Inf = 0x3f3f3f3f;
using namespace std;
int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}

struct edge
{
	int to,next;
} e[M];
int head[N],cnt = 0;
void Insert(int u,int v)
{
	e[++cnt] = (edge){v,head[u]};
	head[u] = cnt;
}
int n,m;
void Readin()
{
	n = read();m = read();
	int x,y;
	for (int i=1;i<=m;++i)
	{
		x = read(); y = read();
		Insert(y,x);
	}
}

stack<int> s;
int num[N],dfn[N],low[N],scc[N],dfsc = 0,scnt = 0;
bool ins[N];
void Dfs(int u)
{
	dfn[u] = low[u] = ++dfsc;
	ins[u] = true;
	s.push(u);
	int v;
	for (int i=head[u];i;i=e[i].next)
	{
		v = e[i].to;
		if (!dfn[v])
		{
			Dfs(v);
			low[u] = min(low[u],low[v]);
		}	
		else if (ins[v])
			low[u] = min(low[u],dfn[v]);
	}
	if (low[u] == dfn[u])
	{
		++scnt;
		while (1)
	    {
			++num[scnt];
			int now = s.top();
			s.pop();
			ins[now] = false;
			scc[now] = scnt;
			if (now == u)
			break;
	    }
	}
}
int t[N];
void Work()
{
	for (int i=1;i<=n;++i)
		if (!dfn[i])
			Dfs(i);
	for (int i=1;i<=n;++i)
		for (int k=head[i];k;k=e[k].next)
		{
			int v = e[k].to;
			if (scc[i] != scc[v])
				++t[scc[v]];
		}
	int ans = 0,u = 0;
	for (int i=1;i<=scnt;++i)
		if (!t[i])
			ans = num[i],++u;
	if (u == 1)
		printf("%d\n",ans);
	else 
		puts("0");
}
int main()
{
	Readin();
	Work();
    return 0;
}


