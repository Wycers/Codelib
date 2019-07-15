/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        int top = 0;
        for (int i = 0, len = s.length(); i < len; ++i)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else
            {
                if (st.empty())
                    return false;
                if (s[i] == ')' && st.top() != '(')
                    return false;
                if (s[i] == ']' && st.top() != '[')
                    return false;
                if (s[i] == '}' && st.top() != '{')
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

