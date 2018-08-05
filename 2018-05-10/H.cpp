#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
bool a[200];
int len, limit[2];
string str; int x, y;
int find(int x, int d, bool type)
{
    int res = 0;
    if (d == 1)
    {
        for (int i = x; i < len; ++i)
            if (a[str[i]] == type)
                ++res;
            else   
                break;
    }
    else
    {
        for (int i = x; i >= 0; --i)
            if (a[str[i]] == type)
                ++res;
            else   
                break;
    }
    return res;
}
string solve()
{
    cin >> str >> limit[1] >> limit[0];
    len = str.length();
    
    bool flag = true;
    for (int i = 0; i < len; ++i)
    {
        if (str[i] == '?')
            continue;
        int l = i, r;
        for (int j = i; j < len; ++j)
        {
            if (str[j] == '?')
            {
                r = j - 1;
                break;
            }
            if (j == len - 1)
                r = j;
        }
        int cnt = 0, type = a[str[l]];
        for (int k = l; k <= r; ++k)
        {
            if (type == a[str[k]])
                ++cnt;
            if (k == r || type != a[str[k + 1]])
            {
                if (cnt == limit[type])
                    flag = false;
                if (k != r)
                    type = a[str[k + 1]];
                cnt = 0;
            }
        }
        i = r + 1;
    }
    if (!flag)
        return "DISLIKE";

    flag = true;
    string tmp1 = "", tmp2;
    for (int i = 0; i < len; ++i)
    {
        if (str[i] == '?')
        {
            tmp1 += "a";
            tmp2 += "b";
            continue;
        }
        tmp1 += str[i];
        tmp2 += str[i];
    }
    int cnt = 0, type = a[tmp1[0]];
    for (int i = 0; i < len; ++i)
    {
        if (type == a[tmp1[i]])
            ++cnt;
        if (i == len - 1 || type != a[tmp1[i + 1]])
        {
            if (cnt >= limit[type])
                flag = false;
            if (i != len - 1)
            {
                type = a[tmp1[i + 1]];
                cnt = 0;
            }
        }
    }
    cnt = 0; type = a[tmp2[0]];
    for (int i = 0; i < len; ++i)
    {
        if (type == a[tmp2[i]])
            ++cnt;
        if (i == len - 1 || type != a[tmp2[i + 1]])
        {
            if (cnt >= limit[type])
                flag = false;
            if (i != len - 1)
            {
                type = a[tmp2[i + 1]];
                cnt = 0;
            }
        }
    }
    if (!flag)
        return "SURPRISE";
    return "LIKE";
}
int main()
{
    memset(a, false, sizeof(a));
    a['a'] = true; a['e'] = true; a['i'] = true;
    a['o'] = true; a['u'] = true;
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
        printf("Case #%D: %s\n", i, solve().c_str());
    return 0;
}