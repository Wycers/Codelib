#include <cstdio>
#include <algorithm>
const int N = 1e6 + 10;
using namespace std;
int n,m,pos[N];
void Readin()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
        scanf("%d",pos + i);
}
bool Judge(int x)
{
    int cnt = 1,last = 1;
    for (int i=2;i<=n;++i)
        if (pos[i] - pos[last] >= x)
        {
            last = i;
            if (++cnt >= m)
                return true; //x is too small
        }
    return false;
}
void Work()
{
    sort(pos + 1,pos + n + 1);
    int l = 1,r = 0x3f3f3f3f,mid,ans;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (Judge(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    printf("%d\n",ans);
}

int main()
{
    Readin();
    Work();
    return 0;
}
