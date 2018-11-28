#include <cstdio>
#include <algorithm>
const int N = 3500;
const int M = 13000;
using namespace std;
int v[N],w[N];
int n,m;

int Read()
{
    int x = 0;char ch = getchar();
    while (!('0' <= ch && ch <= '9')) ch = getchar();
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x;
}
void Readin()
{
    n = Read(); m = Read();
    for (int i=1;i<=n;i++)
        w[i] = Read(),v[i] = Read();
}

int f[M];
void Dp()
{
    for (int i=1;i<=n;++i)
        for (int j=m;j>=w[i];--j)
            f[j] = max(f[j],f[j - w[i]] + v[i]);
    int ans = -1;
    for (int i=0;i<=m;++i)
        ans = max(ans,f[i]);
    printf("%d\n",ans);
}

int main()
{
    Readin();
    Dp();
    return 0;
}
