#include <cstdio>
const int N = 410;
int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || '9' < ch)
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}
double f[450][450];

int main()
{
    int n = read();
    int k = read();
    for (int i = 0; i <= 400; ++i)
        for (int j = 0; j <= 400; ++j)
            f[i][j] = 0;
    f[0][0] = 1;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            f[i + 1][j] += f[i][j] * 0.5;
            f[i + 1][j + 1] += f[i][j] * 0.5;
        }
        f[i + 1][n] += f[i][n] * 0.5;
        f[i + 1][n - 1] += f[i][n] * 0.5;
    }
    double ans = 0;
    for (int i = 1; i <= n; i++)
        ans += f[k][i] * i;
    printf("%.6f\n", ans);
    return 0;
}