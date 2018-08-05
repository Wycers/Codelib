#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || '9' < ch) { if (ch == '-') f = -1; ch = getchar(); }
    while ('0' <= ch && ch <= '9') {x = x * 10 + ch - 48; ch = getchar(); }
    return x * f;
}
struct data
{
    int u, v, w;
} a[N];
inline bool cmp(const data &a, const data &b)
{
    return a.w > b.w;
}
int n, m, k;
bool used[N];
long long solve()
{
    n = read(); m = read(); k = read();
    for (int i = 1; i <= k; ++i)
    {
        a[i].u = read();
        a[i].v = read();
        a[i].w = read();
    }
    sort(a + 1, a + k + 1, cmp);
    
    memset(used, false, sizeof used);
    long long ans = 0;
    for (int i = 1; i <= k; ++i)
    {
        if (used[a[i].v])
            continue;
        used[a[i].v] = true;
        ans += 1LL * a[i].w;
    }
    return ans;
}
int main()
{
    for (int T = read(), i = 1; i <= T;++i)
        printf("Case #%d: %lld\n", i, solve());
    return 0;
}