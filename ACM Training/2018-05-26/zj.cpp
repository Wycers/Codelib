#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
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

struct node
{
    int cntl, cntr;
} tr[1000000];

int n, m, a[N];
int ans = 0, tot = 0;

void init()
{
    n = read(); m = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
}
void solve()
{
    char ch[10]; int x, y;
    while (m--)
    {
        scanf("%s%d", ch, &x);
        if (ch[0] == 'Q')
        {
            for (int i = 1; i <= n; ++i)
                a[i] ^= x;
            ans = 0;
            for (int i = 1; i <= n; ++i)
                ans = a[i] > ans ? a[i] : ans;
            printf("%d\n", ans);
        }
        else
        {
            scanf("%d", &y);
            a[x] = y;
        }
    }
}

int main()
{
    freopen("readin.in", "r", stdin);
    freopen("zj.out", "w", stdout);
    for (int T = read(); T; --T)
    {
        init();
        solve();
    }
    return 0;
}