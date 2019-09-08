#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e2 + 10;
const double eps = 1e-8;
int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || '9' < ch) { if (ch == '-') f = -1; ch = getchar(); }
    while ('0' <= ch && ch <= '9') {x = x * 10 + ch - 48; ch = getchar(); }
    return x * f;
}

struct Vector {
    double x, y;
    Vector(double _x, double _y) {
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

struct Point {
    double x, y;
    Point () {}
    Point (double _x, double _y) {
        x = _x;
        y = _y;
    }
    Vector operator - (const Point &b) const {
        return Vector(x - b.x, y - b.y);
    }
};

struct Line {
    Point s, t;
    Line () {}
    Line (Point _s, Point _t) {
        s = _s;
        t = _t;
    }
} line[N];

int sign(double x)
{
    if (fabs(x) < eps)
        return 0;
    if (x < 0)
        return -1;
    return 1;
}

bool intersect(Line sl, Line seg)
{
    Vector d = sl.s - sl.t;
    Vector a = seg.s - sl.t;
    Vector b = seg.t - sl.t;
    return sign(d ^ a) * sign(d ^ b) <= 0;
}

int n, m;

double mag(Line seg)
{
    return (seg.s.x - seg.t.x) * (seg.s.x - seg.t.x) + (seg.s.y - seg.t.y) * (seg.s.y - seg.t.y);
}
bool check(Line t, int i, int j)
{
    if (mag(t) == 0)
        return false;
    for (int k = 1; k <= n; ++k)
    {
        if (k == i || k == j)
            continue;
        if (!intersect(t, line[k]))
            return false;
    }
    return true;
}
bool check(int i, int j)
{
    return check(Line(line[i].s, line[j].s), i, j) ||
    check(Line(line[i].s, line[j].t), i, j) ||
    check(Line(line[i].t, line[j].s), i, j) ||
    check(Line(line[i].t, line[j].t), i, j);
}

void solve() 
{
    n = read(); 
    double x1, y1, x2, y2;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
        line[i] = Line(Point(x1, y1), Point(x2, y2));
    }
    if (n == 1)
    {
        puts("Yes!");
        return;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (check(i, j))
            {
                puts("Yes!");
                return;
            }
    puts("No!");
}
int main()
{
    for (int T = read(); T; --T)
        solve();
    return 0;
}