#include <cstdio>
#include <cstdlib>
const int xx[4] = {-1,1,0,0};
const int yy[4] = {0,0,-1,1};
const int N = 100 + 10;
bool mp[N][N];
int f[16][N][N];
int n,m,t;
int sx,sy,ex,ey;
void Readin()
{
    scanf("%d%d%d",&n,&m,&t);getchar();
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
            mp[i][j] = getchar() == '.' ? true : false;
        getchar();
    }
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
}
void Dp()
{
    f[0][sx][sy] = 1;
    int dx,dy;
    for (int i=1;i<=t;++i)
    {
        for (int j=1;j<=n;++j)
            for (int k=1;k<=m;++k)
                for (int l=0;l<4;++l)
                {
                    dx = j + xx[l];dy = k + yy[l];
                    if (dx < 1 || dx > n || dy < 1 || dy > m || !mp[dx][dy])
                        continue;
                    f[i][j][k] += f[i - 1][dx][dy];
                }
    }
    printf("%d\n",f[t][ex][ey]);
}
int main()
{
    Readin();
    Dp();
    return 0;
}
