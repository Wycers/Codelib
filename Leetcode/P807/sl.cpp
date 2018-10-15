#include <bits/stdc++.h>
class Solution
{
  public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> h(n, 0);
        vector<int> v(m, 0);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] > h[i])
                    h[i] = grid[i][j];
                if (grid[i][j] > v[j])
                    v[j] = grid[i][j];
            }

        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                ans += min(h[i], v[j]) - grid[i][j];

        return ans;
    }
};