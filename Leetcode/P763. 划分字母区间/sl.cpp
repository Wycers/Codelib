#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int pos[26];
    vector<int> partitionLabels(string str)
    {
        vector<int> ans;
        while (!ans.empty())
            ans.pop_back();
        for (int i = 0, len = str.length(); i < len; ++i)
            pos[str[i] - 'a'] = i;
        int l = 0, r = 0;
        for (int i = 0, len = str.length(); i < len; ++i)
        {
            r = max(r, pos[str[i] - 'a']);
            if (i == r)
            {
                ans.push_back(r - l + 1);
                l = r + 1;
            }
        }
        return ans;
    }
};
int main()
{
    Solution sl;
    vector<int> ans = sl.partitionLabels("ababcbacadefegdehijhklij");
    for (auto i : ans)
        cout << i << endl;
    return 0;
}