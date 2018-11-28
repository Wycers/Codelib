#include <cstdio>
#include <algorithm>
const int N = 5000 + 10;
using namespace std;
int a[N],n;
void Readin()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",a + i);
}
int f[N];
void Dp()
{
    f[1] = 1;
    int max,ans = 0;
    for (int i=1;i<=n;i++)
    {
        max = 0;
        for (int j=1;j<i;j++)
            if (a[i] > a[j] && f[j] > max)
                max = f[j];
        f[i] = max + 1;
        if (f[i] > ans)
            ans = f[i];
    }
    printf("%d\n",ans);
}

int main()
{
    Readin();
    Dp();
    return 0;
}
