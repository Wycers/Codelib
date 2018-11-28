#include<cstdio>
#define max(a,b) a > b ? a : b
using namespace std;
int n,tot;
int f[1 << 21],sum[1 << 21];
void Init()
{
    int m;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&sum[1 << i >> 1]);
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d",&sum[1 << (n + i) >> 1]);
        sum[1 << (n + i) >> 1] = -sum[1 << (n + i) >> 1];
    }
    n += m;
    tot = (1 << n) - 1;
}
void Dp()
{
    int t;
    for (int i=1;i<=tot;i++)
    {
        t = i & (-i);
        sum[i] = sum[t] + sum[i - t];
        for (int j=1;j<=n;j++)
            if ((i & (1 << j >> 1)) > 0)
                f[i] = max(f[i],f[i - (1 << j >> 1)]);
        if (!sum[i])
            f[i] ++;
    }
    printf("%d\n",n - 2 * f[tot]);
}
int main()
{
    Init();
    Dp();
    return 0;
}
