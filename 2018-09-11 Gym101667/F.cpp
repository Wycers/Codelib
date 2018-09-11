#include <cstdio>
#include <algorithm>
#define fi first
#define se second
using namespace std;
pair<int, int> dfs(int len, int k)
{
    int h = len / 2;
    int t = h * h;
    if (t == 1)
    {
        switch (k)
        {
            case 1: return make_pair(1, 1);
            case 2: return make_pair(1, 2);
            case 3: return make_pair(2, 2);
            case 4: return make_pair(2, 1);
        }
    }
    int cnt = k / t, r = k % t;
    if (r)
        ++cnt;
    else
        r = t;
    pair<int, int> res = dfs(h, r);
    switch (cnt)
    {
        case 1: return make_pair(res.se    , res.fi);
        case 2: return make_pair(res.fi    , res.se + h);
        case 3: return make_pair(res.fi + h, res.se + h);
        case 4: 
            res.fi += h;
            int y = -res.fi + len + 1;
            return make_pair(res.fi - (res.se - y), y);
    }
}
int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        pair<int, int> ans = dfs(n, m);
        printf("%d %d\n", ans.fi, ans.se);
    }
    return 0;
}