class Solution
{
public:
    int firstUniqChar(string s)
    {
        int n = s.length();
        if (n == 0)
            return -1;
        int pos[26];
        for (int i = 0; i < 26; ++i)
            pos[i] = -1;
        for (int i = n - 1; i >= 0; --i)
        {
            int ch = s[i] - 'a';
            if (pos[ch] == -1)
                pos[ch] = i;
        }
        for (int i = 0; i < n; ++i)
        {
            int ch = s[i] - 'a';
            if (pos[ch] == i)
                return i;
            else
                pos[ch] = -1;
        }
        return -1;
    }
};
