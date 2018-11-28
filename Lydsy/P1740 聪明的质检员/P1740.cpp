#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 2e5 + 10;
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
int n, m, w[N], v[N], s[N], t[N], mx = 0;ll S;
void Readin()
{
	n = read(); m = read(); scanf("%lld", &S);
	for (int i = 1; i <= n; ++i)
		w[i] = read(), v[i] = read(), mx = max(mx, w[i]);
	for (int i = 1; i <= m; ++i)
		s[i] = read(), t[i] = read();
}
ll cnt[N], tr[N];
int lowbit(int x)
{
	return x & -x;
}
void Add(int pos, int val)
{
	for (int i = pos; i <= n; i += lowbit(i))
		tr[i] += val, cnt[i]++;
}
pair<ll, ll> Query(int pos)
{
	ll res1 = 0, res2 = 0;
	for (int i = pos; i >= 1; i -= lowbit(i))
		res1 += cnt[i], res2 += tr[i];
	return make_pair(res1, res2);
}
ll Judge(int x)
{
	Clr(tr, 0); Clr(cnt, 0);
	for (int i = 1; i <= n; ++i)
		if (w[i] >= x)
			Add(i, v[i]);
	ll res = 0; pair<ll, ll> a, b;
	for (int i = 1; i <= m; ++i)
	{
		a = Query(s[i] - 1);
		b = Query(t[i]);
		res += (ll)(b.first - a.first) * (b.second - a.second);
	}
	return res;
}
void Work()
{
	int l = 1, r = mx + 100, mid; ll tmp, res = 0x3f3f3f3f3f3f3f3f;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		tmp = Judge(mid);
		if (res > abs(tmp - S))
			res = abs(tmp - S);
		if (tmp > S)
			l = mid + 1;
		else
			r = mid - 1;
	}
	cout << res << endl;
}
int main()
{
	Readin();	
	Work();
    return 0;
}


