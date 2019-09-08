#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 15;
const int Q = 5e5 + 10;
int n, m, q, w[N]; 
int tr[1 << 20];
long long s[N * 100];
void insert()
{
    char str[N];
    scanf("%s", str + 1);
    for (int i = 1, now = 1; i <= n; ++i)
    {
        now = (now << 1) | (str[i] - '0');
        ++tr[now];
    }
}

char t[N];
void dfs(int k, int now, int use, int res)
{
    if (now > n)
    {
        s[use] += 1ll * res;
        return;
    }
    if (tr[k] == 0)
        return;
    if ((k & 1) ^ (t[now] - '0') == 0)
    {
        dfs(k << 1, now + 1, use + w[now], tr[k]);
        dfs(k << 1 | 1, now + 1, use + w[now], tr[k]);
    }
    else
    {
        dfs(k << 1, now + 1, use, tr[k]);
        dfs(k << 1 | 1, now + 1, use, tr[k]);
    }
}

struct data
{
    int x, k, index;
} p[Q];
long long ans[Q];
char query[Q][N];
inline bool cmp(const data &a, const data &b)
{
    return a.x < b.x;
}
int main()
{   
    freopen("test.in", "r", stdin);
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%d", w + i);
    for (int i = 1; i <= m; ++i)
        insert();
    for (int i = 1; i <= q; ++i)
    {
        scanf("%s%d", query[i] + 1, &p[i].k);
        p[i].index = i;
        int x = 0;
        for (int dight = 1; dight <= n; ++dight)
            x = (x << 1) | (query[i][dight] - '0');
        p[i].x = x;
    }
    sort(p + 1, p + q + 1, cmp);
    for (int i = 1, pre = 1; i <= q; ++i)
    {

        if (p[i].x != p[i + 1].x)
        {
            strcpy(t + 1, query[p[i].index] + 1);
            memset(s, 0, sizeof s);
            dfs(2, 1, 0, 0);
            dfs(3, 1, 0, 0);
            for (int i = 0; i <= 1200; ++i)
                s[i] /= 2;
            for (int i = 1; i <= 1200; ++i)
                s[i] += s[i - 1];
            for (pre; pre <= i; pre++)
                ans[p[pre].index] = s[p[pre].k];
        }
    }
    for (int i = 1; i <= q; ++i)
        printf("%lld\n", ans[i]);
    return 0;
}