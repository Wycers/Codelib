#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
const int Inf = 0x3f3f3f3f;

ll read()
{
    ll x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
//Struct
struct Ans
{
	ll a[10];
	Ans()
	{
		Clr(a, 0);
	}
	Ans operator - (Ans y)
	{
		Ans res;
		for (int i = 0; i < 10; ++i)
			res.a[i] = a[i] - y.a[i];
		return res; 
	}
	Ans operator + (Ans y)
	{
		Ans res;
		for (int i = 0; i < 10; ++i)
			res.a[i] = a[i] + y.a[i];
		return res;
	}
} A, B, f[15][10];
//Code
ll a, b, bin[15];
Ans Cal(ll x)
{
	Ans res;
	if (!x)
	{
		res.a[0] = 1;
		return res;
	}
	int len;
	for (len = 12; bin[len] > x; --len);
	for (int i = 1; i < len; ++i)
		for (int j = 1; j < 10; ++j)
			res = res + f[i][j];
	res.a[0]++;
	int cur = x / bin[len];
	for (int i = 1; i < cur; ++i)
		res = res + f[len][i];
	x %= bin[len];
	res.a[cur] += x + 1;
	for (int i = len - 1; i; --i)
	{
		cur = x / bin[i];
		for (int j = 0; j < cur; ++j)
			res = res + f[i][j];
		x %= bin[i];
		res.a[cur] += x + 1;
	}
	return res;
	
}
void Prt(Ans x)
{
	for (int i = 0; i < 10; ++i)
		printf("%lld%c", x.a[i], i == 9 ? '\n' : ' ');
}
int main()
{
	a = read(); b = read();
	bin[1] = 1;
	for (int i = 2; i <= 12; ++i)
		bin[i] = bin[i - 1] * 10;
	for (int i = 0; i < 10; ++i)
		f[1][i].a[i] = 1;
	for (int i = 2; i <= 12; ++i)
		for (int x = 0; x < 10; ++x)
			for (int y = 0; y < 10; ++y)
			{
				f[i][y] = f[i][y] + f[i - 1][x];
				f[i][y].a[y] += bin[i - 1];
			}
	for (int i = 1; i <= 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
			Prt(f[i][j]);
		puts("");
	}
	Prt(Cal(b) - Cal(a - 1));
    return 0;
}


