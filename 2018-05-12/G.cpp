#include <cstdio>
#include <iostream>
#include<cmath>
#include <ctime>
#include<algorithm>
#include <cstdlib>
using namespace std;
const int N = 1e5 + 10;
int n, h;
double x[N], y[N], rd, ru;
void readin()
{
    scanf("%d%d", &n, &h);
    for (int i = 1; i <= n; ++i)
        scanf("%lf%lf", x + i, y + i);
    x[0] = y[0] = 0.0;
}

double work(double d)
{
    double u = d + (double)h;
    double ans = 0;
    for (int i = 0; i < n; ++i)
    {
        double k = (y[i + 1] - y[i]) / (x[i + 1] - x[i]);
        double b = y[i] - k * x[i];
        if (y[i] > u)
        {
            if (y[i + 1] > u)
                continue;
            if (y[i + 1] < d)
                ans += (d - u) / k;
            else
                ans += x[i + 1] - (u - b) / k;
        }
        else if (y[i] < d)
        {
            if (y[i + 1] < d)
                continue;
            if (y[i + 1] > u)
                ans += (u - d) / k;
            else
                ans += x[i + 1] - (d - b) / k;
        }
        else
        {
            if (y[i + 1] > u)
                ans += (u - b) / k;
            else if (y[i + 1] < d)
                ans += (d - b) / k;
            else
                ans += x[i + 1];
            ans -= x[i];
        }
    }
    return ans;
}

void solve()
{
    rd = ru = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (rd > y[i])
            rd = y[i];
        if (ru < y[i])
            ru = y[i];
    }
    int T = 50;
    double ans = 0;
    srand(time(0));
    while (T--)
    {
        double nowy =  rd + (ru - rd) * (rand() % 1000000 / 1000000.0), ty, now;
        double mx = work(nowy);
        double t = ru - rd;
        while (t > 1e-8)
        {
            ty = rand() % 2;
            if (ty == 0)
                ty = -1;
            ty = nowy + ty * t;
        
            now = work(ty);
            if (now >= mx)
            {
                mx = now;
                nowy = ty;
            }
            t *= 0.985;
        }
        ans = max(ans, mx);
    }
    printf("%.6lf\n", ans);
}
int main()
{
    readin();
    solve();
    return 0;
}