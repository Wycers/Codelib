class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int a[15], len = 0;
        while (x)
        {
            a[++len] = x % 10;
            x /= 10;
        }
        int l = 1, r = len;
        while (l < r)
            if (a[l++] != a[r--])
                return false;
        return true;
    }
};
