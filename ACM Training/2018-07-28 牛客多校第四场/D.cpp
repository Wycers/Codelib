//=============================================================
// File Name: D.cpp
// Author: Wycer
// Created Time: 2018-07-29 17:02
//=============================================================
#include <cstdio>


int n, a[210][210];

void work(int now)
{
	if (a[now][now] == -1)
		return;
	a[now - 1][now - 1] = 1; a[now - 1][now] = 0;
	a[now][now - 1] = 1; a[now][now] = -1;
	if (now == 2)
		return;
	for (int i = 1; i <= now - 2; ++i)
		a[now][i] = a[i][now] = (i & 1) ? 1 : -1;
	for (int i = 1; i <= now - 2; ++i)
		a[now - 1][i] = a[i][now - 1] = (i & 1) ? 1 : -1;
	work(n - 2);
}

void solve()
{
	if (n & 1)
	{
		puts("impossible");
		return;
	}
	puts("possible");
	work(n);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			printf("%d ", a[i][j]);
		puts("");
	}
}

int main()
{
  	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		solve();
	}
	return 0;
}
