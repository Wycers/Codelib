#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

const int N = 1e7 + 10;
unsigned x, y, z, a[N];
int n;
unsigned tang()
{
    unsigned t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;

    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y;
    return z;
}

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}
unsigned long long lcm(unsigned long long a, unsigned long long b)
{
    return 1LL * a / gcd(a, b) * b ;
}
int main()
{
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        scanf("%d%u%u%u", &n, &x, &y, &z);
        for (int i = 1; i <= n; ++i)
            a[i] = tang();
        
        int magic = min(233, n);

        nth_element(a + 1, a + magic + 1, a + n + 1, greater<unsigned>());
        unsigned long long ans = 0;
        for (int i = 1; i <= magic; ++i)
            for (int j = i + 1; j <= magic; ++j)
                ans = max(ans, lcm(a[i], a[j]));
        printf("Case #%d: %llu\n", t, ans);
    }
    return 0;
}