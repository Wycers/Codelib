#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
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
int n, m, a[N];
ll t1[N], t2[N];
char str[10];
void Add(ll *tr, int pos, ll val)
{
	for (; pos <= n; pos += pos & -pos)
		tr[pos] += val;
}
ll Query(ll *tr, int pos)
{
	ll res = 0;
	for (; pos; pos -= pos & -pos)
		res += tr[pos];
	return res; 
}
int main()
{
	n = read(); m = read();
	int x, y;
	Clr(t1, 0); Clr(t2, 0);
	for (int i = 1; i <= n; ++i)
	{
		a[i] = read();
		Add(t1, i, a[i]);
		Add(t2, i, (ll)(n - i + 1) * a[i]);
	}
	for (int i = 1; i <= m; ++i)
	{
		scanf("%s", str);
		if (str[0] == 'Q')
		{
			x = read();
			printf("%lld\n", Query(t2, x) - (n - x) * Query(t1, x));
		}
		else
		{
			x = read(); y = read();
			Add(t1, x, y - a[x]);
			Add(t2, x, (ll)(n - x + 1) * (y - a[x]));
			a[x] = y;
		}
	}
    return 0;
}


