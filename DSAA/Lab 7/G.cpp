#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
int a[N], h[N], top;


struct Data
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
        f[i] = (Data){x, y, y == 0 ? 1 : x % y};
        tag[i] = i;
    }
    sort(tag + 1, tag + n + 1, cmp);

    int i, pre;
    for (i = 1; i <= n; ++i)
    {
        int x = f[tag[i]].x, y = f[tag[i]].y;
        if (y == 0)
            ans[tag[i]] =  k == 1 ? a[x] : -1;
        else
        {
            pre = i;
            break;
        }
    }
    // for (int i = 1; i <= n; ++i)
    //     printf("%d %d %d\n", f[tag[i]].x, f[tag[i]].y, f[tag[i]].k);
    for (; i <= n; ++i)
    {
        if (i < n && f[tag[pre]].y == f[tag[i + 1]].y && f[tag[pre]].k == f[tag[i + 1]].k)
            continue;
        top = 0;
        int fx = f[tag[pre]].x, fy = f[tag[pre]].y;
        int tx = (n - fx) / fy, ty = fy;
        if (tx == 0)
            tx = fx;
        else
            tx = tx * ty + fx;
        // printf("==> %d %d %d %d %d\n", tx, pre, i, fx, fy);
        while (pre <= i)
        {
            if (top == k)
            {
                if (a[tx] > h[1])
                {
                    add(a[tx]);
                    del();
                }
            }
            else
                add(a[tx]);
            // printf("qwq：%d %d\n", tx, f[tag[pre]].x);
            while (tx == f[tag[pre]].x && ty == f[tag[pre]].y)
            {
                // printf("%d %d %d %d\n", pre, h[1], tag[pre], top);
                if (top < k)
                    ans[tag[pre]] = -1;
                else
                    ans[tag[pre]] = h[1];
                ++pre;
            }
            tx -= ty;
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%d\n", ans[i]);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}