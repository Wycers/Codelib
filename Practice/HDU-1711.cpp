#include <cstdio>
using namespace std;
const int N = 1e6 + 10;
int n, m, nx[N], a[N], b[N];
void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    for (int i = 0; i < m; ++i)
        scanf("%d", b + i);
    nx[0] = -1;
    for (int i = 0, j = -1; i < m; )
    {
        if (j == -1 || b[i] == b[j])
            nx[++i] = ++j;
        else
            j = nx[j];
    }
    for (int i = 0, j = 0; i < n;)
    {
        if (j == -1 || a[i] == b[j])
            ++i, ++j;
        else 
            j = nx[j];
        if (j == m)
        {
            printf("%d\n", i - j + 1);
            return;
        }
    }
    puts("-1");
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}