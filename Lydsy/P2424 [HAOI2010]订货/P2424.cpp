#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
typedef long long ll;
using namespace std;
const int N = 150;
const int M = 500;
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
	int to,next,w,c;
};
struct Network
{
	edge e[M];
	int head[N],cnt,S,T,ans;
	void Init(int s,int t)
	{
		S = s; T = t; ans = 0;
		cnt = 1;
	}
	void Insert(int u,int v,int w,int c)
	{
		e[++cnt] = (edge){v,head[u],w, c}; head[u] = cnt;
		e[++cnt] = (edge){u,head[v],0,-c}; head[v] = cnt;	
	}
	queue<int> q;
	int dis[N];bool vis[N];
	bool Spfa()
	{
		memset(dis,0x3f,sizeof(dis));
		memset(vis,false,sizeof(vis));
		q.push(T); vis[T] = true; dis[T] = 0;
		int u,v;
		while (!q.empty())
		{
			u = q.front(); q.pop();
			for (int i=head[u];i;i=e[i].next)
			{
				v = e[i].to;
				if (e[i ^ 1].w && dis[u] + e[i ^ 1].c < dis[v])
				{
					dis[v] = dis[u] + e[i ^ 1].c;
					if (!vis[v])
					{
						q.push(v);
						vis[v] = true;	
					}	
				}	
			}	
			vis[u] = false;
		}
		return dis[S] != Inf;
	}
	int Dfs(int u,int f)
	{
		vis[u] = true;
		if (u == T)
			return f;
		int v,w,used = 0;
		for (int i=head[u];i;i=e[i].next)
		{
			v = e[i].to;
			if (!vis[v] && e[i].w && dis[u] - e[i].c == dis[v])	
			{
				w = Dfs(v,min(e[i].w,f - used));
				ans += w * e[i].c;
				e[i].w -= w;
				e[i ^ 1].w += w;
				if ((used += w) == f)
					return f;	
			}
		}
		return used;
	}
	void Zkw()
	{
		while (Spfa())
		{
			vis[T] = true;
			while (vis[T])
			{
				memset(vis,false,sizeof(vis));
				Dfs(S,Inf);		
			}	
		}	
	}
} G;
int n,m,s;
void Init()
{
	n = read(); m = read(); s = read();
	G.Init(0,n + 2);
	for (int i=1;i<=n;++i)
		G.Insert(i,G.T,read(),0);
	for (int i=1;i<=n;++i)
		G.Insert(G.S,i,Inf,read());	
	for (int i=1;i<n;++i)
		G.Insert(i,i + 1,s,m);	
}
int main()
{
	Init();
	G.Zkw();
	printf("%d\n",G.ans);
    return 0;
}


