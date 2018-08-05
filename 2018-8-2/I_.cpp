#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int Mo = 998244353;
int n, cnty, cnt[N], hy[N];

struct node
{
    int x, y;
} a[N];
inline bool cmpx(const node &i, const node &j)
{
    return i.x > j.x;
}

int tr[N << 2];
void add(int pos)
{
    for (int i = pos; i <= n; i += i & -i)
        ++tr[i];
}
int sum(int pos)
{
    int res = 0;
    for (int i = pos; i >= 1; i -= i & -i)
        res += tr[i];
    return res;
}
 
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].x, &a[i].y);

    for (int i = 1; i <= n; ++i)
        hy[i] = a[i].y;
    sort(hy + 1, hy + n + 1);



    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(hy + 1, hy + n + 1, a[i].y) - hy;
        a[i].y = pos;
        ++cnt[pos];
    }

    // |S| = 1
    long long ans = n;

    // |S| = 2
    ans += 1LL * n * (n - 1) / 2;
    for (int i = 1; i <= n; ++i)
        ans -= 1LL * cnt[i] * (cnt[i] - 1) / 2;
    ans %= Mo;

    // |S| = 3
    sort(a + 1, a + n + 1, cmpx);
    for (int i = 1, pre = 1; i <= n; i++)
    {
        int up = sum(n) - sum(a[i].y);
        int down = sum(a[i].y - 1);
        ans = (ans + 1LL * up * down) % Mo;
        if (a[i].x != a[i + 1].x)
            for (pre; pre <= i; ++pre)
                add(a[pre].y);
    }
    printf("%lld\n", ans);
    return 0;
}