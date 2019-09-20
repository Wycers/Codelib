#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 2e3 + 10;
int n;

struct node
{
    int c, e;
    node () 
    {
        c = 0, e = 0;
    }
    void input() 
    {
        scanf("%d%d", &c, &e);
    }
    void output()
    {
        if (c < 0)
            printf("-");
        if (abs(c) != 1)
            printf("%d", abs(c));
        if (e != 0)
            printf("x");
        if (abs(c) == 1 && e == 0)
            printf("1");
        if (e != 1 && e != 0)
            printf("^%d", e);
    }
} a[N];

inline bool cmp(const node &a, const node &b)
{
    return a.e < b.e;
}

vector<node> v;
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        a[i].input();
    v.clear();
    sort(a + 1, a + n + 1, cmp);
    int pre = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (i < n && a[pre].e == a[i + 1].e)
            continue;
        node x;
        x.e = a[pre].e;
        while (pre <= i)
        {
            x.c += a[pre].c;
            ++pre;
        }
        x.c *= x.e--;
        if (x.c)
            v.push_back(x);
    }
    if (v.size() == 0)
    {
        puts("0");
        return;
    }
    for (int i = 0, sz = v.size(); i < sz; ++i)
    {
        v[i].output();
        if (i + 1 != sz && v[i + 1].c > 0)
            printf("+");
    }
    puts("");
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}