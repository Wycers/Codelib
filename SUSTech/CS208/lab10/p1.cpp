#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e2 + 10;
int n, w[N], v[N], f[N * N], ans[N * N];
int main()
{
    scanf("%d", &n);
    int c = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", v + i, w + i);
        c += w[i] - v[i];
    }
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; ++i)
        for (int j = c; j >= w[i]; --j)
        {
            if (f[j - w[i]] + 1 > f[j])
            {
                f[j] = f[j - w[i]] + 1;
                ans[j] = ans[j - w[i]] + v[i];
            }
            if (f[j - w[i]] + 1 == f[j])
                ans[j] = min(ans[j], ans[j - w[i]] + v[i]);
        }
    printf("%d\n", ans[c]);
    return 0;
}
