#include <cstdio>
int a[10005],f[10005],ans = 0,n;
bool Judge()
{
    for (int i=2;i<=n;i++)
    {
        f[i + 1] = a[i] - f[i] - f[i - 1];
        if (f[i + 1] < 0)
            return 0;
    }
    if (a[n] - f[n] - f[n - 1] != 0)
        return 0;
    return 1;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",a + i);
    if (a[1] == 0)
        ans += Judge();
    else if (a[1] == 1)
    {
        f[1] = 1;ans += Judge();
        f[1] = 0; f[2] = 1; ans += Judge();
    }
    else
    {
        f[1] = f[2] = 1;
        ans += Judge();
    }
    printf("%d\n",ans);
    return 0;
}
