#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
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
int n, p[N], cnt = 0;
bool vis[N];
void GetPrime()
{
	Clr(vis, false);
	for (int i = 2; i <= 50000; ++i)
		if (!vis[i])
			for (ll j = (ll)i * i; j <= 50000; j += i)
				vis[j] = true;
	for (int i = 2; i <= 50000; ++i)
		if (!vis[i])
			p[++cnt] = i;
}
vector<int> ans;
int lim;
bool Judge(int x)
{
	if (x <= 50000)
		return !vis[x];
	for (int i = 1, t = sqrt(x); i <= cnt, p[i] <= t; ++i)
		if (x % p[i] == 0)
			return false;
	return true; 
}
 
void Dfs(int last, ll tot, int sum)
{
	if (tot == 1)
	{
		ans.push_back(sum);
		return;
	}
	if (tot - 1 > lim && Judge(tot - 1))
		ans.push_back(sum * (tot - 1));
	ll tmp, t;
	for (int i = last + 1; p[i] <= lim; ++i)
	{
		tmp = 1, t = p[i];
		for (int j = 1; tmp + t <= tot; ++j)
		{
			tmp += t;
			if (tot % tmp == 0)
				Dfs(i, tot / tmp, sum * t);
			t *= p[i];
		}
	}
}
int main()
{
	GetPrime();
	while (scanf("%d", &n) != EOF)
	{
		ans.clear(); lim = sqrt(n);
		Dfs(0, n, 1);
		sort(ans.begin(), ans.end());
		printf("%d\n", cnt = ans.size());
		for (int i = 0; i < cnt; ++i)
			printf("%d%c", ans[i], i == cnt - 1 ? '\n' : ' ');
	} 
    return 0;
}


