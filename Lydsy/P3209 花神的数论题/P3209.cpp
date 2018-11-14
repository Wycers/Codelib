#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 65;
const int Mo = 10000007;
const int Inf = 0x3f3f3f3f;

ll read()
{
    ll x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
//Struct

//Code
int len = 0, a[N]; ll c[N][N];
ll Solve(int x)
{
	ll res = 0;
	for (int i = len; i >= 1; --i)
	{
		if (a[i])
			res += c[i - 1][x--];
		if (x < 0)
			break;
	}
	return res;
}
ll pow(ll a, ll b)
{
	ll res = 1;
	for (ll i = b; i; i >>= 1, a = a * a % Mo)
		if (i & 1)
			res = res * a % Mo;
	return res;
}
int main()
{
	for (ll i = read() + 1; i; i >>= 1)
		a[++len] = i & 1;
	for (int i = 0; i < 60; ++i)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j)
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	}
	ll ans = 1; 
	for (int i = len; i >= 1; --i)
		ans = (ans * pow(i, Solve(i))) % Mo;
	printf("%lld\n", ans);
    return 0;
}


