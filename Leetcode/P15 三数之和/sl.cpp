
class Solution {
public:
    vector<vector<int>> res;
    int n;
    void work(vector<int>& nums, int L, int R, int l, int i, int r)
    {
        while (L <= l && r < R)
        {
            while (L <= l - 1 && nums[l] == nums[l - 1])
                --l;
            while (r + 1 < R && nums[r] == nums[r + 1])
                ++r;
            int tmp = nums[l] + nums[i] + nums[r];
            if (tmp == 0)
                res.push_back({nums[l], nums[i], nums[r]});
            if (tmp <= 0)
                ++r;
            if (tmp >= 0)
                --l;
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            int p = i;
            while (p + 1 < n && nums[i] == nums[p + 1])
                ++p;
            int len = p - i + 1;
            if (len == 1)
                work(nums, 0, n, i - 1, i, p + 1);
            else if (len == 2)
            {
                work(nums, 0, n, i - 1, i, p);
                work(nums, i, n, i, p, p + 1);
            }
            else
                work(nums, 0, n, i, i + 1, p);
            i = p;
        }
        return res;
    }
};
