class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = INT_MAX;
        string* s;
        for (int i = 0, len = strs.size(); i < len; ++i)
            if (n > strs[i].length())
            {
                n = strs[i].length();
                s = &strs[i];
            }
        if (n == INT_MAX)
            return "";
        for (int ans = 0; ans < n; ++ans)
        {
            bool flag = true;
            for (int i = 0, len = strs.size(); i < len; ++i)
                if (strs[i][ans] != (*s)[ans])
                {
                    flag = false;
                    break;
                }
            if (flag)
                continue;
            return s->substr(0, ans);
        }
        return *s;
    }
};
