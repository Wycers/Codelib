/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans = {-1, -1};
        if (nums.size() == 0)
            return ans;
        nums.push_back(0x7fffffff);
        int l = lower_bound(nums, target);
        int r = upper_bound(nums, target) - 1;
        if (l <= r)
        {
            ans[0] = l;
            ans[1] = r;
        }
        return ans;
    }
    int lower_bound(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1, mid, ans;
        while (l < r)
        {
            mid = (l + r) >> 1;
            if (nums[mid] < target)
            {
                l = mid + 1;
                ans = l;
            }
            else
            {
                r = mid;
                ans = r;
            }
        }
        return ans;
    }
    int upper_bound(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        int mid, ans = 0;

        while (l < r)
        {
            mid = (l + r) >> 1;
            if (nums[mid] > target)
            {
                r = mid;
                ans = r;
            }
            else
            {
                l = mid + 1;
                ans = l;
            }
        }
        return ans;
    }
};
