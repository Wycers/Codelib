#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid.empty())
            return 0;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> f(n, vector<int>(m, 0));

        f[0][0] = obstacleGrid[0][0] ^ 1;
        for (int i = 1; i < m; ++i)
            f[0][i] = obstacleGrid[0][i] ? 0 : f[0][i - 1];
        for (int i = 1; i < n; ++i)
            f[i][0] = obstacleGrid[i][0] ? 0 : f[i - 1][0];
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                f[i][j] = obstacleGrid[i][j] ? 0 : f[i - 1][j] + f[i][j - 1];
        return f[n - 1][m - 1];
    }
};
 
int main()
{
    Solution sl;
    return 0;
}