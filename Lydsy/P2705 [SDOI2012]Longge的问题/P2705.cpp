#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
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
ll n, m;
ll phi(ll x)
{
	ll res = x, lim = sqrt(x);
	for (int i = 2; i <= lim; ++i)
		if (x % i == 0)
		{
			res = res / i * (i - 1);
			while (x % i == 0)
				x /= i; 
		} 
	if (x > 1)
		res = res / x * (x - 1);
	return res;
}

int main()
{
	m = sqrt(n = read());
	ll ans = 0; 
	for (int i = 1; i <= m; ++i)
		if (n % i == 0)
		{
			ans += (ll)i * phi(n / i);
			ans += (ll)(n / i) * phi(i);
		}
	cout << ans << endl;
    return 0;
}


