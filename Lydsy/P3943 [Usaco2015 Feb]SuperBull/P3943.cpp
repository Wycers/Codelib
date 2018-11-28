#include <cstdio>
#include <algorithm>
const int N = 2e3 + 10;
using namespace std;
int n,a[N];
long long ans;
void Prim()
{
    static int f[N];
    static bool vis[N];
    int tag;
    for (int i=1;i<=n;++i)
    {
        tag = 0;
        for (int j=1;j<=n;++j)
            if (!vis[j] && f[j] >= f[tag])
                tag = j;
        vis[tag] = true;
        ans += f[tag];
        for (int j=1;j<=n;++j)
            f[j] = max(f[j],a[tag] ^ a[j]);
    }
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",a + i);
    Prim();
    printf("%I64d\n",ans);
    return 0;
}
