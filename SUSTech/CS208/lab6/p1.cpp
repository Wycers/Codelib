#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int N = 1e5 + 10;
int n, a[N], ls[N], nx[N], pos[N];
map<int, int> mp;
bool judge(int l, int r)
{
    if (l >= r)
        return true;
    int mid = (l + r) >> 1;
    int tag = -1;
    for (int step = 0; step <= mid; ++step)
    {
        int i = mid + step;
        if (l <= i && i <= r && ls[i] < l && nx[i] > r)
        {
            tag = i;
            break;
        }
        i = mid - step;
        if (l <= i && i <= r && ls[i] < l && nx[i] > r)
        {
            tag = i;
            break;
        }
    }
    if (tag == -1)
        return false;
    return judge(l, tag - 1) && judge(tag + 1, r);
}
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    memset(ls, 0, sizeof ls);
    memset(nx, 0, sizeof nx);
    
    mp.clear();
    for (int i = 1; i <= n; ++i)
    {
        ls[i] = mp[a[i]];
        nx[ls[i]] = i;
        mp[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
        nx[mp[a[i]]] = n + 1;
    puts(judge(1, n) ? "Yes" : "No");
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}