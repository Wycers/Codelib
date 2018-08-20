#include <bits/stdc++.h>
using namespace std;
string ans, now;
vector<int> pos[256];
int n;
void solve()
{
    scanf("%d", &n);
    ans = "";
    for (int i = 0; i < 256; ++i)
        pos[i].clear();
    while (n--)
    {
        cin >> now;
        int cur = -1, len = now.length();
        for (int i = 0; i < len; ++i)
        {
            int ch = now[i];
            int p = upper_bound(pos[ch].begin(), pos[ch].end(), cur) - pos[ch].begin();
            if (p == pos[ch].size())
            {
                ans += now.substr(i);
                for (int j = i, t = ans.length(); j < len; ++j)
                    pos[now[j]].push_back(t + j - 1);
                break;
            }
            cur = pos[ch][p];
        }
    }
    cout << ans << endl;
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}