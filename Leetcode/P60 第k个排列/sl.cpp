class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        string num = "123456789";
        vector<int> f(n, 1);
        for (int i = 1; i < n; ++i) f[i] = f[i - 1] * i;
        --k;
        for (int i = n - 1; i >= 0; --i) {
            int cnt = k / f[i];
            k %= f[i];
            res.push_back(num[cnt]);
            num.erase(cnt, 1);
        }
        return res;
    }
};