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
using namespace std;
const int sz = 1 << 18 | 1;
typedef bitset<sz> bs;
unordered_map<bs, ll> dp[2];

int main()
{
    int n;
    string s;
    cin >> n >> s;
    dp[0][bs(s)] = 1;
    bs l, r;
    for (int i = 1; i <= n; ++i)
    {
        dp[i & 1].clear();
        int k = 1 << (n - i), t = sz - k;
        for (const auto &st : dp[!(i & 1)])
        {
            l = st.first >> k;
            r = (st.first << t) >> t;
            dp[i & 1][l & r] += st.se;
            dp[i & 1][l | r] += st.se;
            dp[i & 1][l ^ r] += st.se;
        }
    }
    cout << dp[n & 1][1] << endl;
    return 0;
}
const int sz = 1 << 18 | 1;
typedef bitset<sz> bs;
unordered_map<bs, ll> dp[2];

int main()
{
    int n;
    string s;
    cin >> n >> s;
    dp[0][bs(s)] = 1;
    bs l, r;
    for (int i = 1; i <= n; ++i)
    {
        dp[i & 1].clear();
        int k = 1 << (n - i), t = sz - k;
        for (const auto &st : dp[!(i & 1)])
        {
            l = st.first >> k;
            r = (st.first << t) >> t;
            dp[i & 1][l & r] += st.se;
            dp[i & 1][l | r] += st.se;
            dp[i & 1][l ^ r] += st.se;
        }
    }
    cout << dp[n & 1][1] << endl;
    return 0;
}


// 赵老师的dp，会MLE