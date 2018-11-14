#include <cstdio>
#include <algorithm>
const int N = 1e5 + 10;
using namespace std;
int l[N],r[N],n,L;
void Readin()
{
    scanf("%d%d",&n,&L);
    for (int i=1;i<=n;++i)
        scanf("%d%d",l + i,r + i);
}
int tag[N];
bool cmp(int a,int b)
{
    return l[a] < l[b];
}
void Work()
{
    for (int i=1;i<=n;++i)
        tag[i] = i;
    sort(tag + 1,tag + n + 1,cmp);
    int now = 0,ans = 0,t;
    for(int i=1;i<=n;++i)
    {
        if(now >= r[tag[i]])continue;
        now = max(now,l[tag[i]]);
        while(now < r[tag[i]])
        {
            ++ans;
            now += L;
        }
    }
    printf("%d\n",ans);
}
int main()
{
    Readin();
    Work();
    return 0;
}
