class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3] = {0, 0, 0}, n = nums.size();
        for (int i = 0; i < n; ++i)
            ++cnt[nums[i]];
        for (int i = 0, j = 0; i < n; ++i)
            if (cnt[j]--)
                nums[i] = j;
            else
                --i, ++j;
    }
};
