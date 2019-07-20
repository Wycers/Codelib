/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            while (nums[i] != i + 1)
            {
                if (nums[i] >= n || nums[i] <= 0 || nums[i] == nums[nums[i] - 1])
                    break;
                swap(nums[nums[i] - 1], nums[i]);
            }
        for (int i = 0; i < n; ++i)
            if (nums[i] != i + 1)
                return i + 1;
        return n + 1;
    }
    void swap(int &a, int &b)
    {
        int c = a;
        a = b;
        b = c;
    }
};

