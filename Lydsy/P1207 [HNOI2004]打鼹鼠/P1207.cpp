#include<iostream>
#include<cstdio>
#include<cstdlib>
#define N 10005
using namespace std;
int n,m,ans;
int f[N],t[N],x[N],y[N],mx[N];
int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1;i<=m;i++)scanf("%d%d%d",&t[i],&x[i],&y[i]);
    f[1]=1;mx[1]=1;
    for(int i=2;i<=m;i++)
    {
        f[i]=1;
        for(int j=i-1;j>=1;j--)  
        {
            if(mx[j]+1<=f[i])break;
            if(f[j]+1>f[i])
                if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])
			        f[i]=f[j]+1;
        }
        mx[i]=max(f[i],mx[i-1]);
        if(f[i]>ans)ans=f[i];
    }
    printf("%d",ans);
    return 0;
}
