class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0)
            return 0;

        stack<int> st;
        while (!st.empty())
            st.pop();
        st.push(-1);
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            while (st.top() != -1 && heights[st.top()] >= heights[i])
            {
                int tmp = st.top();
                st.pop();
                ans = max(ans, heights[tmp] * (i - st.top() - 1));
            }
            st.push(i);
        }
        while (st.top() != -1)
        {
            int tmp = st.top();
            st.pop();
            ans = max(ans, heights[tmp] * (n - st.top() - 1));
        }
        return ans;
    }
};
