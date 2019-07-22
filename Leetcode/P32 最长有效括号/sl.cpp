/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int top = 0, ans = 0, last = 0;
        for (int i = 0, len = s.length(); i < len; ++i)
        {
            if (s[i] == '(')
                st.push(i);
            else if (st.empty())
                last = i + 1;
            else
            {
                st.pop();
                if (st.empty())
                    ans = max(ans, i - last + 1);
                else
                    ans = max(ans, i - st.top());
            }
        }
        return ans;
    }
};

