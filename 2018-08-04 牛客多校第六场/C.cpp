#include <cstdio>
typedef long long ll;
const int mo = 998244353;
const int N = 1000010;
int inv[N];
ll n, m;
ll solve()
{
    scanf("%lld%lld", &n, &m);
    ll ans = 0, comp1 = m % mo, comp2 = 1;
    for (int i = 1; i <= n && i <= m; ++i)
    {
        ans = (ans + comp1 * comp2) % mo;
        comp1 = comp1 * ((m - i) % mo) % mo;
        comp2 = comp2 * ((n - i) % mo) % mo * inv[i] % mo;
    }
    return ans;
}

int main()
{
    inv[1] = 1;
    for (int i = 2; i < N; ++i)
        inv[i] = (mo - 1ll * (mo / i) * inv[mo % i] % mo) % mo;
    int T; scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
        printf("Case #%d: %lld\n", i, solve());
    return 0;
}