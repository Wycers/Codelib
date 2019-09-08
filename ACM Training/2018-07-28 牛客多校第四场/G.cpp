//=============================================================
// File Name: G.cpp
// Author: Wycer
// Created Time: 2018-07-29 11:34
//=============================================================
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, m, a[N];

void readin()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
}


int sum[N], tmp[N], cnt[N], v[N], tag[N], p[N];
struct data
{
	int cnt, val;
} b[N];
bool cmp(const data& x, const data& y)
{
	return x.cnt < y.cnt;
}

void solve()
{
	memcpy(tmp, a, sizeof a);
	sort(tmp + 1, tmp + 1 + n);
	int tot = unique(tmp + 1, tmp + 1 + n) - tmp - 1;
	memset(cnt, 0, sizeof cnt);
	for (int i = 1; i <= n; ++i)
	{
		int pos = lower_bound(tmp + 1, tmp + 1 + tot, a[i]) - tmp;
		cnt[pos]++;
		v[pos] = a[i];
	}
	for (int i = 1; i <= tot; ++i)
		b[i] = (data){cnt[i], v[i]};
	sort(b + 1, b + tot + 1, cmp);
 
	for (int i = 1; i <= tot; ++i)
		sum[i] = sum[i - 1] + b[i].cnt;

	int ans = -1;
	for (int i = 1; i <= tot; ++i)
		p[i] = b[i].cnt == b[i - 1].cnt ? p[i - 1] : i;
	for (int i = 1; i <= tot; ++i)
		if (m >= sum[tot] - sum[p[i] - 1] - (tot - p[i] + 1) * (b[i].cnt - 1) - 1)
			ans = max(ans, b[i].val);
	printf("%d\n", ans);
}	

int main()
{
	freopen("test.in", "r", stdin);
 	int T;
	scanf("%d", &T);
	while (T--)
	{
		readin();
		solve();
	}	
	return 0;
}
