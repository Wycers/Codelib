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

ll read()
{
    ll x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
//Struct
struct point
{
	ll x, y; int id;
	void Init()
	{
		ll X = read(); ll Y = read();
		x = X + Y;
		y = X - Y;
	} 
} p[N];
bool cmpx(point a, point b)
{
	return a.x < b.x;
}
bool cmpy(point a, point b)
{
	return a.y < b.y;
}
//Code
int n; ll ans[N];
int main()
{
	n = read();
	for (int i = 1; i <= n; ++i)
	{
		p[i].Init();
		p[i].id = i;
	}
	
	ll sumx = 0, sumy = 0, now;
	for (int i = 1; i <= n; ++i)
		sumx += p[i].x, sumy += p[i].y;
	
	Clr(ans, 0);
	
	sort(p + 1, p + n + 1, cmpx); now = 0;
	for (int i = 1; i <= n; ++i)
	{
		/*ans[p[i].id] += (ll)(i - 1) * p[i].x - now;
		ans[p[i].id] += (ll)(sumx - now) - (ll)(n - i + 1) * p[i].x; */
		ans[p[i].id] += sumx - now - now - (ll)(n - i + 1) * p[i].x + (ll)(i - 1) * p[i].x;
		now += p[i].x;
	}
	sort(p + 1, p + n + 1, cmpy); now = 0;
	for (int i = 1; i <= n; ++i)
	{
		/*ans[p[i].id] += (ll)(i - 1) * p[i].y - now;
		ans[p[i].id] += (ll)(sumy - now) - (ll)(n - i + 1) * p[i].y; */
		ans[p[i].id] += sumy - now - now - (ll)(n - i + 1) * p[i].y + (ll)(i - 1) * p[i].y;
		now += p[i].y;
	} 
	ll Ans = 1e18;
	for (int i = 1; i <= n; ++i)
		Ans = min(Ans, ans[i]);	
	printf("%lld\n", Ans >> 1);
    return 0;
}


