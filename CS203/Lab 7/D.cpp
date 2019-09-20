#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 5e5 + 10;
int h[N], top;
bool XD = true;
bool cmp(const int &a, const int &b)
{
    return XD ? a > b : a < b;
}
void fix(int pos)
{
    while ((pos << 1) <= top)
    {
        int t = pos;
        if (cmp(h[pos << 1], h[t]))
            t = pos << 1;
        if ((pos << 1 | 1) <= top && cmp(h[pos << 1 | 1], h[t]))
            t = pos << 1 | 1;
        if (t == pos)
            break;
        swap(h[t], h[pos]);
        pos = t;
    }
}
void del()
{
    swap(h[1], h[top]);
    --top;
    fix(1);
} 
void solve()
{
    int k;
    scanf("%d%d", &top, &k);
    if (top < 2 * k)
    {
        XD = false;
        k = top - k + 1;
    }
    else 
        XD = true;
    memset(h, 0, sizeof h);
    for (int i = 1; i <= top; ++i)
        scanf("%d", h + i);
    for (int i = top / 2 + 1; i >= 1; --i)
        fix(i);
    --k;
    while (k--)
        del();
    printf("%d\n", h[1]);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}