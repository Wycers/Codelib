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
    double length() {
        return hypot(x, y);
    }
    double lengths() {
        return x * x + y * y;
    }
    double distance(const Vector &b) const {
        return hypot(x - b.x, y - b.y);
    }
    Vector rotccw() {
        return Vector(-y, x);
    }
    Vector rotcw() {
        return Vector(y, -x);
    }
    Vector rot(double rad, const Vector &b) const {
        Vector v = (*this) - b, t = Vector(sin(rad), cos(rad));
        return b + Vector(v ^ t, v * t);
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
    double length() {
        return s.distance(e);
    }
    bool parallel(const Line &b) {
        return sign(v ^ b.v) == 0;
    }
    bool onleft(const Vector &b) {
        return sign(v ^ (b - s)) > 0;
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
    int que[N];
    int st, ed;
    void push(Line tmp)
    {
        hp[n++] = tmp;
        // tmp.s.output();
        // tmp.e.output();
    }
    int halfplaneinsert()
    {
        sort(hp, hp + n);
	    vector<Line> q(n);
        int first, last;
        q[first = last = 0] = hp[0];
        for (int i = 1; i < n; i++)
        {
            while (first < last && !hp[i].onleft(p[last - 1]))
                last--;       //Remove the top of the half plane
            while (first < last && !hp[i].onleft(p[first]))
                first++;      //Remove the bottom half plane
            q[++last] = hp[i]; //The half plane current if the double ended queue at the top.
            if (sign(q[last].v ^ q[last - 1].v) == 0)
            { //For the polar angle the same, selective retention of a.
                last--;
                if (q[last].onleft(hp[i].s))
                    q[last] = hp[i];
            }
            if (first < last)
                p[last - 1] = q[last-1].crosspoint(q[last]); //Calculation of the top of the queue half plane intersection.
        }
        while (first < last && !q[first].onleft(p[last - 1]))
            last--; //Remove the top of the queue of useless half plane.
        return last - first + 1;
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
    printf("%d\n", hp.halfplaneinsert() - 2);
}
int main()
{
    freopen("test.in", "r", stdin);
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}