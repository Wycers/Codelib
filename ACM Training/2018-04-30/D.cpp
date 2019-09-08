#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 20;
const double eps = 1e-8;
int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || '9' < ch)
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

struct Point
{
    double x, y;
    Point () {}
    Point (double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    void Init()
    {
        x = read();
        y = read();
    }
} p[N];

struct Vector
{
    double x, y;
    Vector () {}
    Vector (double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    double operator * (const Vector &b) const {
        return x * b.x + y * b.y;
    }
    double operator ^ (const Vector &b) const {
        return x * b.y - y * b.x;
    }
};

Vector operator - (const Point &a, const Point &b) {
    return Vector(a.x - b.x, a.y - b.y);
}