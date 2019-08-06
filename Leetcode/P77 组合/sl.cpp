class Solution {
public:
    vector<vector<int>> ans;
    void work(const int &n, const int &k, vector<int>& res, int i)
    {
        if (res.size() == k)
        {
            ans.push_back(res);
            return;
        }
        if (i == n + 1)
            return;
        work(n, k, res, i + 1);
        res.push_back(i);
        work(n, k, res, i + 1);
        res.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        ans.clear()
        if(n <= 0 || k > n || k <= 0)
            return ans;
        vector<int> res;
        work(n, k, res, 1);
        return ans;
    }
};
