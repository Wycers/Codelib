class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> res;
        work(ans, res, nums, 0);
        return ans;
    }
    void work(vector<vector<int>> &ans, vector<int> &res, vector<int> &nums, int now)
    {
        ans.push_back(res);
        for (int i = now; i < nums.size(); i++)
        {
            res.push_back(nums[i]);
            work(ans, res, nums, i + 1);
            res.pop_back();
        }
    }
};
