#include <cstdio>
#include <algorithm>
#define N 100005
using namespace std;
int a[N],n;
int Guass()
{
    int now = 1,i,m = 31;
    while (m--)
    {
        for (i=now;i<=n;i++)
            if (a[i] & (1 << m))
            {
                swap(a[i],a[now]);
                for (int j=1;j<=n;j++)
                    if (j != now && a[j] & (1 << m))
                        a[j] ^= a[now];
                now++;
                break;
            }
    }
    return --now;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",a + i);
    int have = Guass(),now = 0,q;
    scanf("%d",&q);
    long long rank = 0;
    for (int i=1;i<=have;i++)
        if ((now ^ a[i]) <= q)
        {
            now ^= a[i];
            rank += ((long long)(1 <<(have - i))) % 10086;
            rank %= 10086;
        }
    for (int i=1;i<=n-have;i++)
    {
        rank <<= 1;
        rank %= 10086;
    }
    rank ++;
    printf("%lld",rank % 10086);
    return 0;
}
