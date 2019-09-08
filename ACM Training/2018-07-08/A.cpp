#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 4e3 + 10;

int n, m, w[N], p[N], f[200010];
int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; ++i)
            scanf("%d%d", w + i, p + i);
        for (int i = 1; i <= n; ++i)
            for (int j = m; j >= w[i]; --j)
                f[j] = max(f[j], f[j - w[i]] + p[i]);
        printf("%d\n", f[m]);
    }
    return 0;
}
