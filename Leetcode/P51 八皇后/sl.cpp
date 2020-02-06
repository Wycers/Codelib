class Solution {
    vector <vector<string>> res;

    int n;

    void dfs(vector<bool> &col, vector<bool> &dig, vector<bool> &udig, vector <string> &v, int rownum) {
        if (rownum == n) {
            res.push_back(v);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (col[i] || dig[i - rownum + n] || udig[i + rownum])
                continue;
            v[rownum][i] = 'Q';
            col[i] = dig[i - rownum + n] = udig[i + rownum] = true;
            dfs(col, dig, udig, v, rownum + 1);
            col[i] = dig[i - rownum + n] = udig[i + rownum] = false;
            v[rownum][i] = '.';
        }
    }

public:
    vector <vector<string>> solveNQueens(int n) {
        this->n = n;
        int N = n << 1;
        vector<bool> row(n, false);
        vector<bool> col(n, false), dig(N, false), udig(N, false);

        vector <string> v(n, string(n, '.'));
        dfs(col, dig, udig, v, 0);
        return res;
    }
};
