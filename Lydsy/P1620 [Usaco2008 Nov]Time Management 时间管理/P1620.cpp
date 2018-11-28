#include <cstdio>
#include <algorithm>
const int N = 1000 + 10;
using namespace std;
int x[N],y[N],tag[N];
int n,ans = 0x3f3f3f3f;
bool cmp(const int a,const int b)
{
    return y[a] < y[b];
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d%d",x + i,y + i);
        tag[i] = i;
    }
    sort(tag + 1,tag + n + 1,cmp);
    for (int i=n;i>=1;--i)
        ans = min(ans,y[tag[i]]) - x[tag[i]];
    printf("%d\n",ans < 0 ? -1 : ans);
    return 0;
}
