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
const double eps = 1e-8;
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
int n, m, a[30], pos[30], sum[30];
double ave = 0, ans = 1e5;

#define sqr(x) ((x) * (x))
void SA()
{
	double res = 0.0;
	Clr(sum, 0);
	for (int i = 1; i <= n; ++i)
	{
		pos[i] = rand() % m + 1;
		sum[pos[i]] += a[i];
	}
	for (int i = 1; i <= m; ++i)
		res += sqr(sum[i] - ave);
	int t, x, y;
	for (double T = 2000; T > eps; T *= 0.9)
	{
		t = rand() % n + 1;
		x = pos[t];
		if (T > 200)
			y = min_element(sum + 1, sum + m + 1) - sum;
		else
			y = rand() % m + 1;
		if (x == y)
			continue;
		
		double tmp = res;
		res -= sqr(sum[x] - ave); res -= sqr(sum[y] - ave);
		sum[x] -= a[t]; sum[y] += a[t];
		res += sqr(sum[x] - ave); res += sqr(sum[y] - ave);
		
		if (res <= tmp || rand() % 2000 <= T)
			pos[t] = y; 
		else 
		{
			sum[x] += a[t]; sum[y] -= a[t];
			res = tmp; 
		} 
	}
	ans = min(ans, res);
}

int main()
{
	srand(20151113);
	n = read(); m = read();
	for (int i = 1; i <= n; ++i)
		ave += (a[i] = read());
	ave /= m;
	for (int i = 1; i <= 10000; ++i)
		SA();
	printf("%.2lf\n", sqrt(ans / m));
	return 0;
}


