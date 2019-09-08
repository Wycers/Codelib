#include <cstdio>
using namespace std;
const int N = 5e3 + 10;
const int mo = 1e9 + 7;
long long f[N][N];
int n, m;
int main()
{
    f[1][1] = 2;
    for (int i = 2; i <= 5000; ++i)
    {
        f[1][i] = i + 1;
        f[i][1] = i + 1;
    }
    for (int i = 2; i <= 5000; ++i)
        for (int j = 2; j <= 5000; ++j)
        {
            f[i][j] = f[i - 1][j] + f[i][j - 1];
            f[i][j] %= mo;
        }

    while (scanf("%d%d", &n, &m))
    {
        long long ans = f[n][m] * (long long)(n + m - 1);
        printf("%lld\n", ans % mo);
    }
    return 0;
}