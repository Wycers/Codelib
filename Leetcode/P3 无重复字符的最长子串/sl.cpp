class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos[128];
        for (int i = 0; i < 128; ++i)
            pos[i] = -1;
        int ans = 0, l = 0;
        for (int r = 0, len = s.length(); r < len; ++r)
        {
            int c = s[r];
            if (pos[c] != -1)
                l = max(l, pos[c] + 1);
            pos[c] = r;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
