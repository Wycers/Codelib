#include <cstdio>
#include <queue>
using namespace std;
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
int n, m;
queue<int> q;
void solve()
{
    while (!q.empty())
        q.pop();

    n = read(); m = read();
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        q.push(read());
        while (q.size() && q.back() - q.front() > m)
            q.pop();
        int g = q.size() - 1;
        ans += 1ll * g * (g - 1) / 2;
    }
    printf("%lld\n", ans);
}
int main()
{
    int T = read();
    while (T--)
        solve();
    return 0;
}