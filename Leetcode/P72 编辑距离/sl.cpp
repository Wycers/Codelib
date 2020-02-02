class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; ++i)
            f[i][0] = i;
        for (int j = 0; j <= m; ++j)
            f[0][j] = j;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (word1[i - 1] == word2[j - 1])
                    f[i][j] = f[i - 1][j - 1];
                else
                    f[i][j] = min(f[i - 1][j - 1], min(f[i][j - 1], f[i - 1][j])) + 1;
        return f[n][m];
    }
};