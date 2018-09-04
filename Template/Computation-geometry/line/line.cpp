#include "../base.cpp"

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
    
    // 线段与线段是否相交 2 - 规范相交, 1 - 非规范相交, 0 - 不相交
    int segcrossseg(Line v)
    {
        int d1 = sign((e - s) ^ (v.s - s));
        int d2 = sign((e - s) ^ (v.e - s));
        int d3 = sign((v.e - v.s) ^ (s - v.s));
        int d4 = sign((v.e - v.s) ^ (e - v.s));
        if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2)
            return 2;
        return (d1 == 0 && sign((v.s - s) * (v.s - e)) <= 0) ||
               (d2 == 0 && sign((v.e - s) * (v.e - e)) <= 0) ||
               (d3 == 0 && sign((s - v.s) * (s - v.e)) <= 0) ||
               (d4 == 0 && sign((e - v.s) * (e - v.e)) <= 0);
    }

    // 求两直线的交点，要保证两直线不平行或重合
    Vector crosspoint(const Line &v) {
        double a1 = (v.e - v.s) ^ (s - v.s);
        double a2 = (v.e - v.s) ^ (e - v.s);
        return Vector((s.x * a2 - e.x * a1) / (a2 - a1), (s.y * a2 - e.y * a1) / (a2 - a1));
    }
    // 求某点到该直线的距离
    double dfltp(const Vector &p) {
        return fabs((p - s) ^ (e - s)) / length();
    }
    // 求某点到该线段的距离
    double dfstp(const Vector &p) {
        if (sign((p - s) * (e - s)) < 0 || sign((p - e) * (s - e)) < 0)
            return min(p.distance(s), p.distance(e));
        return dfltp(p);
    }
    // 求某线段到该线段的距离 前提是两线段不相交,相交距离就是 0 了
    double dfsts(Line v) {
        return min(min(dfstp(v.s), dfstp(v.e)), min(v.dfstp(s), v.dfstp(e)));
    }
    // 求某点在该直线上的投影点
    Vector lineprog(Vector p) {
        return s + (((e - s) * ((e - s) * (p - s))) / ((e - s).lengths()));
    }
    // 求某点关于该直线的对称点
    Vector symmetryVector(Vector p) {
        Vector q = lineprog(p);
        return Vector(2 * q.x - p.x, 2 * q.y - p.y);
    }
};