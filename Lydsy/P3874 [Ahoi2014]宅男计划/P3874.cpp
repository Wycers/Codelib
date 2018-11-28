#include<cstdio>
#include<algorithm>
using namespace std;
struct food
{
     long long p,s;
}ta[301],a[301];
int p;
inline bool cmp1(food x,food y)
{
     if(x.s<y.s)
          return true;
     if(x.s==y.s&&x.p<y.p)
          return true;
     return false;
}
inline bool cmp2(food x,food y)
{
     if(x.p<y.p)
          return true;
     return false;
}
long long m,f;
inline long long getans(long long x)
{
     long long xm=m-f*x;
     if(xm<0)
          return 0;
     int i;
     long long d=0,ans=0;
     for(i=1;i<=p;i++)
     {
          if(d<=a[i].s)
          {
               long long px=a[i].s-d+(long long)1;
               long long tx=min(px,xm/(a[i].p*x));
               ans+=tx*x;
               xm-=a[i].p*x*tx;
               d+=tx;
          }
          if(d<=a[i].s)
          {
               long long tx=min(x,xm/a[i].p);
               ans+=tx;
               xm-=a[i].p*tx;
               d++;
          }
     }
     return ans;
}
int main()
{
     int n;
     scanf("%lld%lld%d",&m,&f,&n);
     int i;
     for(i=1;i<=n;i++)
          scanf("%lld%lld",&ta[i].p,&ta[i].s);
     sort(ta+1,ta+1+n,cmp1);
     p++;
     a[p]=ta[1];
     for(i=1;i<=n;i++)
     {
          if(ta[i].s>a[p].s)
          {
               p++;
               a[p]=ta[i];
          }
     }
     sort(a+1,a+1+p,cmp2);
     long long l=1,r=m/(f+a[1].p);
     long long ans=max(getans(l),getans(r));
     while(l+12<=r)
     {
          long long tx=r-l+1;
          long long midl=l+tx/(long long)3,ansl=getans(midl);
          long long midr=l+tx*(long long)2/(long long)3,ansr=getans(midr);
          if(ansl<ansr)
          {
               ans=max(ansl,ans);
               l=midl;
          }
          else
          {
               ans=max(ansr,ans);
               r=midr;
          }
     }
     long long mk;
     for(mk=l;mk<=r;mk++)
          ans=max(ans,getans(mk));
     printf("%lld\n",ans);
     return 0;
}
