#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int h[N], top;
void fix(int pos)
{
    if (pos == 1)
        return;
    while (pos != 1)
    {
        if (h[pos] < h[pos >> 1])
            swap(h[pos], h[pos >> 1]);
        else
            break;
        pos >>= 1;
    }
}
void add(int x)
{
    h[++top] = x;
    fix(top);
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
    scanf("%d", &top);
    for (int i = 1; i <= top; ++i)
    {
        scanf("%d", h + i);
        fix(i);
    }
    int q, opt, x; scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &opt);
        if (opt == 1)
        {
            scanf("%d", &x);
            add(x);
        }
        else if (opt == 2)
            del();
        else 
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