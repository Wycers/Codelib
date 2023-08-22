#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int N = 1e5 + 10;
int n, a[N][3], x;
long long sqr(long long g)
{
    return g * g;
}
long long qwq(long long p, long long q)
{
    long long res = 0;
    res += sqr(a[p][0] - a[q][0]);
    res += sqr(a[p][1] - a[q][1]);
    res += sqr(a[p][2] - a[q][2]);
    return res;
}
void solve()
{
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; ++i)
        for (int d = 0; d < 3; ++d)
            scanf("%d", &a[i][d]);
    
    long long ans = 0x7fffffffffffffff;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            ans = min(ans, qwq(i, j));
    printf("%I64d\n", ans);
}
int main()
{
    solve();
    return 0;
}