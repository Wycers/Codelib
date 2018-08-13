#include <cstdio>
using namespace std;
int Euler(int x)
{
    int res = x;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
        {
            x /= i;
            res = res - res / i;
            while (x % i == 0)
                x /= i;
        }
    if (x > 1)
        res = res - res / x;
    return res;
}
typedef long long ll;

void exgcd(ll a, ll b, ll &d, ll &x, ll &y)
{
    if (!b)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        exgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}

ll inv(ll a, ll p)
{
    ll d, x, y;
    exgcd(a, p, d, x, y);
    return d == 1 ? (x + p) % p : -1;
}
int n, m, p;
int main()
{
    scanf("%d%d%d", &m, &n, &p);
    printf("%d %d %d\n", Euler(9), inv(Euler(3) * Euler(3), p), inv(Euler(3), p));
    
    int res = 0;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {

            printf("%d %d %d\n", i, j, (Euler(i * j) * inv(Euler(i) * Euler(j), p)) % p);
            res += Euler(i * j) * inv(Euler(i) * Euler(j), p);
        }
    printf("%d\n", res % p);
    return 0;
}