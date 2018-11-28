#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
const int Mo = 20100403;
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
void exgcd(ll a, ll b, ll& x, ll& y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return;
	}
	exgcd(b, a % b, y, x);
	y -= x * (a / b);
}
ll n, m;
int main()
{
	n = read(); m = read();
	ll tmp1 = (n - m + 1), tmp2 = n + 1;
	for (int i = 1; i <= n + m; ++i)
		tmp1 = (ll)tmp1 * i % Mo;
	for (int i = 1; i <= n; ++i)
		tmp2 = (ll)tmp2 * i % Mo;
	for (int i = 1; i <= m; ++i)
		tmp2 = (ll)tmp2 * i % Mo;
	ll x, y;
	exgcd(tmp2, Mo, x, y);
	ll ans = tmp1 * ((x + Mo) % Mo) % Mo;
	cout << ans << endl;
    return 0;
}


