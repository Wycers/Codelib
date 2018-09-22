#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isChar(string s)
    {
        if (s.length() > 1)
            return false;
        if (s[0] == '-')
            return true;
        if (s[0] == '+')
            return true;
        if (s[0] == '*')
            return true;
        if (s[0] == '/')
            return true;
        return false;
    }
    int toint(string s)
    {
        int x = 0, f = 1;
        for (int i = 0, len = s.length(); i < len; ++i)
        {
            if (s[i] < '0' || '9' < s[i])
            {
                if (s[i] == '-')
                    f = -1;
                continue;
            }
            x = x * 10 + s[i] - 48;   
        }
        return x * f;
    }
        
    int evalRPN(vector<string>& tokens) {
        vector<int> num;
        num.clear();
        for (int i = 0, len = tokens.size(); i < len; ++i)
        {
            if (isChar(tokens[i]))
            {
                int b = num.back(); num.pop_back();
                int a = num.back(); num.pop_back();
                if (tokens[i][0] == '+')
                    num.push_back(a + b);
                else if (tokens[i][0] == '-')
                    num.push_back(a - b);
                else if (tokens[i][0] == '*')
                    num.push_back(a * b);
                else 
                    num.push_back(a / b);
                printf("%d %d\n", a ,b );
            }
            else 
                num.push_back(toint(tokens[i]));
        }
        return num[0];
    }
};

int main()
{
    Solution sl;
    vector<string> test;
    test.clear();
    test.push_back("4");
    test.push_back("13");
    test.push_back("5");
    test.push_back("/");
    test.push_back("+");
    printf("%d\n", sl.evalRPN(test));
    return 0;
}