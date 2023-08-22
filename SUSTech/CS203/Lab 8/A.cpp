#include <cstdio>
#include <cstring>
using namespace std;
const int N = 510;
int n, m, a[N][N];
void solve()
{
    scanf("%d%d", &n, &m);
    memset(a, 0, sizeof a);
    while (m--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x][y] = 1;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            printf("%d%c", a[i][j], j == n ? '\n' : ' ');
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}