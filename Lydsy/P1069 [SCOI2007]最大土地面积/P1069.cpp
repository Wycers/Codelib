#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#define For(i,x,y) for (int i=x;i<=y;++i)
#define Dor(i,x,y) for (int i=x;i>=y;--i)
#define Clri(x) memset(x,0x3f,sizeof(x))
#define Clre(x) memset(x,0x00,sizeof(x))
#define eps (1e-12)
typedef long long ll;
using namespace std;
const int N = 2e3 + 10;
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
    point operator - (point b)
    {
        return (point){x - b.x,y - b.y};    
    }
    bool operator < (point b)
    {
        if (fabs(y - b.y) < eps)
            return x < b.x;
        return y < b.y;
    }
    double operator * (point b)
    {
        return x * b.y - y * b.x;
    }
} p[N],q[2 * N];
double Dis(point a,point b)
{
    point t = a - b;
    return hypot(t.x,t.y);
}
double Dis2(point p1,point p2,point x)
{
    return fabs((x - p1) * (p2 - p1));
}
//Code
int n,top = 0;
void Readin()
{
    n = read();
    for (int i=1;i<=n;++i)
        scanf("%lf%lf",&p[i].x,&p[i].y);
}

bool cmp(point a,point b)
{
    if (fabs((a - p[1]) * (b - p[1])) < eps)
        return Dis(p[1],a) < Dis(p[1],b);
    return (a - p[1]) * (b - p[1]) > 0;
}
void Graham()
{
    for (int i=1;i<=n;++i)
        if (p[i] < p[1]) 
            swap(p[i],p[1]);
    sort(p + 2,p + n + 1,cmp);
    for (int i=1;i<=n;i++)
    {
        while (1 < top && (q[top] - q[top - 1]) * (p[i] - q[top - 1]) <= 0)
            --top;
        q[++top] = p[i]; 
    }
}
void Work()
{
    Graham();
    double ans = 0.0;
    for (int i=1;i<=top;++i)
        q[i + top] = q[i];
    for (int p1 = 1,p2,p3,p4; p1 <= top; ++p1)
    {
        p2 = p1 + 1; p3 = p2 + 1; p4 = p3 + 1;
        for (;p3 <= p1 + top - 2;++p3)
        {
            while (p2 + 1 < p3 && Dis2(q[p1],q[p3],q[p2]) < Dis2(q[p1],q[p3],q[p2 + 1]))
                ++p2;
            while (Dis2(q[p1],q[p3],q[p4]) < Dis2(q[p1],q[p3],q[p4 + 1]))
            {
                ++p4;
                if (p4 - p1 >= top - 1)
                    break;
            }
            ans = max(ans,fabs((q[p2] - q[p1]) * (q[p3] - q[p1])) + fabs((q[p3] - q[p1]) * (q[p4] - q[p1])));
        }
    }
    printf("%.3lf\n",ans / 2);
}
int main()
{
    Readin();
    Work();
    return 0;
}
