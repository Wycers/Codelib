#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
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
    Vector s, e;
    double ag;
    Line () {}
    Line (Vector _s, Vector _e) {
        s = _s;
        e = _e;
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
    }
    // 一般式确定直线
    Line (double a, double b, double c) {
        if (sign(a) == 0) {
            s = Vector(0, -c / b);
            e = Vector(1, -c / b);
        }
        if (sign(b) == 0) {
            s = Vector(-c / a, 0);
            e = Vector(-c / a, 1);
        }
        else {
            s = Vector(0, -c / b);
            e = Vector(1, (-c - a) / b);
        }
    }
    void input() {
        s.input();
        e.input();
    }
    double length() {
        return s.distance(e);
    }
    // 计算倾斜角
    double angle() {
        Vector t = e - s;
        double k = atan2(t.x, t.y);
        if (sign(k) == -1)
            k += pi;
        if (sign(k - pi) == 0)
            k -= pi;
        return k;
    }
    double calangle()
    {
        ag = atan2(e.y - s.y, e.x - s.x);
    }
    // 某点和该直线的关系，1在左，0在上，-1在右
    int prelation (const Vector &p) {
        return sign((e - s) ^ (p - s));
    }
    // 线与线是否平行
    bool parallel(const Line &b) {
        return sign((e - s) ^ (b.e - b.s)) == 0;
    }
    // 某线和该直线的关系，0 - 平行， 1 - 重合， 2 - 相交
    int linecrossline(Line v) {
        if ((*this).parallel(v))
            return v.prelation(s) == 0;
        return 2;
    }
    // 点在线段是否在线段上
    bool cross(const Vector &p) {
        return prelation(p) == 0 && sign((p - s) ^ (p - e)) <= 0; 
    }
    // 求两直线的交点，要保证两直线不平行或重合
    Vector crosspoint(const Line &b) {
        Vector v1 = e - s;
        Vector v2 = b.e - b.s;
        Vector t = s - b.s;
        double tmp = (v2 ^ t) / (v1 ^ v2);
        return s + v1 * tmp;
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
    // 求该多边形面积
    double area() {
        double res = 0;
        for (int i = 0; i < n; i++)
            res += (p[i] ^ p[(i + 1) % n]);
        return fabs(res) / 2;
    }
} ans;
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
    void unique()
    {
        int m = 1;
        for (int i = 1; i < n; i++)
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
        for (int i = 0; i < n; i++)
            hp[i].calangle();
        sort(hp, hp + n);
        unique();
        que[st = 0] = 0;
        que[ed = 1] = 1;
        p[1] = hp[0].crosspoint(hp[1]);
        for (int i = 2; i < n; i++)
        {
            while (st < ed && sign((hp[i].e - hp[i].s) ^ (p[ed] - hp[i].s)) < 0)
                ed--;
            while (st < ed && sign((hp[i].e - hp[i].s) ^ (p[st + 1] - hp[i].s)) < 0)
                st++;
            que[++ed] = i;
            if (hp[i].parallel(hp[que[ed - 1]]))
                return false;
            p[ed] = hp[i].crosspoint(hp[que[ed - 1]]);
        }
        while (st < ed && sign((hp[que[st]].e - hp[que[st]].s) ^ (p[ed] - hp[que[st]].s)) < 0)
            ed--;
        while (st < ed && sign((hp[que[ed]].e - hp[que[ed]].s) ^ (p[st + 1] - hp[que[ed]].s)) < 0)
            st++;
        if (st + 1 >= ed)
            return false;
        return true;
    }

    //需要调用halfplaneinsert。
    void getconvex(polygon &con)
    {
        p[st] = hp[que[st]].crosspoint(hp[que[ed]]);
        con.n = ed - st + 1;
        for (int j = st, i = 0; j <= ed; i++, j++)
            con.p[i] = p[j];
    }
} hp;

int n;
void solve()
{
    scanf("%d", &n);
    hp.n = 0;
    hp.push(Line(Vector(1e12, 1e12), Vector(-1, 1e12)));
    hp.push(Line(Vector(0, 1e12), Vector(0, -1)));
    for (int i = 0; i < n; ++i)
    {
        double b, k;
        scanf("%lf%lf", &b, &k);
        hp.push(Line(k, -1, b));
    }
    hp.halfplaneinsert();
    hp.getconvex(ans);
    // for (int i = 0; i < ans.n; ++i)
    //     ans.p[i].output();
    printf("%d\n", ans.n - 2);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}