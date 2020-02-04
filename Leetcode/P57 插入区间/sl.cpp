class Solution {
public:
    vector <vector<int>> insert(vector <vector<int>> &intervals, vector<int> &newInterval) {
        int n = intervals.size();
        if (n == 0) {
            return vector < vector < int >> {newInterval};
        }
        vector <vector<int>> res;
        int l = 0, r = n - 1;
        while (l <= r && intervals[l][1] < newInterval[0]) {
            res.push_back(intervals[l++]);
        }
        while (l <= r && intervals[r][0] > newInterval[1]) {
            --r;
        }
        for (int i = l; i <= r; ++i) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
        res.push_back(newInterval);
        ++r;
        while (r < n) {
            res.push_back(intervals[r++]);
        }
        return res;
    }
};