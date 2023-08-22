#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 7;
const double PI = acos(-1.0);
ll notpri[maxn], pri[maxn], divi[maxn];
ll n, p;
ll f[maxn];
int cnt[maxn];
int l = 0, rev[maxn];
int lim = 1;
ll ans[maxn];
int id[maxn];
struct complx
{
    double x, y;
    complx(double a = 0, double b = 0)
    {
        x = a;
        y = b;
    }
    complx operator+(complx a)
    {
        return complx(x + a.x, y + a.y);
    }
    complx operator-(complx a)
    {
        return complx(x - a.x, y - a.y);
    }
    complx operator*(complx a)
    {
        return complx(x * a.x - y * a.y, x * a.y + y * a.x);
    }
} a[maxn], b[maxn];
void FFT(complx *A, int type)
{
    for (int i = 0; i < lim; i++)
    {
        if (i < rev[i])
            swap(A[i], A[rev[i]]);
    }
    for (int i = 1; i < lim; i <<= 1)
    {
        complx wn(cos(PI / i), type * sin(PI / i));
        for (int j = 0; j < lim; j += (i << 1))
        {
            complx w(1, 0);
            for (int k = 0; k < i; k++, w = w * wn)
            {
                complx x = A[j + k], y = w * A[j + i + k];
                A[j + k] = x + y;
                A[j + i + k] = x - y;
            }
        }
    }
    if (type == -1)
    {
        for (int i = 0; i < lim; i++)
            a[i].x /= lim;
    }
}
void doit()
{
    while (lim <= (p << 1))
    {
        lim <<= 1;
        l++;
    }
    for (int i = 0; i < lim; i++)
        a[i].x = (double)cnt[i];
    for (int i = 0; i < lim; i++)
    {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));
    }
    FFT(a, 1);
    for (int i = 0; i < lim; i++)
    {
        a[i] = a[i] * a[i];
    }
    FFT(a, -1);
    for (int i = 0; i < lim; i++)
    {
        ans[i % (p - 1)] += (ll)(a[i].x + 0.5);
    }
}
ll qpow(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans = (ans % p) * (a % p) % p;
        b >>= 1;
        a = (a % p) * (a % p) % p;
    }
    return ans % p;
}
void getprime()
{
    notpri[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!notpri[i])
            pri[++pri[0]] = i;
        for (int j = 1; j <= pri[0] && i * pri[j] < maxn; j++)
        {
            notpri[i * pri[j]] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
}
int findroot(ll x)
{
    ll tmp = x - 1;
    for (int i = 1; i <= pri[0]; i++)
    {
        if (tmp % pri[i] == 0)
        {
            divi[++divi[0]] = pri[i];
            while (tmp % pri[i] == 0)
                tmp /= pri[i];
        }
    }
    if (tmp > 1)
        divi[++divi[0]] = tmp;
    for (int g = 2; g <= x - 1; g++)
    {
        bool found = false;
        for (int i = 1; i <= divi[0]; i++)
        {
            if (qpow(g, (x - 1) / divi[i]) == 1)
            {
                found = true;
                break;
            }
        }
        if (!found)
            return g;
    }
    return 0;
}
int main()
{
    getprime();
    scanf("%lld%lld", &n, &p);
    int g = findroot(p);
    int t = 1;
    for (int i = 0; i < p - 1; i++)
    {
        id[t] = i;
        t = (t % p) * (g % p) % p;
    }
    ll zero = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", f + i);
        if (f[i] % p == 0)
        {
            zero++;
            continue;
        }
        cnt[id[f[i] % p]]++;
        printf("%d %d\n", id[f[i] % p], cnt[id[f[i] % p]]);
    }
    
    doit();
    for (int i = 1; i <= n; i++)
    {
        if (f[i] >= p)
            printf("0\n");
        else if (f[i] % p == 0)
            printf("%lld\n", 2 * zero * (n - zero) + zero * zero);
        else
            printf("%lld\n", ans[id[f[i] % p]]);
    }
    return 0;
}