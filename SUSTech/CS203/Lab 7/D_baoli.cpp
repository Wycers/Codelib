#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    printf("%d\n", a[n - m + 1]);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}