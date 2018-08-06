#include <cstdio>
#include <cmath>
using namespace std;
const double pi = acos(-1.0);

int n; double R;
double dis(double x, double y)
{
    return sqrt(x * x + y * y);
}
void solve()
{
    scanf("%d%lf", &n, &R);
    double ans = 2 * pi * R, x, y, r;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lf%lf%lf", &x, &y, &r);
        double d = dis(x, y);
        if (d > R + r)
            continue;
        if (d < R - r)
            continue;
        double ao = 2 * acos((R * R + d * d - r * r) / (2.0 * R * d));
        ans -= R * ao;
        double as = 2 * acos((r * r + d * d - R * R) / (2.0 * r * d));
        ans += r * as;
    }
    printf("%.8lf\n", ans);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}