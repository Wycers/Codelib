class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void work(vector<int>& nums, vector<int>& res, int k)
    {
        if (k == ((1 << n) - 1))
        {
            ans.push_back(res);
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if ((1 << i) & k)
                continue;
            res.push_back(nums[i]);
            work(nums, res, k | (1 << i));
            res.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        if (n == 0)
            return ans;
        vector<int> res;
        work(nums, res, 0);
        return ans;
    }
};
