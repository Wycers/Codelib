/**************************************************************
    Problem: 1091
    User: zhengly123
    Language: C++
    Result: Accepted
    Time:124 ms
    Memory:1276 kb
****************************************************************/
 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>
#define MEM(a) memset(a,0,sizeof(a))
#define CPY(a,b) memcpy(b,a,sizeof(b))
using namespace std;
const int INF = 999999999;
const int MAXN = 20;
const double eps = 1e-8;
 
int zero(double a)
{
    if (fabs(a) < eps) return 0;
    else return (a>0) ? 1 : -1;
}
double MIN(double a, double b){ return (a < b) ? a : b; }
 
struct point//点或向量
{
    double x, y;
    point(){}
    point(double a, double b){ x = a; y = b; }
    friend point operator+(const point&a, const point&b){ return point(a.x + b.x, a.y + b.y); }
    friend point operator -(const point&a, const point&b){ return point(a.x - b.x, a.y - b.y); }
    friend point operator *(const double&k, const point&a){ return point(k*a.x, k*a.y); }//数乘
    friend double operator *(const point&a, const point&b){ return a.x*b.x + a.y*b.y; }//点积
    friend double operator /(const point&a, const point&b){ return a.x*b.y - a.y*b.x; }//叉积,用^优先级有问题
    friend bool operator <(const point&a, const point&b){ return (a.x - b.x < -eps) || (fabs(a.x - b.x) < eps && (a.y - b.y) < -eps); }
    friend bool operator ==(const point&a, const point&b){ return zero(a.x - b.x) && zero(a.y - b.y); }
    double dis(){ return (sqrt(x*x + y*y)); }
    void input(){ scanf("%lf%lf", &x, &y); }
    void output(){ printf("%lf %lf\n", x, y); }
}p[MAXN], pt[MAXN];

point inter(point a, point b, point c, point d)
{
    double s1 = (b - a) / (d - a), s2 = (b - a) / (c - a);
    return (point((s1*c.x - s2*d.x) / (s1 - s2), (s1*c.y - s2*d.y) / (s1 - s2)));
}
 
int nump;
double ans = INF;
 
int cut(point pp[], int num,int k, double &dis)//the number of p is num, cut the (k,k+1)半平面交
{
    int i, j, cnt = 0, newcnt = -1, t;
    point newp[2];
    MEM(pt);
    for (i = 1; i <= num; ++i)
    {
        t = zero((p[k + 1] - p[k]) / (pp[i] - p[k]));
        if (t >= 0)
        {
            pt[++cnt] = pp[i];
            if (t == 0) newp[++newcnt] = pp[i];
        }
        else
        {
            if (zero((p[k + 1] - p[k]) / (pp[i - 1] - p[k])) > 0) 
                 newp[++newcnt] = pt[++cnt] = inter(p[k], p[k + 1], pp[i], pp[i - 1]);
            if (zero((p[k + 1] - p[k]) / (pp[i + 1] - p[k])) > 0) 
                newp[++newcnt] = pt[++cnt] = inter(p[k], p[k + 1], pp[i], pp[i + 1]);
        }
    }
    pt[0] = pt[cnt]; pt[cnt + 1] = pt[1];
    dis += (newp[1] - newp[0]).dis();
    return cnt;
}
 
 int s[10],top = 0;
void dfs(int dep, point p[], int num, bool boo[],double dis)
{
    int curnum;
    double curdis;
    point curp[MAXN];
    bool curboo[MAXN];
    if (dep == nump + 1)
    {
        if (ans > dis)
        {
			ans = dis;
			for (int i=1;i<=top;++i)
				printf("%d ",s[i]);
			puts("");	
		}
        return;
    }
    CPY(boo, curboo);
    for (int i = 1; i <= nump; ++i)
    {
        if (!boo[i])
        {
            CPY(p, curp);
            curboo[i] = 1;
            curdis = dis;
            s[++top] = i;
            curnum = cut(curp, num, i, curdis);
            CPY(pt, curp);
            dfs(dep + 1, curp, curnum, curboo, curdis);
            --top;
            curboo[i] = 0;
        }
    }
}
 
void work()
{
    int i, j, n, m;
    bool boo[MAXN] = {};
    point pt[MAXN];
    scanf("%d%d%d", &n, &m, &nump);
    for (i = nump; i > 0; --i) p[i].input();
    p[0] = p[nump]; p[nump + 1] = p[1];
    pt[1] = pt[5] = point(0, 0);
    pt[2] = point(n, 0);
    pt[3] = point(n, m);
    pt[4] = pt[0] = point(0, m);
    dfs(1, pt, 4, boo, 0);
    printf("%.3lf\n", ans);
}
 
int main()
{
    work();
    return 0;
}
