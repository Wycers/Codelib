//=============================================================
// File Name: B.cpp
// Author: Wycer
// Created Time: 2018-07-30 16:35
//=============================================================
#include <cstdio>
#include <cstring>
#include <set>
int n, x, a[100005]; bool ex[500005];
int main()
{
  	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	memset(ex, false, sizeof ex);
	for (int i = 1; i <= n; ++i)
	{
		if (ex[a[i]])
		{
			puts("0");
			return 0;
		}
		ex[a[i]] = true;
	}
	for (int i = 1; i <= n; ++i)
		if (ex[a[i] & x] && (a[i] & x) != a[i])
		{
			puts("1");
			return 0;
		}
	memset(ex, false, sizeof ex);
	for (int i = 1; i <= n; ++i)
	{
		if (ex[a[i] & x])
		{
			puts("2");
			return 0;
		}
		ex[a[i] & x] = true;
	}
	puts("-1");
 	return 0;
}
