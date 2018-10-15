#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<string> ans;
    void dfs(int left, int right, string now)
    {
        if (left == 0 && right == 0) 
        {
            ans.push_back(now);
            return;
        }
        if (left)
            dfs(left - 1, right, now + "(");
        if (right && right > left)
            dfs(left, right - 1, now + ")");
    }
    vector<string> generateParenthesis(int n)
    {
        while (!ans.empty())
            ans.pop();
        dfs(n, n, "");
        return ans;
    }
};