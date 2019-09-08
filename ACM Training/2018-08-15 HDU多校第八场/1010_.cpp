#include <cstdio>
#include <algorithm>
const int N = 1e5 + 10;
using namespace std;
int n, m, a[N];

inline void output(int x)
{
    printf("%d\n", x - 1);
}

int st[N], pos[N], len[N], top = 0;
int st1[N], pos1[N], len1[N], top1 = 0; 
void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    a[++n] = 0x3f3f3f3f;
    
    top = 0;
    for (int i = n; i >= 1; --i)
    {
        while (top && st[top] <= a[i]) 
            --top;
        len[i] = len[pos[top]] + 1;
        ++top;
        st[top] = a[i];
        pos[top] = i;
    }
    a[1] = -0x3f3f3f3f;
    top1 = 0;
    for (int i = n; i >= 1; --i)
    {
        while (top1 && st1[top1] <= a[i]) 
            --top1;
        len1[i] = len1[pos1[top1]] + 1;
        ++top1;
        st1[top1] = a[i];
        pos1[top1] = i;
    }
    
    reverse(st + 1, st + top + 1);
    reverse(pos + 1, pos + top + 1);
    reverse(st1 + 1, st1 + top1 + 1);
    reverse(pos1 + 1, pos1 + top1 + 1);
    for (int i = 1; i <= top; ++i)
    {
        printf("%d %d\n", pos[i], st[i]);
    }
    for (int i = 1; i <= n; ++i)
        printf("%d\n", len[i]);
    puts("");
    int x, y;
    while (m--)
    {
        scanf("%d%d", &x, &y);
        if (a[x] == y)
        {
            output(len[1]);
            continue;
        }
        if (x == 1)
        {
            int yyy = upper_bound(st1 + 1, st1 + top1 + 1, y) - st1;
            output(1 + len1[pos1[yyy]]);
        }
        else
        {
            bool inq = false;
            int yy = lower_bound(pos + 1, pos + top + 1, x) - pos;
            inq = (pos[yy] == x);
            if (inq)
            {
                if (a[x] > y)
                {
                    if (st[yy - 1] < y)
                        output(len[1]);
                    else
                        output(len[1] - 1);
                }
                else 
                {
                    int yyy = upper_bound(st + 1, st + top + 1, y) - st;
                    if (st[yyy] < y)
                        output(yyy + len[pos[yyy]]);
                    else 
                        output(len[1]);
                }
            }
            else
            {
                if (a[x] > y)
                {
                    output(len[1]);
                }
                else 
                {
                    if (st[yy] < y)
                        output(len[1]);
                    else
                    {
                        int yyy = upper_bound(st + 1, st + top + 1, y) - st;
                        if (st[yyy] < y)
                            output(yyy + len[pos[yyy]]);
                        else 
                            output(len[1]);
                    }
                }   
            }
        }
    }
}
int main()
{
    freopen("test.in", "r", stdin);
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}