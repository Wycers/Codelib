#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stack>
#include <cctype>
#include <queue>
#include <string>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define mst(x, y) memset(x, y, sizeof(x))
#define mcp(x, y) memcpy(x, y, sizeof(y))
using namespace std;
#define inf 0x3f3f3f3f
#define N 100005
typedef pair<int, int> PII;
typedef long long LL;
const double pi = acos(-1.0);
const double e = 2.718281828459;

int n, m, k, x, y;
int no[N << 2], ls[N << 2], rs[N << 2];
int a[N];
inline void pushup(int rt, int l, int r)
{
    int mid = (l + r) >> 1;
    ls[rt] = ls[rt << 1];
    rs[rt] = rs[rt << 1 | 1];
    no[rt] = max(no[rt << 1], no[rt << 1 | 1]);
    if (a[mid] < a[mid + 1])
    {
        if (ls[rt] == mid - l + 1)
            ls[rt] += ls[rt << 1 | 1];
        if (rs[rt] == r - mid)
            rs[rt] += rs[rt << 1];
        no[rt] = max(no[rt], ls[rt << 1 | 1] + rs[rt << 1]);
    }
}
void build(int rt, int l, int r)
{
    if (l == r)
    {
        no[rt] = ls[rt] = rs[rt] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt, l, r);
}
void add(int rt, int l, int r)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        add(lson);
    else
        add(rson);
    pushup(rt, l, r);
}
int query(int rt, int l, int r)
{
    if (x <= l && r <= y)
        return no[rt];
    int mid = (l + r) >> 1;
    if (y <= mid)
        return query(lson);
    if (x > mid)
        return query(rson);
    int t1 = query(lson);
    int t2 = query(rson);
    int ans = max(t1, t2);
    if (a[mid] < a[mid + 1])
    {
        ans = max(ans, (min(ls[rt << 1 | 1], y - mid) + min(rs[rt << 1], mid + 1 - x)));
    }
    return ans;
}
int main()
{
    int i, j, group;
    scanf("%d", &group);
    while (group--)
    {
        char str[5];
        scanf("%d%d", &n, &m);
        for (i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        build(1, 1, n);
        while (m--)
        {
            scanf("%s%d%d", str, &x, &y);
            if (str[0] == 'U')
            {
                a[x] = y;
                add(1, 1, n);
            }
            else
            {
                printf("%d\n", query(1, 1, n));
            }
        }
    }
    return 0;
}