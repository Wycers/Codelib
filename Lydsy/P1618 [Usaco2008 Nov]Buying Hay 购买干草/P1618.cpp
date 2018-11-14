#include <cstdio>
#include <algorithm>
#include <cstring>
const int H = 50000 + 10;
const int N = 100 + 10;
using namespace std;
int f[2 * H];
int p[N],c[N];
int n,m;
void Readin()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
        scanf("%d%d",p + i,c + i);
}
void Dp()
{
    memset(f,0x3f,sizeof(f));
    f[0] = 0;
    for (int i=1;i<=n;++i)
        for (int j=p[i];j<=m + H;++j)
            f[j] = min(f[j],f[j - p[i]] + c[i]);
    int ans = 0x7fffffff;
    for (int i=m;i<=m + H;++i)
        ans = min(ans,f[i]);
    printf("%d\n",ans);
}
int main()
{
    Readin();
    Dp();
    return 0;
}
