#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int N = 2e5 + 10;
int n, enter[26], leave[26], g[55];
vector<int> v;

priority_queue<int, vector<int>, greater<int> > q;
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
 
    int ans = 0, now = 0;
    for (int i = 0; i < 52; ++i)
    {
        if (q.size() && i == q.top())
        {
            if (q.size() > n)
                ++ans;
            q.pop();
        }
        if (now < v.size() && i == enter[v[now]])
        {
            q.push(leave[v[now++]]);
        }
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

// 此份代码有误