#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void push(vector<int> &ans, int val)
    {
        ans.push_back(val * val);
    }
    vector<int> sortedSquares(vector<int> &a)
    {
        int n = a.size();
        vector<int> ans;
        if (a[0] < 0 && a[n - 1] > 0)
        {
            int index;
            for (index = 0; index < n; ++index)
                if (a[index] >= 0)
                    break;
            int i = index - 1, j = index;
            while (0 <= i || j < n)
            {
                if (i == -1)
                {
                    push(ans, a[j++]);
                    continue;
                }
                if (j == n)
                {
                    push(ans, a[i--]);
                    continue;
                }
                if (abs(a[i]) > abs(a[j]))
                    push(ans, a[j++]);
                else
                    push(ans, a[i--]);
            }
            return ans;
        }
        if (a[0] <= 0 && a[n - 1] <= 0)
        {
            for (int i = n - 1; i >= 0; --i)
                push(ans, a[i]);
            return ans;
        }
        if (a[0] >= 0 && a[n - 1] >= 0)
        {
            for (int i = 0; i < n; ++i)
                push(ans, a[i]);
            return ans;
        }
        return ans;
    }
};

int main()
{
    vector<int> input = {-4,-1,0,3,10};
    Solution sl;
    vector<int> ans = sl.sortedSquares(input);
    for (int i : ans)
        printf("%d\n", i);
    return 0;
}
