class Solution {
public:
    int n, m, d[4][2] = {{-1, 0},
                         {1,  0},
                         {0,  -1},
                         {0,  1}};

    bool exist(vector<vector<char>> &board, vector<vector<bool>> &mp, string word, int x, int y, int k) {
        if (board[x][y] != word[k])
            return false;
        if (k + 1 == word.length())
            return true;
        for (int i = 0; i < 4; ++i) {
            int dx = x + d[i][0];
            int dy = y + d[i][1];
            if (dx < 0 || dx >= n || dy < 0 || dy >= m || mp[dx][dy])
                continue;
            mp[dx][dy] = true;
            if (exist(board, mp, word, dx, dy, k + 1))
                return true;
            mp[dx][dy] = false;
        }
        return false;
    }

    bool exist(vector<vector<char>> &board, string word) {
        n = board.size();
        if (n == 0)
            return false;
        m = board[0].size();
        if (m == 0)
            return false;

        vector<vector<bool>> mp(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                mp[i][j] = true;
                if (exist(board, mp, word, i, j, 0))
                    return true;
                mp[i][j] = false;
            }
        return false;
    }
};