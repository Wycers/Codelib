class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.length() > num2.length())
            swap(num1, num2);
        int n = num1.length(), m = num2.length();
        vector<int> res(n + m, 0);

        int now = 0;
        for (int i = n - 1; i >= 0; --i) {

            for (int j = m - 1; j >= 0; --j) {
                res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                res[i + j] += res[i + j + 1] / 10;
                res[i + j + 1] %= 10;
            }
        }
        stringstream ss;
        for (auto i = res.begin(); i < res.end(); ++i) {
            if (*i == 0)
                continue;
            copy(i, res.end(), ostream_iterator<int>(ss, ""));
            return ss.str();
        }
        return "0";
    }
};