/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root, long long l, long long r) {
        if (root == NULL)
            return true;
        int val = root->val;
        if (val <= l || r <= val)
            return false;
        return isValidBST(root->left, l, val) && isValidBST(root->right, val, r);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, INT64_MIN, INT64_MAX);
    }
};