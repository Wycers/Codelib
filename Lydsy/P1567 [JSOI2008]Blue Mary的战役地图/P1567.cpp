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
ll T[55], f[2][55][55], H[5005];
int n, cnt, a[2][55][55];
ll cal(int t, int x, int y, int l)
{
	ll val = 1;
	for (int i = x; i <= x + l - 1; ++i)
		val = (val * 3659 + f[t][i][y + l - 1] - f[t][i][y - 1] * T[l]);
	return val;
}
bool Judge(int x)
{
	cnt = 0;
	for (int i = 1; i <= n - x + 1; ++i)
		for (int j = 1; j <= n - x + 1; ++j)
			H[++cnt] = cal(0, i, j, x);
	sort(H + 1, H + cnt + 1);
	for (int i = 1; i <= n - x + 1; ++i)
		for (int j = 1; j <= n - x + 1; ++j)
		{
			ll t = cal(1, i, j, x);
			if (*lower_bound(H + 1, H + cnt + 1, t) == t)
				return true;
		}
	return false;
}
int main()
{
	T[0] = 1;
	for (int i = 1;i <= 50; ++i)
		T[i] = T[i - 1] * 1789;
	n = read();
	for (int k = 0; k <= 1; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				a[k][i][j] = read();
	for (int k = 0; k <= 1; ++k)
		for (int i = 1; i <= n; ++i)
		{
			f[k][i][0] = 1;
			for (int j = 1; j <= n; ++j)
				f[k][i][j] = f[k][i][j - 1] * 1789 + a[k][i][j];
		}
	int l = 1, r = n, mid, ans;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (Judge(mid))
		{
			ans = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	printf("%d\n", ans);
    return 0;
}


