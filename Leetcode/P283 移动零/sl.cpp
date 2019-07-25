class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = 0;
        for (int i = 0, len = nums.size(); i < len; ++i)
        {
            if (nums[i] == 0)
                continue;
            nums[n++] = nums[i];
        }
        for (int i = n, len = nums.size(); i < len; ++i)
            nums[i] = 0;
    }
};
