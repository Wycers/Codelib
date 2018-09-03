#include <cstdio>
using namespace std;
const int N = 2e5 + 10;
int n, a[N];
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    int mm = a[1], ans = -0x3f3f3f3f;
    for (int i = 2; i <= n; ++i)
    {
        if (mm - a[i] > ans)
            ans = mm - a[i];
        if (a[i] > mm)
            mm = a[i];
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