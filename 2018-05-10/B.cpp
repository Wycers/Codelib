#include <iostream>
#include <queue>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 2e5 + 10;
const double eps = 1e-8;
int read()
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

double x[N], y[N], ave;
double sqr(double x)
{
    return x * x;
}
double cal(int i)
{
    return sqr(x[i]) * (1.0 / y[i] - 1.0 / (y[i] + 1.0));
}
struct cmp
{
    bool operator()(const int &a, const int &b)
    {
        return cal(a) < cal(b);
    }
};
priority_queue<int, vector<int>, cmp> pq;

int n, m, a[N];
double solve()
{
    n = read();
    m = read();
    ave = 0;
    for (int i = 1; i <= n; ++i)
    {
        a[i] = read();
        ave += (double)a[i];
    }
    ave /= (double)m;


    while (!pq.empty())
        pq.pop();
    double tt = 0;
    for (int i = 1; i <= n; ++i)
    {
        x[i] = (double)a[i];
        y[i] = 1.0;
        pq.push(i);
        tt += sqr((double)a[i] - ave);
    }
    double ans = tt + sqr(ave) * (double)(m - n);


    for (int i = n + 1; i <= m; ++i)
        {
            int t = pq.top(); pq.pop();
            if (cal(t) < eps)
                break;
            ans -= cal(t);
            ++y[t];
            pq.push(t);
        }
    return ans / (double)m;
}
int main()
{
    for (int i = 1, T = read(); i <= T; ++i)
        printf("Case #%d: %.8lf\n", i, solve());
    return 0;
}