#include<iostream>
#include<cstdio>
#include<cmath>
#define eps 1e-6
#define sqr(x) (x) * (x)
const int N = 100000 + 10;
using namespace std;
struct point
{
    double x,y;
} p[N],O;
int n;
double r;

void Readin()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
}

double Dis(point a,point b)
{
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
void GetO(point x,point y)
{
    O.x = (x.x + y.x) / 2;
    O.y = (x.y + y.y) / 2;
    r = Dis(O,x);
}
void GetO(point x,point y,point z)
{
    double a = 2 * (y.x - x.x),b = 2 * (y.y - x.y);
    double c = sqr(y.x) + sqr(y.y) - sqr(x.x) - sqr(x.y);
    double d = 2 * (z.x - y.x),e = 2 * (z.y-y.y);
    double f = sqr(z.x) + sqr(z.y) - sqr(y.x) - sqr(y.y);
    O.x = (b * f - e * c) / (b * d - e * a);
    O.y = (d * c - a * f) / (b * d - e * a);
    r = Dis(O,x);
}
void Solve()
{
    O = p[1]; r = 0;
    for (int i=2;i<=n;++i)
        if (Dis(O,p[i]) > r + eps)
        {
            O = p[i];r = 0;
            for (int j=1;j<i;++j)
                if (Dis(O,p[j]) > r + eps)
                {
                    GetO(p[i],p[j]);
                    for (int k=1;k<j;k++)
                        if (Dis(O,p[k]) > r + eps)
                            GetO(p[i],p[j],p[k]);
                }
        }
}
int main()
{
    Readin();
    Solve();
    printf("%.10lf\n",r);
    printf("%.10lf %.10lf\n",O.x,O.y);
    return 0;
}
