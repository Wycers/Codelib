#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 1e4 + 10;
const int Inf = 0x3f3f3f3f;
const double eps = 1e-8;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
//Struct
struct point
{
	double x, y, g;
	point (double _x = 0.0, double _y = 0.0)
	{
		x = _x; 
		y = _y;
	}
	point operator - (point &b)
	{
		return point(x - b.x, y - b.y);
	}
} p[N];
double Dis(point &a, point &b)
{
	point t = a - b;
	return hypot(t.x, t.y);
}
//Code
int n;
void ClimbHill()
{
	double T = 1000, x, y;
	point res;
	for (int i = 1; i <= n; ++i)
	{
		res.x += p[i].x * p[i].g;
		res.y += p[i].y * p[i].g;
	}
	res.x /= n; res.y /= n;
	while (T > eps)
	{
		x = y = 0;
		for (int i = 1; i <= n; ++i)
		{
			x += (p[i].x - res.x) * p[i].g / Dis(res, p[i]);
			y += (p[i].y - res.y) * p[i].g / Dis(res, p[i]);
		}
		res.x += x * T, res.y += y * T;
		if (T > 0.5)
			T *= 0.5;
		else
			T *= 0.98;
	}
     printf("%.3lf %.3lf\n", res.x, res.y);
}
int main()
{
	n = read();
	for (int i = 1; i <= n; ++i)
		scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].g);
	ClimbHill();
    return 0;
}


