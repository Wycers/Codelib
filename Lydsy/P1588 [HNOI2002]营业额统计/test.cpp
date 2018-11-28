#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
 
using namespace std;
const int INF=2000000000;
long long ans;
int n,a[40005],root,t1,t2,size;
int v[40005],c[40005][2],fa[40005];
 
void ROTATE(int x,int &k)
{
    int y=fa[x];int z=fa[y];int l,r;
    if (c[y][0]==x) l=0;else l=1;
    r=l^1; 
    if (y==k) k=x;
    else
    {
        if (c[z][0]==y) c[z][0]=x;
        else c[z][1]=x;
    }
    fa[y]=x;fa[x]=z;fa[c[x][r]]=y;
    c[y][l]=c[x][r];c[x][r]=y;
}
 
void splay(int x,int &k)
{
    while (x!=k)
    {
        int y=fa[x];
        int z=fa[x];
        if (y!=k)
        {
            if (c[y][0]==x^c[z][0]==y)
            ROTATE(x,k);else ROTATE(y,k);
        }
        ROTATE(x,k);
    }
}
 
void INSERT(int &k,int x,int last)
{
    if (k==0)
    {
        k=++size;
        v[k]=x;
        fa[k]=last;
        if (x<v[last]) c[last][0]=k;
        else c[last][1]=k;
        splay(k,root);
    }
    else
    {
        if (x<v[k])
        INSERT(c[k][0],x,k);
        else
        INSERT(c[k][1],x,k);
    }
}
 
void ASK_PRE(int &k,int x)
{
    if (k==0) return;
    if (v[k]<=x)
    {
        t1=v[k];
        ASK_PRE(c[k][1],x);
    } else
    ASK_PRE(c[k][0],x);
}
 
void ASK_NEX(int &k,int x)
{
    if (k==0) return;
    if (v[k]>=x)
    {
        t2=v[k];
        ASK_NEX(c[k][0],x);
    } else
    ASK_NEX(c[k][1],x);
}
 
void READIN()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        t1=INF;t2=INF;
        int sum=0;
        if (i==1) sum=a[i];
        else
        {
            ASK_PRE(root,a[i]);ASK_NEX(root,a[i]);
            sum=min(abs(a[i]-t1),abs(a[i]-t2));
        }
        ans+=sum;
        INSERT(root,a[i],0);
    }
    cout<<ans<<endl;
    return;
}
 
int main()
{
    READIN();
    return 0;
}
