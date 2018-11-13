#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int cnt[1 << 20], enter[1 << 10], leave[1 << 20];
struct data
{
    int type, cnt, ti;
} h[N];
bool operator < (const data &a, const data &b) {
    if (a.cnt == b.cnt)
        return a.ti > b.ti;
    return a.cnt < b.cnt;
}
int n, m, top, g;
void fix(int pos)
{
    if (pos == 1)
        return;
    while (pos != 1)
    {
        if (h[pos >> 1] < h[pos])
            swap(h[pos], h[pos >> 1]);
        else
            break;
        pos >>= 1;
    }
}
void add(int x)
{
    h[++top] = (data){x, ++cnt[x], enter[x]};
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
        if (h[t] < h[pos << 1])
            t = pos << 1;
        if ((pos << 1 | 1) <= top && h[t] < h[pos << 1 | 1])
            t = pos << 1 | 1;
        if (t == pos)
            break;
        swap(h[t], h[pos]);
        pos = t;
    }
} 
void solve()
{
    scanf("%d%d", &m, &n);
    top = 0; g = 0;
    int x, ans = 0;
    memset(cnt, 0, sizeof cnt);
    memset(enter, 0, sizeof enter);
    memset(leave, 0, sizeof leave);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &x);
        while (leave[h[1].type] > h[1].ti)
            del();
        if (cnt[x] == 0 && g == m)
        {
            ++ans;
            cnt[h[1].type] = 0; 
            --g; 
            leave[h[1].type] = i;
            del();
        }
        if (cnt[x] == 0)
        {
            enter[x] = i;
            ++g;
        }
        add(x);
    } 
    printf("%d\n", ans);
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}

/*
6
3 5
1 2 3 2 4
2 4
1 2 2 1
2 6
1 2 2 1 1024 1
1
2 10
1 2 3 2 4 2 3 6 7 8
2 1
1048575
1
6 16
10 1 2 3 4 5 6 1 2 3 6 5 4 10 1 6
 
 */