#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e6 + 10;
int n, m, sta[N], cap[N], s[N], t[N], d[N];
bool judge(int x)
{
    memset(sta, 0, sizeof sta);
    for (int i = 1; i <= x; ++i)
    {
        sta[s[i]] += d[i];
        sta[t[i] + 1] -= d[i]; 
    }
    for (int i = 1; i <= n; ++i)
    {
        sta[i] += sta[i - 1];
        if (sta[i] > cap[i])
            return false;
    }
    return true;
}
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; ++i)
            scanf("%d", cap + i);
        for (int i = 1; i <= m; ++i)
            scanf("%d%d%d", d + i, s + i, t + i);
        int l = 1, r = m, ans = 0;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (judge(mid))
                l = mid + 1;
            else
            {
                ans = mid;
                r = mid - 1;
            }
        }
        if (ans)
            puts("-1");
        printf("%d\n", ans);
    }
    return 0;
}