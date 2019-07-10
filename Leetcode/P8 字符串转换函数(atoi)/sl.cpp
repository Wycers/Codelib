class Solution {
public:
    int myAtoi(string str) {
        bool sign = false;
        for (int i = 0, len = str.length(); i < len; ++i)
        {
            if (str[i] == ' ')
                continue;
            if (str[i] == '-')
                sign = true;
            int res = 0;
            for (int j = i + sign; j < len && '0' <= str[j] && str[j] <= '9'; ++j)
            {
                if (abs(res) > INT_MAX / 10)
                    return sign ? INT_MIN : INT_MAX;
                if (abs(res) == INT_MAX / 10)
                {
                    if (sign && str[j] > '8')
                        return INT_MIN;
                    if (!sign && str[j] > '7')
                        return INT_MAX;
                }
                res = res * 10 + (sign ? -1 : 1) * (str[j] - '0');
            }
            return res;
        }
        return 0;
    }
};
