#include <cstdio>
#include <cmath>
#include <algorithm>
const double pi = acos(-1.0);
const double eps = 1e-8;

struct Vector
{
    double x, y;
} p[4];

Vector operator+(const Vector &a, const Vector &b)
{
    return (Vector){a.x + b.x, a.y + b.y};
}
Vector operator-(const Vector &a, const Vector &b)
{
    return (Vector){a.x - b.x, a.y - b.y};
}
Vector operator*(const Vector &a, const double &k)
{
    return (Vector){a.x * k, a.y * k};
}
Vector operator/(const Vector &a, const double &k)
{
    return (Vector){a.x / k, a.y / k};
}
double operator*(const Vector &a, const Vector &b)
{
    return a.x * b.x + a.y * b.y;
}
double operator^(const Vector &a, const Vector &b)
{
    return a.x * b.y - a.y * b.x;
}
int sign(double x)
{
    if (fabs(x) < eps)
        return 0;
    return x > 0 ? 1 : -1;
}
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
    return sqrt(t * t);
}
Vector rotate(Vector &a, double angle)
{
    double s = sin(angle), c = cos(angle);
    return (Vector){(c * a.x - s * a.y), (s * a.x + c * a.y)};
}
inline double fmin(double a, double b)
{
    return a < b ? a : b;
}
inline double fmax(double a, double b)
{
    return a > b ? a : b;
}
inline double fmin(double a, double b, double c)
{
    double res = 1e5;
    res = fmin(res, a);
    res = fmin(res, b);
    res = fmin(res, c);
    return res;
}
inline double fmax(double a, double b, double c)
{
    double res = 0;
    res = fmax(res, a);
    res = fmax(res, b);
    res = fmax(res, c);
    return res;
}
double w;
void solve()
{
    scanf("%lf%lf%lf%lf%lf%lf%lf", &p[1].x, &p[1].y, &p[2].x, &p[2].y, &p[3].x, &p[3].y, &w);
    double s = fabs(Area2(p[1], p[2], p[3]));
    if (s / dist(p[1], p[2]) > w && s / dist(p[1], p[3]) > w && s / dist(p[2], p[3]) > w)
    {
        puts("impossible");
        return;
    }
    Vector a = p[2] - p[1], b = p[3] - p[1];
    p[1] = p[1] - p[1];
    double ans = 1e5;
    for (int i = 0; i < 50000; ++i)
    {
        double angle = (double)i * pi / 25000.0;
        Vector ra = rotate(a, angle), rb = rotate(b, angle);
        double xmin = fmin(ra.x, rb.x, 0.0), xmax = fmax(ra.x, rb.x, 0.0);
        double ymin = fmin(ra.y, rb.y, 0.0), ymax = fmax(ra.y, rb.y, 0.0);
        if (xmax - xmin < w)
            ans = fmin(ans, ymax - ymin);
        if (ymax - ymin < w)
            ans = fmin(ans, xmax - xmin);
        printf("%lf %lf %lf\n", angle, ymax - ymin, xmax - xmin);
    }
    printf("%lf\n", ans);
}

int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}