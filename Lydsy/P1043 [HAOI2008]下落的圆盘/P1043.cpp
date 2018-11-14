#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define For(i,x,y) for (int i=x;i<=y;++i)
#define Dor(i,x,y) for (int i=x;i>=y;--i)
#define Clri(x) memset(x,0x3f,sizeof(x))
#define Clre(x) memset(x,0x00,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
const double pi = 2 * asin(1);
const int Inf = 0x3f3f3f3f;
const int Eps = 1e-10;

int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
int n,top;
double ans;
double x[1005],y[1005],r[1005];
struct line{double l,r;}q[1005];
bool operator<(line a,line b)
{
	return a.l<b.l;
}
inline double dis(int a,int b)
{
	return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
bool conta(int a,int b)
{
	if(r[a]>=r[b]+dis(a,b))return 1;
	return 0;
}
void inter(int a,int b)
{
	double d,t,st,l;
	d=dis(a,b);
	t=(r[a]*r[a]-r[b]*r[b]+d*d)/(2*d);
	st=atan2((x[a]-x[b]),(y[a]-y[b]));
	l=acos(t/r[a]);
	q[++top]=(line){(st-l),(st+l)};
}
double cal(int x)
{
	for(int i=x+1;i<=n;i++)
		if(conta(i,x))return 0;
	top=0;
	for(int i=x+1;i<=n;i++)
	{
		if(!conta(x,i)&&r[x]+r[i]>=dis(x,i))inter(x,i);
	}
	double tmp=0,now=0;
	for(int i=1;i<=top;i++)
	{
		if(q[i].l<0)q[i].l+=2*pi;
		if(q[i].r<0)q[i].r+=2*pi;
		if(q[i].l>q[i].r)
		{
			q[++top]=(line){0,q[i].r};
			q[i].r=2*pi;
		}
	}
	sort(q+1,q+top+1);
	for(int i=1;i<=top;i++)
		if(q[i].l>now)
		{
			tmp+=q[i].l-now;
			now=q[i].r;
		}
		else now=max(now,q[i].r);
	tmp+=2*pi-now;
	return r[x]*tmp;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf%lf",&r[i],&x[i],&y[i]);
	for(int i=1;i<=n;i++)
		ans+=cal(i);
	printf("%.3lf\n",ans);
	return 0;
}

