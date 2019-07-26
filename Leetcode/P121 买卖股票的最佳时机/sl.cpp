class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ans = 0, mn = 0x3f3f3f3f;
        for (int i = 0; i < n; ++i)
        {
            ans = max(ans, prices[i] - mn);
            mn = min(mn, prices[i]);
        }
        return ans;
    }
};
