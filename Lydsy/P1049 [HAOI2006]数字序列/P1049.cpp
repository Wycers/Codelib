#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 35010;
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
} e[N];
int head[N], cnt = 0;
void Insert(int u, int v)
{
	e[++cnt] = (edge){v, head[u]};
	head[u] = cnt;
}
//Code
int n, a[N], mn[N], f[N], L;
int find(int x)
{
	int l = 1, r = L, mid, t = 0;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (mn[mid] <= x)
			t = mid, l = mid + 1;
		else
			r = mid - 1;
	}
	return t;
}
void Dp()
{
	Clr(mn, 0x3f);
	mn[0] = -1 << 30;
	for (int i = 1; i <= n; ++i)
	{
		int t = find(a[i]);
		L = max(L, f[i] = t + 1);
		mn[t + 1] = min(mn[t + 1], a[i]);
	}
	printf("%d\n", n - f[n]);
}
ll g[N], s1[N], s2[N];
void Solve()
{
	Clr(g, 0x3f);
	for (int i = n; i >= 0; --i)
		Insert(f[i], i);
	g[0] = 0; a[0] = -1 << 30;
	for (int i = 1; i <= n; ++i)
		for (int k = head[f[i] - 1], p; k; k = e[k].next)
		{
			p = e[k].to;
			if (p > i)
				break;
			if (a[p] > a[i])
				continue;
			for(int j = p; j <= i; j++)
				s1[j] = abs(a[p] - a[j]), s2[j] = abs(a[i] - a[j]);
			for(int j = p + 1; j <= i ; j++)
				s1[j] += s1[j - 1], s2[j] += s2[j - 1];
			for(int j = p; j < i; j++)
				g[i] = min(g[i], g[p] + s1[j] - s1[p] + s2[i] - s2[j]);
		}
	cout << g[n] << endl;
}
int main()
{
	n = read();
	for (int i = 1; i <= n; ++i)
		a[i] = read() - i;
	a[++n] = 1 << 30;
	Dp();
	Solve();
    return 0;
}


