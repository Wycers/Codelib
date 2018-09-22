#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (int i = 0, len = moves.length(); i < len; ++i)
        {
            if (moves[i] == 'U')
                ++y;
            else if (moves[i] == 'D')
                --y;
            else if (moves[i] == 'L')
                --x;
            else
                ++x;
        }
        return !x && !y;
    }
};

int main()
{
    Solution sl;
    printf("%d\n", sl.judgeCircle("UD"));
    return 0;
}