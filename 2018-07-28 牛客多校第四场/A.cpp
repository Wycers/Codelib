#include <cstdio>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;

const ll N = 100005;
const ll mod = 1000000007;

map<ll, ll> ph;

char s[N];
ll n;

ll phi(ll n)
{
    ll res = n;
    for (ll i = 2; i < sqrt(n) + 1; ++i)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            res = res / i * (i - 1);
        }
    }
    if (n > 1)
        res = res / n * (n - 1);
    return res;
}

void init()
{
    ll tmp = mod;
    while (tmp != 1)
    {
        ph[tmp] = phi(tmp);
        tmp = ph[tmp];
    }
    ph[1] = 1;
}

ll pow(ll x, ll n, ll Mod)
{
    ll res = 1;
    for ( ; n; n >>= 1, x = (x * x) % Mod)
        if (n & 1)
            res = (res * x) % Mod;
    return res;
}

ll dfs(ll now, ll Mod)
{
    if (now == 0)
        return 0;
    if (s[now] == '1')
        return (dfs(now - 1, Mod) * 2 + 2) % Mod;
    if (s[now] == '0')
        return (dfs(now - 1, Mod) + 1) % Mod;
    return ((ll)3 * (pow((ll)2, dfs(now - 1, ph[Mod]) + 1, Mod) - 1) % Mod + Mod) % Mod;
}

int main()
{
    init();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s + 1);
        printf("%lld\n", dfs(strlen(s + 1), mod));
    }
}