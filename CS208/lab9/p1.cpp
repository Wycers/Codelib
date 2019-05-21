#include <cstdio>
using namespace std;
const int N = 1e5 + 10;
const int M = 1e2 + 10;
const int P = 1e9 + 7;
int n, a[N], f[2][M][2], sum[2][M][2];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1; i <= 1; ++i)
    {
        if (a[i] == -1)
            for(int j = 1; j <= 100; ++j)
                f[i][j][0] = 1, f[i][j][1] = 0;
        else
        {
            for(int j = 1; j <= 100; ++j)
                f[i][j][0] = 0, f[i][j][1] = 0;
            int j = a[1];
            f[i][j][0] = 1;
        }
        sum[i][0][0] = sum[i][0][1] = 0;
        for (int j = 1; j <= 100; ++j)
        {
            sum[i][j][0] = (sum[i][j - 1][0] + f[i][j][0]) % P;
            sum[i][j][1] = (sum[i][j - 1][1] + f[i][j][1]) % P;
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        int now = i & 1;
        int last = now ^ 1;
        if (a[i] == -1)
            for(int j = 1; j <= 100; ++j)
            {
                f[now][j][0] = (sum[last][j - 1][0] + sum[last][j - 1][1]) % P;
                f[now][j][1] = ((sum[last][100][1] - sum[last][j - 1][1] + P) % P + f[last][j][0]) % P;
            }
        else
        {
            for(int j = 1; j <= 100; ++j)
                f[now][j][0] = 0, f[now][j][1] = 0;
            int j = a[i];
            f[now][j][0] = (sum[last][j - 1][0] + sum[last][j - 1][1]) % P;
            f[now][j][1] = ((sum[last][100][1] - sum[last][j - 1][1] + P) % P + f[last][j][0]) % P;
        }
        sum[now][0][0] = sum[now][0][1] = 0;
        for (int j = 1; j <= 100; ++j)
        {
            sum[now][j][0] = (sum[now][j - 1][0] + f[now][j][0]) % P;
            sum[now][j][1] = (sum[now][j - 1][1] + f[now][j][1]) % P;
        }
    }
    int ans = 0;
    for (int j = 1; j <= 100; ++j)
        ans = (ans + f[n & 1][j][1]) % P;
    printf("%d\n", ans);
    return 0;
}