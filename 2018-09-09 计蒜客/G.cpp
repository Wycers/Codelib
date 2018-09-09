#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 5e4 + 10;
const int M = 10000000;
int n, x[N], y[N];
struct tree
{
    int tr[M + 10];
    tree () {
        memset(tr, 0, sizeof tr);
    }
    void add(int x)
    {
        for (int i = x; i <= M; i += (i & -i))
            ++tr[i];
    }
    ll sum(int x)
    {
        ll res = 0;
        for (int i = x; i >= 1; i -= (i & -i))
            res += tr[i];
        return res;
    }
} tx, ty;
ll find(tree &t, int x)
{
    int l = 1, r = x, tar = t.sum(x);
    ll res;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (t.sum(mid) < tar)
        {
            l = mid + 1;
        }
        else
        {
            res = mid;
            r = mid - 1;
        }
    }
    return res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", x + i, y + i);
        ++x[i]; ++y[i];
    }
    ll ans = x[n] + y[n] - 2;
    tx.add(x[n]);
    ty.add(y[n]);
    for (int i = n - 1; i >= 1; --i)
    {
        ll mx = find(tx, x[i]);
        ll my = find(ty, y[i]);
        ans += x[i] - mx + y[i] - my;
        tx.add(x[i]);
        ty.add(y[i]);
    }
    printf("%lld\n", ans);
    return 0;
}
