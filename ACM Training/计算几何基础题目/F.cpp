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
} line[N];

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
    memset(layer, 0, sizeof(layer));
    for (int i = 1; i <= n; ++i) {
        line[i].s.Init();
        line[i].t.Init();
    }   
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            if (intersect(line[i], line[j]) && intersect(line[j], line[i]))
                break;
            if (j == n)
                q.push(i);
        }
    q.push(n);
    printf("Top sticks:");
    for (; !q.empty(); q.pop())
        printf(" %d%c", q.front(), q.size() == 1 ? '.' : ',');
    puts("");
}
int main()
{
    while ((n = read()) != 0)
        solve();
    return 0;
}