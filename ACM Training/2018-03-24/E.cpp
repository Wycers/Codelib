#include <cstdio>
#include <cmath>
#include <algorithm>
#define eps 1e-15
const int N = 1e3 + 10;
using namespace std;
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

double dis(int x1, int y1, int x2, int y2) 
{
    return sqrt((double)(x1 - x2) * (double)(x1 - x2) + (double)(y1 - y2) * (double)(y1 - y2));
}

int x[N], y[N];
double d[N][N];
void solve() 
{
    int n = read();
    for (int i = 1; i <= n; ++i)
    {
        x[i] = read(); y[i] = read();
        for (int j = 1; j <= i; ++j)
            d[i][j] = d[j][i] = dis(x[i], y[i], x[j], y[j]);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) 
    {
        sort(d[i] + 1, d[i] + n + 1);
        for (int l = 1, r = 1; r <= n; )
        {
            if (fabs(d[i][l] - d[i][r]) < eps)
                ++r;
            else
            {
                ans += (r - l - 1) * (r - l);
                l = r;
            }
            if (r == n + 1) {
                ans += (r - l - 1) * (r - l);
            }
        }
    }
    if (ans == 0)
        puts("WA");
    else
        printf("%d\n", ans);
}

int main()
{
    for (int T = read(); T; T--)
        solve();
    return 0;
}

/*
4
2 20 4 10
20 20 20 20
20 21 21 20
32768 32768 1048576 24576

*/