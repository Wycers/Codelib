class Solution {
private:
    vector<vector<int>> ans;
    vector<int> tmp, nx;
    int n;

    void work(vector<int> &nums, int k) {
        if (k == n) {
            ans.push_back(tmp);
            return;
        }

        work(nums, nx[k]);

        tmp.push_back(nums[k]);
        work(nums, k + 1);
        tmp.pop_back();
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        nx.resize(nums.size());
        int last = nums.size();
        nx[last - 1] = last;
        for (int i = last - 2; i >= 0; --i) {
            if (nums[i] == nums[i + 1]) {
                nx[i] = nx[i + 1];
            } else {
                nx[i] = i + 1;
            }
        }
        work(nums, 0);
        return ans;
    }
};
