/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            if (digits[i] == 9)
                digits[i] = 0;
            else
            {
                ++digits[i];
                return digits;
            }

        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};

