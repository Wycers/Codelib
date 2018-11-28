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
const int N = 2e3 + 10;
const int Inf = 0x3f3f3f3f;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
//Struct

//Code
struct edge
{
	int to,next,w;
} e[2 * N];
int head[N],cnt = 0;
void Insert(int u,int v,int w)
{
	e[++cnt] = (edge){v,head[u],w}; head[u] = cnt;
	e[++cnt] = (edge){u,head[v],w}; head[v] = cnt;
}
int n,K,sz[N];ll f[N][N];
void Init()
{
	n = read(); K = read();
	int u,v,w;
	for (int i = 2;i <= n;++i)
	{
		u = read(); v = read(); w = read();
		Insert(u,v,w);	
	}
}
void dp(int u,int fa)
{
    sz[u] = 1; f[u][0] = f[u][1] = 0;
    int v;
    for(int i = head[u];i;i = e[i].next)
		if((v = e[i].to) != fa)
		{
			dp(v,u);
	        sz[u] += sz[v];
	        for(int j = sz[u];j >= 0;--j)
				for(int k = 0,lim = min(sz[v],j);k <= lim;++k)
	            	f[u][j] = max(f[u][j],f[u][j - k] + ((ll)(k * (K - k)) + (ll)(sz[v] - k) * (ll)(n - K - (sz[v] - k))) * (ll)e[i].w + f[v][k]);
      	}
}
int main()
{
    memset(f,128,sizeof(f));
	Init();
	dp(1,0);
	printf("%lld\n",f[1][K]);
    return 0;
}


