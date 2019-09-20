#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int N = 80;
int n, m, a[N][N];
void solve()
{
    scanf("%d%d", &n, &m);
    memset(a, 0, sizeof a);
    while (m--)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u][v] = a[v][u] = 1;
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (a[i][j])
                for (int k = j + 1; k <= n; ++k)
                    if (a[i][k] && a[j][k])
                        for (int l = k + 1; l <= n; ++l)
                            if (a[i][l] && a[j][l] && a[k][l])
                                ++cnt;
    printf("%d\n", cnt);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}