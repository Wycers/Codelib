#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 100;
const int M = 3 * N;
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
} p[M];
int m = 0;

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
} line[3 * N];
int k = 0;

struct Edge {
    int to, next; double w;
    Edge () {}
    Edge (int _to, int _next, double _w)
    {
        to = _to;
        next = _next;
        w = _w;
    }
} edge[M * M];
int head[M], cnt = 0;

void insert(int u, int v, double w)
{
    edge[++cnt] = Edge(v, head[u], w);
    head[u] = cnt;
}

queue<int> q;
double dis[M];
bool inq[M];
double spfa()
{
    memset(inq, false, sizeof(inq));
    for (int i = 1; i <= m; ++i)
        dis[i] = 0x3f3f3f3f;
    dis[1] = 0; inq[1] = true; q.push(1);
    while (!q.empty())
    {
        int now = q.front();
        for (int i = head[now]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (dis[now] + edge[i].w < dis[v])
            {
                dis[v] = dis[now] + edge[i].w;
                if (!inq[v])
                {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
        q.pop(); inq[now] = false; 
    }
    return dis[m];
}

bool intersect(Line sl, Line seg)
{
    Vector d = sl.s - sl.t;
    Vector a = seg.s - sl.t;
    Vector b = seg.t - sl.t;
    return sign(d ^ a) * sign(d ^ b) <= 0;
}
bool checkline(Point s, Point t)
{
    Line tmp = Line(s, t);
    for (int i = 0; i < k; i += 2)
        if (s.x <= line[i].s.x && line[i].s.x <= t.x && !intersect(tmp, line[i]) && !intersect(tmp, line[i ^ 1]))
            return false;
    return true;
}
double dist(Vector d)
{
    return sqrt(d.x * d.x + d.y * d.y);
}
void insertpoint(double x, double y)
{
    p[++m] = Point(x, y);
    for (int i = 1; i < m; ++i)
        if (sign(p[i].x - p[m].x) && checkline(p[i], p[m]))
            insert(i, m, dist(p[m] - p[i]));
}
int n;
void solve() 
{
    m = k = cnt = 0;
    memset(head, 0, sizeof(head));
    p[++m] = Point(0, 5);
    double x, y0, y1, y2, y3;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lf%lf%lf%lf%lf", &x, &y0, &y1, &y2, &y3);
        insertpoint(x, y0);
        insertpoint(x, y1);
        insertpoint(x, y2);
        insertpoint(x, y3);
        line[k++] = Line(Point(x, y0), Point(x, y1));
        line[k++] = Line(Point(x, y2), Point(x, y3));
    }
    insertpoint(10, 5);
    double ans = spfa();
    if (!sign(ans - 0x3f3f3f3f))
        puts("-1");
    else
        printf("%.2lf\n", ans);
}
int main()
{
    while ((n = read()) != -1)
        solve();
    return 0;
}