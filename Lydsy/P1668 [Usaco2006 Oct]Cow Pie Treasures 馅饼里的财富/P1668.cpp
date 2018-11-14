#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 100 + 10;
using namespace std;
int mp[N][N];
int f[N][2];
int r,c;
int MAX(int a,int b,int c)
{
    return max(max(a,b),c);
}
void Readin()
{
    scanf("%d%d",&r,&c);
    for (int i=1;i<=r;++i)
        for (int j=1;j<=c;++j)
            scanf("%d",&mp[i][j]);
}
void Dp()
{
    memset(f,0,sizeof(f));
    if (c < r)
        return;
    for (int j=2;j<=r;++j)
        for (int i=1;i<=j - 1;++i)
            mp[j][i] = 0;
    for (int i=1;i<=r;++i)
        f[i][1] = mp[i][1];
    int a;
    for (int j=2;j<=c;++j)
    {
        a = j % 2;
        for (int i=1;i<=r;++i)
            f[i][a] = MAX(f[i - 1][a ^ 1],f[i][a ^ 1],f[i + 1][a ^ 1]) + mp[i][j];
    }
}
int main()
{
    Readin();
    Dp();
    printf("%d\n",f[r][c % 2]);
    return 0;
}
