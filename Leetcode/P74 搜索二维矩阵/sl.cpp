class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0)
            return false;
        int m = matrix[0].size();
        if (m == 0)
            return false;

        int l = 0, r = n - 1, mid;

        int row = 0;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (target < matrix[mid][0])
                r = mid - 1;
            else if (target > matrix[mid][0])
            {
                row = mid;
                l = mid + 1;
            }
            else
                return true;
        }

        l = 0;
        r = m - 1;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (target < matrix[row][mid])
                r = mid - 1;
            else if (target > matrix[row][mid])
                l = mid + 1;
            else
                return true;
        }
        return false;
    }
};
