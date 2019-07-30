/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {

        if (nums.size() <= 1)
            return true;
        int current_max_index = nums[0];
        int pre_max_index = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (i > current_max_index)
            {
                if (pre_max_index <= current_max_index)
                    return false;
                current_max_index = pre_max_index;
            }
            if (pre_max_index < nums[i] + i)
                pre_max_index = nums[i] + i;
        }
        return true;
    }
};

