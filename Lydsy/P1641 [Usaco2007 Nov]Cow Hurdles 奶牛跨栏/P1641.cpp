#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 300 + 10;
const int M = 1000000;
using namespace std;
int f[N][N];
int n,m,T;
void Floyd()
{
    for (int k=1;k<=n;++k)
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
                if (f[i][k] <= M && f[k][j] <= M)
                    f[i][j] = min(f[i][j],max(f[i][k],f[k][j]));
}
void Readin()
{
    memset(f,0x3f,sizeof(f));
    int u,v,w;
    scanf("%d%d%d",&n,&m,&T);
    for (int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&u,&v,&w);
        f[u][v] = w;
    }
}
void Work()
{
    int u,v;
    while (T--)
    {
        scanf("%d%d",&u,&v);
        printf("%d\n",f[u][v] > M ? -1 : f[u][v]);
    }
}
int main()
{
    Readin();
    Floyd();
    Work();
    return 0;
}
