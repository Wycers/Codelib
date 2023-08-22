#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N], b[N];
void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1; i <= m; ++i)
        scanf("%d", b + i);
    int pa = 1, pb = 1;
    a[n + 1] = b[m + 1] = 0x7fffffff; 
    while (pa <= n || pb <= m)
    {
        if (a[pa] < b[pb])
            printf("%d ", a[pa++]);
        else
            printf("%d ", b[pb++]);
    }
    puts("");
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}