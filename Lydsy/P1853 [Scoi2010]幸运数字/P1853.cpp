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
const int N = 1e5 + 10;
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
ll gcd(ll x, ll y)
{
	return y == 0 ? x : gcd(y, x % y);
}
ll l, r, a[N], b[N]; bool avi[N]; int n = 0, m = 0;
void Pre(int x, ll y)
{
	if (y > r)
		return;
	if (x > 0)
		a[++m] = y;
	Pre(x + 1, y * 10 + 6);
	Pre(x + 1, y * 10 + 8);
}
ll ans = 0;
void Dfs(int x, int y, ll lcm)
{
	if (x > n)
	{
		if (y & 1)
			ans += r / lcm - (l - 1) / lcm;
		else if (y)
			ans -= r / lcm - (l - 1) / lcm;
		return;
	}
	Dfs(x + 1, y, lcm);
	ll tmp = lcm / gcd(a[x], lcm);
	if (((double)a[x] * tmp) <= r)
		Dfs(x + 1, y + 1, a[x] * tmp);
	
}
int main()
{
	l = read(); r = read();
	Pre(0, 0);
	sort(a + 1, a + m + 1);
	Clr(avi, true);
	for (int i = 1; i <= m; ++i)
		if (avi[i])
		{
			b[++n] = a[i];
			for (int j = i + 1; j <= m; ++j)
				if (a[j] % a[i] == 0)
					avi[j] = false;
		}
	for (int i = 1; i <= n; ++i)
		a[n - i + 1] = b[i];
	Dfs(1, 0, 1);
	cout << ans << endl;
    return 0;
}


