#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const double eps = 1e-8;
int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || '9' < ch) { if (ch == '-') f = -1; ch = getchar(); }
    while ('0' <= ch && ch <= '9') {x = x * 10 + ch - 48; ch = getchar(); }
    return x * f;
}

struct Vector {
    double x, y, z;
    Vector () {}
    Vector(double _x, double _y, double _z) {
        x = _x;
        y = _y;
        z = _z;
    }
    double operator * (const Vector &b) const {
        return x * b.x + y * b.y + z * b.z;
    }
    Vector operator ^ (const Vector &b) const {
        return Vector(y * b.z - z * b.y, x * b.z - z * b.x, x * b.y - y * b.x);
    }
    Vector operator - (const Vector &b) const {
        return Vector(x - b.x, y - b.y, z - b.z);
    }
    Vector operator + (const Vector &b) const {
        return Vector(x + b.x, y + b.y, z + b.z);
    }
    double length() {
        return sqrt(x * x + y * y + z * z);
    }
};

struct Point {
    double x, y, z;
    Point () {}
    Point (double _x, double _y, double _z) {
        x = _x;
        y = _y;
        z = _z;
    }
    Vector operator - (const Point &b) const {
        return Vector(x - b.x, y - b.y, z - b.z);
    }
    
    void Init()
    {
        scanf("%lf%lf%lf", &x, &y, &z);
    }
} p[20];

Point operator + (const Point &p, const Vector &v) {
    return Point(p.x + v.x, p.y + v.y, p.z + v.z);
}
Point operator - (const Point &p, const Vector &v) {
    return Point(p.x - v.x, p.y - v.y, p.z - v.z);
}
Vector operator * (const double &k, const Vector &v) {
    return Vector(k * v.x, k * v.y, k * v.z);
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
};

double v1, v2;
Point s; Vector N;
int n;
double t[20][20];
double toplane(Point x)
{
    Vector t = x - s;
    return (t * N) / N.length();
}
double topoint(Point x, Point y)
{
    Vector t = y - x;
    return t.length();
}
double cal(double L, double x1, double y1, double x2, double y2)
{
    double k1 = x1 / (x1 + x2);
    double k2 = x2 / (x1 + x2);
    double t1 = sqrt(x1 * x1 + (y1 - k1 * L) * (y1 - k1 * L));
    double t2 = sqrt(x2 * x2 + (y2 - k2 * L) * (y2 - k2 * L));
    double t3 = L;
    return  (t1 + t2) / v1 + t3 / v2;
}
double gettime(int i, int j)
{
    if (i == j)
        return 0;
    Point p1 = p[i]; Point p2 = p[j];
    double dis = topoint(p1, p2);
    double res = dis / v1;

    double h1 = toplane(p1), h2 = toplane(p2); 
    double tdis = topoint(p1 - h1 * N, p2 - h2 * N);
    double a = fabs(h1), c = fabs(h2);
    if (sign(a) == 0 && sign(c) == 0)
    {
        res = min(res, dis / v2);
        return res;
    }
    double b = tdis * a / (a + c), d = tdis * c / (a + c);

    double l = 0, r = tdis;
    while (r - l > eps)
    {
        double mid1 = l + (r - l) / 3;
        double mid2 = r - (r - l) / 3;
        if (cal(mid1, a, b, c, d) > cal(mid2, a, b, c, d))
            l = mid1;
        else 
            r = mid2;
    }
    res = min(res, cal(l, a, b, c, d));
    return res;
}  

double ans;
struct Edge {
    int to, next, c; double w;
} edge[2000];
int head[100], cnt;
void Insert(int u, int v, int c, double w)
{
    edge[++cnt] = (Edge){v, head[u], c, w};
    head[u] = cnt;
}
void insert(int u, int v, int c, double w)
{
    Insert(u, v, c, w);
    Insert(v, u, 0, -w);
}

int S, T;
queue<int> q;
bool inq[100]; double dis[100];
bool spfa()
{
    const int Inf = 0x3f3f3f3f;
    for (int i = S; i <= T; ++i)
        dis[i] = Inf;
    memset(inq, 0, sizeof(inq));
    q.push(T); inq[T] = true; dis[T] = 0;
    while (!q.empty())
    {
        int now = q.front();
        for (int i = head[now]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            if(dis[now] - edge[i].w < dis[v] && edge[i ^ 1].c)
            {
                dis[v] = dis[now] - edge[i].w;
                if(!inq[v])
                {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
        q.pop(); inq[now] = false;
    }
    return sign(dis[S] - Inf) != 0;
}

bool vis[100];
double dfs(int x, int f)
{
    vis[x] = true;
    if (x == T)
        return f;
    int c, used = 0;
    
    for (int i = head[x]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (edge[i].c && !vis[v] && dis[x] - edge[i].w == dis[v])
        {
            c = dfs(v, min(edge[i].c, f - used));
            edge[i].c -= c; edge[i ^ 1].c += c;
            ans += edge[i].w * (double)c;
            used += c;
            if (used == f)
                return f;
        }
    }
    return used;
}
int zkw()
{
    int f = 0;
    while(spfa())
    {
        vis[T] = 1;
        while(vis[T])
        {
            memset(vis, 0, sizeof(vis));
            f += dfs(0, 0x3f3f3f3f);
        }
    }
    return f;
}

double f[15][1 << 16][15]; int tar;
void Dfs(int status, int u, double now)
{
    // printf("%d %d %lf\n", status, u, now);
    if (now > f[0][status][u])
        return;
    
    f[0][status][u] = now;
    if (status == tar)
    {
        if (u != 0)
            Dfs(status, 0, now + t[u][0]);
        return;
    }
    for (int i = 0; i < n; ++i)
        if ((status & (1 << i)) == 0)
            Dfs(status | (1 << i), i, now + t[u][i]);
}
void solve() 
{
    scanf("%lf%lf", &v1, &v2);
    Point p1, p2;
    s.Init(); p1.Init(); p2.Init();
    N = (p1 - s) ^ (p2 - s);
    double x, y, z;
    n = read();
    for (int i = 1; i <= n; ++i)
        p[i].Init();
    if (n <= 1)
    {
        printf("%lf\n", 0.0);
        return;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            t[j - 1][i - 1] = t[i - 1][j - 1] = gettime(i, j);
    // memset(head, 0, sizeof(head));
    // cnt = 1;
    // S = 0; T = 2 * n + 1;
    // for (int i = 1; i <= n; ++i)
    //     insert(S, i, 1, 0);
    // for (int i = 1; i <= n; ++i)
    //     for (int j = 1; j <= n; ++j)
    //         if (i != j)
    //             insert(i, j + n, 1, t[i][j]);
    // for (int i = 1; i <= n; ++i)
    //     insert(i + n, T, 1, 0);

    // ans = 0; 
    // zkw();
    tar = (1 << n) - 1;
    for (int i = 0; i <= tar; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                f[j][i][k] = 0x3f3f3f3f;
    // for (int i = 0; i < n; ++i)
    //     for (int j = 0; j < n; ++j)
    //         if (i != j)
    //             f[i][(1 << i) | (1 << j)][j] = t[i + 1][j + 1];

    Dfs(1, 0, 0);
    printf("%lf\n", f[0][tar][0]);
}
int main()
{
    for (int T = read(); T; --T)
        solve();
    return 0;
}