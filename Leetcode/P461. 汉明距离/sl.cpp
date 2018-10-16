class Solution
{
  public:
    int hammingDistance(int x, int y)
    {
        int ans = 0;
        for (int tmp = x ^ y; tmp; tmp &= (tmp - 1))
            ++ans;
        return ans;
    }
};