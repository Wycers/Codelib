#include <bit/stdc++.h>
using namespace std;
class Solution
{
  public:
    string toLowerCase(string str)
    {
        int g = 'a' - 'A';
        for (int i = 0, len = str.length(); i < len; ++i)
            if ('A' <= str[i] && str[i] <= 'Z')
                str[i] = str[i] + g;
        return str;
    }
};