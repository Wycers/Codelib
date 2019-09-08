#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 1e3 + 10;
const int M = 1e6 + 10;
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
} pu[N], pv[N];

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
};

Vector operator - (const Point &a, const Point &b) {
    return Vector(a.x - b.x, a.y - b.y);
}

int n, u[M], v[M], tag[M]; double dis[M];
double Dis(const Point &a, const Point &b)
{
    Vector v = a - b;
    return sqrt(v * v);
}
void readin()
{
    n = read();
    for (int i = 1; i <= n; ++i)
    {
        pu[i].Init();
        pv[i].Init();
    }
}
bool cmp(const int a, const int b)
{
    return dis[a] < dis[b];
}
int fa[N];
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int cnt = 0;
void solve()
{
    for (int i = 1; i <= n; ++i)
        fa[i] = tag[i] = i;
    
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            double d = 1e9;
            d = min(d, Dis(pu[i], pu[j]));
            d = min(d, Dis(pv[i], pu[j]));
            d = min(d, Dis(pu[i], pv[j]));
            d = min(d, Dis(pv[i], pv[j]));
            ++cnt;
            u[cnt] = i; v[cnt] = j;
            dis[cnt] = d;
        }
        
    sort(tag + 1, tag + cnt + 1, cmp);
    double ans = 0;
    int tot = 0;
    for (int i = 1; i <= cnt; ++i)
    {
        int x = find(u[tag[i]]);
        int y = find(v[tag[i]]);
        if (x != y)
        {
            fa[x] = y;
            ans += dis[tag[i]];
            if (++tot == n - 1)
                break;
        }
    }
    printf("%.6lf\n", ans);
}
int main()
{
    readin();
    solve();
    return 0;
}