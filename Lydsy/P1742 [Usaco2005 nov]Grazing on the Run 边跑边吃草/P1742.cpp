#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
#define N 1100
using namespace std;
int f[N][N][2];
int a[N],n,x;
int main()
{
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++)
        scanf("%d",a + i);
    sort(a + 1,a + n + 1);
    for(int i=1;i<=n;i++)
        f[i][i][0] = f[i][i][1] = abs(a[i] - x) * n;
    for(int len=2;len<=n;len++)
        for(int i=1;i<=n-len+1;i++)
        {
            int j=i+len-1;
            f[i][j][0] = f[i][j][1] = 0x3f3f3f3f;
            f[i][j][0] = min(f[i][j][0],f[i+1][j][0]+(n-(j-i))*(a[i+1]-a[i]));
            f[i][j][0] = min(f[i][j][0],f[i+1][j][1]+(n-(j-i))*(a[j]-a[i]));
            f[i][j][1] = min(f[i][j][1],f[i][j-1][0]+(n-(j-i))*(a[j]-a[i]));
            f[i][j][1] = min(f[i][j][1],f[i][j-1][1]+(n-(j-i))*(a[j]-a[j-1]));
        }
    printf("%d\n",min(f[1][n][0],f[1][n][1]));
    return 0;
}
