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
const int N = 1e2 + 10;
const int Mo = 2009;
const int Inf = 0x3f3f3f3f;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
//Struct
struct Martix
{
	int a[N][N];
	Martix()
	{
		Clr(a, 0);
	}
	int* operator [] (int x)
	{
		return a[x];
	}
} a;
//Code
int n, m, t;
void operator *= (Martix &x, Martix &y)
{
	Martix res;
	for(int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= n; ++k)
      			res[i][j] = (res[i][j] + x[i][k] * y[k][j] % Mo) % Mo;
  	x = res;
}
Martix Pow(int b)
{
	Martix res;
	for (int i = 1; i <= n; ++i)
		res[i][i] = 1;
	for (int i = b; i; i >>= 1, a *= a)
		if (i & 1)
			res *= a; 
	return res;
}
int P(int i, int j)
{
	return (i - 1) * 9 + j;
}
int main()
{
	m = read(); t = read(); n = m * 9;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= 8; ++j)
			a[P(i, j)][P(i, j + 1)] = 1;
	int x;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= m; ++j)
		{
			scanf("%1d", &x);
			if (x != 0)
				a[P(i, x)][P(j, 1)] = 1;
		}
	Martix ans = Pow(t);
	printf("%d\n", ans[1][P(m, 1)]);
	return 0;
}


