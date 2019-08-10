class Solution
{
public:
    int row[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int col[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int block[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    bool flag = false;
    void work(vector<vector<char>> &board, int x, int y)
    {
        if (flag)
            return;
        if (y == 9)
        {
            ++x;
            y = 0;
        }
        if (x == 9)
        {
            flag = true;
            return;
        }

        if (board[x][y] != '.')
        {
            work(board, x, y + 1);
            return;
        }
        int blk = 3 * (x / 3) + y / 3;
        for (int i = 1; i <= 9; ++i)
        {
            if (row[x] & (1 << i))
                continue;
            if (col[y] & (1 << i))
                continue;
            if (block[blk] & (1 << i))
                continue;

            row[x] ^= (1 << i);
            col[y] ^= (1 << i);
            block[blk] ^= (1 << i);
            board[x][y] = i + '0';
            work(board, x, y + 1);
            if (flag)
                return;
            row[x] -= (1 << i);
            col[y] -= (1 << i);
            block[blk] -= (1 << i);
            board[x][y] = '.';
        }
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    row[i] |= (1 << num);
                    col[j] |= (1 << num);
                    block[3 * (i / 3) + j / 3] |= (1 << num);
                }
        work(board, 0, 0);
    }
};
