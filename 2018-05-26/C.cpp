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
} tr[2000000];

int n, m, a[N];

void insert(int k, int t, int x)
{  
    if (t == -1)
        return;
    if ((1 << t) & x)
    {
        ++tr[k].cntr;
        insert(k << 1 | 1, t - 1, x);
    }
    else
    {
        ++tr[k].cntl;
        insert(k << 1, t - 1, x);
    }
}

void del(int k, int t, int x)
{
    if (t == -1)
        return;
    if ((1 << t) & x)
    {
        --tr[k].cntr;
        del(k << 1 | 1, t - 1, x);
    }
    else
    {
        --tr[k].cntl;
        del(k << 1, t - 1, x);
    }
}

int ans = 0, tot = 0;
void query(int k, int t, int v)
{
    if (t == -1)
        return;
    if ((1 << t) & v)
    {
        if (tr[k].cntl)
        {
            ans |= (1 << t);
            query(k << 1, t - 1, v);
        }
        else
            query(k << 1 | 1, t - 1, v);
    }
    else
    {
        if (tr[k].cntr)
        {
            ans |= (1 << t);
            query(k << 1 | 1, t - 1, v);
        }
        else
            query(k << 1, t - 1, v);
    }
}

void init()
{
    n = read(); m = read(); tot = 0;
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    for (int i = 1; i <= n; ++i)
        insert(1, 18, a[i]);
}
void solve()
{
    char ch[10]; int x, y;
    while (m--)
    {
        scanf("%s", ch); x = read();
        if (ch[0] == 'Q')
        {
            ans = 0; tot ^= x;
            query(1, 18, tot);
            printf("%d\n", ans);
        }
        else
        {
            scanf("%d", &y); 
            del(1, 18, a[x]);
            insert(1, 18, a[x] = (y ^ tot));
        }
    }
}

int main()
{
    freopen("readin.in", "r", stdin);
    freopen("pai.out", "w", stdout);
    for (int T = read(); T; --T)
    {
        init();
        solve();
    }
    return 0;
}