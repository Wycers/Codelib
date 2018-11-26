#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <algorithm>
const int N = 1e5 + 10;
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
struct tree
{
    int l, r, val, rnd, sz;
} tr[N];
int n, mn, Delta, leave, root = 0;
struct Treap
{
    int cnt;
    Treap() { cnt = 0; }
    void update(int k)
    {
        tr[k].sz = tr[tr[k].l].sz + tr[tr[k].r].sz + 1;
    }
    void Rturn(int &k)
    {
        int t = tr[k].l;
        tr[k].l = tr[t].r;
        tr[t].r = k;
        update(k);
        update(t);
        k = t;
    }
    void Lturn(int &k)
    {
        int t = tr[k].r;
        tr[k].r = tr[t].l;
        tr[t].l = k;
        update(k);
        update(t);
        k = t;
    }
    void Ins(int &k, int x)
    {
        if (k == 0)
        {
            cnt++;
            k = cnt;
            tr[k].rnd = rand();
            tr[k].val = x;
            tr[k].l = tr[k].r = 0;
            tr[k].sz = 1;
            return;
        }
        tr[k].sz++;
        if (x < tr[k].val)
        {
            Ins(tr[k].l, x);
            if (tr[tr[k].l].rnd < tr[k].rnd)
                Rturn(k);
        }
        else
        {
            Ins(tr[k].r, x);
            if (tr[tr[k].r].rnd < tr[k].rnd)
                Lturn(k);
        }
    }
    int Del(int &k, int x)
    {
        int t;
        if (k == 0)
            return 0;
        if (tr[k].val < x)
        {
            t = tr[tr[k].l].sz + 1;
            k = tr[k].r;
            return t + Del(k, x);
        }
        else
        {
            t = Del(tr[k].l, x);
            tr[k].sz -= t;
            return t;
        }
    }
    int Find(int k, int x)
    {
        if (tr[tr[k].l].sz + 1 == x)
            return tr[k].val + Delta;
        else if (tr[tr[k].l].sz + 1 < x)
            return Find(tr[k].r, x - tr[tr[k].l].sz - 1);
        else
            return Find(tr[k].l, x);
    }
} Tr;
void solve()
{   
    n = read(), mn = read();
    // Tr.cnt = 0;
    memset(tr, 0, sizeof tr);
    char opt[10];
    int x;
    root = Tr.cnt = Delta = leave = 0;
    while (n--)
    {
        scanf("%s", opt);
        x = read();
        if (opt[0] == 'I')
            if (x >= mn)
                Tr.Ins(root, x - Delta);
        if (opt[0] == 'A')
            Delta += x;
        if (opt[0] == 'S')
        {
            Delta -= x;
            leave += Tr.Del(root, mn - Delta);
        }
        if (opt[0] == 'Q')
        {
            if (x > tr[root].sz)
                printf("-1");
            else
                printf("%d", Tr.Find(root, tr[root].sz - x + 1));
            printf("\n");
        }
    }
    printf("%d\n", leave);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}