class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        for (int i = 0, n = nums.size(); i < n; ++i)
        {
            int p = i;
            while (p + 1 != n && nums[p + 1] == nums[i])
                ++p;
            int t = nums[i];
            nums[len++] = t;
            if (p - i > 0)
                nums[len++] = t;
            i = p;
        }
        return len;
    }
};

