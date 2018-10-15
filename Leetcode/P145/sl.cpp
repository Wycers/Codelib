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
    vector<int> ans;
    void dfs(TreeNode *now)
    {
        if (now == NULL)
            return;
        dfs(now->left);
        dfs(now->right);
        ans.push_back(now->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        while (!ans.empty())
            ans.pop_back();
        dfs(root);
        return ans;
    }
};