class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = nums[0], sum = 0;
        for (int num : nums)
        {
            sum = sum > 0 ? sum + num : num;
            ans = max(ans, sum);
        }
        return ans;
    }
};
