#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 1e3 + 10;
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
int gcd[N][N];
int Gcd(int x, int y)
{
	if (gcd[x][y])
		return gcd[x][y];
	return gcd[x][y] = gcd[y][x] = (y == 0) ? x : Gcd(y, x % y);
}
int n, m;
int main()
{
	n = read(); m = read();
	ll t = (n + 1) * (m + 1), ans = t * (t - 1) * (t - 2) / 6;
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
			if (i || j)
			{
				ans -= (ll)(Gcd(i, j) - 1) * (n - i + 1) * (m - j + 1);
				if (i && j)
					ans -= (ll)(Gcd(i, j) - 1) * (n - i + 1) * (m - j + 1);
			}
    printf("%lld\n", ans);  
    return 0;
}


