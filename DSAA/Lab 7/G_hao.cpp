// #pragma GCC optimize("O3")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
const int maxn = 40005;
int x[maxn], y[maxn], mod[maxn], id[maxn], ans[maxn], t[maxn];
int T, n, k, m;
priority_queue<int> pq, tmp;
inline bool cmp(const int &a, const int &b)
{
    if (y[a] == y[b])
        if (mod[a] == mod[b])
            return x[a] > x[b];
        else
            return mod[a] < mod[b];
    return y[a] < y[b];
}
void clean()
{
    while(!pq.empty())
        pq.pop();
}
void solve(void)
{
    int prey = -1, prem = -1, mx = n;
    for (int i = 1; i <= n; i++)
    {
        if (!y[id[i]])
        {
            mx = n;
            clean();
            prey = y[id[i]];
            prem = mod[id[i]];
            if (m == 1)
                ans[id[i]] = t[x[id[i]]];
            else
                ans[id[i]] = -1;
            continue;
        }
        if (prey != y[id[i]] || prem != mod[id[i]])
        {
            clean();
            mx = n;
        }
        for (int j = x[id[i]]; j <= mx; j += y[id[i]])
        {
            pq.push(-(t[j]));
            if (pq.size() > m)
                pq.pop();
        }
        if (pq.size() < m)
            ans[id[i]] = -1;
        else
            ans[id[i]] = -(pq.top());
        mx = x[id[i]] - 1;
        prey = y[id[i]];
        prem = mod[id[i]];
    }
}
int main(void)
{
    int i;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        m = sqrt(n);
        for (i = 1; i <= n; i++)
            scanf("%d", &t[i]);
        for (i = 1; i <= n; i++)
        {
            scanf("%d%d", &x[i], &y[i]);
            if (y[i])
                mod[i] = x[i] % y[i];
            else
                mod[i] = 1;
            id[i] = i;
            ans[i] = 0;
        }
        sort(id + 1, id + 1 + n, cmp);
        solve();
        for (i = 1; i <= n; i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}