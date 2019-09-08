//=============================================================
// File Name: loj-2097.cpp
// Author: Wycer
// Created Time: 2018-05-19 12:12
//=============================================================
#include <cstdio>
#include <cmath>
#include <cmath>
#include <algorithm>
const double eps = 1e-8;
const int N = 1e3 + 10;
using namespace std;
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

double res[N];
int n, tag[N];
bool cmp(const int &a, const int &b)
{
    if (fabs(res[a] - res[b]) < eps)
        return a < b;
    return res[a] < res[b];
}
void solve()
{
    double a, b, c;
    for (int i = 1; i <= n; ++i)
    {
        a = (double)read(); b = (double)read(); c = (double)read();
        res[i] = (a + b) / c;
        tag[i] = i;
    }
    sort(tag + 1, tag + n + 1, cmp);
    for (int i = 1; i <= n; ++i)
        printf("%d ", tag[i]);
    puts("");
}

int main()
{
    while (scanf("%d", &n))
        solve();
    return 0;
}