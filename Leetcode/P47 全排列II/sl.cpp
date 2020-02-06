class Solution {
private:
    vector<vector<int>> ans;
    vector<int> tmp, cnt;
    int len = 0, n;

    void work(vector<int> &nums, int k, int last) {
        if (k == n) {
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i < len; ++i) {
            if (i == last)
                continue;

            int t = cnt[i];
            for (int j = 1; j <= t; ++j) {
                tmp.push_back(nums[i]);
                --cnt[i];
                work(nums, k + j, i);
            }
            cnt[i] = t;
            for (int j = 1; j <= t; ++j)
                tmp.pop_back();
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        for (int i = 0; i < n; ++i) {
            int p = i;
            while (p + 1 != n && nums[p + 1] == nums[i])
                ++p;
            nums[len++] = nums[i];
            cnt.push_back(p - i + 1);
            i = p;
        }
        work(nums, 0, -1);
        return ans;
    }
};