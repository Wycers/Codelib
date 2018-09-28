#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N = 2e5 + 10;
int n, enter[26], leave[26], g[55];
vector<int> v;
void solve()
{
    memset(g, 0, sizeof g);
    memset(enter, -1, sizeof enter);
    v.clear();
 
 
    string str; cin >> str;
    for (int i = 0, len = str.length(); i < len; ++i)
    {
        int ch = str[i] - 'A';
        if (enter[ch] == -1)
        {
            enter[ch] = i;
            v.push_back(ch);
        }
        else
            leave[ch] = i;
    }
 
    int ans = 0;
    for (int i = 0, len = v.size(); i < len; ++i)
    {
        bool flag = false;
        for (int j = enter[v[i]]; j <= leave[v[i]]; ++j)
        {
            if (g[j] >= n)
                continue;
            ++g[j];
            flag = true;
        }
        if (flag == false)
            ++ans;
    }
    printf("%d\n", ans);
}
int main()
{
    while (~scanf("%d", &n))
    {
        if (n == 0)
            break;
        solve();
    }
    return 0;
}