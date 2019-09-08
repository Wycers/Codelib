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
const double pi = acos(-1.0);
int n, top;
const int N = 2e6 + 10;
struct P
{
    double x, y;
} p[N], s[N];
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
double cal()
{
    double ans = dis(s[top], s[1]);
    for (int i = 1; i < top; ++i)
        ans += dis(s[i], s[i + 1]);
    return ans;
}
int main()
{
    int cnt = 0; double x, y, r;
    scanf("%d", &cnt);
    n = 0;
    for (int i = 1; i <= cnt; ++i)
    {
        scanf("%lf%lf%lf", &x, &y, &r);
        r += 10;
        for (int j = 0; j < 5000; ++j)
        {
            double theta = 2 * pi * ((double)j / 5000);
            p[++n] = (P){x + r * cos(theta), y + r * sin(theta)};
        }
    }
    graham();
    printf("%.6lf", cal());
    return 0;
}