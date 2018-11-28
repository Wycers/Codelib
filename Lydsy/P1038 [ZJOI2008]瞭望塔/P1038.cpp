#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 1e3 + 10;
const double eps = 1e-6;
const int Inf = 0x3f3f3f3f;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
//Struct
struct Point
{
	double x, y;
	Point(double _x = 0.0, double _y = 0.0)
	{
		x = _x;
		y = _y;
	}
	Point operator + (const Point &b)
	{
		return Point(x + b.x, y + b.y);
	}
	Point operator - (const Point &b)
	{
		return Point(x - b.x, y - b.y);
	}
	double operator * (const Point &b)
	{
		return x * b.y - y * b.x;
	}
	Point operator * (const double &b)
	{
		return Point(x * b, y * b);
	}
	void Prt()
	{
		printf("%.2lf %.2lf\n", x, y);
	}
} P[N], a[N];
struct Line
{
	Point p, v;
	double ang;
	Line(){}
	Line(Point p, Point v) : p(p), v(v)
	{
		ang = atan2(v.y, v.x);	
	}
	bool operator < (const Line &b) const
	{
		return ang < b.ang;
	}
} L[N];
//Code
int n, cnt;
void Init()
{
	n = read();
	for (int i = 1; i <= n; ++i)
		P[i].x = (double)read();
	for (int i = 1; i <= n; ++i)
		P[i].y = (double)read();
	P[0] = Point(P[1].x, 100001);
	P[n + 1] = Point(P[n].x, 100001);
	for(int i = 1; i <= n; i++)
	{
		L[++cnt] = Line(P[i - 1], P[i] - P[i - 1]);
		L[++cnt] = Line(P[i], P[i + 1] - P[i]);
	}
}
bool Onleft(Line line, Point p)
{
	Point t = p - line.p;
	return line.v * t > 0; 
}
Point Cross(Line a, Line b)
{
	Point u = a.p - b.p;
	double t = (b.v * u) / (a.v * b.v);
	return a.p + a.v * t;
}

Point p[N]; Line q[N];
void Hpi()
{
	sort(L + 1, L + cnt + 1);
	int l = 1, r = 1;
	q[l] = L[1];
	for (int i = 2; i <= cnt; ++i)
	{
		while (l < r && !Onleft(L[i], p[r - 1])) --r;
		while (l < r && !Onleft(L[i], p[l])) ++l;
		q[++r] = L[i];
		if (fabs(q[r].v * q[r - 1].v) <= eps)
		{
			--r;
			if (Onleft(q[r], L[i].p))
				q[r] = L[i];
		}
		if (l < r)
			p[r - 1] = Cross(q[r], q[r - 1]);
	}
	while (l < r && !Onleft(q[l], p[r - 1])) --r;
	cnt = 0;
	for (int i = l; i < r; ++i)
		a[++cnt] = p[i];
}
void Solve()
{
	double ans = 1e11; Point t;
	for (int k = 1; k <= cnt; ++k)
		for (int i = 1; i < n; ++i)
		{
			t = a[k]; t.y = -1;
			if (P[i].x <= a[k].x && a[k].x <= P[i + 1].x)
				ans = min(ans, a[k].y - Cross(Line(P[i], P[i + 1] - P[i]), Line(t, a[k] - t)).y);
		}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i < cnt; ++i)
		{
			t = P[k]; t.y = -1;
			if (a[i].x <= P[k].x && P[k].x <= a[i + 1].x)
				ans = min(ans, Cross(Line(a[i], a[i + 1] - a[i]), Line(t, P[k] - t)).y - P[k].y);
		}
	printf("%.3lf\n", ans);
}
int main()
{
	Init();
	Hpi();
	Solve();
    return 0;
}


