class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i + 1] > nums[i]) {
                int j = n - 1;
                while (j > i && nums[j] <= nums[i])
                    --j;
                swap(nums[i], nums[j]);
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};