#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N];
void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1; i <= m; ++i)
        scanf("%d", a + n + i);
    sort(a + 1, a + n + m + 1);
    for (int i = 1, len = n + m; i <= len; ++i)
        printf("%d%c", a[i], i == len ? '\n' : ' ');
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}