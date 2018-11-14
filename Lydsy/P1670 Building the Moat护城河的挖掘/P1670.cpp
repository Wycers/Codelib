#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define eps 1e-8
using namespace std;
double ans;
int n,top;
double sqr(double x)
{
    return x*x;
}
struct P
{
    int x,y;
    P(double _x=0,double _y=0){x=_x;y=_y;}
    friend P operator-(P a,P b)
	{
        return P(a.x-b.x,a.y-b.y);
    }
    friend double operator*(P a,P b)
	{
        return a.x*b.y-a.y*b.x;       
    }
    friend bool operator<(P a,P b)
	{
        if(fabs(a.y-b.y)<eps)return a.x<b.x;
        return a.y<b.y;
    }
    friend double dis2(P a)
	{
        return sqr(a.x)+sqr(a.y);       
    }
}p[5005],q[5005];
bool cmp(P a,P b)
{
    if(fabs((a-p[1])*(b-p[1]))<eps)return dis2(p[1]-a)<dis2(p[1]-b);
    return (a-p[1])*(b-p[1])>0;
}
void Graham()
{
    for(int i=1;i<=n;i++)
        if(p[i]<p[1])
			swap(p[i],p[1]);
    sort(p+2,p+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        while(top>1&&(q[top]-q[top-1])*(p[i]-q[top-1])<-eps)
           top--;
        q[++top] = p[i];
    }
}
void Solve()
{
    q[top+1] = q[1];
    for(int i=1;i<=top;i++)
        ans += sqrt(dis2(q[i]-q[i+1]));
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&p[i].x,&p[i].y);
    Graham();
    Solve();
    printf("%.2lf",ans);
    return 0;
}
