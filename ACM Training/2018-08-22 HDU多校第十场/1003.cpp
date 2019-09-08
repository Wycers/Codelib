#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e7 + 10;
int euler_phi(int n)
{
    int m = (int)sqrt(n + 0.5);
    int res = n;
    for (int i = 2; i <= m; ++i)
        if (n % i == 0)
        {
            for (res = res / i * (i - 1); n % i == 0; n /= i);
        }
    if (n > 1)
        res = res / n * (n - 1);
    return res;
}
inline ll fpow(ll x, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = res * x;
        x = x * x;
        n >>= 1;
    }
    return res;
}
int phi[N];
void gen_phi(int n)
{
    phi[1] = 1;
    for (int i = 2; i <= n; ++i)
        if (!phi[i])
        {
            for (int j = i; j <= n; j += i)
            {
                if (!phi[j])
                    phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
}
ll f[N], g[N];

bool is_prime[N], update[N];
int prime[N], facnt[N];

int sieve(int n)
{
    int p = 0;
    fill(is_prime + 2, is_prime + n + 1, true);
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
            prime[p++] = i;
        for (int j = 0; j < p; j++)
        {
            if (prime[j] * i > n)
                break;
            is_prime[prime[j] * i] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
    return p;
}
void init()
{
    int cnt = sieve(1e7);
    for (int i = 0; i <= 1e7; ++i)
        f[i] = g[i] = 1;
    for (int i = 0; i < cnt; ++i)
        for (ll res = 1, j = prime[i]; j <= 1e7; ++res, j *= prime[i])
        {
            if (res >= 2)
                f[j] *= fpow(prime[i], res - (int)floor((float)res / 2.0));
            else 
                f[j] *= j;
            if (res >= 3)
                g[j] *= fpow(prime[i], res - (int)floor((float)res / 3.0));
            else 
                g[j] *= j;
        }
    for (int i = 0; i < cnt; ++i)
         for (ll j = fpow(prime[i], (int)log(1e7) / log((double)prime[i])); j >= 2; j /= prime[i])
            for (int k = j; k <= 1e7; k += j)
            {
                if (f[k] % prime[i] != 0)
                    f[k] *= f[j];
                if (g[k] % prime[i] != 0)
                    g[k] *= g[j];
            }
    printf("%d\n", f[8]);
    printf("%d\n", f[9]);
    printf("%d\n", f[5]);
    printf("%d\n", f[72]);
    printf("%d\n", f[360]);
}
int main()
{
    init();
    return 0;
}