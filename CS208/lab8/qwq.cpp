#include <cstdio>
#include <algorithm>
#include <complex>
typedef long long ll;
const int N = 1e6 + 10;
const double PI = acos(-1.0);
using namespace std;
struct FastFourierTransform
{
    complex<double> omega[N], omegaInverse[N];

    void init(const int n)
    {
        for (int i = 0; i < n; i++)
        {
            omega[i] = complex<double>(cos(2 * PI / n * i), sin(2 * PI / n * i));
            omegaInverse[i] = conj(omega[i]);
        }
    }

    void transform(complex<double> *a, const int n, const complex<double> *omega)
    {
        int k = 0;
        while ((1 << k) < n)
            k++;
        for (int i = 0; i < n; i++)
        {
            int t = 0;
            for (int j = 0; j < k; j++)
                if (i & (1 << j))
                    t |= (1 << (k - j - 1));
            if (i < t)
                swap(a[i], a[t]);
        }

        for (int l = 2; l <= n; l <<= 1)
        {
            int m = l >> 1;
            for (complex<double> *p = a; p != a + n; p += l)
            {
                for (int i = 0; i < m; i++)
                {
                    complex<double> t = omega[n / l * i] * p[m + i];
                    p[m + i] = p[i] - t;
                    p[i] += t;
                }
            }
        }
    }

    void dft(complex<double> *a, const int n)
    {
        transform(a, n, omega);
    }

    void idft(complex<double> *a, const int n)
    {
        transform(a, n, omegaInverse);
        for (int i = 0; i < n; i++)
            a[i] /= n;
    }
} fft;

inline void multiply(const int *a1, const int n1, const int *a2, const int n2, int *res)
{
    int n = 1;
    while (n < n1 + n2)
        n *= 2;
    static complex<double> c1[N], c2[N];
    for (int i = 0; i < n1; i++)
        c1[i].real(a1[i]);
    for (int i = 0; i < n2; i++)
        c2[i].real(a2[i]);
    fft.init(n);
    fft.dft(c1, n), fft.dft(c2, n);
    for (int i = 0; i < n; i++)
        c1[i] *= c2[i];
    fft.idft(c1, n);
    for (int i = 0; i < n1 + n2 - 1; i++)
        res[i] = static_cast<int>(floor(c1[i].real() + 0.5));
}

int n, p, a[N], id[N], cnt[N], res[N];
ll notpri[N], pri[N], divi[N];
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
    for (int i = 2; i < N; i++)
    {
        if (!notpri[i])
            pri[++pri[0]] = i;
        for (int j = 1; j <= pri[0] && i * pri[j] < N; j++)
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
    scanf("%d%d", &n, &p);
    getprime();
    int g = findroot(p);
    int t = 1;
    for (int i = 0; i < p - 1; i++)
    {
        id[t] = i;
        t = (t % p) * (g % p) % p;
    }
    ll zero = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        if (a[i] % p == 0)
        {
            ++zero;
            continue;
        }
        ++cnt[id[a[i] % p]];
    }
    multiply(cnt, p, cnt, p, res);
    printf("%lld\n", 2 * zero * (n - zero) + zero * zero);
    for (int i = 1; i < p; ++i)
        printf("%lld\n", res[id[i]] + res[id[i] + p - 1]);
    return 0;
}