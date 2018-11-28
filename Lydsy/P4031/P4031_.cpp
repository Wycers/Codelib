#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define M 110
#define MOD 1000000000
using namespace std;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int m,n,tot;
char map[15][15];
int num[15][15];
long long f[M][M];
long long Gauss_Elimination(int n)
{
    int i,j,k,mark=0;
    for(i=1;i<=n;i++)
    {
        for(k=i;k<=n;k++)
            if(f[k][i])
                break;
        if(k==n+1)
            continue;
        if(i!=k)
        {
            mark^=1;
            for(j=i;j<=n;j++)
                swap(f[i][j],f[k][j]);
        }
        for(k=i+1;k<=n;k++)
        {
            while(f[k][i])
            {
                int temp=f[k][i]/f[i][i];
                for(j=i;j<=n;j++)
                    (f[k][j]+=MOD-f[i][j]*temp%MOD)%=MOD;
                if(!f[k][i])
                    break;
                mark^=1;
                for(j=i;j<=n;j++)
                    swap(f[i][j],f[k][j]);
            }
        }
    }
    long long re=1;
    for(i=1;i<=n;i++)
        (re*=f[i][i])%=MOD;
    if(mark)
        re=(MOD-re)%MOD;
    return re;
}
int main()
{
    //freopen("room.in","r",stdin);
    //freopen("room.out","w",stdout);
    int i,j,k;
    cin>>m>>n;
    for(i=1;i<=m;i++)
    {
        scanf("%s",map[i]+1);
        for(j=1;j<=n;j++)
            if(map[i][j]=='.')
                num[i][j]=++tot;
    }
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(num[i][j])
                for(k=0;k<4;k++)
                {
                    int xx=i+dx[k];
                    int yy=j+dy[k];
                    if(!num[xx][yy])
                        continue;
                    f[num[i][j]][num[i][j]]++;
                    f[num[i][j]][num[xx][yy]]--;
                }
    for(i=1;i<=tot;i++)
        for(j=1;j<=tot;j++)
            if(f[i][j]<0)
                f[i][j]+=MOD;
    cout<<Gauss_Elimination(tot-1)<<endl;
    return 0;
}
