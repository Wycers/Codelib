/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0)
            return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        int l = intervals[0][0];
        int r = 0x80000000;
        int now = 0;
        for (int i = 0, n = intervals.size(); i < n; ++i)
        {
            r = max(r, intervals[i][1]);
            if (i + 1 < n && intervals[i + 1][0] <= r)
                continue;
            intervals[now][0] = l;
            intervals[now][1] = r;
            ++now;
            l = i + 1 < n ? intervals[i + 1][0] : 0;
            r = 0x80000000;
        }
        while (intervals.size() > now)
            intervals.pop_back();
        return intervals;
    }
};

