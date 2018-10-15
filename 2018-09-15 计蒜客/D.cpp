#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100;
int n, m, a[N], cnt[N], gg[N];
void dfs(int k)
{
    if (k == m)
    {
        memset(cnt, 0 ,sizeof cnt);
        for (int i = 0; i < m; ++i)
            ++cnt[a[i]];
        int res = 0;
        for (int i = 1; i <= n; ++i)
            res = max(res, cnt[i]);
        ++gg[res];
        return;
    }
    if (k == 0)
        for (a[k] = 1; a[k] <= n; ++a[k])
            dfs(k + 1);
    else 
        for (a[k] = a[k - 1]; a[k] <= n; ++a[k])
            dfs(k + 1);
}
int main()
{
    while (~scanf("%d%d", &m, &n))
    {
        memset(gg, 0, sizeof gg);
        dfs(0);
        for (int i = 1; i <= m; ++i)
            printf("%d: %d\n", i, gg[i]);
    }
    return 0;
}