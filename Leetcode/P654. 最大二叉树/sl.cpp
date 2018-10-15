class Solution {
  public:
    TreeNode *construct(vector<int> &nums, int l, int r)
    {
        if (l == r)
            return NULL;
        int pos = l;
        int mx = nums[l];
        for (int i = l; i < r; ++i)
            if (nums[i] > mx)
            {
                mx = nums[i];
                pos = i;
            }
        TreeNode *now = new TreeNode(mx);
        now->left = construct(nums, l, pos);
        now->right = construct(nums, pos + 1, r);
        return now;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return construct(nums, 0, nums.size());
    }
};