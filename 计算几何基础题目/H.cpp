#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
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
        return x * b.x + y * b.y                         ;
    }
    double operator ^ (const Vector &b) const {
        return x * b.y - y * b.x;
    }
    Vector operator - (const Vector &b) const {
        return Vector(x - b.x, y - b.y);
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
    void Init()
    {
        scanf("%lf%lf", &x, &y);
    }
};

Point operator + (const Point &p, const Vector &v) {
    return Point(p.x + v.x, p.y + v.y);
}
Vector operator * (const double &k, const Vector &v) {
    return Vector(k * v.x, k * v.y);
}

int sign(double x)
{
    if (fabs(x) < eps)
        return 0;
    if (x < 0)
        return -1;
    return 1;
}

struct Line {
    Point s, t;
    Line () {}
    Line (Point _s, Point _t) {
        s = _s;
        t = _t;
    }
} seg, line[4];

bool intersect(Line &sl, Line &seg)
{
    Vector d = sl.s - sl.t;
    Vector a = seg.s - sl.t;
    Vector b = seg.t - sl.t;
    return sign(d ^ a) * sign(d ^ b) <= 0;
}
int n, layer[N];
queue<int> q;
void solve() 
{
    seg.s.Init();
    seg.t.Init();

    double x1, y1, x2, y2;
    scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
    line[0] = Line(Point(x1, y1), Point(x2, y1));
    line[1] = Line(Point(x2, y1), Point(x2, y2));
    line[2] = Line(Point(x2, y2), Point(x1, y2));
    line[3] = Line(Point(x1, y2), Point(x1, y1));

    for (int i = 0; i < 4; ++i) {
        if (intersect(line[i], seg) && intersect(seg, line[i]))
        {
            puts("T");
            return;
        }
    }
    puts("F");
}
int main()
{
    for (int T = read(); T; --T)
        solve();
    return 0;

