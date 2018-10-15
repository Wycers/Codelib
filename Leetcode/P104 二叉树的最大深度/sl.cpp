/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int ans = 0;
    void dfs(TreeNode *now, int dp)
    {
        if (now == NULL)
            return;
        if (dp > ans)
            ans = dp;
        dfs(now->left, dp + 1);
        dfs(now->right, dp + 1);
    }
    int maxDepth(TreeNode *root)
    {
        dfs(root, 1);
        return ans;
    }
};