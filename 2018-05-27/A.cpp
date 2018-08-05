#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double pi = acos(-1);
double R, r, m, n, x[2], y[2];
int main() 
{
    scanf("%lf%lf%lf%lf%lf%lf%lf", &m, &n, &R, x, y, x + 1, y + 1);
    r = R / n;
    double ans1 = r * fabs(y[0] - y[1]) + pi * r * min(y[0], y[1]) * fabs(x[0] - x[1]) / m;
    double ans2 = (y[0] + y[1]) * r;
    printf("%.6f\n", min(ans1, ans2));
    return 0;
}