#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define For(i,x,y) for (int i=x;i<=y;++i)
#define Dor(i,x,y) for (int i=x;i>=y;--i)
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 60;
const int M = 2600;
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
int n, m, T, f[N][N], dp[N][M] = {0}, sum[N] = {0};
char s[N];
int main()
{
	n = read(); m = read(); T = read();
	for (int i = 1; i <= n; ++i)
	{
		scanf("%s", s + 1);
		for (int j = 1; j <= m; ++j)
			sum[j] = sum[j - 1] + s[j] - '0';
		for (int j = 1; j <= m; ++j)
			for (int x = 1; x <= m; ++x)
			{
				f[x][j] = 0;
				for (int y = 0; y < x; ++y)
				{
					int tmp = sum[x] - sum[y];
					f[x][j] = max(f[x][j], f[y][j - 1] + max(tmp, x - y - tmp));
				}
			}
		for (int j = 1; j <= T; ++j)
			for (int k = 1, tmp = min(j, m); k <= tmp; ++k)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + f[m][k]);
	}
	int ans = -1;
	for (int i = 1; i <= T; ++i)
		ans = max(ans, dp[n][i]);
    printf("%d",ans);
    return 0;
}


