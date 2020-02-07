class Solution {
public:
    int d[4][2] = {{0,  1},
                   {1,  0},
                   {0,  -1},
                   {-1, 0}};

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));

        int x = 0, y = -1, i = 0;
        for (int cur = 0, tar = n * n; cur < tar;) {
            int dx = x + d[i][0], dy = y + d[i][1];
            if (dx < 0 || dy < 0 || dx >= n || dy >= n || res[dx][dy] != 0) {
                if ((++i) > 3)
                    i = 0;
                continue;
            }
            res[x = dx][y = dy] = ++cur;
        }
        return res;
    }
};