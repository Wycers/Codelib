#include <cstdio>
#include <algorithm>
const int N = 50000;
using namespace std;
int n,m,L;
int pos[N];
void Readin()
{
    scanf("%d%d%d",&L,&n,&m);
    for (int i=1;i<=n;++i)
        scanf("%d",pos + i);
    pos[++n] = 0;
    pos[++n] = L;
}
bool Judge(int x)
{
    int last = 1,ans = 0;
    for (int i=2;i<=n;++i)
    {
        if (pos[i] - pos[last] < x)
        {
            if (++ans > m)
                return false;
        }
        else
            last = i;
    }
    return true;
}
void Work()
{
    sort(pos + 1,pos + n + 1);
    int l = 1,r = L,mid,ans;
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
