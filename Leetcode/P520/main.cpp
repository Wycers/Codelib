#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    bool detectCapitalUse(string word)
    {
        int cnt = 0;
        for (int i = 0, len = word.length(); i < len; ++i)
            if ('A' <= word[i] && word[i] <= 'Z')
                ++cnt;
        if (cnt == word.length())
            return true;
        if (cnt == 0)
            return true;
        if (word.length() > 1 && cnt == 1 && 'A' <= word[0] && word[0] <= 'Z')
            return true;
        return false;
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