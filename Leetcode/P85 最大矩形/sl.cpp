class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.size() == 0)
            return 0;
        if (matrix[0].size() == 0)
            return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> a(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                a[i][j] = matrix[i][j] == '1' ? 1 : 0;

        int ans = 0;

        vector<vector<int>> f(n, vector<int>(m, 0));

        for (int j = 0; j < m; ++j) {
            f[0][j] = a[0][j];
            for (int i = 1; i < n; ++i)
                f[i][j] = a[i][j] == 0 ? 0 : f[i - 1][j] + 1;
        }

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                ans = max(ans, f[i][j]);

        for (int i = 0; i < n; ++i) {
            ans = max(ans, largestRectangleArea(f[i]));
        }

        return ans;
    }

private:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        if (n == 0)
            return 0;

        stack<int> st;
        while (!st.empty())
            st.pop();
        st.push(-1);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            while (st.top() != -1 && heights[st.top()] >= heights[i]) {
                int tmp = st.top();
                st.pop();
                ans = max(ans, heights[tmp] * (i - st.top() - 1));
            }
            st.push(i);
        }
        while (st.top() != -1) {
            int tmp = st.top();
            st.pop();
            ans = max(ans, heights[tmp] * (n - st.top() - 1));
        }
        return ans;
    }
};