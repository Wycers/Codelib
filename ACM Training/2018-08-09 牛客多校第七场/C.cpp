#include <set>
#include <cstring>
#include <bitset>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define fi first
#define se second
typedef long long ll;
const int N = 1 << 18 | 1;
using namespace std;

int n, m; ll ans = 0;
char str[N];
bool judge(bool *str, int len)
{
    for (int i = 0; i < len; ++i)
        if (str[i] == 1)
            return true;
    return false;
}
void dfs(bool *str, int len)
{
    if (len == 1)
    {
        if (str[0] == 1)
            ++ans;
        return;
    }
    bool ss[N];
    for (int i = 0; i < len; i += 2)
        ss[i >> 1] = (str[i] | str[i + 1]);
    if (judge(ss, len >> 1))
        dfs(ss, len >> 1);

    for (int i = 0; i < len; i += 2)
        ss[i >> 1] = (str[i] & str[i + 1]);
    if (judge(ss, len >> 1))
        dfs(ss, len >> 1);

    for (int i = 0; i < len; i += 2)
        ss[i >> 1] = (str[i] ^ str[i + 1]);
    if (judge(ss, len >> 1))
        dfs(ss, len >> 1);
}   

int main()
{
    string s;
    cin >> n >> s;
    bool str[N];
    for (int i = 0, len = s.length(); i < len; ++i)
        str[i] = (s[i] == '1');
    dfs(str, 1 << n);
    cout << ans << endl;
    return 0;
}