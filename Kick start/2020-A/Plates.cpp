#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int K = 35;

int n, m, p, a[N][K], f[10000];

void work(int T) {
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; ++i) {
        a[i][0] = 0;
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);
        for (int j = 1; j <= m; ++j)
            a[i][j] += a[i][j - 1];
    }
    memset(f, 0, sizeof f);
    for (int k = 1; k <= n; k++)
        for (int i = p; i >= 0; i--)
            for (int j = 1; j <= m; j++)
                if (i >= j)
                    f[i] = max(f[i],
                               f[i - j] + a[k][j]);
    printf("Case #%d: %d\n", T, f[p]);
}


int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
        work(i);
    return 0;
}
