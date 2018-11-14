#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Dor(i,y,x) for(int i=y;i>=x;i--)
#define Clr(a,x) memset(a,x,sizeof(a))
#define eps 1e-8
#define inf 2147483647/10
#define LL long long
#define MAXN 505
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
int n, m,f[MAXN][MAXN];
struct type
{
    int num, data;  
}a[MAXN];
int Dp(int l, int r)
{
    if (f[l][r] != -1) return f[l][r];
    if (l == r) return (a[l].num <= 2) ? 3 - a[l].num : 1;
    int now = inf;
    if (a[l].data == a[r].data)
        now = (a[l].num + a[r].num >= 3) ? Dp(l + 1, r - 1) : Dp(l + 1, r - 1) + 1;  
    For(i, l , r - 1)
        now = min(now, Dp(l, i) + Dp(i + 1, r));
    return f[l][r] = now;
}
int main()
{
    n = read();
    m = 0;
    a[m].data = -1;
    For(i, 1, n)
    {
        int x = read();
        if (x != a[m].data)
        {
            m ++;
            a[m].data = x;
            a[m].num = 1;
        }
        else a[m].num ++;
    }
    Clr(f, -1);
    cout << Dp(1, m) << endl;
    return 0;
}
