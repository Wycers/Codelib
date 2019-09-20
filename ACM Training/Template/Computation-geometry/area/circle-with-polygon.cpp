#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 1e3 + 10;
const double eps = 1e-6;
const double pi = acos(-1.0);

int n; double R;
struct Vector
{
    double x, y;
} p[N], o;

Vector operator+(const Vector &a, const Vector &b)
{
    return (Vector){a.x + b.x, a.y + b.y};
}
Vector operator-(const Vector &a, const Vector &b)
{
    return (Vector){a.x - b.x, a.y - b.y};
}
Vector operator*(const double &k, const Vector &a)
{
    return (Vector){k * a.x, k * a.y};
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

void init()
{
    int i;
    double temp, sum;
    for (i = 2; i < n; i++)
    {
        temp = Area2(p[1], p[i], p[i + 1]);
        sum += temp;
    }
    if (sum < 0)
        reverse(p + 1, p + n + 1);
    p[n + 1] = p[1];
}

inline bool inCircle(Vector &s)
{
    return dist(o, s) <= R;
}

bool SameSide(Vector a, Vector b)
{
    if (dist(a, o) > dist(b, o))
        swap(a, b);
    return dot(a, b, o) < eps;
}

double ShadomOnCircle(Vector a, Vector b)
{
    double flag = Area2(o, a, b), res = 0;
    if (fabs(flag) < eps)
        return 0;

    bool ina = inCircle(a), inb = inCircle(b);
    if (ina && inb)
    {
        res = fabs(Area2(o, a, b)) / 2;
    }
    else if (!ina && !inb)
    {
        if (SameSide(a, b))
        {
            double theta = acos(dot(o, a, b) / dist(o, a) / dist(o, b));
            res = R * R * theta / 2;
        }
        else
        {
            double height = fabs(Area2(o, a, b)) / dist(a, b);
            double theta = acos(dot(o, a, b) / dist(o, a) / dist(o, b));
            if (height >= R)
            {
                res = R * R * theta / 2;
            }
            else
            {
                double _theta = 2 * acos(height / R);
                res = R * R * (theta - _theta) / 2 + R * R * sin(_theta) / 2;
            }
        }
    }
    else
    {
        if (!ina && inb)
            swap(a, b);
        double height = fabs(Area2(o, a, b)) / dist(a, b);
        double temp = dot(a, o, b);
        double theta = acos(dot(o, a, b) / dist(o, a) / dist(o, b)), theta1, theta2;
        if (fabs(temp) < eps)
        {
            double _theta = acos(height / R);
            res += R * height / 2 * sin(_theta);
            res += R * R / 2 * (theta - _theta);
        }
        else
        {
            theta1 = asin(height / R);
            theta2 = asin(height / dist(a, o));
            if (temp > 0)
            {
                res += dist(o, a) * R / 2 * sin(pi - theta1 - theta2);
                res += R * R / 2 * (theta + theta1 + theta2 - pi);
            }
            else
            {
                res += dist(o, a) * R / 2 * sin(theta2 - theta1);
                res += R * R / 2 * (theta - theta2 + theta1);
            }
        }
    }
    if (flag < 0)
        return -res;
    else
        return res;
}


//
void init()
{
    double sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= 2; ++i)
        scanf("%lf%lf", &p[i].x, &p[i].y);
    for (int i = 3; i <= n; ++i)
    {
        scanf("%lf%lf", &p[i].x, &p[i].y);
        sum += Area2(p[1], p[i - 1], p[i]);
    }
    if (sum < 0)
        reverse(p + 1, p + n + 1);
    p[n + 1] = p[1];
}
double Cover()
{
    int i;
    double res = 0;
    for (i = 1; i <= n; i++)
        res += ShadomOnCircle(p[i], p[i + 1]);
    return res;
}

int main()
{
    init();
    printf("%lf\n", Cover());
    return 0;
}