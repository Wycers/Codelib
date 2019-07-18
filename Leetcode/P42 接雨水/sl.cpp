/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> st;
        for (int i = 0, n = height.size(); i < n; ++i)
        {
            while (!st.empty() && height[st.top()] < height[i])
            {
                int t = st.top(); st.pop();
                if (st.empty())
                    break;
                int h = min(height[st.top()], height[i]);
                int w = i - st.top() - 1;
                ans += (h - height[t]) * w;
            }
            st.push(i);
        }
        return ans;
    }
};

