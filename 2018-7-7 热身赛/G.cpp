#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;

struct node
{
    int flag;
    long long sum;
} tree[N * 4];

void build(int k, int l, int r)
{
    if (l == r)
    {
        scanf("%lld", &tree[k].sum);
        tree[k].flag = 1;
        if (tree[k].sum <= 1)
            tree[k].flag = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    tree[k].sum = tree[k << 1].sum + tree[k << 1 | 1].sum;
    tree[k].flag = tree[k << 1].flag | tree[k << 1 | 1].flag;
}
void update(int k, int l, int r, int L, int R)
{
    if (l == r)
    {
        tree[k].sum = (long long)sqrt(1.0 * tree[k].sum);
        if (tree[k].sum <= 1)
            tree[k].flag = 0;
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid && tree[k << 1].flag)
        update(k << 1, l, mid, L, R);
    if (R > mid && tree[k << 1 | 1].flag)
        update(k << 1 | 1, mid + 1, r, L, R);
    tree[k].sum = tree[k << 1].sum + tree[k << 1 | 1].sum;
    tree[k].flag = tree[k << 1].flag | tree[k << 1 | 1].flag;
}
long long query(int k, int l, int r, int L, int R)
{
    if (L <= l && r <= R)
        return tree[k].sum;
    long long sum = 0;
    int mid = (l + r) >> 1;
    if (L <= mid)
        sum += query(k << 1, l, mid, L, R);
    if (R > mid)
        sum += query(k << 1 | 1, mid + 1, r, L, R);
    return sum;
}
int main()
{
    int n, m, opt, l, r, T = 0;
    while (~scanf("%d", &n))
    {
        build(1, 1, n);
        scanf("%d", &m);
        printf("Case #%d:\n", ++T);
        while (m--)
        {
            scanf("%d%d%d", &opt, &l, &r);
            if (l > r)
                swap(l, r);
            if (opt == 0)
                update(1, 1, n, l, r);
            else
                printf("%lld\n", query(1, 1, n, l, r));
        }
        puts("");
    }
    return 0;
}
