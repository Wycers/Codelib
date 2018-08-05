#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
int n, a[2][N], t[2][2][N];
long long ma(long long a, long long b)
{
    return a > b ? a : b;
}
long long k[2], b[2];
long long ans = 0, res = 0;
void work(int tnow, int i, int now)
{
    k[now] -= a[0][i];
    k[now] -= a[1][i];
    b[now] -= t[now][0][i] * a[0][i];
    b[now] -= t[now][1][i] * a[1][i];
    res += tnow * a[now][i];
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[0][i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[1][i]);

    int ti = 0;
    for (int i = 1; i <= n; ++i)
        t[1][1][i] = t[0][0][i] = ti++;
    for (int i = n; i >= 1; --i)
        t[1][0][i] = t[0][1][i] = ti++;

    for (int i = 1; i <= n; ++i)
        k[0] += 1LL * a[0][i];
    for (int i = n; i >= 1; --i)
        k[0] += 1LL * a[1][i];
    for (int i = 1; i <= n; ++i)
        b[0] += 1LL * t[0][0][i] * a[0][i];
    for (int i = n; i >= 1; --i)
        b[0] += 1LL * t[0][1][i] * a[1][i];

    k[1] = k[0];
    for (int i = 1; i <= n; ++i)
        b[1] += 1LL * t[1][0][i] * a[0][i];
    for (int i = n; i >= 1; --i)
        b[1] += 1LL * t[1][1][i] * a[1][i];
    
    int now = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = ma(ans, res + k[now] * (i - 1) + b[now]);
        work(2 * (i - 1), i, now);
        now ^= 1;
        work(2 * (i - 1) + 1, i, now);
    }
    printf("%lld\n", ans);
    return 0;
}