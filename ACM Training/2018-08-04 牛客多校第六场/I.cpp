#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
const int mo = 998244353;

int t, n, m, x[N], y[N], tmp[N], tag[N], v[N];
vector<int> c[N];
void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", x + i, y + i);
    for (int i = 1; i <= n; ++i)
        tmp[i] = x[i];

    sort(tmp + 1, tmp + n + 1);
    int cntx = unique(tmp + 1, tmp + n + 1) - tmp - 1;
    for (int i = 1; i <= n; ++i)
    {
        x[i] = lower_bound(tmp + 1, tmp + cntx + 1, x[i]) - tmp;
        c[i].clear();
        v[i] = 0;
        tag[i] = i;
    }

    sort(tag + 1, tag + n + 1, [&](int i, int j){
        return y[i] < y[j];
    });
    for (int i = 1; i <= n; ++i)
    {
        int j = tag[i];
        for (int k = x[j]; k <= n; k += k & -k)
            c[k].emplace_back(j);
    }

    printf("Case #%d:\n", t);
    for (int i = 1, x, res = 0; i <= m; ++i)
    {
        scanf("%d", &x);
        x ^= res;
        int j = upper_bound(tmp + 1, tmp + cntx + 1, x) - tmp - 1;
        int cnt = 0; res = 1;
        for (int k = j; k > 0; k -= k & -k)
        {
            while (!c[k].empty() && y[c[k].back()] >= x)
            {
                int u = c[k].back();
                if (!v[u])
                {
                    v[u] = i;
                    ++cnt;
                    res = 1ll * u * res % mo; 
                }
                c[k].pop_back();
            }
        }
        printf("%d\n", cnt);
        if (cnt == 0)
            res = 0;
    }
    for (int i = 1; i <= n; ++i)
        printf("%d%c", v[i], " \n"[i == n]);
}   

int main()
{
    int T; scanf("%d", &T);
    for (t = 1; t <= T; ++t)
        solve();
    return 0;
}