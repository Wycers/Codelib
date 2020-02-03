class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> res(0);
        int n = matrix.size();
        if (n == 0)
            return res;
        int m = matrix[0].size();
        if (m == 0)
            return res;

        int x0 = 0, y0 = 0, x1 = n - 1, y1 = m - 1;
        while (x0 <= x1 && y0 <= y1) {
            if (x0 == x1 && y0 == y1) {
                res.push_back(matrix[x0][y0]);
            } else if (x0 != x1 && y0 != y1) {
                for (int j = y0; j < y1; ++j)
                    res.push_back(matrix[x0][j]);
                for (int i = x0; i < x1; ++i)
                    res.push_back(matrix[i][y1]);
                for (int j = y1; j > y0; --j)
                    res.push_back(matrix[x1][j]);
                for (int i = x1; i > x0; --i)
                    res.push_back(matrix[i][y0]);
            } else {
                if (x0 == x1) {
                    for (int j = y0; j <= y1; ++j)
                        res.push_back(matrix[x0][j]);
                }
                if (y0 == y1) {
                    for (int i = x0; i <= x1; ++i)
                        res.push_back(matrix[i][y0]);
                }
            }

            ++x0, ++y0;
            --x1, --y1;
        }
        return res;
    }
};