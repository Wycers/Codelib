#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string str, int n) {
        if (n == 1)
            return str;
        string res = "";
        int step = (n - 1) << 1;
        int len = str.length();
        for (int i = 0; i < n; ++i)
        {
            if (i == 0 || i == n - 1)
                for (int j = i; j < len; j += step)
                    res += str[j];
            else
                for (int j = i; j < len; j += step)
                {
                    res += str[j];
                    if (j + step - (i << 1) < len)
                        res += str[j + step - (i << 1)];
                }
        }
        return res;
    }
};
int main()
{
    Solution sl;
    cout << sl.convert("A", 1);
    return 0;
}
