#include <bit/stdc++.h>
using namespace std;
vector<int> pos[128];
int n; 
string ans, now;
void merge()
{
    int lena = ans.length(), lenb = now.length();
    for (int i = 0; i < lenb; ++i)
    {
        int ch = now[i], nowp;
        int p = upper_bound(pos[ch].begin(), pos[ch].end(), nowp);
    }
}
void solve()
{
    for (int i = 0; i < 128; ++i)
        pos[i].clear();
    ans = "";
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        cin >> now;
        merge();
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