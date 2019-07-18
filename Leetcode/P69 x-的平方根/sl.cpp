/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0)
            return 0;
        unsigned int l = 0, r = 1 << 16, mid, ans;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (mid * mid >= x)
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans * ans > x ? ans - 1 : ans;
    }
};

