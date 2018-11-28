#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 50005;
struct point
{
    int x,y;
} p[N];
int n;
void Readin()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d%d",&p[i].x,&p[i].y);
}

bool cmp(const point a,const point b)
{
    return a.x == b.x ? (a.y < b.y) : (a.x > b.x);
}
long long f[N];
int x[N],y[N],q[N],cnt = 0;
double Cal(int j,int k)
{
    return (double)(f[k] - f[j]) / (x[j + 1] - x[k + 1]);
}
void Solve()
{
    memset(f,0x3f,sizeof(f));
    f[0] = 0;
    sort(p + 1,p + n + 1,cmp);
    for(int i=1;i<=n;i++)
    {
        if (cnt && y[cnt] >= p[i].y)
            continue;
        ++cnt;
        x[cnt] = p[i].x;
        y[cnt] = p[i].y;
    }
    int l = 1,r = 1,t;
    for (int i=1;i<=cnt;i++)
    {
        while (l < r && Cal(q[l],q[l + 1]) < y[i]) ++l;
        f[i] = f[q[l]] + (long long)x[q[l] + 1] * y[i];
        while (l < r && Cal(q[r - 1],q[r]) > Cal(q[r],i)) --r;
        q[++r] = i;
    }
    printf("%lld\n",f[cnt]);
}

int main()
{
    Readin();
    Solve();
    return 0;
}
