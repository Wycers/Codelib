#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 30000 + 10;
using namespace std;

short Read()
{
    char ch = getchar();
    while (!('0' <= ch && ch <= '9')) ch = getchar();
    return ch - 48;
}

int n,ans = 0x7fffffff;
short a[N];int f[2][4];
void Readin()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        a[i] = Read();
}

void Dp()
{
    f[0][1] = f[0][2] = f[0][3] = 0;
    int t;
    for (int i=1;i<=n;i++)
    {
        t = i % 2;
        memset(f[t],0x3f,sizeof(f[t]));
        for (short j=1;j<=3;j++)
            for (short k=1;k<=j;k++)
                f[t][j] = min(f[t][j],f[t ^ 1][k] + (a[i] == j ? 0 : 1));
    }
    ans = min(ans,f[n % 2][1]);
    ans = min(ans,f[n % 2][2]);
    ans = min(ans,f[n % 2][3]);
}
void Solve()
{
    Dp();
    reverse(a + 1,a + n + 1);
    Dp();
    printf("%d\n",ans);
}

int main()
{
    Readin();
    Solve();
    return 0;
}
