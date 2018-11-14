#include <iostream>
#include <ctime>
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
#define eps 1e-12
using namespace std;
const int N = 1e5 + 10;
const int Inf = 0x3f3f3f3f;

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
	double x,y;
	double operator * (point b)
	{
		return x * b.y - y * b.x;
	}
	point operator - (point b)
	{
		return (point){x - b.x,y - b.y};	
	} 
	void Prt()
	{
		printf("%d %d\n",(int)x,(int)y);	
	}
} p[1000],q[1000];
double Dis(point a,point b)
{
	point t = a - b;
	return hypot(t.x,t.y);
}
int top = 0;
bool cmp(point a,point b)
{
	if (fabs((a - p[1]) * (b - p[1])) < eps)
        return Dis(p[1],a) < Dis(p[1],b);
    return (a - p[1]) * (b - p[1]) > 0;
}
//Code
int n;
void Graham()
{
	for (int i=1;i<=n;++i)
	{
		while (1 < top && (q[top] - q[top - 1]) * (p[i] - q[top - 1]) <= 0)
			--top;
		q[++top] = p[i];	
	}
}

const int M = 500;
int main()
{
	//freopen("test.in","w",stdout);
	srand(time(0));
	n = rand() % 500 + 250;
	for (int i=1;i<=n;++i)
		p[i].x = rand() % (M - 1) + 1,p[i].y = rand() % (M - 1) + 1;
	int mn = 1;
	for (int i=2;i<=n;++i)
		if (p[i].x < p[mn].x || (p[i].x == p[mn].x && p[i].y < p[mn].y))
			mn = i;
	swap(p[mn],p[1]);
	sort(p + 2, p + n + 1,cmp);
	Graham();
	printf("%d %d\n%d\n",M,M,min(8,top));
	for (int i=1;i<=min(8,top);++i)
		q[i].Prt();
    return 0;
}


