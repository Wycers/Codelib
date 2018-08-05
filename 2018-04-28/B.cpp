#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
#include <ctime>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <deque>
using namespace std;
int n, top;
struct P
{
    double x, y;
} p[2005], s[2005];
double dis(P a, P b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
P operator - (P a, P b)
{
    P t;
    t.x = a.x - b.x;
    t.y = a.y - b.y;
    return t;
}
double operator*(P a, P b)
{
    return a.x * b.y - a.y * b.x;
}
bool operator < (P a, P b)
{
    double t = (a - p[1]) * (b - p[1]);
    if (t == 0)
        return dis(a, p[1]) < dis(b, p[1]);
    return t < 0;
}
double cross_product(P a, P b, P c)
{
    return (b - a) * (c - a);
}
void graham()
{
    int k = 1;
    for (int i = 2; i <= n; i++)
        if (p[k].y > p[i].y || (p[k].y == p[i].y && p[k].x > p[i].x))
            k = i;
    swap(p[1], p[k]);
    sort(p + 2, p + n + 1);
    s[++top] = p[1];
    s[++top] = p[2];
    for (int i = 3; i <= n; i++)
    {
        while (top > 1 && (p[i] - s[top - 1]) * (s[top] - s[top - 1]) <= 0)
            top--;
        s[++top] = p[i];
    }
}
double RC()
{
    s[top + 1] = p[1];
    double ans = 0x3f3f3f3f;
    for (int i = 1; i <= top; ++i)  
    {  
        double res = 0;
        for (int j = 1; j <= top; ++j)
        {
            if (j == i)
                continue;
            if (j == i + 1)
                continue;

            double tmp = fabs(cross_product(s[i], s[i + 1], s[j])) / dis(s[i], s[i + 1]);
            if (fabs(tmp) > 1e-8)
                res = max(res, tmp);
        }
        if (fabs(res) > 1e-8)
            ans = min(ans, res);
    }  
    return ans;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf", &p[i].x, &p[i].y);
    graham();
    printf("%.6lf", RC());
    return 0;
}