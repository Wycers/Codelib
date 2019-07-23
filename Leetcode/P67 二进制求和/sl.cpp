class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() < b.length())
            swap(a, b);
        int n = a.length(), m = b.length();
        string ans = "";
        bool c = 0;
        for (int i = 0; i < m; ++i)
        {
            int na = a[n - i - 1] - '0';
            int nb = b[m - i - 1] - '0';
            int tmp = na + nb + c;
            ans += (char)((tmp & 1) + '0');
            c = tmp & 2;
        }
        for (int i = m; i < n; ++i)
        {
            int na = a[n - i - 1] - '0';
            ans += (char)((na ^ c) + '0');
            c = na & c;
        }
        if (c)
            ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
