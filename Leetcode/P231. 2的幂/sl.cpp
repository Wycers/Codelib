class Solution {
public:
    bool isPowerOfTwo(int n) {
        int ans = 0;
        for (int tmp = n; tmp; tmp &= (tmp - 1))
            ++ans;
        return n > 0 && ans == 1;
    }
};