#include <cstdio>
#include <algorithm>
const int N = 10000 + 10;
const int M = 500 + 10;
using namespace std;
int n,m,a[N];

void Readin()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
        scanf("%d",a + i);
}

int f[N][M];
void Dp()
{
    for (int i=1;i<=n;i++)
    {
        f[i][0] = f[i - 1][0];
        for (int j=1;j<=m;j++)
        {
            if (i >= j) f[i][0] = max(f[i][0],f[i - j][j]);
            f[i][j] = max(f[i][j],f[i - 1][j - 1] + a[i]);
        }
    }
    printf("%d\n",f[n][0]);
}

int main()
{
    Readin();
    Dp();
    return 0;
}
