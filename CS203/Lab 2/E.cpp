#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 5e5 + 10;
int L, n, m, pos[N];
bool judge(int x)
{
    int cnt = 1, last = 0;
    for (int i = 1; i <= n; i++)
        if (pos[i] - pos[last] > x)
        {
            if (++cnt > m)
                return false;
            if (pos[i] - pos[i - 1] > x)
                return false;
            last = i - 1;
        }
    return true;
}
int main()
{
    while (~scanf("%d%d%d", &L, &n, &m))
    {
        for (int i = 1; i <= n; ++i)
            scanf("%d", pos + i);
        sort(pos + 1, pos + n + 1);
        pos[0] = 0;
        pos[++n] = L;
        int l = 0, r = L, ans = L;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (judge(mid))
            {
                r = mid - 1;
                ans = mid;
            }
            else
                l = mid + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}