#include <cstdio>
const int N = 100 + 10;
bool mp[N][N];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    int u,v;
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d",&u,&v);
        mp[u][v] = true;
    }
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                mp[i][j] |= (mp[i][k] & mp[k][j]);
    int temp,ans = 0;
    for (int i=1;i<=n;i++)
    {
        temp = 0;
        for (int j=1;j<=n;j++)
            if (mp[i][j] || mp[j][i])
                ++temp;
        if (temp == n - 1)
            ++ans;
    }
    printf("%d\n",ans);
    return 0;
}
