#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;

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

inline double Area2(Vector &a, Vector &b, Vector &c)
{
    Vector t1 = b - a;
    Vector t2 = c - a;
    return t1 ^ t2;
}
inline double dot(Vector &a, Vector &b, Vector &c)
{
    Vector t1 = b - a;
    Vector t2 = c - a;
    return t1 * t2;
}
inline double dist(Vector &a, Vector &b)
{
    Vector t = b - a;
    return t.length();
}