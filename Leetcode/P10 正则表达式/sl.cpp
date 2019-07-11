#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.length();
        int m = p.length();
        string tmp = "";
        for (int i = 0; i < m; ++i)
        {
            if (p[i] == '*')
            {
                int j;
                for (j = i; j + 1 < m && p[j + 1] == '*'; ++j);
                i = j;
                tmp += "*";
                continue;
            }
            tmp += p[i];
        }
        cout << tmp;
        return match(s, tmp, 0, 0);
    }
    inline bool can(char a, char b)
    {
        return a == b || a == '.';
    }
    bool match(const string &s, const string &p, int i, int j)
    {
        if (i > s.length())
            return false;
        if (j > p.length())
            return false;
        if (i == s.length() && j == p.length())
            return true;
        if (j + 1 < p.length() && p[j + 1] == '*')
            return match(s, p, i, j + 1);
        if (p[j] == '*')
        {
            if (j == 0)
                return false;
            // 能匹配 || 不能匹配
            return (can(p[j - 1], s[i]) && match(s, p, i + 1, j)) || match(s, p, i, j + 1);
        }
        return can(p[j], s[i]) && match(s, p, i + 1, j + 1);
    }
};
int main()
{
    Solution sl;
    cout << sl.isMatch("aab", "c*a*b");
    return 0;
}
