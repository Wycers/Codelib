#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || '9' < ch)
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

int n, m, a[N];
long long d[N], c1[N], c2[N], c3[N];
void add(int x, long long y)
{
    for (int i = x; i <= n; i += i & (-i))
    {
        c1[i] += y;
        c2[i] += (long long)x * y;
        c3[i] += (long long)x * x * y;
    }
}
long long sum(int x)
{
    long long ans = 0;
    for (int i = x; i; i -= i & (-i))
        ans += c3[i] - (3 + 2 * x) * c2[i] + (x * x + 3 * x + 2) * c1[i];
    return ans;
}
void init()
{
    memset(c1, 0, sizeof(c1));
    memset(c2, 0, sizeof(c2));
    memset(c3, 0, sizeof(c3));
    n = read(); m = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    for (int i = 1; i <= n; ++i)
        d[i] = a[i] - a[i - 1];
    for (int i = 1; i <= n; ++i)
        add(i, d[i] - d[i - 1]);
}

void solve()
{
    int q, l, r; long long a, d;
    while (m--)
    {
        q = read(); l = read(); r = read();
        if (q == 1)
        {
            a = (long long)read(); d = (long long)read();
            add(l, a); add(l + 1, -a + d);
            add(r + 1, -(a + (r - l + 1) * d)); add(r + 2, a + (r - l) * d);
        }
        else
        {
            printf("%lld\n", (sum(r) - sum(l - 1)) / 2);
        }
    }
}

int main()
{
    for (int T = read(); T; --T)
    {
        init();
        solve();
    }
    return 0;
}