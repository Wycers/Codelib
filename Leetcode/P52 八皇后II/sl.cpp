class Solution {
public:
    int res, n;

    void dfs(vector<bool> &col, vector<bool> &dig, vector<bool> &udig, int rownum) {
        if (rownum == n) {
            ++res;
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (col[i] || dig[i - rownum + n] || udig[i + rownum])
                continue;
            col[i] = dig[i - rownum + n] = udig[i + rownum] = true;
            dfs(col, dig, udig, rownum + 1);
            col[i] = dig[i - rownum + n] = udig[i + rownum] = false;
        }
    }

public:
    int totalNQueens(int n) {
        this->n = n;
        int N = n << 1;
        vector<bool> row(n, false), col(n, false), dig(N, false), udig(N, false);
        dfs(col, dig, udig, 0);
        return res;
    }
};