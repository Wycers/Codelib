class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> ans = {0};
        for (int i = 0; i < n; i++)
        {
            int head = 1 << i;
            for (int j = ans.size() - 1; j >= 0; j--)
                ans.push_back(head + ans[j]);
        }
        return ans;
    }
};
