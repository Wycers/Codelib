/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */
class Solution {
public:
    double myPow(double x, int n) {
        unsigned int N;
        if (n >= 0)
            N = n;
        else
        {
            x = 1 / x;
            N = 1ll * -1 * n;
        }

        double ans = 1.0, tmp = x;
        for (unsigned int i = N; i ; i >>= 1) {
            if (i & 1)
                ans = ans * tmp;
            tmp = tmp * tmp;
        }
        return ans;
    }
};

