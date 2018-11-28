#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#define Clr(x, y) memset(x, y, sizeof(x))
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
const int Mo = 1e4;
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
int n, m, f[1005][1005];
int g[1005][1005];
int main()
{
	n = read(); m = read();
	/*
	f[0][0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
			for (int k = j - i; k <= j; ++k)
				f[i][j] += f[i - 1][k];
	*/
	f[0][0] = 1;
	for (int i = 0; i <= m; ++i)
		g[0][i] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
		{
			if (j - i >= 0)
				f[i][j] = (g[i - 1][j] - g[i - 1][j - i] + Mo) % Mo;
			else
				f[i][j] = g[i - 1][j];
			if (j == 0)
				g[i][j] = f[i][j];
			else
				g[i][j] = (g[i][j - 1] + f[i][j]) % Mo;
		} 
	printf("%d\n", f[n][m]);
	return 0;
}


