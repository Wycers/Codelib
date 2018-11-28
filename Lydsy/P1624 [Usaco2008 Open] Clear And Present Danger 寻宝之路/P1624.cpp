#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 100 + 10;
const int M = 10000 + 10;
using namespace std;
int a[M];
int n,m;
int f[N][N];
void Readin()
{
    memset(f,0x3f,sizeof(f));
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;++i)
        scanf("%d",a + i);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            scanf("%d",&f[i][j]);
}
void Floyd()
{
    for (int k=1;k<=n;++k)
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
                f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
}
void Work()
{
    long long ans = 0;
    int last = 1;
    for (int i=(int)(a[1] != 1) + 1;i<=m;++i)
    {
        ans += f[last][a[i]];
        last = a[i];
    }
    if (last != n)
        ans += f[last][n];
    printf("%d\n",ans);
}
int main()
{
    Readin();
    Floyd();
    Work();
    return 0;
}
