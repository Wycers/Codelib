#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], h[N], g[N], cnt;
void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", h + i);
        a[i] = h[i];
    }
    sort(a + 1, a + n + 1);
    cnt = unique(a + 1, a + n + 1) - a - 1;

    int ans = 0;
    memset(g, 0, sizeof g);
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(a + 1, a + cnt + 1, h[i]) - a;
        ++g[pos];
    }   
    for (int i = 1; i <= n; ++i)
    {
        int pos = lower_bound(a + 1, a + cnt + 1, m - h[i]) - a;
        if (a[pos] == m - h[i] && g[pos])
            ++ans;
    }
    printf("%d\n", ans / 2);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}