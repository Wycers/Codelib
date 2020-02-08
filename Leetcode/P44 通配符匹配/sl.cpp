class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, false));
        f[0][0] = true;
        for (int j = 1; j <= m; ++j)
            f[0][j] = f[0][j - 1] && (p[j - 1] == '*');
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                    f[i][j] = f[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    f[i][j] = f[i][j - 1] || f[i - 1][j];
                }
            }
        }
        return f[n][m] == 1;
    };
};
