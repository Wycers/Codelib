#include <cmath>
#include <queue>
#include <cstdio>
#include <iostream>
using namespace std;
const double eps = 1e-8;
const int N = 1e4 + 10;
struct Vector {
    double x, y;
    Vector(double _x, double _y) {
        x = _x;
        y = _y;
    }
    double operator * (const Vector &b) const {
        return x * b.x + y * b.y                         ;
    }
    Vector operator * (const double &b) const {
        return Vector(b * x, b * y);
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
} p0[2], o[30];
double r[30];

Point operator + (const Point &a, const Vector &b) 
{
    return Point(a.x + b.x, a.y + b.y);
}

struct edge_
{
    int to, next; double w;
} edge[4 * N];
int head[N], cnt = 0;
void insert(int u, int v, double w)
{
    edge[++cnt] = (edge_){v, head[u], w};
    head[u] = cnt;
}

int n, cntN = 0;
void readin()
{
    p0[0].Init(); p0[1].Init();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        o[i].Init();
        scanf("%lf", r + i);
    }
}

double sqr(double x)
{
    return x * x;
}

void init() // get insection point of every two circles.
{
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            Vector v = o[j] - o[i];
            double a = v * v;
            double tmp = sqr(r[j]) - sqr(r[i]) - a; tmp /= 2.0;
            double b = 2.0 * tmp * v.x / r[i];
            double c = sqr(tmp / r[i]) - sqr(v.y);
            double delta = sqr(b) - 4 * a * c;
            if (delta < 0)
                continue;
            Point sec[2];
            if (fabs(delta) < eps)
            {
                double cost = -b / 2 / a;
                double sint = sqrt(1 - sqr(cost));
                Vector test = o[i] + Vector(cost,  sint) * r[i] - o[j];
                if (fabs(test * test - sqr(r[j])) > eps)
                    secp.push_back(o[i] + Vector(cost,  sint) * r[i]);
                else 
                    secp.push_back(o[i] + Vector(cost,  -sint) * r[i]);
            }
            if (delta > eps)
            {
                double cost, t, sint; Vector test;
                cost = (-b + sqrt(delta)) / 2 / a;
                t = acos(cost);
                sint = sin(t);
                sec[0] = o[i] + Vector(cost,  sint) * r[i];
                test = sec[0] - o[j];
                if (fabs(test * test - sqr(r[j])) > eps)
                {
                    sint = -sint;
                    sec[0] = o[i] + Vector(cost, sint) * r[i];
                }

                cost = (-b - sqrt(delta)) / 2 / a;
                t = acos(cost);
                sint = sin(t);
                sec[1] = o[i] + Vector(cost,  sint) * r[i];
                test = sec[1] - o[j];
                if (fabs(test * test - sqr(r[j])) > eps)
                {
                    sint = -sint;
                    sec[1] = o[i] + Vector(cost, sint) * r[i];
                }
                secp.push_back(sec[0]);
                secp.push_back(sec[1]);
            }
            printf("%lf %lf %lf %lf\n", sec[0].x, sec[0].y, sec[1].x, sec[1].y);
        }
}

bool incircle(Point p, int k)
{
    Vector t = p - o[k];
    return t * t <= sqr(r[k]);
}

void build() // build the graph.
{
    for (vector<Point>::iterator i = secp.begin(); i != secp.end(); ++i)
        for (vector<Point>::iterator j = secp.begin(); j != secp.end(); ++j)
        {
            if (i == j)
                continue;
            int k; bool flag = false;
            for (int k = 1; k <= n; ++k)
                if (incircle(*i, k) && incircle(*j, k))
                {
                    insert()
                    continue;
                }
        }
}

queue<int> q;
bool inq[N]; double dis[N];
double spfa()
{
    memset(inq, false, sizeof(inq));
    for (int i = 1; i <= cnt; ++i)
        dis[i] = 0x3f3f3f3f;
    q.push(1); inq[1] = true; dis[1] = 0;
    while (!q.empty())
    {
        int u = q.front();
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (dis[u] + edge[i].w < dis[v])
            {
                dis[v] = dis[u] + edge[i].w;
                if (!inq[v])
                {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
        q.pop();
        inq[u] = false;
    }
    return dis[cnt];
}
int main()
{
    readin();
    init();
    double ans = spfa();
    if (fabs(ans - 0x3f3f3f3f) < 1e-6)
        puts("impossible");
    else
        printf("%.6f\n", ans);
    return 0;
}