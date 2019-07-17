/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return 0;
        int l = 0, r = nums.size() - 1, mid, ans;
        if (target > nums[r])
            return r + 1;
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
};

