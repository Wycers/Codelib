#include <cstdio>
#include <cmath>
#define eps 1e-15
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

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve()
{
    int x, a, y, b;
    x = read();
    a = read();
    y = read();
    b = read();
    if (x == 1 && y == 1) {
        puts("Yes");
        return;
    }
    if (x != 1 && y == 1) {
        puts("No");
        return;
    }
    if (x == 1 && y != 1) {
        puts("No");
        return;
    }
    int g = gcd(x, y);
    x /= g; y /= g;

    double t1 = (log((double)x) + log((double)g)) / (log((double)y) + log((double)g));
    double t2 = (double)b / (double)a;
    if (fabs(t1 - t2) < eps)
        puts("Yes");
    else
        puts("No");
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