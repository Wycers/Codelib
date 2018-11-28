#include <cstdio>
#include <algorithm>
const int N = 50000 + 10;
using namespace std;
int Disc[2 * N],a[2 * N],cnt;
void Disc_Init()
{
    sort(Disc + 1,Disc + cnt + 1);
    cnt = unique(Disc + 1,Disc + cnt + 1) - Disc - 1;
}
int Disc_Find(int x)
{
    int l = 1,r = cnt,mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (Disc[mid] == x)
            return mid;
        if (x < Disc[mid])
            r = mid - 1;
        else
            l = mid + 1;
    }
}
int s[N],t[N],n;
void Readin()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d%d",s + i,t + i);
        Disc[++cnt] = s[i];
        Disc[++cnt] = t[i];
    }
}
void Work()
{
    int x,y;
    for (int i=1;i<=n;++i)
    {
        x = Disc_Find(s[i]);
        y = Disc_Find(t[i]);
        ++a[x];
        --a[y + 1];
    }
    int now = 0,ans = 0;
    for (int i=1;i<=cnt;++i)
    {
        now += a[i];
        ans = max(ans,now);
    }
    printf("%d\n",ans);
}
int main()
{
    Readin();
    Disc_Init();
    Work();
    return 0;
}
