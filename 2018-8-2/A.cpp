#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps = 1e-8;
const int N = 1e5 + 10;
int n, k, tag[N];
double s[N], c[N], t[N];
inline bool cmp(const int &a, const int &b)
{
    return t[a] > t[b];
}
bool judge(double d)
{
    for (int i = 1; i <= n; ++i)
    {
        tag[i] = i;
        t[i] = s[i] * (c[i] - d);
    }
    sort(tag + 1, tag + n + 1, cmp);
    double sum = 0;
    for (int i = 1; i <= n - k; ++i)
        sum += t[tag[i]];
    return sum >= 0;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%lf", s + i);
    for (int i = 1; i <= n; ++i)
        scanf("%lf", c + i);

    double l = 0, r = 1e3;
    while (fabs(r - l) > eps)
    {
        double mid = (l + r) / 2;
        if (judge(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%.8lf\n", l);
    return 0;
}