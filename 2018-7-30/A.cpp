//=============================================================
// File Name: A.cpp
// Author: Wycer
// Created Time: 2018-07-30 16:24
//=============================================================
#include <cstdio>
const int N = 55;
int n, a[N], b[N];
int main()
{
  	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	for (int i = 1; i <= n; ++i)
		scanf("%d", b + i);
	int sum = 0;
	for (int i = 1; i <= n; ++i)
		sum += a[i] - b[i];
	puts(sum >= 0 ? "Yes" : "No");
	return 0;
}
