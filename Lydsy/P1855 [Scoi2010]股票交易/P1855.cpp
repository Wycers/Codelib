#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define For(i,x,y) for (int i=x;i<=y;++i)
#define Dor(i,x,y) for (int i=x;i>=y;--i)
#define Clr(x, t) memset(x,t,sizeof(x))
typedef long long ll;
using namespace std;
const int N = 2e3 + 10;
const int Inf = 0x3f3f3f3f;
 
int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
int n, MaxP, w, ans = -1;
int f[N][N], q[N], l, r;int val[N];
//Struct
 
//Code
void Dp(int now)
{
    int ap = read(), bp = read(), as = read(), bs = read(); 
    for (int i = 0; i <= as; ++i)
        f[now][i] = -ap * i;
    for (int i = 0; i <= MaxP; ++i)
        f[now][i] = max(f[now][i], f[now - 1][i]);
    int t = now - w - 1;
    if (t >= 0)
    {
        l = r = 0;
        for (int i = 0; i <= MaxP; ++i)
        {
            while (l < r && q[l] < i - as)
                ++l;
            while (l < r && f[t][i] - f[t][q[r - 1]] >= ap * (q[r - 1] - i))
                --r;
            q[r++] = i;
            if (l < r)
                f[now][i] = max(f[now][i], f[t][q[l]] + ap * (q[l] - i));   
        }
        l = r = 0;
        for (int i = MaxP; i >= 0; --i)
        {
            while (l < r && q[l] > i + bs)
                ++l;
            while (l < r && f[t][i] - f[t][q[r - 1]] >= bp * (q[r - 1] - i))
                --r;
            q[r++] = i;
            if (l < r)
                f[now][i] = max(f[now][i], f[t][q[l]] + bp * (q[l] - i));
        }
    }
    ans = max(ans, f[now][0]);
} 
int main()
{
    n = read(); MaxP = read(); w = read();
    Clr(f, 0xc0);
    for (int i = 1; i <= n; ++i)
        Dp(i);
    printf("%d\n", ans); 
    return 0;
}
