//=============================================================
// File Name: D.cpp
// Author: Wycer
// Created Time: 2018-07-30 23:11
//=============================================================
#include <cstdio>
const int N = 2e5 + 10;
int n, m, q, fa[N << 1];
int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main()
{
  	scanf("%d%d%d", &n, &m, &q);
	int x, y;
	for (int i = 1; i <= n + m; ++i)
		fa[i] = i;
	for (int i = 1; i <= q; ++i)
	{
		scanf("%d%d", &x, &y);
		fa[find(x + m)] = find(y);
	}
	int ans = -1;
	for (int i = 1; i <= n + m; ++i)
		if (i == find(i))
			++ans;
	printf("%d\n", ans);
    return 0;
}
