#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 1000;
const double eps = 1e-8;
inline int read()
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

struct edge_
{
    int to, next; double w;
} edge[2 * N * N];
int head[2 * N], cnt = 0;
int u[N * N], v[N * N]; double d[N * N]; int tag[N * N], cntt = 0;
void insert(int u, int v, double w)
{
    edge[++cnt] = (edge_){v, head[u], w};
    head[u] = cnt;
}


int n, b, r;
double x[2 * N], y[2 * N];
void readin()
{
    scanf("%d%d%d", &n, &b, &r);
    for (int i = 1; i <= b; ++i)
        scanf("%lf%lf", x + i, y + i);
    for (int i = 1; i <= r; ++i)
        scanf("%lf%lf", x + b + i, y + b + i);
}

double sqr(double x)
{
    return x * x;
}
bool cmp(const int &a, const int &b)
{
    return d[a] > d[b];
}

int nn;
void init()
{
    nn = b + r;
    for (int i = 1; i <= b; ++i)
        for (int j = b + 1; j <= nn; ++j)
        {
            ++cntt;
            u[cntt] = i;
            v[cntt] = j;
            d[cntt] = sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]));
            tag[cntt] = cntt;
        }   
    sort(tag + 1, tag + cntt + 1, cmp);
    for (int i = 1; i <= cntt; ++i)
        insert(u[tag[i]], v[tag[i]], d[tag[i]]);
}

bool used[2 * N]; int match[2 * N];
bool find(int x, double limit)
{
    for (int i = head[x]; i; i = edge[i].next)
    {
        if (edge[i].w >= limit)
            break;
        int v = edge[i].to;
        if (used[v] == false)
        {
            used[v] = true;
            if (match[v] == 0 || find(match[v], limit))
            {
                match[v] = x;
                return true;
            }
        }
    }
    return false;
}
void solve()
{
    double l = 0, r = 1e9, ans;
    while (fabs(r - l) > eps)
    {
        double mid = (l + r) / 2.0;
        int all = 0;
        memset(match, 0, sizeof(match));
        for (int i = 1; i <= nn; i++)
        {
            memset(used, 0, sizeof(used));
            if (find(i, mid))
                ++all;
        }
        if (nn - all >= n)
            l = mid;
        else
            r = mid;
    }
    printf("%.6lf\n", l);
}
int main()
{
    readin();
    init();
    solve();
    return 0;
}