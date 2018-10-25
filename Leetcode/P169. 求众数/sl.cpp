class Solution
{
  public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int pre = 0, mx = 0, ans = 0;
        for (int i = 0, len = nums.size(); i < len; ++i)
        {
            if (i != len - 1 && nums[pre] == nums[i + 1])
                continue;
            if (i - pre + 1 > len / 2)
                return nums[pre];
            pre = i + 1;
        }
        return 0;
    }
};