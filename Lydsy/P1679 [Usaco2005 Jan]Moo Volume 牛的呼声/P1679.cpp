#include <cstdio>
#include <algorithm>
const int N = 10000 + 10;
using namespace std;

int pos[N],l[N],r[N],n;
void Init()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",pos + i);
    sort(pos + 1,pos + n + 1);
}
void Work()
{
    long long ans = 0;
    for (int i=2;i<=n;i++)
        ans += pos[i] - pos[1];
    long long last = ans;
    for (int i=2;i<=n;i++)
    {
        last = last + (long long)(i - 1) * (pos[i] - pos[i - 1]) - (long long)(n - i + 1) * (pos[i] - pos[i - 1]);
        ans += last;
    }
    printf("%lld\n",ans);
}

int main()
{
    Init();
    Work();
    return 0;
}
