class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for (int i = 0, len = s.length(); i < len; ++i)
        {
            char now = s[i];
            if (now == 'I')
            {
                if (i + 1 < len && s[i + 1] == 'V')
                {
                    ans += 4;
                    ++i;
                    continue;
                }
                if (i + 1 < len && s[i + 1] == 'X')
                {
                    ans += 9;
                    ++i;
                    continue;
                }
                ans += 1;
            }
            else if (now == 'V')
                ans += 5;
            else if (now == 'X')
            {
                if (i + 1 < len && s[i + 1] == 'L')
                {
                    ans += 40;
                    ++i;
                    continue;
                }
                if (i + 1 < len && s[i + 1] == 'C')
                {
                    ans += 90;
                    ++i;
                    continue;
                }
                ans += 10;
            }
            else if (now == 'L')
                ans += 50;
            else if (now == 'C')
            {
                if (i + 1 < len && s[i + 1] == 'D')
                {
                    ans += 400;
                    ++i;
                    continue;
                }
                if (i + 1 < len && s[i + 1] == 'M')
                {
                    ans += 900;
                    ++i;
                    continue;
                }
                ans += 100;
            }
            else if (now == 'D')
                ans += 500;
            else
                ans += 1000;
        }
        return ans;
    }
};
