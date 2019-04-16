#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2e3 + 10;
int n, u[N * N], v[N * N], w[N * N], tag[N * N], cnt = 0;
inline bool cmp(const int &a, const int &b)
{
    return w[a] < w[b];
}
int fa[N];
int getfa(int x)
{
    return x == fa[x] ? x : fa[x] = getfa(fa[x]);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
        {
            ++cnt;
            u[cnt] = i;
            v[cnt] = j + 1;
            scanf("%d", w + cnt);
            tag[cnt] = cnt;
        }
    sort(tag + 1, tag + cnt + 1, cmp);
    for (int i = 0; i <= n; ++i)
        fa[i] = i;
    long long ans = 0;
    for (int i = 1; i <= cnt; ++i)
    {
        int uf = getfa(u[tag[i]]);
        int vf = getfa(v[tag[i]]);
        if (uf == vf)
            continue;
        fa[uf] = vf;
        ans += w[tag[i]];
    }
    printf("%lld\n", ans);
    return 0;
}