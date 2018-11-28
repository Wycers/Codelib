#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Dor(i,y,x) for(int i=y;i>=x;i--)
#define Clr(a,x) memset(a,x,sizeof(a))
#define eps 1e-8
#define inf 2147483647
using namespace std;
//-----------------------------------------------
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
//-----------------------------------------------
int n, m, P;
double ans;
bool use[15], flag[15];
struct Line
{
	double a, b, c;	
}line[15];
struct Point
{
	double x, y;	
}p[15];
double sqr (double x)
{
	return x * x;	
}
double dis (double ax, double ay, double bx, double by)
{
	return sqrt(sqr(ax - bx) + sqr(ay - by) );	
}
bool Count(double &x, double &y, Line m1, Line m2)
{
	double d=m1.a * m2.b - m2.a * m1.b;
	if (fabs(d) < eps) return false;
	x = (m1.b * m2.c - m2.b * m1.c) / d;
	y = (m1.c * m2.a - m2.c * m1.a) / d;
	return true;
}
inline int pre(int i)
{
	if (i == 1) return P;
	else return i-1;
}
void Find(double &b1, double &b2, double x, double y, int i)
{
	if(x < p[i].x - eps)
		b1 = min(b1, dis(p[i].x, p[i].y, x, y) );
	else if(x > p[i].x + eps)
		b2 = min(b2, dis(p[i].x, p[i].y, x, y) );
	else
	{
		if (y > p[i].y + eps)
			b1 = min(b1, dis(p[i].x, p[i].y, x, y) );
		else if (y < p[i].y - eps)
			b2 = min(b2, dis(p[i].x, p[i].y, x, y) );
		else
		{
			if (p[pre(i)].x > x + eps) b1 = min(b1, dis(p[i].x, p[i].y, x, y) );
			else if (p[pre(i)].x < x - eps) b2 = min(b2, dis(p[i].x, p[i].y, x, y) );
			else
			{
				if (p[pre(i)].y < y - eps) b1 = min(b1, dis(p[i].x, p[i].y, x, y) );
				else b2 = min(b2, dis(p[i].x, p[i].y, x, y) );
			}
		}
	}
}
double Calc(int i)
{
	double b1, b2;	
	double x, y;
	b1 = b2 = 1e5;
	if (Count(x, y, (Line){1, 0, 0}, line[i]) )
		Find(b1, b2, x, y, i);
	if (Count(x, y, (Line){1, 0, -n}, line[i]) )
		Find(b1, b2, x, y, i);
	if (Count(x, y, (Line){0, 1, 0}, line[i]) )
		Find(b1, b2, x, y, i);
	if (Count(x, y, (Line){0, 1, -m}, line[i]) )
		Find(b1, b2, x, y, i);
	For(j, 1, P)
		if(use[j] && !flag[j])
			if(Count( x, y, line[j], line[i]) )
				Find(b1, b2, x, y, i);
	return b1 + b2;
}
void Dfs(int now, double sum)
{
	if(now == P)
	{
		//printf("%.4lf\n",sum);
		ans = min(ans, sum);
		return;
	}
	For(i, 1, P)
		if(!use[i])
		{
			double ll = Calc(i);
			use[i] = 1;
			//printf("%d %.4lf\n",i,ll);
			Dfs(now + 1, sum + ll);
			use[i] = 0;
		}
}
int main()
{
	//freopen("test.in","r",stdin);
	int xx = 0;
	ans = 1e5;
	n = read(); m = read(); P = read();
	Clr(use, 0);
	For(i, 1, P)
	{
		scanf("%lf%lf", &p[i].x, &p[i].y);
		if (i > 1)
		{
			if ((p[i].x == p[i-1].x && p[i].y == n) || (p[i].y == p[i-1].y && p[i].x == m) )
			{
				use[i] = 1;
				flag[i] = 1;
				xx++;
			}
			double k, b;
			Line m1 = {p[i].x, 1, -p[i].y};
			Line m2 = {p[i-1].x, 1, -p[i-1].y};
			if(!Count(k, b, m1, m2))
			{
				if (p[i].x == p[i-1].x) 
				{
					line[i].a = 1;
					line[i].b = 0;
					line[i].c = -p[i-1].x;
				}
				if (p[i].y == p[i-1].y) 
				{
					line[i].a = 0;
					line[i].b = 1;
					line[i].c = -p[i-1].y;
				}
			}
			else
			{
				line[i].a = k;
				line[i].b = -1;
				line[i].c = b;
			}
		}
	}
	if((p[1].x == p[P].x && p[1].y == n) || (p[1].y == p[P].y && p[1].x == m) )
	{
		flag[1] = 1;
		use[1] = 1;
		xx++;
	}
	double k, b;
	Line m1 = {p[1].x, 1, -p[1].y};
	Line m2 = {p[P].x, 1, -p[P].y};
	if(!Count(k, b, m1, m2) )
	{
		if (p[1].x == p[P].x) 
		{
			line[1].a = 1;
			line[1].b = 0;
			line[1].c = -p[P].x;
		}
		if (p[1].y == p[P].y) 
		{
			line[1].a = 0;
			line[1].b = 1;
			line[1].c = -p[P].y;
		}
	}
	else
	{
		line[1].a = k;
		line[1].b = -1;
		line[1].c = b;
	}
	if(xx == P)
	{
		printf("%.3f\n", 0);
		return 0;
	}
	For(i, 1, P) 
		if(!use[i])
		{
			double ll = Calc(i);
			use[i] = 1;
			/*printf("%.2lf %.2lf\n",p[i].x,p[i].y);
			printf("1 %.4lf\n",ll);*/
			Dfs(xx + 1, ll);
			use[i] = 0;
		}
	printf("%.3f\n",ans);
	return 0;
}
//-----------------------------------------------


