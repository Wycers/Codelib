#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 20;
const double eps = 1e-8;
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

struct Point
{
    double x, y;
    Point () {}
    Point (double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    void Init()
    {
        x = read();
        y = read();
    }
} p[N];

struct Vector
{
    double x, y;
    Vector () {}
    Vector (double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    double operator * (const Vector &b) const {
        return x * b.x + y * b.y;
    }
    double operator ^ (const Vector &b) const {
        return x * b.y - y * b.x;
    }
};

Vector operator - (const Point &a, const Point &b) {
    return Vector(a.x - b.x, a.y - b.y);
}
int n;
void readin()
{
    n = read();
    for (int i = 1; i <= n; ++i)
        p[i].Init();
}

int c[N], ans;
void dfs(int k)
{
        
    if (k == n + 1)
    {
        int res = 0;
        for (int i = 1; i <= n; ++i)
        {
            Vector tmp1 = p[c[i]] - p[i];
            for (int j = 1; j <= n; ++j)
                if (c[i] != j && i != j)
                {
                    Vector tmp2 = p[c[j]] - p[j];
                    if (fabs(tmp1 ^ tmp2) < eps)
                        ++res;
                }
        }
        ans = max(ans, res);
        return;
    }
    if (c[k])
        dfs(k + 1);
    else 
        for (int i = 1; i <= n; ++i)
            if (i != k && !c[i])
            {
                c[i] = k; c[k] = i;
                dfs(k + 1);
                c[i] = 0; c[k] = 0;
            }
}
void solve()
{
    ans = 0;
    memset(c, 0, sizeof(c));
    dfs(1);
    printf("%d\n", ans / 8);
}

int main()
{
    readin();
    solve();
    return 0;
}