//=============================================================
// File Name: L.cpp
// Author: Wycer
// Created Time: 2018-05-12 00:03
//=============================================================
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1000;
int read()
{
	int x = 0; char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') 
	{
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x;
}
int sum[N], p[N];
int cal(int x)
{
	if (x % 10 == 9)
	{
		if ((x / 10) % 10 == 9)
			return 19;
		return 10;
	}
	return 1;
}
void prework()
{
	for (int i = 1; i <= 999; ++i)
		p[i] = cal(i - 1);
	sum[0] = p[0];
	for (int i = 1; i <= 999; ++i)
		sum[i] = sum[i - 1] + p[i];
}
int solve()
{
	int res = 0;
	int a = read(); int b = read();
	int k = read();

	for (int i = 0; i <= k; ++i)
		res = max(res, sum[a + i] + sum[b + k - i] - sum[a] - sum[b]);
	return res;
}
int main()
{
	prework();
	for (int i = 1, T = read(); i <= T; ++i)
		printf("Case %d: %d\n", i, solve());
	return 0;
}
