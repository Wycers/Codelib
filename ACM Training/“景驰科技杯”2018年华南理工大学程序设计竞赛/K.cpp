#include <cstdio>
#include <map>
using namespace std;
const int N = 40;
int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || '9' < ch) { if (ch == '-') f = -1; ch = getchar(); }
    while ('0' <= ch && ch <= '9') { x = x * 10 + ch - 48; ch = getchar(); }
    return x * f;
}

map<int, int> mp;
int a[N], b[N], p, n, x, y;
void dfs1(int k, int xx, int yy)
{
    if (k == p + 1)
    {
        ++mp[xx * y - x * yy];
        return;
    }
    dfs1(k + 1, xx, yy);
    dfs1(k + 1, xx + a[k], yy + b[k]);
}

long long ans;
void dfs2(int k, int xx, int yy)
{
    if (k == n + 1)
    {
        ans += mp[-xx * y + x * yy];
        return;
    }
    dfs2(k + 1, xx, yy);
    dfs2(k + 1, xx + a[k], yy + b[k]);
}

void solve() 
{
    n = read(); x = read(); y = read();
    for (int i = 1; i <= n; ++i)
    {
        a[i] = read();
        b[i] = read();
    }
    
    p = n >> 1;
    mp.clear();
    ans = 0;

    dfs1(1, 0, 0);
    dfs2(p + 1, 0, 0);

    printf("%lld\n", ans - 1);
}
int main()
{
    for (int T = read(); T; --T)
        solve();
    return 0;
}