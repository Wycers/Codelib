#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
const int mod = 998244353;

int pow(int x, int y)
{
    int res = 1;
    for (; y; y >>= 1, x = 1LL * x * x % mod)
        if (y & 1)
            res = 1LL * res * x % mod;
    return res;
}
const int inv = pow(100, mod - 2);
int n, cnt, a[N], tr[N], p[N], d[N];

void add(int x, int val)
{
    for (int i = x; i >= 1; i -= i & -i)
        tr[i] = 1LL * tr[i] * val % mod;
}

int sum(int x)
{
    int res = 1;
    for (int i = x; i <= cnt; i += i & -i)
        res = 1LL * res * tr[i] % mod;
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", p + i, d + i);
        p[i] = 1LL * inv * p[i] % mod;
        a[i] = d[i];
    }

    sort(a + 1, a + n + 1);
    cnt = unique(a + 1, a + n + 1) - a - 1;
    for (int i = 1; i <= cnt; ++i)
        tr[i] = 1;

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(a + 1, a + cnt + 1, d[i]) - a;
        ans = (1LL * p[i] * sum(pos) + ans) % mod;
        add(pos, (1 - p[i] + mod) % mod);
    }
    printf("%d", ans);
    return 0;
}