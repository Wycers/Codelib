#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<int> sortArrayByParity(vector<int> &A)
    {
        int l = -1, r = A.size();
        vector<int> ans(r); 
        for (int i = 0, len = A.size(); i < len; ++i)
            if (A[i] & 1)
                ans[--r] = A[i];
            else
                ans[++l] = A[i];
        return ans;
    }
};