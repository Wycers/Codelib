class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        int n = s1.size();
        vector < vector < vector < bool >> > f(n, vector < vector < bool >> (n, vector<bool>(n + 1, false)));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                f[i][j][1] = (s1[i] == s2[j]);
        for (int len = 2; len <= n; ++len)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j) {
                    bool flag = false;
                    for (int k = 1; k < len; ++k) {
                        if (i + k < n && j + k < n)
                            flag |= f[i][j][k] && f[i + k][j + k][len - k];
                        if (j + len - k < n && i + k < n)
                            flag |= f[i][j + len - k][k] && f[i + k][j][len - k];
                        if (flag)
                            break;
                    }
                    f[i][j][len] = flag;
                }

        return f[0][0][n];
    }
};