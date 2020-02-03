class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int t = n + 1 >> 1;
        for (int i = 0; i < t; ++i) {
            for (int k = i; k < n - i - 1; ++k) {
                int tmp = matrix[i][k];
                matrix[i][k] = matrix[n - k - 1][i];
                matrix[n - k - 1][i] = matrix[n - i - 1][n - k - 1];
                matrix[n - i - 1][n - k - 1] = matrix[k][n - i - 1];
                matrix[k][n - i - 1] = tmp;
            }
        }
    }
};