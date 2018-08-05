//=============================================================
// File Name: M.cpp
// Author: Wycer
// Created Time: 2018-05-10 13:09
//=============================================================
#include <cstdio>
#include <cmath>
int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || '9' < ch) { if (ch == '-') f = -1; ch = getchar(); }
	while ('0' <= ch && ch <= '9') { x = x * 10 + ch - 48; ch = getchar(); }
	return x * f;
}
int n, p[5];
int solve()
{
	for (int i = 0; i < 5; ++i)
		p[i] = read();
	n = read();
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		int x = read();
		if (x <= 48)
			ans += p[0];
		else if (x <= 56)
			ans += p[1];
		else if (x <= 60)
			ans += p[2];
		else if (x <= 62)
			ans += p[3];
		else if (x <= 63)
			ans += p[4];
	}
	return ans;
}
int main()
{
	for (int T = read(), i = 1; i <= T; ++i)
		printf("Case #%d: %d0000\n", i, solve());
	return 0;
}
