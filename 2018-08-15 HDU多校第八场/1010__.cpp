#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1000;
int n, m, a[N];
int main()
{
    freopen("test.in", "r", stdin);
    scanf("%d", &n);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    int x, y;
    while (m--)
    {
        scanf("%d%d", &x, &y);
        int t = a[x];
        a[x] = y;
        int pre = a[1], ans = 1;
        for (int i = 1; i <= n; ++i)
            if (a[i] > pre)
            {
                ++ans;
                pre = a[i];
            }
        printf("%d\n", ans);
        a[x] = t;
    }
    return 0;
}