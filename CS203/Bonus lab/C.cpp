#include <cstdio>
#include <algorithm>
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
int n, a[N], tmp[N];
long long ans = 0;
const int sz = sizeof(a[0]);
void merge(int l, int m, int r)
{
    int i = l, j = m + 1, now = l;
    while (i <= m && j <= r)
        if (a[i] <= a[j])
            tmp[now++] = a[i++];
        else
        {
            tmp[now++] = a[j++];
            ans += m - i + 1;
        }
    memcpy(tmp + now, a + i, (m - i + 1) * sz);
    memcpy(tmp + now, a + j, (r - j + 1) * sz);
    memcpy(a + l, tmp + l, (r - l + 1) * sz);
}
void msort(int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    msort(l, mid);
    msort(mid + 1, r);
    merge(l, mid, r);
}


void solve()
{
    int n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    ans = 0;
    msort(1, n);
    printf("%lld\n", ans);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}   