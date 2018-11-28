#include <cstdio>
#include <algorithm>
const int N = 100000 + 10;
const int M = 1000000 + 10;
using namespace std;
int Read()
{
    int x = 0;char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x;
}
int a[N],cnt[M],mx = 0,n;
void Readin()
{
    n = Read();
    for (int i=1;i<=n;++i)
    {
        a[i] = Read();
        ++cnt[a[i]];
        mx = max(a[i],mx);
    }
}
int ans[M];
void Work()
{
    for (int i=1;i<=mx;++i)
        if (cnt[i])
            for (int j=i;j<=mx;j+=i)
                ans[j] += cnt[i];
    for (int i=1;i<=n;++i)
        printf("%d\n",ans[a[i]] - 1);
}
int main()
{
    Readin();
    Work();
    return 0;
}
