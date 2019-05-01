#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
const int N = 1e5 + 10;
int n, x[N], y[N], tagx[N], tagy[N], tr[N];
inline bool cmpx(const int &a, const int &b)
{
    return x[a] < x[b];
}
inline bool cmpy(const int &a, const int &b)
{
    return y[a] < y[b];
}
void add(int pos)
{
    for (int i = pos; i <= n; i += i & -i)
        ++tr[i];
}
int get(int pos)
{
    int res = 0;
    for (int i = pos; i >= 1; i -= i & -i)
        res += tr[i];
    return res;
}
map<int, int> mp;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", x + i, y + i);
        tagx[i] = i;
        tagy[i] = i;
        tr[i] = 0;
    }
    sort(tagx + 1, tagx + n + 1, cmpx);
    sort(tagy + 1, tagy + n + 1, cmpy);
    
    long long ans = 0;
    int p = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (i != n && x[tagx[p]] == x[tagx[i + 1]])
            continue;
        ans += (i - p + 1) * (n - i);
        p = i + 1;
    }
    p = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (i != n && y[tagy[p]] == y[tagy[i + 1]])
            continue;
        ans += (i - p + 1) * (n - i);
        p = i + 1;
    }

    mp.clear();
    for (int i = 1; i <= n; ++i)
        mp[y[tagy[i]]] = i;

    p = 1;
    for (int i = 1; i <= n; ++i)
    {   
        ans -= 1ll * get(mp[y[tagx[i]]]);
        if (i != n && x[tagx[p]] == x[tagx[i + 1]])
            continue;
        while (p <= i)
            add(mp[y[tagx[p++]]]);
    }
    printf("%lld\n", 1ll * n * (n - 1) - ans);
    return 0;
}