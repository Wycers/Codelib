#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define Eps 1e-8
#define N 25
using namespace std;
double a[N][N],f[N];
int n;
double sqr(double x)
{
    return x * x;
}

void Readin()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%lf",&f[i]);
    memset(a,0,sizeof(a));
    double t;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            scanf("%lf",&t);
            a[i][j] = 2 * (t - f[j]);
            a[i][n + 1] += sqr(t) - sqr(f[j]);
        }

}

void Guass()
{
    for (int i=1;i<=n;i++)
    {
        for (int j=i;j<=n;j++)
            if (fabs(a[j][i]) > Eps)
            {
                for (int k=1;k<=n+1;k++)
                    swap(a[j][k],a[i][k]);
                break;
            }
        for (int j=1;j<=n;j++)
            if (j != i && fabs(a[j][i]) > Eps)
            {
                double temp = a[j][i] / a[i][i];
                for (int k=1;k<=n+1;k++)
                    a[j][k] -= temp * a[i][k];
            }
    }
    double ans[N];
    for (int i=1;i<=n;i++)
        ans[i] = a[i][n + 1] / a[i][i];
    for (int i=1;i<=n;i++)
        printf("%.3lf%c",ans[i],i == n ? '\n' : ' ');
}
int main()
{
    Readin();
    Guass();
    return 0;
}
