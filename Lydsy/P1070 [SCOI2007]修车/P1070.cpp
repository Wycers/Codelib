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
const int N = 1500;
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
//Code
int t[100][10],n,m;
void Init()
{
	scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&t[i][j]);
    G.Init(0,1001);
    
    for(int i=1;i<=n*m;i++)
        G.Insert(G.S,i,1,0);
    for(int i=n*m+1;i<=n*m+m;i++)
        G.Insert(i,G.T,1,0);
        
    for(int i=1;i<=n;i++)
    	for(int j=1;j<=m;j++)
        	for(int k=1;k<=m;k++)
            	G.Insert((i-1)*m+j,n*m+k,1,t[k][i]*j);

}

int main()
{
	Init();
	G.Zkw();
	printf("%.2lf\n",(double)G.ans / m);
    return 0;
}


