#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#define For(i,x,y) for(int i=x;i<=y;++i)
#define Dor(i,y,x) for(int i=y;i>=x;--i)
#define Clr(a,x) memset(a,x,sizeof(a))
#define eps 1e-8
#define inf 1e18
#define LL long long
#define MAXN 10010   
using namespace std;
//-----------------------------------------------
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
//-----------------------------------------------
struct Complex{
    double pos,v;
}src[MAXN];
  
struct Type
{
    double l,r;
    bool Merge(const Type &a) 
    {
        if(a.r < l)  return 0;
        if(a.l > r)  return 0;
        l = max(l, a.l);
        r = min(r, a.r);
        return 1;
    }
};
  
int n ,ans[MAXN];
  
int main()
{
    n = read();
    For(i, 1, n)
        src[i].pos = read();
    For(i, 1, n)
        src[i].v = read();
    For(i, 1, n)
    {
        Type now= (Type){0.0, inf};
        bool fl = true;
        For(j, 1, n)
        {
            if(i == j)  continue;
            Type temp;
            if (src[i].v == src[j].v)
                temp = src[i].pos >= src[j].pos ? (Type){-inf , inf}: (Type){- inf, -inf};
            else if (src[i].v > src[j].v)
                temp = (Type){(src[j].pos - src[i].pos) / (src[i].v - src[j].v), inf};
            else
                temp = (Type){-inf,  (src[j].pos - src[i].pos) / (src[i].v - src[j].v)};
            if(!now.Merge(temp)) 
            {
                fl = false;
                break;
            }
        }
        if (fl)
            ans[++ans[0]] = i;
    }
    printf("%d\n", ans[0]);
    For(i, 1, ans[0] - 1)
        printf("%d ",ans[i]);
    if (ans[0])
        printf("%d", ans[ans[0]]);
    return 0;
}
