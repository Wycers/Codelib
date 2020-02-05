class Solution {
public:
    void work(vector<vector<int>> &ans, vector<int> &res, vector<int> &candidates, int k, int target) {
//        cout << k << " " << target << endl;
        if (target == 0) {
            ans.push_back(res);
            return;
        }
        if (k == -1)
            return;
        if (candidates[k] == 0)
            return;
        int t = target / candidates[k];
        work(ans, res, candidates, k - 1, target);
        for (int i = 1; i <= t; ++i) {
            res.push_back(candidates[k]);
            work(ans, res, candidates, k - 1, target -= candidates[k]);
        }
        for (int i = 1; i <= t; ++i)
            res.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> tmp;
        work(res, tmp, candidates, candidates.size() - 1, target);
        return res;
    }
};