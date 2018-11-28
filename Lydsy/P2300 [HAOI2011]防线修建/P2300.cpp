#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <queue>
#define For(i,x,y) for (int i=x;i<=y;++i)
#define Dor(i,x,y) for (int i=x;i>=y;--i)
#define Clri(x) memset(x,0x3f,sizeof(x))
#define Clre(x) memset(x,0x00,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 2e5 + 10;
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
	double x,y;
	Point operator - (const Point &b) const
	{
		return (Point){x - b.x,y - b.y};	
	}
	double operator * (const Point &b) const 
	{
		return (x * b.y) - (y * b.x);	
	}
	bool operator < (const Point &b) const 
	{
		if (x == b.x)
			return y < b.y; 
		return x < b.x;
	}
};
double Dis(Point a,Point b)
{
	Point temp = a - b;
	return hypot(temp.x,temp.y);
}
//Code
set<Point> q;
double res = 0;
Point a[N];int n,m;
void Readin()
{
	n = read();
	q.insert((Point){0,0}); q.insert((Point){n,0});
	Point Orz = (Point){read(),read()};
	q.insert(Orz);
	res += Dis((Point){0,0},Orz);
	res += Dis((Point){n,0},Orz);
	
	m = read();
	for (int i=1;i<=m;++i)
		a[i] = (Point){read(),read()};
}

int del[N],t1 = 0;
int Time[N],t2 = 0;
bool mark[N];
void Init()
{
	int Q = read(),opt,x;
	Clre(mark);
	while (Q--) 
	{
		opt = read();	
		if (opt == 1)
		{
			x = read();
			del[++t1] = x;
			mark[x] = true;
		}
		else 
			Time[++t2] = t1;	
	}
}

void Insert(Point x)
{
	set<Point>::iterator r = q.lower_bound(x),l = r,t; --l;
	if((*r - *l) * (x - *l) < 0) return;
	res -= Dis(*l,*r);
	q.insert(x);
	while (true)
	{
		t = r++;
		if (r == q.end()) break;
		if ((*r - x) * (*t - x) > 0) break;
		res -= Dis(*t,*r);
		q.erase(t);	
	}
	while (l != q.begin())
	{
		t = l--;
		if ((*t - x) * (*l - x) > 0) break;
		res -= Dis(*t,*l);
		q.erase(t);
	}
	q.insert(x);
	l = r = t = q.find(x);
	--l; ++r;
	res += Dis(*l,x) + Dis(x,*r);
}

double ans[N]; 
void Work()
{
	for (int i=1;i<=m;++i)
		if (!mark[i])
			Insert(a[i]);
	for(int i=t2;i;--i)
	{
		while (t1 > Time[i])
			Insert(a[del[t1--]]);
		ans[i] = res;
	}
	for (int i=1;i<=t2;++i)
		printf("%.2lf\n",ans[i]);
}

int main()
{
	Readin();
	Init();
	Work();
    return 0;
}


