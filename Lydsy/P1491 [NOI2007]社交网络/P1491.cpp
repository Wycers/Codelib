#include <cstdio>
using namespace std;
const int Inf = 0x3f3f3f3f;
int n,m;
double a[105][105],cnt[105][105];
void Readin()
{
    int u,v,w;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = Inf;
            cnt[i][j] = 1;
        }
        a[i][i] = 0;
    }
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        a[u][v] = w;
        a[v][u] = w;
    }
}

void Floyd()
{
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                if (i == j || j == k || i == k)
                    continue;
                if (a[i][k] + a[k][j] < a[i][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                    cnt[i][j] = cnt[i][k] * cnt[k][j];
                }
                else if (a[i][k] + a[k][j] == a[i][j])
                    cnt[i][j] += cnt[i][k] * cnt[k][j];
            }
}


void Work()
{
    double ans;
    for (int k=1;k<=n;k++)
    {
        ans = 0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (i != j && j != k && i != k && a[i][k] + a[k][j] == a[i][j])
                    ans += cnt[i][k] * cnt[k][j] / cnt[i][j];
        printf("%.3lf\n",ans);
    }
}

int main()
{
    Readin();
    Floyd();
    Work();
    return 0;
}
