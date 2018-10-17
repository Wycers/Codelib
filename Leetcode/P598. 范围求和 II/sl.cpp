class Solution
{
  public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        int x = m, y = n;
        for (int i = 0, len = ops.size(); i < len; ++i)
        {
            x = min(x, ops[i][0]);
            y = min(y, ops[i][1]);
        }
        printf("%d\n", x * y);
    }
};