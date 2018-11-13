#include <cstdio>
#include <algorithm>
<<<<<<< HEAD
#include <cstring>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q, tmp;
void solve()
{
    int n;
    scanf("%d", &n);
    q = tmp;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        q.push(x);
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int opt, x;
=======
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
>>>>>>> e0b7e4c7140b84fce92116c4e145f271689e043d
        scanf("%d", &opt);
        if (opt == 1)
        {
            scanf("%d", &x);
<<<<<<< HEAD
            q.push(x);    
        }
        else if (opt == 2)
            q.pop();
        else
            printf("%d\n", q.top());
=======
            add(x);
        }
        else if (opt == 2)
            del();
        else 
            printf("%d\n", h[1]);
>>>>>>> e0b7e4c7140b84fce92116c4e145f271689e043d
    }
}
int main()
{
<<<<<<< HEAD
    while (!tmp.empty())
        tmp.pop();
=======
>>>>>>> e0b7e4c7140b84fce92116c4e145f271689e043d
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}