#include <cstdio>
#include <cmath>
const double pi = acos(-1.0);
const double eps = 1e-8;

struct Vector
{
    double x, y;
};

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

int main()
{

}