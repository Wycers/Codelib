/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        for (int i = 0, n = nums.size(); i < n; ++i)
        {
            int p = i;
            while (p + 1 != n && nums[p + 1] == nums[i])
                ++p;
            nums[len++] = nums[i];
            i = p;
        }
        return len;
    }
};

