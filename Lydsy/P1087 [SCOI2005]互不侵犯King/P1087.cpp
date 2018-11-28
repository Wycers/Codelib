#include <cstdio>
#define N 512
using namespace std;

long long f[10][100][N];
short cnt[N],tot,n,m;
bool avi[N],avj[N][N];
void Pre()
{
    int s;
    tot = (1 << n);
    for (int i=0;i<tot;i++)
        if ((i & (i >> 1)) == 0)
        {
            avi[i] = true;
            s = 0;
            for (int j=i;j;j>>=1)
                s += (j & 1);
            cnt[i] = s;
        }
    for(int i=0;i<tot;i++) if(avi[i])
        for(int j=0;j<tot;j++) if(avi[j])
           if((i & j) == 0 && (i & (j >> 1)) == 0 && (j & (i>>1)) == 0)
              avj[i][j] = 1;
}

void Dp()
{
    for (int i=0;i<tot;i++) if (avi[i])
        f[1][cnt[i]][i] = 1;
    for (int j=1;j<n;j++)
        for (int k=0;k<tot;k++) if (avi[k])
            for (int i=0;i<tot;i++) if (avi[i])
                if (avj[k][i])
                    for (int p=cnt[k];p+cnt[i]<=m;p++)
                        f[j + 1][p + cnt[i]][i] += f[j][p][k];
    long long ans = 0;
    for (int i=0;i<tot;i++)
        ans += f[n][m][i];
    printf("%lld\n",ans);
}

int main()
{
    scanf("%d%d",&n,&m);
    Pre();
    Dp();
    return 0;
}
