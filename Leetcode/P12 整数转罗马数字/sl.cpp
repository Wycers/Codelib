class Solution {
public:
       int rep[13] = {1000,  900, 500,  400, 100,   90,  50,   40,  10,    9,   5,    4,   1};
    string str[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string intToRoman(int num) {
        string res = "";
        for (int i = 0; i < 13; ++i)
            while (num >= rep[i])
            {
                num -= rep[i];
                res += str[i];
            }
        return res;
    }
};
