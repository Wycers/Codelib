#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int N = 2000;
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
} p[N];
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

struct polygon 
{
    int n;
    Vector p[N];
    Line l[N];
    void input(int _n) {
        n = _n;
        for (int i = 0; i < n; ++i)
            p[i].input();
    }
    void add(Vector q) {
        p[n++] = q;
    }
    void generate() {
        for (int i = 0; i < n; ++i)
            l[i] = Line(p[i], p[(i + 1) % n]);
    }
    struct cmp {
        Vector p;
        cmp (const Vector &p0) { p = p0; };
        bool operator () (const Vector &a, const Vector &b) {
            int d = sign((a - p) ^ (b - p));
            if (d == 0)
                return sign(a.distance(p) - b.distance(p)) == -1;
            return d > 0;
        }
    };
    // 求该多边形面积
    double area() {
        if (n < 3)
            return 0;
        double res = 0;
        for (int i = 1; i < n - 1; i++)
            res += ((p[i] - p[0]) ^ (p[i + 1] - p[0]));
        return res / 2.0;
    }
} origin, ans;

struct halfplanes
{
    int n;
    Line hp[N], *q[N];
    Vector p[N];
    int st, ed;
    void push(Line tmp)
    {
        hp[n++] = tmp;
    }
    void unique()
    {
        int m = 1;
        for (int i = 1; i < n; ++i)
        {
            if (sign(hp[i].ag - hp[i - 1].ag) != 0)
                hp[m++] = hp[i];
            else if (sign((hp[m - 1].e - hp[m - 1].s) ^ (hp[i].s - hp[m - 1].s)) > 0)
                hp[m - 1] = hp[i];
        }
        n = m;
    }
    bool halfplaneinsert()
    {
        sort(hp, hp + n);
        unique();
        q[st = 0] = &hp[0];
        q[ed = 1] = &hp[1];
        p[1] = hp[0].crosspoint(hp[1]);
        for (int i = 2; i < n; ++i)
        {
            while (st < ed && hp[i].prelation(p[ed]) < 0)
                ed--;
            while (st < ed && hp[i].prelation(p[st + 1]) < 0)
                st++;
            q[++ed] = &hp[i];
            if (hp[i].parallel(*q[ed - 1]))
                return false;
            p[ed] = hp[i].crosspoint(*q[ed - 1]);
        }
        while (st < ed && q[st]->prelation(p[ed]) < 0)
            ed--;
        while (st < ed && q[st]->prelation(p[st + 1]) < 0)
            st++;
        if (st + 1 >= ed)
            return false;
        return true;
    }
    void getconvex(polygon &con)
    {
        p[st] = q[st]->crosspoint(*q[ed]);
        con.n = ed - st + 1;
        for (int j = st, i = 0; j <= ed; ++i, ++j)
            con.p[i] = p[j];
    }
} hp;

void solve()
{
    for (int i = 0; i < origin.n; ++i)
        origin.p[i].input();
    if (origin.area() < 0)
        reverse(origin.p, origin.p + origin.n);

    hp.n = 0;
    for (int i = 0; i < origin.n - 1; ++i)
        hp.push(Line(origin.p[i], origin.p[i + 1]));
    hp.push(Line(origin.p[origin.n - 1], origin.p[0]));
    hp.halfplaneinsert();
    hp.getconvex(ans);
    puts(ans.n > 2 ? "1" : "0");
}
int main()
{
    while (true)
    {
        scanf("%d", &origin.n);
        if (origin.n == 0)
            break;
        solve();
    }
    return 0;
}