#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 15;
const double eps = 1e-8;
const int Inf = 0x3f3f3f3f;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
int n, m, K, a[N][N], s[N][N];
double f[N][N][N][N][N], ave;
//Struct

//Code
double Dfs(int x1, int y1, int x2, int y2, int k)
{
	double &res = f[x1][y1][x2][y2][k];
	if (res >= 0)
		return res;
	if (k == 0)
	{
		res = s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];
		res = (res - ave) * (res - ave);
		return res;
	}
	res = Inf;
	for (int x = x1 + 1; x <= x2; ++x)
		for (int i = 0; i < k; ++i)
			res = min(res, Dfs(x1, y1, x - 1, y2, i) + Dfs(x, y1, x2, y2, k - i - 1));
	for (int y = y1 + 1; y <= y2; ++y)
		for (int i = 0; i < k; ++i)
			res = min(res, Dfs(x1, y1, x2, y - 1, i) + Dfs(x1, y, x2, y2, k - i - 1));
	return res;
}

int main()
{
	int n = read(), m = read(), K = read();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			a[i][j] = read();
	Clr(s, 0); Clr(f, -1);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
	ave = (double)s[n][m] / K;
	Dfs(1, 1, n, m, K - 1);
	printf("%.2lf\n", sqrt(f[1][1][n][m][K - 1] / K));
    return 0;
}


