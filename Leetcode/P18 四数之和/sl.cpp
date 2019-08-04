/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() < 4)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        set<vector<int>> a; //去重
        for (int i = 0; i < nums.size() - 3; i++)
        {
            if (nums[i] > target && target > 0)
                break;
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                int l = j + 1;
                int r = nums.size() - 1;
                while (l < r)
                {
                    if (nums[i] + nums[j] + nums[l] + nums[r] < target)
                        l++;
                    else if (nums[i] + nums[j] + nums[l] + nums[r] > target)
                        r--;
                    else
                    {
                        a.insert({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                    }
                }
            }
        }
        for (auto &c : a)
            res.push_back(c);
        return res;
    }
};
