#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int numJewelsInStones(string J, string S)
    {
        int ans = 0;
        for (int i = 0, n = J.length(); i < n; ++i)
            for (int j = 0, m = S.length(); j < m; ++j)
                if (J[i] == S[j])
                    ++ans;
        return ans;
    }
};