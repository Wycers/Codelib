#include <cstdio>
typedef long long ll;
const int N = 1e3 + 10;
const int Mo = 1e9 + 7;
using namespace std;
int n, m; ll p[N], f[N];
ll pow(ll a, ll b)
{
    ll res = 1;
    for (; b > 0; b >>= 1, a = a * a % Mo)
        if (b & 1)
            res = res * a % Mo;
    return res;
}
const ll inv = pow(100, Mo - 2);
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", p + i);
        p[i] = p[i] * inv % Mo;
    }
    for (int i = 1; i <= n; ++i)
    {
        f[i] = (Mo + 1 - p[i]) % Mo * f[i - 1] % Mo;
        ll sum = p[i];
        for (int j = i - 1; j >= 0; --j)
        {
            ll tp;
            if (j == 0)
                tp = pow(i - j, m) % Mo * sum % Mo;
            else
                tp = (f[j - 1] + pow(i - j, m)) % Mo * (Mo + 1 - p[j]) % Mo % Mo * sum % Mo;
            f[i] = (f[i] + tp) % Mo;
            sum = sum * p[j] % Mo;
        }
    }
    printf("%lld\n", f[n]);
    return 0;
}