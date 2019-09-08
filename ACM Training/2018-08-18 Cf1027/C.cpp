#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, a[N], s[N], st[N], top = 0;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void solve()
{
    n = read();
    for (int i = 1; i <= n; ++i)
        s[a[i] = read()] = 0;
    top = 0;
    for (int i = 1; i <= n; ++i)
        ++s[a[i]];
    for (int i = 1; i <= n; ++i)
    {
        if (s[a[i]] >= 4)
        {
            printf("%d %d %d %d\n", a[i], a[i], a[i], a[i]);
            return;
        }
        if (s[a[i]] >= 2)
            st[++top] = a[i];
    }
    sort(st + 1, st + top + 1);
    int t = unique(st + 1, st + top + 1) - st - 1;
    double k = 1e9;
    int ans1, ans2;
    for (int i = 2; i <= t; ++i)
    {
        double a = (double)st[i - 1] * 1.0;
        double b = (double)st[i] * 1.0;
        double tmp = a / b + b / a;
        if (k > tmp)
        {
            ans1 = st[i - 1];
            ans2 = st[i];
            k = tmp;
        }
    }
    printf("%d %d %d %d\n", ans1, ans1, ans2, ans2);
}
int main()
{
    for (int T = read(); T; --T)
        solve();
    return 0;
}