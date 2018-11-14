#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 1e3 + 10;
const int M = 2 * N;
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
	int to, next;
} e[M];
int head[N], cnt = 0;
void Insert(int u, int v)
{
	e[++cnt] = (edge){v, head[u]};
	head[u] = cnt;
}
//Code
int n, m;
void Init()
{
	n = read(); m = read();
	int u, v;
	for (int i = 2; i <= n; ++i)
	{
		u = read(), v = read();
		Insert(u, v);
		Insert(v, u);
	}
}
int sz[N], belong[N], q[N], cap[N], ans = 0, top = 0;
void Dfs(int u, int fa)
{
	q[++top] = u;
	for (int i = head[u], v; i; i = e[i].next)	
		if ((v = e[i].to) != fa)
		{	
			Dfs(v, u);
			if ((sz[u] += sz[v]) >= m)
			{
				sz[u] = 0;
				cap[++ans] = u;
				while (q[top] != u)
					belong[q[top--]] = ans;
			}
		}
	sz[u]++;
}

void Paint(int u, int fa, int c)
{
	if (belong[u])
		c = belong[u];
	else 
		belong[u] = c;
	for (int i = head[u], v; i; i = e[i].next)
		if ((v = e[i].to) != fa)
			Paint(v, u, c);
}
 
int main()
{
	Init();
	if (n < m)
	{
		puts("0");
		return 0;
	}
	Clr(belong, 0);
	Dfs(1, 0);
	if (!ans)
		cap[++ans] = 1;
		
	Paint(1, 0, ans);
	printf("%d\n", ans);
	for (int i = 1; i <= n; ++i)
		printf("%d ", belong[i]);
	puts("");
	for (int i = 1; i <= ans; ++i)
		printf("%d ", cap[i]);
	puts("");
    return 0;
}


