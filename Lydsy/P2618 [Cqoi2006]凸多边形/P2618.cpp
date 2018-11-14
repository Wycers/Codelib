#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
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
	Point (double _x = 0.0, double _y = 0.0)
	{
		x = _x;
		y = _y;
	}
	void Prt()
	{
		printf("%.2lf %.2lf\n", x, y);
	}
	Point operator - (const Point &b)
	{
		return Point(x - b.x, y - b.y);
	}
	Point operator + (const Point &b)
	{
		return Point(x + b.x, y + b.y);
	}
	double operator * (const Point &b)
	{
		return x * b.y - y * b.x;
	}
	Point operator * (const double &b)
	{
		return Point(x * b, y * b);
	}
} v[510];
struct Line
{
	Point p, v;
	double ang;
	Line(){}
	Line(Point p, Point v) : p(p), v(v)
	{
		ang = atan2(v.y, v.x);
	}
	void Prt()
	{
		p.Prt();
		v.Prt();
		cout << endl;
	}
	bool operator < (const Line &b) const
	{
		return ang < b.ang;
	}
} L[510];
int n = 0;
void Readin()
{
	int nn = read(), m; 
	Point P[55], V[55];
	for (int i = 1; i <= nn; ++i)
	{
		m  = read();
		for (int j = 1; j <= m; ++j)
		{
			P[j].x = (double)read();
			P[j].y = (double)read();
		}
		
		for (int j = 1; j < m; ++j)
			V[j] = P[j + 1] - P[j];
		V[m] = P[1] - P[m];
		
		for (int j = 1; j <= m; ++j)
			L[++n] = Line(P[j], V[j]);
	}
	/*for (int i = 1; i <= n; ++i)
		L[i].Prt();*/
}

bool Onleft(Line line, Point p)
{
	Point t = p - line.p;
	return (line.v * t) > 0;
}
Point Cross(Line a, Line b)
{
	Point u = a.p - b.p;
	double t = (b.v * u) / (a.v * b.v);
	return a.p + a.v * t;
}
Point p[500]; Line q[500];
void Hpi()
{
	sort(L + 1, L + n + 1);
	int l = 1, r = 1;
	q[l] = L[1];
	for (int i = 2; i <= n; ++i)
	{
		while (l < r && !Onleft(L[i], p[r - 1]) ) r--;
		while (l < r && !Onleft(L[i], p[l]) ) l++;
		q[++r] = L[i];
		if (fabs(q[r].v * q[r - 1].v) <= eps)
		{
			--r;
			if (Onleft(q[r], L[i].p))
				q[r] = L[i];
		}
		if (l < r)
			p[r - 1] = Cross(q[r - 1], q[r]);
	}
	while (l < r && !Onleft(q[l], p[r - 1]))
		--r;
	p[r] = Cross(q[l], q[r]);
	double ans = 0;
	for (int i = l; i < r; ++i)
		ans += (p[i] * p[i + 1]);
	if (l <= r)
		ans += p[r] * p[l];
	ans = fabs(ans) / 2.0;
	printf("%.3lf\n", ans);
}
//Code
int main()
{
	Readin();
	Hpi();
    return 0;
}


