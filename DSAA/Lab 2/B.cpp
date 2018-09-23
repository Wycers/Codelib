#include <cstdio>
#include <cmath>
using namespace std;
const double eps = 1e-5;
int n, m;
long double pow(long double x, int n)
{
    long double res = 1.0;
    while (n--)
        res *= x;
    return res;
}
long double CAL(long double x)
{
    return 35 * pow(x, 6) + 36 * pow(x, 5) + 9 * pow(x, 2) + 8 * x;
}
long double cal(long double x, long double y)
{
    return 5 * pow(x, 7) + 6 * pow(x, 6) + 3 * pow(x, 3) + 4 * pow(x, 2) - x * y;
}
long double solve()
{
    double l = 0.0, r = 100.0;
    long double y;
    scanf("%Lf", &y);
    y = y * 2;
    while (fabs(r - l) > eps)
    {
        double mid = (l + r) / 2;
        if (CAL(mid) < y)
            l = mid;
        else 
            r = mid;
    }
    return cal(l, y);
}
int main()
{
    freopen("test.in", "r", stdin);
    int T; scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
        printf("Case %d: %.4Lf\n", i, solve());
    return 0;
}