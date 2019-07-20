/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0)
            return;
        int m = matrix[0].size();
        if (m == 0)
            return;

        bool row = false, col = false;
        for (int i = 0; i < n; ++i)
            if (matrix[i][0] == 0)
            {
                col = true;
                break;
            }

        for (int j = 0; j < m; ++j)
            if (matrix[0][j] == 0)
            {
                row = true;
                break;
            }

        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;

        for (int i = 1; i < n; ++i)
            if (matrix[i][0] == 0)
                for (int j = 1; j < m; ++j)
                    matrix[i][j] = 0;

        for (int j = 1; j < m; ++j)
            if (matrix[0][j] == 0)
                for (int i = 1; i < n; ++i)
                    matrix[i][j] = 0;

        if (row)
            for (int j = 0; j < m; ++j)
                matrix[0][j] = 0;

        if (col)
            for (int i = 0; i < n; ++i)
                matrix[i][0] = 0;
    }
};

