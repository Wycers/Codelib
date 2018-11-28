#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 1e6 + 10;
const int Inf = 0x3f3f3f3f;

ll read()
{
    ll x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
//Struct

//Code
int n, l, r;
ll p[N], x[N], c[N], f[N];
ll b[N], sum[N];
int q[1000005];
inline double slope(int k, int j)
{
	return (double)(f[j] - f[k] + b[j] - b[k]) / (double)(sum[j] - sum[k]);
}
int main()
{
	n = read();
	for (int i = 1; i <= n; ++i)
		x[i] = read(), p[i] = read(), c[i] = read();
	for (int i = 1; i <= n; ++i)
	{
		sum[i] = sum[i - 1] + p[i];
		b[i] = b[i - 1] + p[i] * x[i];
	}
	int t;
	for (int i = 1; i <= n; ++i)
	{
		while (l < r && slope(q[l], q[l + 1]) < x[i])
			++l;
		t = q[l];
		f[i] = f[t] - b[i] + b[t] + (sum[i] - sum[t]) * x[i] + c[i];
		while (l < r && slope(q[r - 1], q[r]) > slope(q[r], i))
			--r;
		q[++r] = i;
	}
	printf("%lld",f[n]);
    return 0;
}


