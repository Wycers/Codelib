#include <cstdio>
#include <cstdlib>
using namespace std;
const int N = 1e3 + 10;
int x[N], y[N];
void solve()
{
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", x + i, y + i);
    scanf("%d", &m);
    while (m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", abs(x[a] - x[b]) + abs(y[a] - y[b]));
    }
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}