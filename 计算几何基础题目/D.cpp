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
};

Point operator + (const Point &p, const Vector &v) {
    return Point(p.x + v.x, p.y + v.y);
}
Vector operator * (const double &k, const Vector &v) {
    return Vector(k * v.x, k * v.y);
}

struct Line {
    Point s, t;
    Line () {}
    Line (Point _s, Point _t) {
        s = _s;
        t = _t;
    }
} a, b;

int sign(double x)
{
    if (fabs(x) < eps)
        return 0;
    if (x < 0)
        return -1;
    return 1;
}

void solve() 
{
    double x1, y1, x2, y2;
    scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
    a = Line(Point(x1, y1), Point(x2, y2));

    scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
    b = Line(Point(x1, y1), Point(x2, y2));
    
    if (sign((a.t - a.s) ^ (b.t - b.s)) == 0) // 平行
    {
        puts(sign((b.s - a.s) ^ (a.t - a.s)) == 0 ? "LINE" : "NONE");
        return;
    }
    Vector v0 = a.t - a.s;
    Vector v1 = b.s - a.s;
    Vector v2 = b.t - a.s;
    double k = (v1 ^ v2) / ((v1 ^ v0) + (v0 ^ v2));
    Point p = a.s + k * v0;
    printf("POINT %.2lf %.2lf\n", p.x, p.y);
}
int main()
{
    puts("INTERSECTING LINES OUTPUT");
    for (int T = read(); T; --T)
        solve();
    puts("END OF OUTPUT");
    return 0;
}