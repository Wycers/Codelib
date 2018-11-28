#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=100+10;
const int md=1000000000;
int a[maxn][maxn],d[maxn][maxn],map[maxn][maxn],n,id[maxn][maxn],tot,m;
long long c[maxn][maxn];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
char ch[12];
void gauss(int n)
{
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      c[i][j]=(c[i][j]+md)%md;
  int f=1;
  for(int i=1;i<=n;i++)
  {
    int j=i;
    while(!c[j][i]&&j<=n) j++;
    if(j==n+1)
    {
      puts("0");
      return;
    }
    if(j!=i)
    {
      for(int k=1;k<=n;k++) swap(c[i][k],c[j][k]);
      f*=-1;
    }
    for(int k=i+1;k<=n;k++)
    {
      while(c[k][i])
      {
        long long t=c[k][i]/c[i][i];
        for(int l=i;l<=n;l++) c[k][l]=(c[k][l]-c[i][l]*t%md+md)%md;
        if(!c[k][i]) break;
        for(int l=i;l<=n;l++) swap(c[k][l],c[i][l]);
        f*=-1;
      }
    }
  }
  long long res=1;
  for(int i=1;i<=n;i++) res=(res*c[i][i])%md;
  if(f<0) res=(md-res)%md;
  printf("%lld\n",res);
}
int main()
{
  //freopen("4031.in","r",stdin);
  //freopen("4031.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",&ch);
        for(int j=0;j<m;j++)
            if(ch[j]=='.')
                map[i][j+1]=1;
      else map[i][j+1]=0;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(map[i][j]) id[i][j]=++tot;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      if(map[i][j])
      {
        for(int k=0;k<4;k++)
        {
          int nx=i+dx[k],ny=j+dy[k],u=id[i][j],v=id[nx][ny];
          if(nx&&nx<=n&&ny&&ny<=m&&map[nx][ny])
          {
            a[u][v]=1;d[u][u]++;
          }
        }
      }
  for(int i=1;i<=tot;i++)
    for(int j=1;j<=tot;j++)
      c[i][j]=d[i][j]-a[i][j];
  //cout<<tot<<endl;
  gauss(tot-1);
  return 0;
}
