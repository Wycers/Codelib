#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 5e3 + 10;
int n, s[N], t[N], tag[N];
inline bool cmp(const int a, const int b)
{
    if (t[a] == t[b])
        return s[a] < s[b];
    return t[a] < t[b];
}
bool used[10010];
bool judge(int x)
{
    memset(used, false, sizeof used);
    for (int i_ = 0; i_ < n; ++i_)
    {
        int i = tag[i_];
        int cnt = 0;
        bool flag = false;
        for (int j = s[i]; j <= t[i]; ++j)
        {
            if (used[j])
                continue;
            used[j] = true;
            if (++cnt == x)
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
            return false;
    }
    return true;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", s + i, t + i);
    int l = 0, r = 0, ans = 0;
    for (int i = 0; i < n; ++i)
    {
        tag[i] = i;
        r += t[i] - s[i];
        --t[i];
    }
    r = r / n + 1;
    sort(tag, tag + n, cmp);
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (judge(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}