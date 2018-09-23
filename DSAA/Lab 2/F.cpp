#include <cstdio>
#include <cmath>
using namespace std;
const double eps = 1e-12;
const int N = 5e4 + 10;
int n;
double x[N], w[N];
double cal(double t)
{
    double res = 0;
    for (int i = 1; i <= n; ++i)
    {
        double tmp = fabs(x[i] - t);
        res += w[i] * tmp * tmp * tmp;
    }
    return res;
}
double solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lf%lf", x + i, w + i);
    double l = -1e6 - 5, r = 1e6 + 5;
    while (fabs(r - l) > eps)
    {
        double mid1 = l + (r - l) / 3;
        double mid2 = r - (r - l) / 3;
        if (cal(mid1) < cal(mid2))
            r = mid2;
        else
            l = mid1;
    }
    return cal(l);
}
int main()
{
    int T; scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
        printf("Case #%d: %.0f\n", i, solve());
    return 0;
}