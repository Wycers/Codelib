#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 4e4 + 10;
int a[N], h[N], top;


struct data
{
    int x, y, k;
} f[N];
int ans[N], tag[N];
inline bool cmp(const int &a, const int &b)
{
    if (f[a].y == f[b].y)
    {
        if (f[a].k == f[b].k)
            return f[a].x > f[b].x;
        return f[a].k < f[b].k;
    }
    return f[a].y < f[b].y;
}

void add(int x)
{
    h[++top] = x;
    int pos = top;
    if (pos == 1)
        return;
    while (pos != 1)
    {
        if ( h[pos >> 1] > h[pos])
            swap(h[pos], h[pos >> 1]);
        else
            break;
        pos >>= 1;
    }
}
void del()
{
    swap(h[1], h[top]);
    --top;
    int pos = 1;
    while ((pos << 1) <= top)
    {
        int t = pos;
        if (h[t] > h[pos << 1])
            t = pos << 1;
        if ((pos << 1 | 1) <= top && h[t] > h[pos << 1 | 1])
            t = pos << 1 | 1;
        if (t == pos)
            break;
        swap(h[t], h[pos]);
        pos = t;
    }
} 
void solve()
{
    int n, k;
    scanf("%d", &n); k = sqrt(n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        f[i] = (data){x, y, y == 0 ? 1 : x % y};
        tag[i] = i;
    }
    sort(tag + 1, tag + n + 1, cmp);
    for (int i = 1; i <= n; ++i)
        printf("%d %d %d\n", f[tag[i]].x, f[tag[i]].y, f[tag[i]].k);
    int t = n;
    while (t--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        top = 0;
        if (x + (k - 1) * y > n)
        {
            puts("-1");
            continue;
        }
        if (y == 0)
        {
            printf("%d\n", k == 1 ? a[x] : -1);
            continue;
        }
        for (int i = x; i <= n; i += y)
        {
            if (top == k)
            {
                if (a[i] <= h[1])
                    continue;
                else
                {
                    add(a[i]);
                    del();
                }
            }
            else
                add(a[i]);
        }
        printf("%d\n", h[1]);
    }
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}