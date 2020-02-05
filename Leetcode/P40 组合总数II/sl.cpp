class Solution {
public:
    vector<int> res, nx;

    void work(vector<vector<int>> &ans, vector<int> &candidates, int k, int target) {
        if (target < 0)
            return;
        if (target == 0) {
            ans.push_back(res);
            return;
        }
        if (k == candidates.size())
            return;

        work(ans, candidates, nx[k], target);

        res.push_back(candidates[k]);
        work(ans, candidates, k + 1, target - candidates[k]);
        res.pop_back();
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end(), [](int a, int b) -> bool {
            return a > b;
        });
        vector<vector<int>> ans;
        nx.resize(candidates.size());
        int last = candidates.size();
        nx[last - 1] = last;
        for (int i = last - 2; i >= 0; --i) {
            if (candidates[i] == candidates[i + 1]) {
                nx[i] = nx[i + 1];
            } else {
                nx[i] = i + 1;
            }
        }

        work(ans, candidates, 0, target);
        return ans;
    }
};