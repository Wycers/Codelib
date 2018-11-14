#include <cstdio>
#include <algorithm>
const int N = 50000 + 10;
using namespace std;
int str[N],wei[N],tag[N];
int n;
void Readin()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d%d",wei + i,str + i);
        tag[i] = i;
    }
}
bool cmp(const int a,const int b)
{
    return wei[b] - str[a] < wei[a] - str[b];
}
void Work()
{
    int sum = 0,ans = -0x3f3f3f3f;
    for (int i=1;i<=n;++i)
        tag[i] = i;
    sort(tag + 1,tag + n + 1,cmp);
    for (int i=n;i>=1;--i)
    {
        ans = max(ans,sum - str[tag[i]]);
        sum += wei[tag[i]];
    }
    printf("%d\n",ans);
}
int main()
{
    Readin();
    Work();
    return 0;
}
