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
void Solve()
{
    memset(f,0x3f,sizeof(f));
    f[0] = 0;
    sort(p + 1,p + n + 1,cmp);
    for (int i=1;i<=n;i++)
        for (int j=0;j<i;j++)
            f[i] = min(f[i],f[j] + p[j + 1].x * p[i].y);
    printf("%lld\n",f[n]);
}

int main()
{
    Readin();
    Solve();
    return 0;
}
