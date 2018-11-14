#include <cstdio>
#include <cmath>
using namespace std;
int tr[400005],M,n;
int Read()
{
    char ch = getchar();int x = 0;
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') {x = x * 10 + ch - 48;ch = getchar(); }
    return x;
}

void Change(int x,int y,bool k)
{
    x += M;
    tr[x] = sqrt(tr[x]);
    if (k) tr[x] = y;
    for (x>>=1;x;x>>=1)
        tr[x] = tr[x << 1] + tr[x << 1 | 1];
}

void Query(int s,int t)
{
    long long ans = 0;
    for (s=s+M-1,t=t+M+1;s^t^1;s>>=1,t>>=1)
    {
        if (~s & 1) ans += tr[s ^ 1];
        if ( t & 1) ans += tr[t ^ 1];
    }
    printf("%lld\n",ans);
}

void Readin()
{
    int t;
    scanf("%d",&n);
    for(M=1;M<(n+2);M<<=1);
    for (int i=1;i<=n;i++)
    {
        t = Read();
        Change(i,t,true);
    }
}

void Work()
{
    int T,opt,x,y;
    scanf("%d",&T);
    while (T--)
    {
        opt = Read();x = Read();y = Read();
        if (opt)
            Query(x,y);
        else
            for (int i=x;i<=y;i++)
                Change(i,0,false);
    }
}

int main()
{
    Readin();
    Work();
    return 0;
}
