//=============================================================
// File Name: C.cpp
// Author: Wycer
// Created Time: 2018-07-30 16:50
//=============================================================
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n, a[N << 1];

long long mi(long long a, long long b)
{
	return a < b ? a : b;
}
long long ma(long long a, long long b)
{
	return a > b ? a : b;
}
int main()
{
  	scanf("%d", &n);
	int m = n << 1;
	for (int i = 1; i <= m; ++i)
		scanf("%d", a + i);
   	sort(a + 1, a + m + 1);
	if (n == 1)
	{
		puts("0");
		return 0;
	}
	long long ans = (long long)(a[n] - a[1]) * (a[m] - a[n + 1]);
	for (int i = 2; i <= n; ++i)
		ans = mi(ans, (long long)(a[i + n - 1] - a[i]) * (a[m] - a[1]));		
	cout << ans << endl;
	return 0;
}
