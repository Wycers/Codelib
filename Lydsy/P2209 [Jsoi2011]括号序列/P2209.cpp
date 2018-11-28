#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int n,m,q;
int mp[305][305];
int t[105][305][305];
inline int lowbit(int x){return x&(-x);}
void update(int x,int y,int c,int val)
{
     for(int i=x;i<=n;i+=lowbit(i))
         for(int j=y;j<=m;j+=lowbit(j))
             t[c][i][j]+=val;
}
inline int ask(int x,int y,int c)
{
    int tmp=0;
    for(int i=x;i;i-=lowbit(i))
        for(int j=y;j;j-=lowbit(j))
            tmp+=t[c][i][j];
    return tmp;
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            mp[i][j]=read();
            update(i,j,mp[i][j],1);
        }
    q=read();
    for(int i=1;i<=q;i++)
    {
        int f=read();
        int x1,y1,x2,y2,c;
        if(f==1)
        {
            x1=read();y1=read();c=read();
            update(x1,y1,mp[x1][y1],-1);
            mp[x1][y1]=c;
            update(x1,y1,mp[x1][y1],1);
        }
        else 
        {
            x1=read();x2=read();
            y1=read();y2=read();c=read();
            int ans=0;
            ans=ask(x2,y2,c)+ask(x1-1,y1-1,c);
            ans-=ask(x1-1,y2,c);
            ans-=ask(x2,y1-1,c);
            printf("%d\n",ans);
        }
    }
    return 0;
