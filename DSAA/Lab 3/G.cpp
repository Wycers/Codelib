#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 3e5 + 10;
int n, m, val[N];
vector<int> ans;
struct data
{
    int val, cnt;
    data *pre, *nxt;
} a[N];
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
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

void del(data *p)
{
    p->nxt->pre = p->pre;
    p->pre->nxt = p->nxt;
}
void solve()
{
    n = read();
    a[0].pre = &a[0];
    a[0].nxt = &a[1];
    a[0].cnt = 0;
    a[300001].nxt = &a[300001];
    for (int i = 1; i <= 300000; ++i)
    {
        a[i].pre = &a[i - 1];
        a[i].nxt = &a[i + 1];
        a[i].val = i;
        a[i].cnt = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        val[i] = read();
        ++a[val[i]].cnt;
    }
    
    for (data *i = a; i <= a + 300000; ++i)
        if (i->cnt == 0)
            del(i);

    data *p; int s = 0;
    for (p = a; p <= a + 300000; p = p->nxt)
    {
        s += p->cnt;
        if (s >= ((n + 1) >> 1))
            break;
    }
    int cntl, cntr;
    cntl = cntr = (n - 1) >> 1;
    for (int t = n; t >= 1; --t)
    {
        if (t & 1)
            ans.push_back(p->val);

        if (val[t] > p->val)
            --cntr;
        if (val[t] < p->val) 
            --cntl;
        if (--a[val[t]].cnt == 0)
            del(&a[val[t]]);
        if (cntl + p->cnt < cntr)
        {
            cntl += p->cnt;
            p = p->nxt;
            cntr -= p->cnt;
        }
        if (cntl > p->cnt + cntr)
        {
            cntr += p->cnt;
            p = p->pre;
            cntl -= p->cnt;
        }
    }
    for (int i = ans.size() - 1; i >= 0; --i)
        printf("%d%c", ans[i], i == 0 ? '\n' : ' ');
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}