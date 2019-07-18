/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
           return n;
        vector<int> f = {0, 1, 2};
        for (int i = 3; i <= n; ++i)
            f.push_back(f[i - 1] + f [i - 2]);
        return f[n];
    }
};

