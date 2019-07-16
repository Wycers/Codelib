/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = 0;
        for (int i = 0, n = nums.size(); i < n; ++i)
            if (nums[i] != val)
                nums[len++] = nums[i];
        return len;
    }
};

