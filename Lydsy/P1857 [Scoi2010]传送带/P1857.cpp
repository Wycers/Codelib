#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define For(i,x,y) for (int i=x;i<=y;++i)
#define Dor(i,x,y) for (int i=x;i>=y;--i)
#define Clri(x) memset(x,0x3f,sizeof(x))
#define Clre(x) memset(x,0x00,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
const double eps = 1e-3;
const int Inf = 0x3f3f3f3f;

double read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return (double)x * f;
}
//Struct
struct point
{
	double x, y;
	point operator - (point b)
	{
		return (point){x - b.x, y - b.y};	
	}
};
//Code
point a, b, c, d;
double p, q, r;
double Dis(point a, point b)
{
	point t = a - b;
	return hypot(t.x, t.y);
}
void Readin()
{
	a.x = read(); a.y = read(); b.x = read(); b.y = read();
	c.x = read(); c.y = read(); d.x = read(); d.y = read();
	p = read(); q = read(); r = read();
}
double cal(point s, point t)
{
	return Dis(a, s) / p + Dis(s, t) / r + Dis(t, d) / q;	
}
double Cal(point t)
{
	point l = c, r = d, fmid, smid, res;
	while (fabs(l.x - r.x) > eps || fabs(l.y - r.y) > eps)
	{
		fmid = (point){l.x + (r.x - l.x) / 3, l.y + (r.y - l.y) / 3};
		smid = (point){l.x + (r.x - l.x) / 3 * 2, l.y + (r.y - l.y) / 3 * 2};
		if (cal(t, fmid) > cal(t, smid))
			l = fmid;
		else
			r = smid;
 	} 
	return (cal(t, l));
}

void Work()
{
	point l = a, r = b, fmid, smid;
	while (fabs(l.x - r.x) > eps || fabs(l.y - r.y) > eps)
	{
		fmid = (point){l.x + (r.x - l.x) / 3, l.y + (r.y - l.y) / 3};
		smid = (point){l.x + (r.x - l.x) / 3 * 2, l.y + (r.y - l.y) / 3 * 2};
		if (Cal(fmid) > Cal(smid))
			l = fmid;
		else
			r = smid;
	}
	printf("%.2lf\n", Cal(l));
}

int main()
{
	Readin();
	Work();
    return 0;
}


