#include <cstdio>
using namespace std;
const double eps = 1e-8;
const int N = 105;
struct Vector
{
    double x, y;
    Vector () {}
    Vector (double _x, double _y)
    {
        x = _x; 
        y = _y;
    }
    void Init()
    {
        scanf("%lf%lf", &x, &y);
    }
};
struct Line
{
    Vector p, v;
    Line () {}
    Line (Vector _p, Vector _v)
    {
        p = _p;
        v = _v;
    }
};

int n, r;
Vector p[N];

int main()
{
    scanf("%d%d", n, r);
    for (int i = 0; i < n; ++i)
        p[i].Init();
}