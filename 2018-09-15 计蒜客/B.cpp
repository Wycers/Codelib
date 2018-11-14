#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
char str[110];
inline bool isdight(char c)
{
    return '0' <= c && c <= '9';
}
inline int pri(char c)
{
    if (c == 'd')
        return 2;
    if (c == '*')
        return 1;
    return 0;
}
pair<int, int> cal(int l, int r)
{
    vector<pair<int, int> > dig;
    vector<char> opt;
    int x = 0; bool flag = false;
    for (int i = l; i < r; ++i)
    {
        // printf("%c\n", str[i]);
        if (isdight(str[i]))
        {
            x = x * 10 + str[i] - '0';
            flag = true;
        }
        else if (str[i] == '(')
        {
            for (int j = r - 1; j >= l; --j)
                if (str[j] == ')')
                {
                    dig.push_back(cal(i + 1, j));
                    i = j;
                    break;
                }
        }
        else
        {
            if (flag)
            {
                dig.push_back(make_pair(x, x));
                x = 0;
                flag = false;
            }
            while (opt.size() && pri(str[i]) < pri(opt[opt.size() - 1]))
            {
                char ch = opt.back(); opt.pop_back();
                pair<int, int> a, b;
                if (dig.size())
                {
                    b = dig.back();
                    dig.pop_back();
                }
                else    
                    b = make_pair(0, 0);
                if (dig.size())
                {
                    a = dig.back();
                    dig.pop_back();
                }
                else    
                    a = make_pair(0, 0);
                // printf("[%d, %d] %c [%d, %d]\n", a.first, a.second, ch, b.first, b.second);
                if (ch == 'd')
                    dig.push_back(make_pair(a.first * 1, a.second * b.second));
                else if (ch == '*')
                    dig.push_back(make_pair(a.first * b.first, a.second * b.second));
                else if (ch == '+')
                    dig.push_back(make_pair(a.first + b.first, a.second + b.second));
                else
                    dig.push_back(make_pair(a.first - b.second, a.second - b.first));
            }
            opt.push_back(str[i]);
        }
        if (i == r - 1 && flag) 
            dig.push_back(make_pair(x, x));
    }

    // puts("dig:");
    // for (int i = 0, len = dig.size(); i < len; ++i)
    //     printf("%d %d\n", dig[i].first, dig[i].second);
    // puts("opt:");
    // for (int i = 0, len = opt.size(); i < len; ++i)
    //     printf("%c\n", opt[i]);
    // puts("");

    while (opt.size())
    {
        char ch = opt.back(); opt.pop_back();
        pair<int, int> a, b;
        if (dig.size())
        {
            b = dig.back();
            dig.pop_back();
        }
        else    
            b = make_pair(0, 0);
        if (dig.size())
        {
            a = dig.back();
            dig.pop_back();
        }
        else    
            a = make_pair(0, 0);
        if (ch == 'd')
            dig.push_back(make_pair(a.first * 1, a.second * b.second));
        else if (ch == '*')
            dig.push_back(make_pair(a.first * b.first, a.second * b.second));
        else if (ch == '+')
            dig.push_back(make_pair(a.first + b.first, a.second + b.second));
        else
            dig.push_back(make_pair(a.first - b.second, a.second - b.first));
    }
    // printf("==>%d %d\n", dig[0].first, dig[0].second);
    return dig[0];
}
void solve()
{
    pair<int, int> ans = cal(0, strlen(str));
    printf("%d %d\n", ans.first, ans.second);
}
int main()
{
    // freopen("test.in", "r", stdin);
    while (~scanf("%s", str))
        solve();
    return 0;
}