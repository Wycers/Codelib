#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    map<int, int> mp;
    vector<int> twoSum(vector<int>& nums, int target) {
        mp.clear();
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
        {
            int need = target - nums[i];
            map<int, int> ::iterator iter = mp.find(need);
            if (iter != mp.end())
            {
                res.push_back(mp[iter->first]);
                res.push_back(i);
                break;
            }
            mp[nums[i]] = i;
        }
        return res;
    }
};
Solution sl;
int main()
{
    vector<int> test;
    test.push_back(3);
    test.push_back(2);
    test.push_back(4);
    vector<int> res = sl.twoSum(test, 6);
    printf("%d %d\n", res[0], res[1]);
    return 0;
}
