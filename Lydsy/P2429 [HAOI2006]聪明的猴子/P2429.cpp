#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define For(i,x,y) for (int i=x;i<=y;++i)
#define Dor(i,x,y) for (int i=x;i>=y;--i)
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 1e3 + 10;
const int M = 5e2 + 10;
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
	int u, v, w;
} e[N * N];
int cnt = 0;
//Code
int n, m, a[M], x[N], y[N];
#define sqr(x) ((x) * (x))
int Dis(int i, int j)
{
	return sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
}
void Insert(int x, int y)
{
	e[++cnt] = (edge){x, y, Dis(x, y)};
	e[++cnt] = (edge){y, x, Dis(x, y)};	
}
void Readin()
{
	m = read();
	for (int i = 1; i <= m; ++i)
		a[i] = read();
	n = read();
	for (int i = 1; i <= n; ++i)
	{
		x[i] = read(), y[i] = read();
		for (int j = 1; j < i; ++j)
			Insert(i, j); 
	}
}

bool cmp(edge a, edge b)
{
	return a.w < b.w;
}
int fa[N];
int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void Kruskal()
{
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	sort(e + 1, e + cnt + 1, cmp);
	int x, y, val, now = 0;
	for (int i = 1; i <= cnt; ++i)
	{
		x = find(e[i].u); y = find(e[i].v);
		if (x != y)
		{
			fa[x] = y;
			if ((++now) == n - 1)
			{
				val = e[i].w;
				break;
			}
		}	
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i)
		if (sqr(a[i]) >= val)
			++ans;
	printf("%d\n", ans);
}

int main()
{
	Readin();
	Kruskal();
    return 0;
}


