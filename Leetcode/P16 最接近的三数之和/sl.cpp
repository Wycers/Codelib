#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = accumulate(nums.begin(), nums.begin() + 3, 0);
        for (int i = 0; i < n; ++i)
        {
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                int res = nums[i] + nums[l] + nums[r];
                if (abs(target - res) < abs(target - ans))
                    ans = res;
                if (sum > target)
                    --r;
                else if (sum < target)
                    ++l;
                else
                    break;
            }
            return ans;
        }
    }
};
