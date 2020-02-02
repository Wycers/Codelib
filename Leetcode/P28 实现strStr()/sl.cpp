class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length();
        if (n == 0)
            return 0;

        vector<int> nx(n, 0);
        nx[0] = -1;
        for (int i = 0, j = -1; i < n; )
        {
            if (j == -1 || needle[i] == needle[j])
                nx[++i] = ++j;
            else
                j = nx[j];
        }

        int m = haystack.length();
        for (int i = 0, j = 0; i < m; ) {
            if (j == -1 || haystack[i] == needle[j]) {
                ++i; ++j;
                if (j == n)
                    return i - n;
            } else {
                j = nx[j];
            }
        }
        return -1;
    }
};