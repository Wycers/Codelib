#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
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

int n, a[N];
int find(int l, int r, int x)
{
    int res = l;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (a[mid] >= x)
        {
            res = mid;
            r = mid - 1;
        }
        else 
            l = mid + 1;
    }
    return res;
}
long long count(int d)
{
    long long res = 0;
    for (int i = 1, j = 1; i <= n; ++i)
    {
        while (a[i] - a[j] > d)
            ++j;
        res += i - j;
    }
    return res;
}
void solve()
{
    n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    sort(a + 1, a + n + 1);
    long long c = 1ll * n * (n - 1) / 2;
    if (c & 1)
        c = (c + 1) >> 1;
    else
        c = c >> 1;
    int l = 0, r = a[n] - a[1], ans = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (count(mid) >= c)
        {
            r = mid - 1;
            ans = mid;
        }
        else
            l = mid + 1;
    }
    printf("%d\n", ans);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}