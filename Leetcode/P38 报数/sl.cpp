/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 报数
 */
class Solution {
public:
    string countAndSay(int n) {
        string res[35];
        res[0] = "";
        res[1] = "1";
        for (int i = 1; i <= n; ++i)
        {
            int last = 0;
            for (int j = 0, len = res[i].length(); j < len; ++j)
            {
                if (j + 1 < len && res[i][j + 1] == res[i][last])
                    continue;
                res[i + 1] += to_string(j - last + 1);
                res[i + 1] += res[i][j];
                last = j + 1;
            }
        }
        return res[n];
    }
};

