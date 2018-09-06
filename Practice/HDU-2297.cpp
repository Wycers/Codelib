#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int N = 5e4 + 10;
int sign(double x)
{
    if (fabs(x) < eps)
        return 0;
    return x > 0 ? 1 : -1;
}

struct Vector
{
    double x, y;
    void input() { scanf("%lf%lf", &x, &y); }
    void output() { printf("%.2lf %.2lf\n", x, y); }
    Vector () {}
    Vector (double _x, double _y) { 
        x = _x; y = _y; 
    }
    bool operator == (const Vector &b) const {
        return sign(x - b.x) == 0 && sign(y - b.y) == 0;
    }
    bool operator < (const Vector &b) const {
        return sign(x - b.x) == 0 ? sign(y - b.y) < 0 : x < b.x;
    }
    Vector operator + (const Vector &b) const {
        return Vector(x + b.x, y + b.y);
    }
    Vector operator - (const Vector &b) const {
        return Vector(x - b.x, y - b.y);
    }
    Vector operator * (const double &k) const {
        return Vector(x * k, y * k);
    }
    Vector operator / (const double &k) const {
        return Vector(x / k, y / k);
    }
    double operator * (const Vector &b) const {
        return x * b.x + y * b.y;
    }
    double operator ^ (const Vector &b) const {
        return x * b.y - y * b.x;
    }
};
struct Line 
{
    Vector s, e, v;
    double ag;
    Line () {}
    void init() {
        v = e - s;
        ag = atan2(v.y, v.x);
    }
    Line (Vector _s, Vector _e) {
        s = _s;
        e = _e;
        init();
    }
    bool operator == (const Line &b) const {
        return (s == b.s) && (e == b.e);
    }
    bool operator<(const Line &b) const
    {
        return ag < b.ag;
    }
    // 点角式确定直线
    Line (Vector p, double rad) {
        s = p;
        if (sign(rad - pi / 2) == 0)
            e = s + Vector(0, 1);
        else
            e = s + Vector(1, tan(rad));
        init();
        ag = atan2(v.y, v.x);
    }
    // 一般式确定直线
    Line (double a, double b, double c) {
        if (sign(a) == 0) {
            s = Vector(0, -c / b);
            e = Vector(1, -c / b);
        }
        else if (sign(b) == 0) {
            s = Vector(-c / a, 0);
            e = Vector(-c / a, 1);
        } 
        else {
            s = Vector(0, -c / b);
            e = Vector(1, (-c - a) / b);
        }
        init();
    }
    void input() {
        s.input();
        e.input();
    }
    int prelation (const Vector &p) {
        return sign(v ^ (p - s));
    }
    bool cross(const Vector &p) {
        return prelation(p) == 0 && sign((p - s) ^ (p - e)) <= 0; 
    }
    bool parallel(const Line &b) {
        return sign(v ^ b.v) == 0;
    }
    // 求两直线的交点，要保证两直线不平行或重合
    Vector crosspoint(const Line &b) {
        Vector u = s - b.s;
        double t = (b.v ^ u) / (v ^ b.v);
        return s + v * t;
    }
};
struct halfplane
{
    int n;
    Line hp[N];
    Vector p[N];
    Line *q[N];
    int st, ed;
    void push(Line tmp)
    {
        hp[n++] = tmp;
    }
    void halfplaneinsert()
    {
        sort(hp, hp + n);
        q[st = ed = 0] = &hp[0];
        for (int i = 1; i < n; i++)
        {
            while (st < ed && hp[i].prelation(p[ed - 1]) != 1)
                --ed;       //Remove the top of the half plane
            while (st < ed && hp[i].prelation(p[st]) != 1)
                ++st;      //Remove the bottom half plane
            q[++ed] = &hp[i]; //The half plane current if the double ended queue at the top.
            if (sign(q[ed]->v ^ q[ed - 1]->v) == 0)
            { //For the polar angle the same, selective retention of a.
                --ed;
                if ((*q[ed]).prelation(hp[i].s) == 1)
                    q[ed] = &hp[i];
            }
            if (st < ed)
                p[ed - 1] = (*q[ed - 1]).crosspoint(*q[ed]); //Calculation of the top of the queue half plane intersection.
        }
        while (st < ed && (*q[st]).prelation(p[ed - 1]) != 1)
            --ed; //Remove the top of the queue of useless half plane.
        if (ed - st <= 1)
            return;
        p[ed] = (*q[ed]).crosspoint(*q[st]); //The top of the queue and the first intersection calculation.
    }
    int getconvex()
    {
        return ed - st + 1;
    }
} hp;

int n;
void solve()
{
    scanf("%d", &n);
    hp.n = 0;
    hp.push(Line(Vector(1e10, 1e10), Vector(-1, 1e10)));
    hp.push(Line(Vector(0, 1e10), Vector(0, -1)));
    for (int i = 0; i < n; ++i)
    {
        double b, k;
        scanf("%lf%lf", &b, &k);
        hp.push(Line(Vector(0, b), Vector(1, b + k)));
    }
    hp.halfplaneinsert();
    printf("%d\n", hp.getconvex() - 2);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}